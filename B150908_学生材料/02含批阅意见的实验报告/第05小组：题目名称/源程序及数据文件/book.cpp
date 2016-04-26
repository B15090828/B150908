/*②book.c文件的完整内容*/
#include "book.h"
#include <stdio.h>

int readBook(Book  *book , int n)          /*读入图书记录值，图书为0或读满规定条数记录时停止*/
{
	int i;
	for (i=0;i<n;i++)
	{
		printf("Input one book's information\n");
		printf("num:  ");
	     scanf("%ld", &book[i].number);
		if (book[i].number==0) break;
		printf("name: ");
		scanf("%s",book[i].title);	
		printf("输入这本书的数量总数:\n");
		scanf("%d",&book[i].kc);	
	}
	return i;                         /*返回实际读入的记录条数*/
}

void printBook ( Book  *book , int n)       /*输出所有图书记录的值*/
{
    int i;
	for (i=0;i<n;i++)
	{
		printf("%8ld  ", book[i].number);
		printf("%8s", book[i].title);
	    printf("%5d\n",book[i].kc);
	}
}

int equal(Book b1,Book b2,int condition)  /*如何判断两个图书记录相等*/
{
	if (condition==1)                    /*如果参数condition的值为1，则比较索引号*/
		return b1.number==b2.number;
	else if (condition==2)                /*如果参数condition的值为2，则比较书名*/
     {
	     if (strcmp(b1.title,b2.title)==0) 	return 1;
		else return 0;
     }
 else if (condition==3)                /*如果参数condition的值为3，则比较库存*/
	     return b1.kc==b2.kc;
	else return 1;                       /*其余情况返回1*/
} 

int larger(Book b1,Book b2,int condition)  /*根据condition条件比较两个图书 索引号记录的大小*/
{
	if (condition==1)                    /*如果参数condition的值为1，则比较学号*/
		return b1.number>b2.number;	
	else return 1; /*其余情况返回1*/
}

void reverse(Book book[],int n)             /*数组元素逆置*/
{
	int i;
	Book temp;
	for (i=0;i<n/2;i++)                   /*循环次数为元素数量的一半*/
	{
		temp=book[i];
		book[i]=book[n-1-i];
		book[n-1-i]=temp;
	}
}
void sortBook(Book book[],int n,int condition)  /*选择法排序，按condition条件由小到大排序*/
{
	int i,j,minpos;                      /*minpos用来存储本趟最小元素所在的下标*/
	Book t;
	for (i=0;i<n-1;i++)                  /*控制循环的n-1趟*/
	{
		minpos=i;
		for (j=i+1;j<n;j++)             /*寻找本趟最小元素所在的下标*/
			if (larger(book[minpos],book[j],condition))
				minpos=j;
		if (i!=minpos)                 /*保证本趟最小元素到达下标为i的位置*/
		{
			t=book[i];
			book[i]=book[minpos];
			book[minpos]=t;
		}
	}
}

int searchBook(Book book[],int n,Book b,int condition,int f[ ])  /*在book数组中依condition条件查找*/
/*与b相同的元素，由于不止一条记录符合条件，因此将这些元素的下标置于 f数组中*/
{
	int i,j=0,find=0;
	for (i=0;i<n;i++)                                 /*待查找的元素*/
		if (equal(book[i],b,condition))  
		{
			f[j++]=i;                          /*找到了相等的元素，将其下标放到f数组中*/
			find++;	                        /*统计找到的元素个数*/                              
		}
	 return find;                                /*返回find，其值为0则表示没找到*/ 
}

int addBook(Book book[],int n,Book b)              /*向book数组中依学号递增插入一个元素s*/
{
	int i;
	sortBook(book,n,1);                              /*先按学号排序*/
	for (i=n-1;i>=0;i--)                          /*按学号从小到大有序*/
	{
		if (!larger(book[i],b,1))                    /*如果b大于当前元素book[i]，则退出循环*/
		break;
		book[i+1]=book[i];                         /*否则元素book[i]后移一个位置*/
	}
	book[i+1]=b;                                /*在下标i+1处插入元素s*/                                   
	n++;                                     /*元素个数增加1*/
	return n;                                  /*返回现有元素个数*/
}

int deleteBook(Book book[],int n,Book b)            /*从数组中删除指定学号的一个元素*/
{
	int i,j;
	for (i=0;i<n;i++)                           /*寻找待删除的元素*/
		if (equal(book[i],b,1))   break;            /*如果找到相等元素则退出循环*/
	if (i==n)                                 /*如果找不到待删除的元素*/
	{
		printf("This record does not exist!\n");    /*给出提示信息然后返回*/
		return n;
	}
	for (j=i; j<n-1; j++)                        /*此处隐含条件为i<n且equal(book[i],b,1)成立*/ 
		book[j]=book[j+1];                       /*通过移动覆盖删除下标为i的元素*/
                                                                            
	n--;                                      /*元素个数减少加1*/
	return n;                                  /*返回现有个数*/
}