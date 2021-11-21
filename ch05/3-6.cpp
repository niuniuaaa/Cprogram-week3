#include <stdio.h>
#include <stdlib.h>
#define MaxDegree 100
int Max(int A,int B)
{
	return A>B?A:B;
}
// 单链表的类型定义
typedef struct node
{
    int Coeff; // 数据域
    int exp;
    struct node *next; // 指针域
}Node,*Polynomial;
Polynomial Init()
{
	int Coef,exp;
	Polynomial head,r,s;
	head=(Node*)malloc(sizeof(Node));
	head->Coeff=-1;
	head->exp=-1;
	head->next=NULL;
	r=head;
	while(true)
	{
		scanf("%d",&Coef);
		scanf("%d",&exp);
		if(Coef==0&&exp==0)
		{
			break;
		}
		s=(Node*)malloc(sizeof(Node));
		s->Coeff=Coef;
		s->exp=exp;
		s->next=NULL;
		r->next=s;
		r=s;
	 } 
	 return head;
}
Polynomial add(Polynomial P,Polynomial L)
{
	Polynomial head,ha,hb,r,s;
	int a,b,sum;
	head=(Node*)malloc(sizeof(Node));
	head->Coeff=-1;
	head->exp=-1;
	head->next=NULL;
	r=head;
	
	ha=P->next;
	hb=L->next;
	while(ha!=NULL&&hb!=NULL)
	{
		a=ha->exp;
		b=hb->exp;
		if(a<b)
		{
			r->next=ha;
			r=r->next;hb=hb->next;
		}
		else
		{
			sum=ha->Coeff+hb->Coeff;
			if(sum!=0.0)
			{
				ha->Coeff=sum;
				r->next=ha;
				r=r->next;
			}
			else
			{
				s=P;
				while(s!=ha)
				{
					s=s->next;
				}
				s->next=ha->next;
			}
			ha=ha->next;
			hb=hb->next;
		}
	}
	if(ha!=NULL)
	{
		r->next=ha;
	}
	if(hb!=NULL)
	{
		r->next=hb;
	}
	return P;
}
Polynomial Mult()
void PrintPoly(Polynomial Q)
{
	
	while(Q!=NULL)
	{
	printf("%dx^%d+",Q->next->Coeff,Q->next->exp);
	Q=Q->next;
    }
    printf("\n");
}
int main()
{
	Polynomial P,p,q,hc;
	printf("请输入第一个多项式");
	p=Init();
	printf("请输入第二个多项式");
	q= Init();
	hc=add(p,q);
	printf("两个多项式和为"); 
	PrintPoly(hc);
}
