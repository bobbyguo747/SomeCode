#include <stdio.h>
#include <stdlib.h>

int main() {
    // 定义节点结构体
    typedef struct Node {
        int data;
        struct Node *next;
    } ListNode;

    ListNode *head = NULL;

    // 步骤1：添加第一个节点（数据10，头插法）
    ListNode *node1 = (ListNode *)malloc(sizeof(ListNode));
    node1->data = 10;
    node1->next = NULL;
    head = node1; // 空链表，直接作为头节点

    // 步骤2：添加第二个节点（数据20，头插法）
    ListNode *node2 = (ListNode *)malloc(sizeof(ListNode));
    node2->data = 20;
    node2->next = head; // 新节点指向原来的头节点
    head = node2;       // 头指针更新为新节点

    // 步骤3：添加第三个节点（数据30，头插法）
    ListNode *node3 = (ListNode *)malloc(sizeof(ListNode));
    node3->data = 30;
    node3->next = head; // 新节点指向当前头节点
    head = node3;       // 更新头指针

    // 打印链表
    printf("头插法后的链表：");
    ListNode *p = head;
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
