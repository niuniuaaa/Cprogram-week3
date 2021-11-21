#include <stdio.h>
#include <stdlib.h>
// 单链表的类型定义
typedef struct node
{
    int data; // 数据域
    struct node *next; // 指针域
}Node, *LinkList;
//初始化 
LinkList InitiateLinkList()
{
    LinkList  head; // 头指针
    head =(Node*) malloc(sizeof(Node)); // 动态创建头结点
    head->data=1;
    head->next = head;
    return head;
}
LinkList  create(LinkList &P,int N) 
{
	LinkList r,s;
	r=P;
	for(int i=2;i<=N;i++)
	{
	s=(Node*)malloc(sizeof(Node));
	s->data=i;
	s->next=NULL;
	r->next=s;
	r=r->next;
    }
    r->next=P;
    return P;
} 
void find(LinkList P,int k,int m)
{
	Node *tail=P,*p=P;
	while(tail->next!=P)
	{
		tail=tail->next;
	}
	while(p->data!=k)
	{
		tail=p;
		p=p->next;
	}
	while(p->next!=p)
	{
		for(int i=1;i<m;i++)
		{
			tail=p;
			p=p->next;
		}
		tail->next=p->next;
		printf("被淘汰的人的编号为:%d\n",p->data);
		free(p);
		p=tail->next;
	}
	printf("最后被淘汰的人的编号为%d\n",p->data);
	free(p);
}
int main()
{
	LinkList p,q;
	p=InitiateLinkList();
	q=create(p,8);
	printf("%d",q->data);
    int m,k;
    printf("从第K人开始报数：");
    scanf("%d",&k);
    printf("数到第m个的人出列："); 
    scanf("%d",&m);
    find(q,k,m);
    return 0;
}
