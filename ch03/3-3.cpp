#include <stdio.h>
#include <stdlib.h>
// 单链表的类型定义
typedef struct node
{
    int data; // 数据域
    struct node *next; // 指针域
}Node, *LinkList;
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
// 6.遍历单链表
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

void swap(LinkList p,int n)//交换第n个数据和第n+1个数据
{
    int i=0;
    while(i!=n-1&&p->next!=NULL)//找到第n-1个数据 
    {
	p=p->next;
	i++;
    }	
    if(p->next==NULL)
    printf("swap error");
    
    LinkList p1,p2;
    p1=p->next;//第n个数据 
	p2=p1->next;//第n+1个数据 
	//利用指针交换数据
    p1->next=p2->next; 
	p->next=p2;
	p2->next=p1;
} 

int main()
{
    // 初始化变量
    LinkList P;
    int cnt1;

    P = InitiateLinkList();
    printf("初始化成功！\n");

    cnt1 = LengthLinkList(P);
    printf("单链表的长度：%d\n", cnt1);
    
    
    // 单链表插入结点
    InsertLinkList(P, 1, 1);
    InsertLinkList(P, 3, 2);
    InsertLinkList(P, 4, 3);
    InsertLinkList(P,88, 4);
    InsertLinkList(P,13, 5);
    InsertLinkList(P,15, 6);
    InsertLinkList(P,12, 7);

    cnt1 = LengthLinkList(P);
    printf("插入数据后单链表的长度：%d\n", cnt1);
    traverseList(P);
    swap(P,3);
    traverseList(P);
}
