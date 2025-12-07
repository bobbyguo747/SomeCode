# 网络连接诊断脚本
import requests
import socket
import time

print("=" * 50)
print("兰州大学网络连接诊断")
print("=" * 50)

# 测试目标服务器
test_servers = [
    ("兰州大学登录服务器", "login.lzu.edu.cn", 8800),
    ("百度", "www.baidu.com", 80),
    ("谷歌DNS", "8.8.8.8", 53),
]

def test_connection(host, port, timeout=5):
    """测试到指定主机和端口的连接"""
    try:
        start_time = time.time()
        sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        sock.settimeout(timeout)
        result = sock.connect_ex((host, port))
        sock.close()
        connect_time = (time.time() - start_time) * 1000
        
        if result == 0:
            return True, f"✅ 连接成功 ({connect_time:.0f}ms)"
        else:
            return False, f"❌ 连接失败 (错误代码: {result})"
    except Exception as e:
        return False, f"❌ 连接异常: {str(e)}"

# 测试各个服务器
for name, host, port in test_servers:
    print(f"测试 {name} ({host}:{port})...")
    success, message = test_connection(host, port)
    print(f"  {message}")

# 测试HTTP访问
print("\n测试HTTP访问...")
try:
    response = requests.get("https://login.lzu.edu.cn:8800/", timeout=10)
    print(f"✅ 登录页面HTTP访问成功 (状态码: {response.status_code})")
    
    # 检查页面内容
    if "兰州大学" in response.text or "LZU" in response.text.upper():
        print("✅ 页面内容包含兰州大学相关信息")
    else:
        print("⚠️ 页面内容可能不正确")
        
except Exception as e:
    print(f"❌ HTTP访问失败: {str(e)}")

print("\n" + "=" * 50)
input("按回车键退出...")
