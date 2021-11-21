#include <stdio.h>
#include <stdlib.h>
// 单链表的类型定义
typedef struct node
{
    int data; // 数据域
    struct node *next; // 指针域
}Node, *LinkList;
LinkList InitiateLinkList()
{
    LinkList  head; // 头指针
    head =(Node*) malloc(sizeof(Node)); // 动态创建头结点
    head->next = NULL;
    return head;
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
// 3. 读表元素
// 在单链表head中查找第i个元素结点。若找到，返回指向该节点的指针，否则返回NULL
Node * GetLinkList(LinkList head, int i)
{
    int c = 1;
    Node *p;
    p = head -> next; // 初始化时，p指向首结点
    
    
    while((c < i) && (p != NULL))
    {
        p = p->next;
        c++;
    }
    if(c == i) return p;
    else return NULL;/**/

}
// 4. 插入元素
// 在表head的第i个数据元素结点之前插入一个以x为值的新结点
void InsertLinkList(LinkList head, int x, int i)
{
    Node *p, *q;
    if(i == 1) q = head;
    else q = GetLinkList(head, i - 1); // 找到第i - 1个数据元素结点，方便在其后插入

    if(q == NULL) printf("找不到插入位置。\n");
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
			pc->next=pa;//P中结点链接到结果
			pc=pa;
			pa=pa->next;
			u=pb;
			pb=pb->next;//释放重复结点
			free(u); 
		}
		else if(pa->data<pb->data)//当P中当前结点值小于L中，后移指针
		{
		u=pa;
		pa=pa->next;
		free(u);
		} 
		else//当P中当前结点值大于L中，后移L中当前结点的指针 
		{
			u=pb;
			pb=pb->next;
			free(u); 
		}
	}
	while(pa){//P链表长度大于L链表长度 
		u=pa;
		pa=pa->next;
		free(u);
	}
	while(pb)//P链表长度小于L链表长度 
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
    // 初始化变量
    LinkList P,L;
    int cnt1,cnt2;
    Node *p,*q;

    P = InitiateLinkList();
    L = InitiateLinkList();
    printf("初始化成功！\n");

    cnt1 = LengthLinkList(P);
    printf("单链表的长度：%d\n", cnt1);
	cnt2 = LengthLinkList(L);
    printf("单链表的长度：%d\n", cnt2);
    
    
    // 单链表插入结点
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
    printf("插入数据后单链表的长度：%d\n", cnt1);
    cnt2 = LengthLinkList(L);
    printf("插入数据后单链表的长度：%d\n", cnt2);
    //输出
	p=MergeCommon(P,L);
	printf("共同结点为："); 
	print(p);
	printf("\n");
	MergeList(P,L);
	DelSame(P);
	q=P;
	printf("两链表合并之后的链表为：");//因为是头插法，输出的数据是反的 
	print(q);
}

