#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <stdlib.h>

// 函数声明
void crack_numeric_password(const char* target, int length);
void crack_lowercase_password(const char* target, int length);
void crack_custom_password(const char* target, int length, const char* charset);
int parse_rule(const char* rule, int* length, char** charset);
int is_all_digits(const char* str);
int is_all_lowercase(const char* str);
int is_all_uppercase(const char* str);
int is_all_alpha(const char* str);

// 递归破解函数的声明（需要在crack_lowercase_password之前声明）
int crack_recursive(char* current, int pos, int length, const char* target, long* attempts, clock_t start_time);

int main() {
    int choice;
    char target[100];
    
    printf("=== 口令暴力破解模拟程序 ===\n");
    printf("请选择破解模式：\n");
    printf("1. 固定长度纯数字口令破解\n");
    printf("2. 固定长度纯英文小写字母口令破解\n");
    printf("3. 增强模式 - 自定义口令规则\n");
    printf("请输入您的选择 (1, 2 或 3): ");
    
    if(scanf("%d", &choice) != 1) {
        printf("输入错误！\n");
        return 1;
    }
    getchar(); // 清除输入缓冲区中的换行符
    
    switch(choice) {
        case 1: {
            int num_length;
            printf("请输入目标口令长度: ");
            if(scanf("%d", &num_length) != 1) {
                printf("长度输入错误！\n");
                break;
            }
            getchar();
            
            printf("请输入%d位纯数字目标口令: ", num_length);
            fgets(target, sizeof(target), stdin);
            target[strcspn(target, "\n")] = 0; // 去除换行符
            
            if(strlen(target) == num_length && is_all_digits(target)) {
                crack_numeric_password(target, num_length);
            } else {
                printf("错误：请输入%d位纯数字！\n", num_length);
            }
            break;
        }
            
        case 2: {
            int alpha_length;
            printf("请输入目标口令长度: ");
            if(scanf("%d", &alpha_length) != 1) {
                printf("长度输入错误！\n");
                break;
            }
            getchar();
            
            printf("请输入%d位纯英文小写字母目标口令: ", alpha_length);
            fgets(target, sizeof(target), stdin);
            target[strcspn(target, "\n")] = 0; // 去除换行符
            
            if(strlen(target) == alpha_length && is_all_lowercase(target)) {
                crack_lowercase_password(target, alpha_length);
            } else {
                printf("错误：请输入%d位纯英文小写字母！\n", alpha_length);
            }
            break;
        }
            
        case 3: {
            char rule[100];
            printf("请输入口令规则描述 (例如: 所设置口令为6位数字组合): ");
            fgets(rule, sizeof(rule), stdin);
            rule[strcspn(rule, "\n")] = 0; // 去除换行符
            
            printf("请输入目标口令: ");
            fgets(target, sizeof(target), stdin);
            target[strcspn(target, "\n")] = 0; // 去除换行符
            
            int length;
            char* charset = NULL;
            
            if(parse_rule(rule, &length, &charset)) {
                if(strlen(target) == length) {
                    printf("解析规则: 长度=%d, 字符集=%s\n", length, charset);
                    crack_custom_password(target, length, charset);
                    free(charset);
                } else {
                    printf("错误：目标口令长度不符合规则描述！\n");
                    if(charset) free(charset);
                }
            } else {
                printf("错误：无法解析规则描述！\n");
                if(charset) free(charset);
            }
            break;
        }
            
        default: {
            printf("无效选择！\n");
            break;
        }
    }
    
    return 0;
}

