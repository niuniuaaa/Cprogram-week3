#include <stdio.h>
#include <stdlib.h>
// ����������Ͷ���
typedef struct node
{
    int data; // ������
    struct node *next; // ָ����
}Node, *LinkList;
// ������
// p �ǹ���ָ��

// 1. ��ʼ��
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

// 5. ������ɾ��
// ɾ����head�ĵ�i�����
void DeleteLinkList(LinkList head, int i)
{
    // ���ҵ���ɾ����ֱ��ǰ��
    Node *q, *p;
    if(i == 1) q = head;
    else q = GetLinkList(head, i - 1);

    // ��ǰ���������Ҵ�ɾ������
    if(q != NULL && q->next != NULL)
    {
        p = q->next;
        q->next = p->next;
        free(p); // �ͷ����Ƴ����p�Ŀռ�
    }
    else
    {
        printf("�Ҳ�����ɾ���\n");
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


int main()
{
    // ��ʼ������
    LinkList head;
    int cnt;

    head = InitiateLinkList();
    printf("��ʼ���ɹ���\n");

    cnt = LengthLinkList(head);
    printf("������ĳ��ȣ�%d\n", cnt);
    
    // �����������
    InsertLinkList(head, 1, 1);
    InsertLinkList(head, 88, 2);
    InsertLinkList(head, 4, 3);
    InsertLinkList(head, 7, 4);
    InsertLinkList(head, 13, 5);
    InsertLinkList(head, 6, 6);
    InsertLinkList(head, 2, 7);

    cnt = LengthLinkList(head);
    printf("������ĳ��ȣ�%d\n", cnt);

    // ����������
    traverseList(head);

    // ɾ�����
    DeleteLinkList(head, 6);

    traverseList(head);

    printf("����ֵΪ88�����Ϊ��%d\n", LocateLinkList(head, 88));

}
