# 用户名格式测试（附加脚本）
def test_username_formats():
    """测试不同的用户名格式"""
    base_username = "gjunran2025"
    password = "GJRgjr20070407"
    
    username_variants = [
        f"{base_username}@elearning",      # 原始格式
        f"{base_username}@eLearning",      # 大小写变化
        f"{base_username}@ELEARNING",      # 全大写
        base_username,                      # 无域名
        f"{base_username}@study",          # 其他常见域名
        f"{base_username}@STUDY",          # 全大写
    ]
    
    print("测试不同的用户名格式:")
    for username in username_variants:
        print(f"尝试: {username}")
        # 这里可以集成到上面的登录逻辑中测试
    
# 如果需要测试用户名格式，可以取消注释下面的调用
# test_username_formats()
