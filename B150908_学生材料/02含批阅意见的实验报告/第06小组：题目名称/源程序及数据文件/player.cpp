/*��player.c�ļ�����������*/
#include "player.h"
#include <stdio.h>

int readPla(Player  *pla , int n)          /*������Ա��¼ֵ�����º���Ϊ0������涨������¼ʱֹͣ*/
{
	int i,j;
	for (i=0;i<n;i++)
	{
		printf("Input one player\'s information\n");
		printf("num:  ");
	    scanf("%3d", &pla[i].number);
		if (pla[i].number==0) break;
		printf("name: ");
		scanf("%8s",pla[i].name);
    	     pla[i].total=0;                /*�ܵ÷���Ҫ������ã���ֵ��Ϊ0*/
		printf("�����峡�����ĵ÷֣����������壬���ϣ�ʧ��:\n");
		for (j=1;j<=5;j++)
	    {	printf("�����%d�������ĵ÷֣����������壬���ϣ�ʧ��:\n",j);
		    scanf("%d",&pla[i].score[j]);
			scanf("%d",&pla[i].assist[j]);
			scanf("%d",&pla[i].rebounds[j]);
			scanf("%d",&pla[i].steals[j]);
			scanf("%d",&pla[i].turnover[j]);
		}
		pla[i].rank=0;                 /*������Ҫ�����ܷ������㣬��ֵ��Ϊ0*/
	}
	return i;                         /*����ʵ�ʶ���ļ�¼����*/
}

void printPla ( Player  *pla , int n)       /*���������Ա��¼��ֵ*/
{
    int i,j;
	for (i=0;i<n;i++)
	{
		printf("���º���:%3d   ", pla[i].number);
		printf("����:%8s   ", pla[i].name);
		printf("�ܷ�:%7d   ",pla[i].total);
	    printf("����:%5d\n",pla[i].rank);
		for (j=1;j<=5;j++)
		{
		printf("��%d���÷�:%6d   ",j,pla[i].score[j]);
		printf("��%d������:%6d   ",j,pla[i].assist[j]);
		printf("��%d������:%6d   ",j,pla[i].rebounds[j]);
		printf("��%d������:%6d   ",j,pla[i].steals[j]);
		printf("��%d��ʧ��:%6d\n",j,pla[i].turnover[j]);
		}
	}
}

int equal(Player s1,Player s2,int condition)  /*����ж�����Player��¼���*/
{
	if (condition==1)                    /*�������condition��ֵΪ1����Ƚ����º���*/
		return s1.number==s2.number;
	else if (condition==2)                /*�������condition��ֵΪ2����Ƚ�����*/
     {
	    if (strcmp(s1.name,s2.name)==0) 	
			return 1;
		else return 0;
     }
    else if (condition==3)                /*�������condition��ֵΪ3����Ƚ�����*/
	     return s1.rank==s2.rank;
    else if (condition==4)                /*�������condition��ֵΪ4����Ƚ��ܵ÷�*/
		return s1.total==s2.total;
	else return 1;                       /*�����������1*/
} 

int larger(Player s1,Player s2,int condition)  /*����condition�����Ƚ�����Player��¼�Ĵ�С*/
{
	if (condition==1)                    /*�������condition��ֵΪ1����Ƚ����º���*/
		return s1.number>s2.number;
	if (condition==2)                    /*�������condition��ֵΪ2����Ƚ��ܵ÷�*/
		return s1.total>s2.total;	
	else return 1; /*�����������1*/
}

void reverse(Player pla[],int n)             /*����Ԫ������*/
{
	int i;
	Player temp;
	for (i=0;i<n/2;i++)                   /*ѭ������ΪԪ��������һ��*/
	{
		temp=pla[i];
		pla[i]=pla[n-1-i];
	}
}

void calcuRank(Player pla[],int n)          /*�����ּܷ���������Ա���������ܷ���ͬ��������ͬ*/
{
	int i ;                       
		pla[n-1-i]=temp;
	}
}

