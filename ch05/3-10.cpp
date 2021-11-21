#include <stdio.h>
#include <stdlib.h>
// ����������Ͷ���
typedef struct node
{
    int data; // ������
    struct node *next; // ָ����
}Node, *LinkList;
//��ʼ�� 
LinkList InitiateLinkList()
{
    LinkList  head; // ͷָ��
    head =(Node*) malloc(sizeof(Node)); // ��̬����ͷ���
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
		printf("����̭���˵ı��Ϊ:%d\n",p->data);
		free(p);
		p=tail->next;
	}
	printf("�����̭���˵ı��Ϊ%d\n",p->data);
	free(p);
}
int main()
{
	LinkList p,q;
	p=InitiateLinkList();
	q=create(p,8);
	printf("%d",q->data);
    int m,k;
    printf("�ӵ�K�˿�ʼ������");
    scanf("%d",&k);
    printf("������m�����˳��У�"); 
    scanf("%d",&m);
    find(q,k,m);
    return 0;
}
