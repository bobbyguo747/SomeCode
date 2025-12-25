#include <stdio.h>
#include <stdlib.h>

int main() {
    // 定义节点结构体
    typedef struct Node {
        int data;
        struct Node *next;
    } ListNode;

    ListNode *head = NULL;

    // 步骤1：添加第一个节点（数据10，尾插法）
    ListNode *node1 = (ListNode *)malloc(sizeof(ListNode));
    node1->data = 10;
    node1->next = NULL;
    head = node1; // 空链表，直接作为头节点

    // 步骤2：添加第二个节点（数据20，尾插法）
    ListNode *node2 = (ListNode *)malloc(sizeof(ListNode));
    node2->data = 20;
    node2->next = NULL;
    // 找到尾节点（next为NULL的节点）
    ListNode *p = head;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = node2; // 尾节点指向新节点

    // 步骤3：添加第三个节点（数据30，尾插法）
    ListNode *node3 = (ListNode *)malloc(sizeof(ListNode));
    node3->data = 30;
    node3->next = NULL;
    // 再次找尾节点
    p = head;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = node3;

    // 打印链表
    printf("尾插法后的链表：");
    p = head;
    while (p != NULL) {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");

    // 释放内存
    p = head;
    ListNode *temp;
    while (p != NULL) {
        temp = p->next;
        free(p);
        p = temp;
    }
    head = NULL;

    return 0;
}
