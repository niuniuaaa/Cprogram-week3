#include<stdlib.h>
#include<stdio.h>
// 单链表的类型定义
typedef struct node
{
    int data; // 数据域
    struct node *next; // 指针域
}Node, *LinkList;
Node *head=NULL;
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
// 6.遍历单链表
void traverseList(LinkList head)
{
    Node *p;
    p = head->next;
    while(p!= NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
} 

void traverseListNode(LinkList p)
{
    while(p->next!= NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
} 
LinkList Reverse(LinkList p)
{
	Node *s,*r,*m;
	m=p->next;
	int x[10],n=0;
	r=(Node*)malloc(sizeof(Node));//r为头结点 
	r->next=NULL;
	while(m!=NULL)
	{
		x[n]=m->data;
		m=m->next;
//		printf("%d",x[n]);
		n++;
	}
	//printf("%d",n);	
	for(int i=0;i<n;i++)
	{
		s=(Node*)malloc(sizeof(Node));
		s->data=x[i];
		s->next=r->next;
		r->next=s; 
	}
	return r;
}
LinkList DiguiReverse(LinkList p)
{
    if(p==NULL||p->next==NULL)
    return p;
    Node *newhead=DiguiReverse(p->next);
    if(p!=head)
    {
    	p->next->next=p;
    	p->next=NULL;
    	return newhead;
	}
	else
	{
		p->next=newhead;
		return p;
	}
}
int main()
{
	LinkList p,q,r;
	p=InitiateLinkList();
	p=create(p,8);
	traverseList(p);
	printf("\n");
	q=Reverse(p);
	r=DiguiReverse(p);
	traverseList(q);
	traverseListNode(r);

}