// 检查字符串是否全部为数字
int is_all_digits(const char* str) {
    for(int i = 0; str[i] != '\0'; i++) {
        if(!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

// 检查字符串是否全部为小写字母
int is_all_lowercase(const char* str) {
    for(int i = 0; str[i] != '\0'; i++) {
        if(!islower(str[i])) {
            return 0;
        }
    }
    return 1;
}

// 检查字符串是否全部为大写字母
int is_all_uppercase(const char* str) {
    for(int i = 0; str[i] != '\0'; i++) {
        if(!isupper(str[i])) {
            return 0;
        }
    }
    return 1;
}

// 检查字符串是否全部为字母
int is_all_alpha(const char* str) {
    for(int i = 0; str[i] != '\0'; i++) {
        if(!isalpha(str[i])) {
            return 0;
        }
    }
    return 1;
}

// 从规则描述中解析长度和字符集类型
int parse_rule(const char* rule, int* length, char** charset) {
    // 查找"位"字的位置
    const char* pos = strstr(rule, "位");
    if(!pos) return 0;
    
    // 从"位"字向前查找数字
    int len = 0;
    int multiplier = 1;
    const char* num_start = pos - 1;
    
    while(num_start >= rule && isdigit(*num_start)) {
        len += (*num_start - '0') * multiplier;
        multiplier *= 10;
        num_start--;
    }
    
    if(len == 0) return 0;
    *length = len;
    
    // 确定字符集类型
    if(strstr(rule, "数字")) {
        *charset = strdup("0123456789");
    } else if(strstr(rule, "小写字母")) {
        *charset = strdup("abcdefghijklmnopqrstuvwxyz");
    } else if(strstr(rule, "大写字母")) {
        *charset = strdup("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    } else if(strstr(rule, "字母")) {
        *charset = strdup("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
    } else {
        return 0; // 未知字符集类型
    }
    
    return 1;
}

// 递归破解函数（现在独立定义）
int crack_recursive(char* current, int pos, int length, const char* target, long* attempts, clock_t start_time) {
    if(pos == length) {
        (*attempts)++;
        
        if(*attempts % 1000000 == 0) {
            printf("已尝试 %ld 次，当前尝试: %s\n", *attempts, current);
        }
        
        if(strcmp(current, target) == 0) {
            clock_t end_time = clock();
            double cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            
            printf("\n=== 口令破解成功！ ===\n");
            printf("目标口令: %s\n", target);
            printf("总共尝试次数: %ld\n", *attempts);
            printf("破解耗时: %.4f 秒\n", cpu_time_used);
            return 1;
        }
        return 0;
    }
    
    for(char c = 'a'; c <= 'z'; c++) {
        current[pos] = c;
        if(crack_recursive(current, pos + 1, length, target, attempts, start_time)) {
            return 1;
        }
    }
    return 0;
}

// 破解纯数字口令
void crack_numeric_password(const char* target, int length) {
    clock_t start_time, end_time;
    double cpu_time_used;
    long attempts = 0;
    
    // 动态分配内存用于存储猜测的口令
    char* guess = (char*)malloc(length + 1);
    if(!guess) {
        printf("内存分配失败！\n");
        return;
    }
    guess[length] = '\0';
    
    printf("开始破解%d位纯数字口令...\n", length);
    start_time = clock();
    
    // 计算最大值
    long max_attempts = 1;
    for(int i = 0; i < length; i++) {
        max_attempts *= 10;
    }
    
    // 遍历所有可能的组合
    for(long i = 0; i < max_attempts; i++) {
        // 将数字格式化为指定位数字符串，不足位前面补0
        char format[10];
        snprintf(format, sizeof(format), "%%0%dd", length);
        snprintf(guess, length + 1, format, i);
        
        attempts++;
        
        // 每10000次尝试显示一次进度
        if(attempts % 10000 == 0) {
            printf("已尝试 %ld 次，当前尝试: %s\n", attempts, guess);
        }
        
        if(strcmp(guess, target) == 0) {
            end_time = clock();
            cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            
            printf("\n=== 口令破解成功！ ===\n");
            printf("目标口令: %s\n", target);
            printf("总共尝试次数: %ld\n", attempts);
            printf("破解耗时: %.4f 秒\n", cpu_time_used);
            free(guess);
            return;
        }
    }
    
    printf("破解失败：未找到匹配的口令\n");
    free(guess);
}

// 破解小写字母口令
void crack_lowercase_password(const char* target, int length) {
    clock_t start_time = clock();
    long attempts = 0;
    
    // 动态分配内存用于存储猜测的口令
    char* guess = (char*)malloc(length + 1);
    if(!guess) {
        printf("内存分配失败！\n");
        return;
    }
    
    printf("开始破解%d位纯英文小写字母口令...\n", length);
    printf("这可能需要一些时间，请耐心等待...\n");
    
    // 初始化猜测口令为全'a'
    for(int i = 0; i < length; i++) {
        guess[i] = 'a';
    }
    guess[length] = '\0';
    
    // 使用递归函数生成所有组合
    if(!crack_recursive(guess, 0, length, target, &attempts, start_time)) {
        printf("破解失败：未找到匹配的口令\n");
    }
    
    free(guess);
}

// 破解自定义规则的口令
void crack_custom_password(const char* target, int length, const char* charset) {
    clock_t start_time, end_time;
    double cpu_time_used;
    long attempts = 0;
    int charset_size = strlen(charset);
    
    // 动态分配内存用于存储猜测的口令
    char* guess = (char*)malloc(length + 1);
    if(!guess) {
        printf("内存分配失败！\n");
        return;
    }
    
    printf("开始破解自定义规则口令...\n");
    printf("长度: %d, 字符集大小: %d\n", length, charset_size);
    start_time = clock();
    
    // 初始化猜测口令为字符集的第一个字符
    for(int i = 0; i < length; i++) {
        guess[i] = charset[0];
    }
    guess[length] = '\0';
    
    // 使用非递归方法生成所有组合
    int* indices = (int*)calloc(length, sizeof(int));
    if(!indices) {
        printf("内存分配失败！\n");
        free(guess);
        return;
    }
    
    while(1) {
        // 根据当前索引生成猜测口令
        for(int i = 0; i < length; i++) {
            guess[i] = charset[indices[i]];
        }
        
        attempts++;
        
        // 每100000次尝试显示一次进度
        if(attempts % 100000 == 0) {
            printf("已尝试 %ld 次，当前尝试: %s\n", attempts, guess);
        }
        
        if(strcmp(guess, target) == 0) {
            end_time = clock();
            cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            
            printf("\n=== 口令破解成功！ ===\n");
            printf("目标口令: %s\n", target);
            printf("总共尝试次数: %ld\n", attempts);
            printf("破解耗时: %.4f 秒\n", cpu_time_used);
            free(guess);
            free(indices);
            return;
        }
        
        // 递增索引（类似于数字进位）
        int pos = length - 1;
        while(pos >= 0) {
            indices[pos]++;
            if(indices[pos] < charset_size) {
                break;
            }
            indices[pos] = 0;
            pos--;
        }
        
        // 如果已经尝试了所有组合
        if(pos < 0) {
            break;
        }
    }
    
    printf("破解失败：未找到匹配的口令\n");
    free(guess);
    free(indices);
}

