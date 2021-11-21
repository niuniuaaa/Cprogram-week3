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

int main()
{
    // ��ʼ������
    LinkList P,L;
    int cnt1,cnt2;

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
    InsertLinkList(L, 7, 1);
    InsertLinkList(L, 13, 2);
    InsertLinkList(L, 6, 3);
    InsertLinkList(L, 2, 4);

    cnt1 = LengthLinkList(P);
    printf("�������ݺ�����ĳ��ȣ�%d\n", cnt1);
    cnt2 = LengthLinkList(L);
    printf("�������ݺ�����ĳ��ȣ�%d\n", cnt2);
    //���
	Node *p,*q;
    p = P->next;
    while(p != NULL)
    {
        int m=p->data;
        q= GetLinkList(L,m);
        int n=q-> data;
        printf("��P������Ϊ%d�ǣ�L�����е�%d����Ϊ��%d\n",m,m,n);
        p = p->next;
    }
}
