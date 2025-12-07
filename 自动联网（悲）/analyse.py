# 兰州大学登录页面JavaScript分析脚本
import requests
import re
import json

print("=" * 60)
print("兰州大学登录页面JavaScript分析")
print("=" * 60)

# 登录页面URL
login_url = "https://login.lzu.edu.cn:8800/portal/"

try:
    # 获取登录页面HTML
    session = requests.Session()
    response = session.get(login_url, timeout=10)
    
    if response.status_code == 200:
        html_content = response.text
        
        # 查找所有JavaScript文件引用
        js_files = re.findall(r'src="([^"]+\.js[^"]*)"', html_content)
        print(f"发现 {len(js_files)} 个JavaScript文件:")
        
        for i, js_file in enumerate(js_files, 1):
            print(f"{i}. {js_file}")
        
        # 特别关注可能包含认证逻辑的文件
        auth_js_files = [f for f in js_files if any(keyword in f for keyword in 
                        ['portal', 'login', 'auth', 'main', 'srun'])]
        
        print(f"\n重点关注的文件 ({len(auth_js_files)} 个):")
        for i, js_file in enumerate(auth_js_files, 1):
            print(f"{i}. {js_file}")
            
            # 如果是相对路径，补全为绝对路径
            if not js_file.startswith('http'):
                if js_file.startswith('/'):
                    full_url = f"https://login.lzu.edu.cn:8800{js_file}"
                else:
                    full_url = f"https://login.lzu.edu.cn:8800/{js_file}"
            else:
                full_url = js_file
                
            # 下载并分析JavaScript文件
            try:
                js_response = session.get(full_url, timeout=10)
                if js_response.status_code == 200:
                    js_content = js_response.text
                    
                    # 查找加密相关函数
                    encryption_patterns = [
                        r'function\s+(\w+)\s*\([^)]*password[^)]*\)',
                        r'password\s*[:=]\s*function[^}]+}',
                        r'encrypt\w*\s*[:=]\s*function[^}]+}',
                        r'md5\s*\([^)]+password[^)]*\)',
                        r'hmac\s*\([^)]+password[^)]*\)',
                        r'password\s*=\s*[^;]+md5[^;]+;',
                        r'password\s*=\s*[^;]+sha1[^;]+;',
                        r'password\s*=\s*[^;]+base64[^;]+;',
                    ]
                    
                    for pattern in encryption_patterns:
                        matches = re.findall(pattern, js_content, re.IGNORECASE)
                        if matches:
                            print(f"   发现加密模式: {pattern}")
                            for match in matches[:3]:  # 只显示前3个匹配
                                print(f"     - {match[:100]}...")
                    
                    # 查找特定的深澜认证函数
                    srun_patterns = [
                        r'srun_[^:]+?:\s*function[^}]+}',
                        r'getChallenge[^:]+?:\s*function[^}]+}',
                        r'doLogin[^:]+?:\s*function[^}]+}',
                    ]
                    
                    for pattern in srun_patterns:
                        matches = re.findall(pattern, js_content, re.IGNORECASE)
                        if matches:
                            print(f"   发现深澜认证函数: {pattern}")
                            for match in matches[:2]:
                                print(f"     - {match[:100]}...")
                
            except Exception as e:
                print(f"   下载失败: {e}")
        
        # 分析HTML中的内联JavaScript
        inline_scripts = re.findall(r'<script[^>]*>(.*?)</script>', html_content, re.DOTALL)
        print(f"\n发现 {len(inline_scripts)} 个内联脚本")
        
        for i, script in enumerate(inline_scripts, 1):
            if len(script.strip()) > 50:  # 只分析有内容的脚本
                # 查找可能的认证逻辑
                if any(keyword in script.lower() for keyword in 
                      ['login', 'password', 'encrypt', 'md5', 'sha1', 'challenge']):
                    print(f"\n内联脚本 {i} 可能包含认证逻辑:")
                    # 提取关键行
                    lines = script.split('\n')
                    for line in lines:
                        if any(keyword in line.lower() for keyword in 
                              ['password', 'encrypt', 'md5', 'sha1', 'challenge']):
                            clean_line = line.strip()[:200]  # 只显示前200字符
                            if clean_line:
                                print(f"   {clean_line}...")
                
    else:
        print(f"无法访问登录页面: {response.status_code}")
        
except Exception as e:
    print(f"分析过程中出错: {e}")

print("\n" + "=" * 60)
input("按回车键退出...")
