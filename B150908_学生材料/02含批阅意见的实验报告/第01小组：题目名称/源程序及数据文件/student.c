/*②book.c文件的完整内容*/  
#include "bookt.h"  
#include <stdio.h>  
  
int readBook(Book  *bk , int n)          /*读入图书记录值，编号为0或读满规定条数记录时停止*/  
{  
 	int i,j;  
	for (i=0;i<n;i++)  
	{  
	printf("Input one book\'s information\n");  
	printf("ISBN:  ");                    /*每本书的编号*/
     scanf("%s", bk[i].ISBN);  
	if (book[i].num==0) break;  
	printf("name: ");                    /*书名*/
	scanf("%s",bk[i].name);
printf("category: ");                  /*书的种类*/
	scanf("%s",bk[i].category);
    printf("price: ");                     /*每本书的单价*/
	scanf("%ld",bk[i].price);
    printf("remain: ");                   /*每本书的库存*/
	scanf("%ld",bk[i].remain); 
    printf("authorname: ");               /*作者名*/
	scanf("%s",bk[i].authorname);
printf("total: ");                     /*每本书三个月的总销量*/
	scanf("%ld",bk[i].total);
    bk[i].sales=0;                    /*每本书销售额需要计算求得，初值置为0*/  
	printf("Input three datum of the book:\n");  
	for (j=0;j<3;j++)  
    {  
	    scanf("%d",&stu[i].date[j]);	  
	}  
		book[i].rank=0;                 /*名次需要根据每本书的销售额来计算，初值置为0*/  
	}  
	return i;                         /*返回实际读入的记录条数*/  
}  
   
 void printBook ( Book  *bk , int n)       /*输出所有图书记录的值*/  
{  
     int i,j;  
 	for (i=0;i<n;i++)  
 	{  
 	printf("%8ld  ", bk[i].num);  
	printf("%8s", bk[i].name); 
        printf("%8ld  ", bk[i].price);
        printf("%8ld  ", bk[i].totalnum);
        printf("%8s", bk[i].authorname);
		for (j=0;j<2;j++)  
 	   printf("%6d",book[i].date[j]);  
 	    printf("%7d",book[i].total);  
    printf("%5d\n",[i].rank);  
 	}  
 }  
   
 int equal(Book s1,Book s2,int condition)  /*如何判断两个Book记录相等*/  
 {  
	if (condition==1)                    /*如果参数condition的值为1，则比较编号*/  
		return s1.num==s2.num;  
	else if (condition==2)                /*如果参数condition的值为2，则比较书名*/  
     {  
    if (strcmp(s1.name,s2.name)==0) 	return 1;  
	else return 0;  
    }  
 else if (condition==3)                /*如果参数condition的值为3，则比较名次*/  
 	     return s1.rank==s2.rank;  
  else if (condition==4)                /*如果参数condition的值为4，则比较总分*/  
		return s1.total==s2.total;  
	else return 1;                       /*其余情况返回1*/  
 }   
  
int larger(Book s1,Book s2,int condition)  /*根据condition条件比较两个Book记录的大小*/  
 {  
	if (condition==1)                    /*如果参数condition的值为1，则比较学号*/  
		return s1.num>s2.num;  
	if (condition==2)                    /*如果参数condition的值为2，则比较总分*/  
 		return s1.total>s2.total;	  
	else return 1; /*其余情况返回1*/  
}  
  
 void reverse(Book bk [],int n)             /*数组元素逆置*/  
 {  
 	int i;  
 	Book temp;  
 	for (i=0;i<n/2;i++)                   /*循环次数为元素数量的一半*/  
{  
		temp=stu[i];  
 	bk[i]=bk[n-1-i];  
 	bk[n-1-i]=temp;  
}  
 }  
 
 void calcuTotal(Book bk[],int n)         /*计算每本书三个月的总销量*/  
 {  
 	int i,j;  
 	for (i=0;i<n;i++)                    /*外层循环控制所有图书记录*/  
 {  
		bk[i].total =0;  
 	for (j=0;j<3;j++)               /*内层循环控制三个月*/  
 		bk[i].total +=bk[i].score[j];  
 }	  
 }  
   
 void calcuRank(Book stu[],int n)          /*根据销量计算所有图书的排名，销量相同者名次相同*/  
 {  
 int i ;                         
	sortBook(bk,n,2);                     /*先调用sortStu算法，按总分由小到大排序*/  
	reverse(bk,n);                      /*再逆置，则按总分由大到小排序了*/  
 bk[0].rank=1;                      /*第一条记录的名次一定是1*/  
	for (i=1;i<n;i++)                     /*从第二条记录一直到最后一条进行循环*/  
{  
 		if (equal(bk[i],bk[i-1],4))         /*当前记录与其相邻的前一条记录如果总分相等*/  
			bk[i].rank=bk[i-1].rank;     /*当前记录名次等于其相邻的前一条记录名次*/   
	    else  
			bk[i].rank=i+1;             /*不相等时当前记录名次等于其下标号+1*/  
 	}  
}  
 
