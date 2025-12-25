#include <stdio.h>
#include <stdlib.h>

int main() {
    // 定义节点结构体
    typedef struct Node {
        int data;
        struct Node *next;
    } ListNode;

    ListNode *head = NULL;

    // 先构建链表：head -> 10 -> 20 -> 30 -> NULL
    ListNode *node1 = (ListNode *)malloc(sizeof(ListNode));
    ListNode *node2 = (ListNode *)malloc(sizeof(ListNode));
    ListNode *node3 = (ListNode *)malloc(sizeof(ListNode));
    node1->data = 10; node1->next = node2;
    node2->data = 20; node2->next = node3;
    node3->data = 30; node3->next = NULL;
    head = node1;

    printf("删除前链表：");
    ListNode *p = head;
    while (p != NULL) {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");

    // 要删除的目标数据
    int target = 20;
    ListNode *pre = NULL; // 记录待删除节点的前驱节点
    p = head;             // 遍历指针从头开始

    // 场景1：空链表（此处链表非空，仅演示判断逻辑）
    if (head == NULL) {
        printf("链表为空，无法删除！\n");
        return 1;
    }

    // 场景2：头节点就是待删除节点（若target=10，触发此逻辑）
    if (p->data == target) {
        head = p->next; // 头指针指向原头节点的后继
        free(p);        // 释放原头节点
        printf("成功删除头节点（数据%d）\n", target);
    } else {
        // 场景3：查找中间/尾节点
        while (p != NULL && p->data != target) {
            pre = p;    // 记录前驱
            p = p->next; // 移动到下一个节点
        }

        if (p == NULL) { // 未找到目标节点
            printf("未找到数据%d的节点\n", target);
        } else { // 找到目标节点，执行删除
            pre->next = p->next; // 前驱节点指向后继节点，断链
            free(p);             // 释放目标节点
            printf("成功删除数据%d的节点\n", target);
        }
    }

    // 打印删除后的链表
    printf("删除后链表：");
    p = head;
    while (p != NULL) {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");

    // 释放剩余内存
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
