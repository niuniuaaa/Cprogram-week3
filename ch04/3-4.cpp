#include <stdio.h>
#include <stdlib.h>
// ����������Ͷ���
typedef struct node
{
    int data; // ������
    struct node *next; // ָ����
}Node, *LinkList;
LinkList InitiateLinkList()
{
    LinkList  head; // ͷָ��
    head =(Node*) malloc(sizeof(Node)); // ��̬����ͷ���
    head->next = NULL;
    return head;
}

// 2. ���
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
// 3. ����Ԫ��
// �ڵ�����head�в��ҵ�i��Ԫ�ؽ�㡣���ҵ�������ָ��ýڵ��ָ�룬���򷵻�NULL
Node * GetLinkList(LinkList head, int i)
{
    int c = 1;
    Node *p;
    p = head -> next; // ��ʼ��ʱ��pָ���׽��
    
    
    while((c < i) && (p != NULL))
    {
        p = p->next;
        c++;
    }
    if(c == i) return p;
    else return NULL;/**/

}
// 4. ����Ԫ��
// �ڱ�head�ĵ�i������Ԫ�ؽ��֮ǰ����һ����xΪֵ���½��
void InsertLinkList(LinkList head, int x, int i)
{
    Node *p, *q;
    if(i == 1) q = head;
    else q = GetLinkList(head, i - 1); // �ҵ���i - 1������Ԫ�ؽ�㣬������������

    if(q == NULL) printf("�Ҳ�������λ�á�\n");
    else
    {
        p = (Node*)malloc(sizeof(Node));
        p->data = x;
        p->next = q->next;
        q->next = p;
    }
}
LinkList MergeCommon(LinkList P,LinkList L)
{
	Node *p=P->next,*q=L->next,*r,*s,*m;
	LinkList C=(Node*)malloc(sizeof(Node));
	r=m=C;
	while(p!=NULL&&q!=NULL)
	{
		if(p->data<q->data)
		p=p->next;
		else if(p->data>q->data)
		q=q->next;
		else
		{
			s=(Node*)malloc(sizeof(Node));
			s->data=p->data;
			r->next=s;
			r=s;
			p=p->next;
			q=q->next;
		}
	 } 
	 r->next=NULL;
	 return m;
}
LinkList MergeUnion(LinkList &P,LinkList &L)
{
	Node *pa,*pb,*pc,*u;
	pa=P->next;
	pb=L->next;
	pc=P;
	while(pa&&pb)
	{
		if(pa->data==pb->data)
		{
			pc->next=pa;//P�н�����ӵ����
			pc=pa;
			pa=pa->next;
			u=pb;
			pb=pb->next;//�ͷ��ظ����
			free(u); 
		}
		else if(pa->data<pb->data)//��P�е�ǰ���ֵС��L�У�����ָ��
		{
		u=pa;
		pa=pa->next;
		free(u);
		} 
		else//��P�е�ǰ���ֵ����L�У�����L�е�ǰ����ָ�� 
		{
			u=pb;
			pb=pb->next;
			free(u); 
		}
	}
	while(pa){//P�����ȴ���L������ 
		u=pa;
		pa=pa->next;
		free(u);
	}
	while(pb)//P������С��L������ 
	{
		u=pb;
		pb=pb->next;
		free(u);
	 } 
	 pc->next=NULL;
	 free(L);
	 return P;
}
void MergeList(LinkList &P,LinkList &L)
{
	
	Node *r,*pa=P->next,*pb=L->next;
	P->next=NULL;
	
	while(pa&&pb)
	{
		if(pa->data<=pb->data)
		{
			r=pa->next;
			pa->next=P->next;
			P->next=pa;
			pa=r;
		}
		else
		{
			r=pb->next;
			pb->next=P->next;
			P->next=pb;
			pb=r;
		}
    } 
		if(pa)
		pb=pa;
		
		while(pb)
		{
			r=pb->next;
			pb->next=P->next;
			P->next=pb;
			pb=r;
		}
		free(L); 

}
void DelSame(LinkList &P)
{
	Node *p=P->next,*q;
	if(p==NULL)
	return;
	while(p->next!=NULL)
	{
		q=p->next;
		if(p->data==q->data)
		{
			p->next=q->next;
			free(q);
		}
		else
		p=p->next;
	 } 
}
void print(Node *p)
{
	while(p->next!=NULL)
	{
		p=p->next;
		printf("%d ",p->data);
	}
}

int main()
{
    // ��ʼ������
    LinkList P,L;
    int cnt1,cnt2;
    Node *p,*q;

    P = InitiateLinkList();
    L = InitiateLinkList();
    printf("��ʼ���ɹ���\n");

    cnt1 = LengthLinkList(P);
    printf("������ĳ��ȣ�%d\n", cnt1);
	cnt2 = LengthLinkList(L);
    printf("������ĳ��ȣ�%d\n", cnt2);
    
    
    // �����������
    InsertLinkList(P, 1, 1);
    InsertLinkList(P, 3, 2);
    InsertLinkList(P, 4, 3);
    InsertLinkList(P, 13,4);
    InsertLinkList(L, 2, 1);
    InsertLinkList(L, 4, 2);
    InsertLinkList(L, 9, 3);
    InsertLinkList(L, 13,4);
    InsertLinkList(L, 15,5);
    
    cnt1 = LengthLinkList(P);
    printf("�������ݺ�����ĳ��ȣ�%d\n", cnt1);
    cnt2 = LengthLinkList(L);
    printf("�������ݺ�����ĳ��ȣ�%d\n", cnt2);
    //���
	p=MergeCommon(P,L);
	printf("��ͬ���Ϊ��"); 
	print(p);
	printf("\n");
	MergeList(P,L);
	DelSame(P);
	q=P;
	printf("������ϲ�֮�������Ϊ��");//��Ϊ��ͷ�巨������������Ƿ��� 
	print(q);
}

