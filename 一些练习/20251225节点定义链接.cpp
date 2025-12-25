#include <stdio.h>
#include <stdlib.h>

int main() {
    // 1. 定义单向链表节点结构体（基础语法，无自定义函数）
    typedef struct Node {
        int data;               // 数据域：存储节点数据
        struct Node *next;      // 指针域：指向后继节点
    } ListNode;

    // 2. 定义头指针，初始化为NULL（空链表）
    ListNode *head = NULL;

    // 3. 创建第一个节点（节点1：数据为10）
    ListNode *node1 = (ListNode *)malloc(sizeof(ListNode));
    if (node1 == NULL) { // 判断内存分配是否成功
        printf("内存分配失败！\n");
        return 1; // 异常退出
    }
    node1->data = 10;    // 给节点1赋值
    node1->next = NULL;  // 节点1暂时没有后继节点

    // 4. 创建第二个节点（节点2：数据为20）
    ListNode *node2 = (ListNode *)malloc(sizeof(ListNode));
    if (node2 == NULL) {
        printf("内存分配失败！\n");
        free(node1); // 释放已分配的node1，避免内存泄漏
        return 1;
    }
    node2->data = 20;
    node2->next = NULL;

    // 5. 链接节点，形成链表：head -> node1 -> node2 -> NULL
    head = node1;        // 头指针指向第一个节点
    node1->next = node2; // 节点1的后继指向节点2

    // 6. 打印链表（遍历输出）
    printf("链表内容：");
    ListNode *p = head;  // 定义遍历指针，从头节点开始
    while (p != NULL) {  // 遍历到尾节点的next（NULL）结束
        printf("%d -> ", p->data);
        p = p->next;     // 移动到下一个节点
    }
    printf("NULL\n");

    // 7. 临时释放内存（后续片段会详细演示释放逻辑）
    free(node1);
    free(node2);
    head = NULL;

    return 0;
}
