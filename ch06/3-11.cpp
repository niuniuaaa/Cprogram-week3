#include <stdio.h>
#include <stdlib.h>
// 单链表的类型定义
typedef struct node
{
    int data; // 数据域
    struct node *next; // 指针域
}Node, *LinkList;
int count=0;
LinkList InitiateLinkList()
{
    LinkList  head; // 头指针
    head =(Node*) malloc(sizeof(Node)); // 动态创建头结点
    head->next = NULL;
    return head;
    
}
LinkList  create(LinkList &P,int N) 
{
	LinkList r,s;
	r=P;
	for(int i=1;i<=N;i++)
	{
	s=(Node*)malloc(sizeof(Node));
	s->data=i;
	s->next=NULL;
	r->next=s;
	r=r->next;
    }
    return P;
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

// 7. 定位
// 求表head中第一个值等于x的结点的序号，若不存在这种结点，返回结果为0
int LocateLinkList(LinkList head, int x)
{
    int i = 0;
    Node * p = head; // p是工作指针
    p = p->next; // 初始时p指向首结点    
    while(p != NULL && p->data != x)
    {
        i++;
        p = p->next;
    }
    if(p != NULL) return i + 1;
    else return 0;
}
int search(Node *p,int m){
    if(p==NULL){
        return count+1;
    }
    if(p->data==m){
        return count;
    }
    else {
        p=p->next;
        count++;
        search(p,m);
    }
}
int main()
{
	LinkList p;
	p=InitiateLinkList();
	create(p,8);
	traverseList(p);
	int j=8; 
	int i=LocateLinkList(p,j);
	printf("元素%d对应链表中的位置为：%d",j,i);
	int count=search(p,4);
    printf("此元素在链表的第%d个",count);
    return 0;
}
