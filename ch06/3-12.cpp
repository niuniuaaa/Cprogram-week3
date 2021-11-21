#include<stdlib.h>
#include<stdio.h>
// ����������Ͷ���
typedef struct node
{
    int data; // ������
    struct node *next; // ָ����
}Node, *LinkList;
Node *head=NULL;
LinkList InitiateLinkList()
{
    LinkList  head; // ͷָ��
    head =(Node*) malloc(sizeof(Node)); // ��̬����ͷ���
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
// 6.����������
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
	r=(Node*)malloc(sizeof(Node));//rΪͷ��� 
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
