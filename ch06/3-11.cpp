#include <stdio.h>
#include <stdlib.h>
// ����������Ͷ���
typedef struct node
{
    int data; // ������
    struct node *next; // ָ����
}Node, *LinkList;
int count=0;
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

// 6.����������
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

// 7. ��λ
// ���head�е�һ��ֵ����x�Ľ�����ţ������������ֽ�㣬���ؽ��Ϊ0
int LocateLinkList(LinkList head, int x)
{
    int i = 0;
    Node * p = head; // p�ǹ���ָ��
    p = p->next; // ��ʼʱpָ���׽��    
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
	printf("Ԫ��%d��Ӧ�����е�λ��Ϊ��%d",j,i);
	int count=search(p,4);
    printf("��Ԫ��������ĵ�%d��",count);
    return 0;
}
