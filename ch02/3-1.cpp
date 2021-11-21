#include <stdio.h>
#include <stdlib.h>
// 单链表的类型定义
typedef struct node
{
    int data; // 数据域
    struct node *next; // 指针域
}Node, *LinkList;
// 单链表
// p 是工作指针

// 1. 初始化
LinkList InitiateLinkList()
{
    LinkList  head; // 头指针
    head =(Node*) malloc(sizeof(Node)); // 动态创建头结点
    head->next = NULL;
    return head;
}

// 2. 求表长
int LengthLinkList(LinkList head)
{
    int cnt = 0;
    Node *p = head;
    while(p->next != NULL)
    {
        p = p->next;
        cnt++;
    }
    return cnt;
}

// 3. 读表元素
// 在单链表head中查找第i个元素结点。若找到，返回指向该节点的指针，否则返回NULL
Node * GetLinkList(LinkList head, int i)
{
    int c = 1;
    Node *p;
    p = head -> next; // 初始化时，p指向首结点
    
    
    while((c < i) && (p != NULL))
    {
        p = p->next;
        c++;
    }
    if(c == i) return p;
    else return NULL;/**/

}

// 4. 插入元素
// 在表head的第i个数据元素结点之前插入一个以x为值的新结点
void InsertLinkList(LinkList head, int x, int i)
{
    Node *p, *q;
    if(i == 1) q = head;
    else q = GetLinkList(head, i - 1); // 找到第i - 1个数据元素结点，方便在其后插入

    if(q == NULL) printf("找不到插入位置。\n");
    else
    {
        p = (Node*)malloc(sizeof(Node));
        p->data = x;
        p->next = q->next;
        q->next = p;
    }
}





void traverseList(LinkList head)
{
    Node *p;
    p = head->next;
    while(p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}




int main()
{
    // 初始化变量
    LinkList head;
    int cnt;

    head = InitiateLinkList();
    printf("初始化成功！\n");

    cnt = LengthLinkList(head);
    printf("单链表的长度：%d\n", cnt);
    
    // 单链表插入结点
    InsertLinkList(head, 1, 1);
    InsertLinkList(head, 88, 2);
    InsertLinkList(head, 4, 3);
    InsertLinkList(head, 7, 4);
    InsertLinkList(head, 13, 5);
    InsertLinkList(head, 6, 6);
    InsertLinkList(head, 2, 7);

    cnt = LengthLinkList(head);
    printf("单链表的长度：%d\n", cnt);

    // 遍历单链表
    traverseList(head);


}
