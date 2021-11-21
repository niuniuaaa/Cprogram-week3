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

void swap(LinkList p,int n)//������n�����ݺ͵�n+1������
{
    int i=0;
    while(i!=n-1&&p->next!=NULL)//�ҵ���n-1������ 
    {
	p=p->next;
	i++;
    }	
    if(p->next==NULL)
    printf("swap error");
    
    LinkList p1,p2;
    p1=p->next;//��n������ 
	p2=p1->next;//��n+1������ 
	//����ָ�뽻������
    p1->next=p2->next; 
	p->next=p2;
	p2->next=p1;
} 

int main()
{
    // ��ʼ������
    LinkList P;
    int cnt1;

    P = InitiateLinkList();
    printf("��ʼ���ɹ���\n");

    cnt1 = LengthLinkList(P);
    printf("������ĳ��ȣ�%d\n", cnt1);
    
    
    // �����������
    InsertLinkList(P, 1, 1);
    InsertLinkList(P, 3, 2);
    InsertLinkList(P, 4, 3);
    InsertLinkList(P,88, 4);
    InsertLinkList(P,13, 5);
    InsertLinkList(P,15, 6);
    InsertLinkList(P,12, 7);

    cnt1 = LengthLinkList(P);
    printf("�������ݺ�����ĳ��ȣ�%d\n", cnt1);
    traverseList(P);
    swap(P,3);
    traverseList(P);
}
