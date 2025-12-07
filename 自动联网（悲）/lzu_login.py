# 兰州大学深澜认证系统完整实现尝试
import requests
import time
import hashlib
import hmac
import base64
import json
import re
import random

print("=" * 60)
print("兰州大学深澜认证系统完整实现")
print("=" * 60)

USERNAME = "gjunran2025@elearning"
PASSWORD = "GJRgjr20070407"
BASE_URL = "http://10.10.0.166"
AC_ID = "2"

class SrunAuthFull:
    def __init__(self):
        self.session = requests.Session()
        self.session.headers.update({
            'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36',
        })
    
    def get_timestamp(self):
        return str(int(time.time() * 1000))
    
    def force_logout(self):
        """强制下线（清除可能的已登录状态）"""
        print("0. 强制下线（清理可能的状态）...")
        callback = f"jQuery1124{self.get_timestamp()}"
        url = f"{BASE_URL}/cgi-bin/srun_portal"
        params = {
            'callback': callback,
            'action': 'logout',
            'username': USERNAME,
            'ac_id': AC_ID,
            '_': self.get_timestamp()
        }
        
        try:
            response = self.session.get(url, params=params, timeout=5)
            print("   强制下线请求已发送")
        except:
            print("   强制下线请求失败（可能本来就没有登录）")
    
    def get_challenge(self):
        """获取挑战码（标准深澜协议）"""
        print("1. 获取挑战码...")
        callback = f"jQuery1124{self.get_timestamp()}"
        url = f"{BASE_URL}/cgi-bin/get_challenge"
        params = {
            'callback': callback,
            'username': USERNAME,
            'ip': '',
            '_': self.get_timestamp()
        }
        
        response = self.session.get(url, params=params, timeout=10)
        match = re.search(r'\(({.*})\)', response.text)
        if match:
            data = json.loads(match.group(1))
            if data.get('challenge'):
                print(f"✅ 挑战码: {data['challenge']}")
                return data['challenge']
        print(f"❌ 获取挑战码失败: {response.text[:200]}")
        return None
    
    def srun_encrypt(self, text, key, algorithm='md5'):
        """深澜系统加密函数"""
        if algorithm == 'md5':
            return hmac.new(key.encode(), text.encode(), hashlib.md5).hexdigest()
        elif algorithm == 'sha1':
            return hmac.new(key.encode(), text.encode(), hashlib.sha1).hexdigest()
    
    def srun_base64(self, text):
        """Base64编码"""
        return base64.b64encode(text.encode()).decode()
    
    def get_info(self, username, password, ip, token):
        """构造info参数（深澜标准格式）"""
        import json as json_lib
        
        # 多种可能的info格式
        info_formats = [
            # 格式1: 简单JSON
            {"username": username, "password": password, "ip": ip, "acid": AC_ID},
            # 格式2: 带加密版本
            {"username": username, "password": password, "ip": ip, "acid": AC_ID, "enc_ver": "srun_bx1"},
            # 格式3: 带更多字段
            {"username": username, "password": self.srun_encrypt(password, token), "ip": ip, "acid": AC_ID},
        ]
        
        results = []
        for info in info_formats:
            info_json = json_lib.dumps(info, separators=(',', ':'))
            results.append("{SRBX1}" + self.srun_base64(info_json))
        
        return results
    
    def get_chksum(self, token, username, password, ip, info):
        """计算校验和（多种可能算法）"""
        # 算法1: 标准深澜算法
        chkstr = token + username
        chkstr += token + self.srun_encrypt(password, token, 'md5')
        chkstr += token + AC_ID
        chkstr += token + ip
        chkstr += token + "200"
        chkstr += token + "1"
        chkstr += token + info
        chksum1 = hashlib.sha1(chkstr.encode()).hexdigest()
        
        # 算法2: 简化版
        chkstr2 = token + username + token + self.srun_encrypt(password, token, 'md5')
        chksum2 = hashlib.md5(chkstr2.encode()).hexdigest()
        
        return [chksum1, chksum2]
    
    def try_full_login(self):
        """尝试完整登录流程"""
        self.force_logout()
        time.sleep(2)
        
        token = self.get_challenge()
        if not token:
            return False
        
        print("2. 构造登录参数...")
        
        # 获取客户端IP
        try:
            import socket
            s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
            s.connect(("8.8.8.8", 80))
            client_ip = s.getsockname()[0]
            s.close()
        except:
            client_ip = "172.23.39.85"  # 使用页面中的IP
        
        print(f"   客户端IP: {client_ip}")
        
        # 尝试多种密码加密方式
        password_variants = [
            PASSWORD,  # 原始密码
            self.srun_encrypt(PASSWORD, token, 'md5'),  # HMAC-MD5
            self.srun_encrypt(PASSWORD, token, 'sha1'),  # HMAC-SHA1
            hashlib.md5(PASSWORD.encode()).hexdigest(),  # 纯MD5
        ]
        
        # 尝试多种组合
        for pwd_idx, password_enc in enumerate(password_variants):
            print(f"\n   尝试密码格式 {pwd_idx+1}/{len(password_variants)}...")
            
            # 获取info参数变体
            info_variants = self.get_info(USERNAME, password_enc, client_ip, token)
            
            for info_idx, info in enumerate(info_variants):
                print(f"      Info格式 {info_idx+1}/{len(info_variants)}...")
                
                # 获取chksum变体
                chksum_variants = self.get_chksum(token, USERNAME, password_enc, client_ip, info)
                
                for chksum_idx, chksum in enumerate(chksum_variants):
                    print(f"        Chksum算法 {chksum_idx+1}/{len(chksum_variants)}...")
                    
                    # 构造登录请求
                    callback = f"jQuery1124{self.get_timestamp()}"
                    url = f"{BASE_URL}/cgi-bin/srun_portal"
                    
                    params = {
                        'callback': callback,
                        'action': 'login',
                        'username': USERNAME,
                        'password': password_enc,
                        'ac_id': AC_ID,
                        'ip': client_ip,
                        'chksum': chksum,
                        'info': info,
                        'n': '200',
                        'type': '1',
                        'os': 'Windows 10',
                        'name': 'Windows',
                        'double_stack': '0',
                        '_': self.get_timestamp()
                    }
                    
                    try:
                        response = self.session.get(url, params=params, timeout=10)
                        match = re.search(r'\(({.*})\)', response.text)
                        
                        if match:
                            result = json.loads(match.group(1))
                            error = result.get('error', '')
                            
                            if error == 'ok':
                                print(f"✅ 登录成功！")
                                print(f"   使用的组合: 密码格式{pwd_idx+1}, Info格式{info_idx+1}, Chksum算法{chksum_idx+1}")
                                return True
                            elif error != 'password_algo_error':
                                print(f"⚠️ 新错误: {error}")
                                # 新错误可能意味着我们接近正确答案
                            # 如果是password_algo_error，继续尝试
                    
                    except Exception as e:
                        print(f"       请求失败: {e}")
        
        print("❌ 所有组合尝试失败")
        return False

# 执行完整登录尝试
if __name__ == "__main__":
    auth = SrunAuthFull()
    if auth.try_full_login():
        print("🎉 登录成功！")
        
        # 测试网络
        print("3. 测试网络连接...")
        try:
            test_response = requests.get("http://www.baidu.com", timeout=10)
            if test_response.status_code == 200:
                print("✅ 外网连接正常！")
        except:
            print("❌ 无法连接外网")
    else:
        print("💥 登录失败")
    
    print("\n" + "=" * 60)
    input("按回车键退出...")