void calcuMark(double m[3][3],Book bk[],int n) /*求三个月的销售额最高、最低*/  
/*其中形式参数二维数组m的第一维代表三个月，第二维代表最高、最低*/  
{  
 	int i,j;  
	for (i=0;i<3;i++)                 /*求三个月销售额最高*/		  
	{   
		m[i][0]=bk[0].score[i];       
		for (j=1;j<n;j++)  
			if (m[i][0]<bk[j].score[i])  
				m[i][0]=stu[j].score[i];  
	}  
	for (i=0;i<3;i++)                  /*求求三个月销售额最低*/  
 	{   
 		m[i][1]=bk[0].score[i];        
		for (j=1;j<n;j++)  
 			if (m[i][1]>bk[j].score[i])  
				m[i][1]=bk[j].score[i];  
 	}  
	 
 }  
  
 void sortStu(Book stu[],int n,int condition)  /*选择法排序，按condition条件由小到大排序*/  
 {  
 	int i,j,minpos;                      /*minpos用来存储本趟最小元素所在的下标*/  
 	Book t;  
 	for (i=0;i<n-1;i++)                  /*控制循环的n-1趟*/  
	{  
		minpos=i;  
		for (j=i+1;j<n;j++)             /*寻找本趟最小元素所在的下标*/  
			if (larger(bk[minpos],bk[j],condition))  
				minpos=j;  
		if (i!=minpos)                 /*保证本趟最小元素到达下标为i的位置*/  
		{  
			t=bk[i];  
			bk[i]=bk[minpos];  
		        bk[minpos]=t;  
		}  
	}  
}  
  
int searchBook(Book stu[],int n,Book s,int condition,int f[ ])  /*在stu数组中依condition条件查找*/  
/*与s相同的元素，由于不止一条记录符合条件，因此将这些元素的下标置于 f数组中*/  
{  
	int i,j=0,find=0;  
 	for (i=0;i<n;i++)                                 /*待查找的元素*/  
 		if (equal(bk[i],s,condition))    
 		{  
			f[j++]=i;                          /*找到了相等的元素，将其下标放到f数组中*/  
			find++;	                        /*统计找到的元素个数*/                                
		}  
	 return find;                                /*返回find，其值为0则表示没找到*/   
}  
   
int insertBook(Book bk[],int n,Book s)              /*向stu数组中依学号递增插入一个元素s*/  
{  
 	int i;  
 	sortBook(bk,n,1);                              /*先按编号排序*/  
	for (i=0;i<n;i++)  
	{  
		if (equal(bk[i],s,1))                      /*编号相同不允许插入，保证学号的唯一性*/  
		{  
                   printf("this record exist,can not insert again!\n"); 
		    return n;  
		}  
	}  
	for (i=n-1;i>=0;i--)                          /*按编号从小到大有序*/  
	{  
		if (!larger(bk[i],s,1))                    /*如果s大于当前元素stu[i]，则退出循环*/  
		break;  
		bk[i+1]=bk[i];                         /*否则元素stu[i]后移一个位置*/  
	}  
	bk[i+1]=s;                                /*在下标i+1处插入元素s*/                                     
	n++;                                     /*元素个数增加1*/  
	return n;                                  /*返回现有元素个数*/  
}  
  
int deleteBook(Book bk[],int n,Book s)            /*从数组中删除指定学号的一个元素*/  
{  
	int i,j;  
		if (equal(bk[i],s,1))   break;            /*如果找到相等元素则退出循环*/  
	if (i==n)                                 /*如果找不到待删除的元素*/  
	{  
		printf("This record does not exist!\n");    /*给出提示信息然后返回*/  
		return n;  
	}  
	for (j=i; j<n-1; j++)                        /*此处隐含条件为i<n且equal(stu[i],s,1)成立*/   
		stu[j]=stu[j+1];                       /*通过移动覆盖删除下标为i的元素*/  
                                                                            
	n--;                                      /*元素个数减少加1*/  
	return n;                                  /*返回现有个数*/  
}  
