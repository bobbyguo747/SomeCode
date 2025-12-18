#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stu_info {
    char stu_num[10];      
    char stu_name[8]; 
    char stu_sex[2];     
    int stu_score;         
    struct stu_info *next; 
};
struct stu_info* createList(int n);
void displayList(struct stu_info *head);
void insertNode(struct stu_info **head);
void deleteNode(struct stu_info **head);
void searchNode(struct stu_info *head);
void freeList(struct stu_info *head);
void menu();
int main() {
    int choice, n;
    struct stu_info *head = NULL;
    printf("========== 学生信息管理系统 ==========\n");
    do {
        printf("请输入初始学生人数(3-5人): ");
        scanf("%d", &n);
        getchar();
    } while (n < 3 || n > 5);
    head = createList(n);
    while (1) {
        menu();
        printf("请选择操作(0-4): ");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                insertNode(&head);
                break;
            case 2:
                deleteNode(&head);
                break;
            case 3:
                searchNode(head);
                break;
            case 4:
                printf("\n当前所有学生信息：\n");
                printf("==========================================\n");
                displayList(head);
                printf("==========================================\n");
                break;
            case 0:
                printf("\n感谢使用，程序退出！\n");
                freeList(head);
                return 0;
            default:
                printf("输入错误，请重新选择！\n");
        }
        printf("\n");
    }
}
struct stu_info* createList(int n) {
    struct stu_info *head = NULL, *tail = NULL, *newNode = NULL;
    int i;
    printf("\n请依次输入%d个学生的信息：\n", n);
    for (i = 1; i <= n; i++) {
        newNode = (struct stu_info*)malloc(sizeof(struct stu_info));
        if (newNode == NULL) {
            printf("内存分配失败！\n");
            return NULL;
        }
        printf("\n--- 第%d个学生信息 ---\n", i);
        printf("学号: ");
        fgets(newNode->stu_num, 10, stdin);
        newNode->stu_num[strcspn(newNode->stu_num, "\n")] = 0;
        printf("姓名: ");
        fgets(newNode->stu_name, 8, stdin);
        newNode->stu_name[strcspn(newNode->stu_name, "\n")] = 0;
        printf("性别(M/F): ");
        fgets(newNode->stu_sex, 3, stdin);
        newNode->stu_sex[strcspn(newNode->stu_sex, "\n")] = 0;
        printf("成绩: ");
        scanf("%d", &(newNode->stu_score));
        getchar(); 
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    printf("\n初始化完成！已成功添加%d名学生信息。\n", n);
    return head;
}
void displayList(struct stu_info *head) {
    struct stu_info *current = head;
    int count = 1;
    if (head == NULL) {
        printf("学生信息为空！\n");
        return;
    }
    printf("%-4s %-10s %-8s %-4s %-6s\n", 
           "序号", "学号", "姓名", "性别", "成绩");
    printf("------------------------------------------\n");
    while (current != NULL) {
        printf("%-4d %-10s %-8s %-4s %-6d\n", 
               count, 
               current->stu_num, 
               current->stu_name, 
               current->stu_sex, 
               current->stu_score);
        current = current->next;
        count++;
    }
}
void insertNode(struct stu_info **head) {
    struct stu_info *newNode, *current, *prev = NULL;
    int position, i, count = 1;
    char choice;
    newNode = (struct stu_info*)malloc(sizeof(struct stu_info));
    if (newNode == NULL) {
        printf("内存分配失败！\n");
        return;
    }
    printf("\n--- 插入新学生信息 ---\n");
    printf("学号: ");
    fgets(newNode->stu_num, 10, stdin);
    newNode->stu_num[strcspn(newNode->stu_num, "\n")] = 0;
    printf("姓名: ");
    fgets(newNode->stu_name, 8, stdin);
    newNode->stu_name[strcspn(newNode->stu_name, "\n")] = 0;
    printf("性别(M/F): ");
    fgets(newNode->stu_sex, 3, stdin);
    newNode->stu_sex[strcspn(newNode->stu_sex, "\n")] = 0;
    printf("成绩: ");
    scanf("%d", &(newNode->stu_score));
    getchar();
    printf("\n请选择插入位置：\n");
    printf("1. 插入到链表开头\n");
    printf("2. 插入到链表末尾\n");
    printf("3. 插入到指定位置\n");
    printf("请选择(1-3): ");
    scanf("%c", &choice);
    getchar();
    switch (choice) {
        case '1': 
            newNode->next = *head;
            *head = newNode;
            printf("成功插入到链表开头！\n");
            break;
        case '2': 
            if (*head == NULL) {
                *head = newNode;
                newNode->next = NULL;
            } else {
                current = *head;
                while (current->next != NULL) {
                    current = current->next;
                }
                current->next = newNode;
                newNode->next = NULL;
            }
            printf("成功插入到链表末尾！\n");
            break;
        case '3': 
            printf("请输入要插入的位置(从1开始): ");
            scanf("%d", &position);
            getchar();
            if (position < 1) {
                printf("位置无效！\n");
                free(newNode);
                return;
            }
            if (position == 1) { // 插入到第一个位置
                newNode->next = *head;
                *head = newNode;
                printf("成功插入到第1个位置！\n");
                return;
            }
            current = *head;
            for (i = 1; i < position && current != NULL; i++) {
                prev = current;
                current = current->next;
            }
            if (prev == NULL) {
                printf("指定位置超出链表范围！\n");
                free(newNode);
                return;
            }
            prev->next = newNode;
            newNode->next = current;
            printf("成功插入到第%d个位置！\n", position);
            break;
        default:
            printf("选择无效，将插入到链表末尾。\n");
            if (*head == NULL) {
                *head = newNode;
                newNode->next = NULL;
            } else {
                current = *head;
                while (current->next != NULL) {
                    current = current->next;
                }
                current->next = newNode;
                newNode->next = NULL;
            }
            printf("成功插入到链表末尾！\n");
    }
}
void deleteNode(struct stu_info **head) {
    char stu_num[10];
    struct stu_info *current = *head, *prev = NULL;
    int found = 0;
    if (*head == NULL) {
        printf("学生信息为空，无法删除！\n");
        return;
    }
    printf("\n--- 删除学生信息 ---\n");
    printf("请输入要删除的学生学号: ");
    fgets(stu_num, 10, stdin);
    stu_num[strcspn(stu_num, "\n")] = 0;
    while (current != NULL) {
        if (strcmp(current->stu_num, stu_num) == 0) {
            found = 1;
            printf("找到学生信息：\n");
            printf("学号: %s, 姓名: %s, 性别: %s, 成绩: %d\n", 
                   current->stu_num, current->stu_name, 
                   current->stu_sex, current->stu_score);
            printf("确认删除？(Y/N): ");
            char confirm = getchar();
            getchar(); 
            if (confirm == 'Y' || confirm == 'y') {
                if (prev == NULL) { 
                    *head = current->next;
                } else { 
                    prev->next = current->next;
                }
                free(current);
                printf("删除成功！\n");
            } else {
                printf("已取消删除操作。\n");
            }
            break;
        }
        prev = current;
        current = current->next;
    }
    if (!found) {
        printf("未找到学号为 %s 的学生信息！\n", stu_num);
    }
}
void searchNode(struct stu_info *head) {
    char stu_num[10];
    struct stu_info *current = head;
    int found = 0;
    if (head == NULL) {
        printf("学生信息为空，无法查询！\n");
        return;
    }
    printf("\n--- 查询学生信息 ---\n");
    printf("请输入要查询的学生学号: ");
    fgets(stu_num, 10, stdin);
    stu_num[strcspn(stu_num, "\n")] = 0;
    while (current != NULL) {
        if (strcmp(current->stu_num, stu_num) == 0) {
            found = 1;
            printf("\n查询结果：\n");
            printf("==========================================\n");
            printf("学号: %s\n", current->stu_num);
            printf("姓名: %s\n", current->stu_name);
            printf("性别: %s\n", current->stu_sex);
            printf("成绩: %d\n", current->stu_score);
            printf("==========================================\n");
            break;
        }
        current = current->next;
    }
    if (!found) {
        printf("未找到学号为 %s 的学生信息！\n", stu_num);
    }
}
void freeList(struct stu_info *head) {
    struct stu_info *current = head, *temp = NULL;
    int count = 0;
    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
        count++;
    }
    printf("已成功释放%d个学生信息的内存空间。\n", count);
}
void menu() {
    printf("\n========== 功能菜单 ==========\n");
    printf("1. 插入新的学生信息\n");
    printf("2. 删除指定的学生信息\n");
    printf("3. 根据学号查询学生信息\n");
    printf("4. 显示所有学生信息\n");
    printf("0. 退出程序\n");
    printf("==============================\n");
}