void calcuTotal(Player pla[],int n)         /*����������Ա���ܵ÷�*/
{
	int i,j;
	for (i=0;i<n;i++)                    /*���ѭ������������Ա��¼*/
	{
		pla[i].total =0;
		for (j=0;j<=5;j++)               /*�ڲ�ѭ�������峡����*/
			pla[i].total +=pla[i].score[j];
	sortPla(pla,n,2);                     /*�ȵ���sortPla�㷨�����ܷ���С��������*/
	reverse(pla,n);                      /*�����ã����ܷ��ɴ�С������*/
	pla[0].rank=1;                      /*��һ����¼������һ����1*/
	for (i=1;i<n;i++)                     /*�ӵڶ�����¼һֱ�����һ������ѭ��*/
	{
		if (equal(pla[i],pla[i-1],4))         /*��ǰ��¼�������ڵ�ǰһ����¼����ܷ����*/
			pla[i].rank=pla[i-1].rank;     /*��ǰ��¼���ε��������ڵ�ǰһ����¼����*/ 
	    else
			pla[i].rank=i+1;             /*�����ʱ��ǰ��¼���ε������±��+1*/
	}
}


void sortPla(Player pla[],int n,int condition)  /*ѡ�����򣬰�condition������С��������*/
{
	int i,j,minpos;                      /*minpos�����洢������СԪ�����ڵ��±�*/
	Player t;
	for (i=0;i<n-1;i++)                  /*����ѭ����n-1��*/
	{
		minpos=i;
		for (j=i+1;j<n;j++)             /*Ѱ�ұ�����СԪ�����ڵ��±�*/
			if (larger(pla[minpos],pla[j],condition))
				minpos=j;
		if (i!=minpos)                 /*��֤������СԪ�ص����±�Ϊi��λ��*/
		{
			t=pla[i];
			pla[i]=pla[minpos];
			pla[minpos]=t;
		}
	}
}

int searchPla(Player pla[],int n,Player s,int condition,int f[ ])  /*��pla��������condition��������*/
/*��s��ͬ��Ԫ�أ����ڲ�ֹһ����¼������������˽���ЩԪ�ص��±����� f������*/
{
	int i,j=0,find=0;
	for (i=0;i<n;i++)                                 /*�����ҵ�Ԫ��*/
    if (equal(pla[i],s,condition))  
		{
			f[j++]=i;                          /*�ҵ�����ȵ�Ԫ�أ������±�ŵ�f������*/
			find++;	                        /*ͳ���ҵ���Ԫ�ظ���*/                              
		}
	 return find;                                /*����find����ֵΪ0���ʾû�ҵ�*/ 
}

int insertPla(Player pla[],int n,Player s)              /*��pla�����������º����������һ��Ԫ��s*/
{
	int i;
	sortPla(pla,n,1);                              /*�Ȱ����º�������*/
	for (i=0;i<n;i++)
	{
		if (equal(pla[i],s,1))                      /*���º�����ͬ��������룬��֤ѧ�ŵ�Ψһ��*/
		{
		    printf("this record exist,can not insert again!\n");
		    return n;
		}
	}
	for (i=n-1;i>=0;i--)                          /*�����º����С��������*/
	{
		if (!larger(pla[i],s,1))                    /*���s���ڵ�ǰԪ��pla[i]�����˳�ѭ��*/
		break;
		pla[i+1]=pla[i];                         /*����Ԫ��pla[i]����һ��λ��*/
	}
	pla[i+1]=s;                                /*���±�i+1������Ԫ��s*/                                   
	n++;                                     /*Ԫ�ظ�������1*/
	return n;                                  /*��������Ԫ�ظ���*/
}

int deletePla(Player pla[],int n,Player s)            /*��������ɾ��ָ�����º����һ��Ԫ��*/
{
	int i,j;
	for (i=0;i<n;i++)                           /*Ѱ�Ҵ�ɾ����Ԫ��*/
		if (equal(pla[i],s,1))   break;            /*����ҵ����Ԫ�����˳�ѭ��*/
	if (i==n)                                 /*����Ҳ�����ɾ����Ԫ��*/
	{
		printf("This record does not exist!\n");    /*������ʾ��ϢȻ�󷵻�*/
		return n;
	}
	for (j=i; j<n-1; j++)                        /*�˴���������Ϊi<n��equal(pla[i],s,1)����*/ 
		pla[j]=pla[j+1];                       /*ͨ���ƶ�����ɾ���±�Ϊi��Ԫ��*/
                                                                            
	n--;                                      /*Ԫ�ظ������ټ�1*/
	return n;                                  /*�������и���*/
}