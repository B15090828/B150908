/*②car.c文件的完整内容*/
#include "car.h"
#include <stdio.h>

int readche(car  *che , int n)          /*读入车辆记录值，车牌号为0或读满规定条数记录时停止*/
{
	int i,j;
	for (i=0;i<n;i++)
	{
		printf("Input one cheliang\'s information\n");
		printf("number:  ");
	     scanf("%ld", &che[i].number);
		if (che[i].number==0) break;
		printf("name: ");
		scanf("%s",che[i].name);	
		printf("color:  ");
		scanf("%s",che[i].color);
		printf("型号:  ");
		scanf("%s",che[i].xinghao);
    	     che[i].total=0;                /*总扣分需要计算求得，初值置为0*/
		    scanf("%d",&che[i].grade[j]);	
		che[i].rank=0;                 /*名次需要根据总扣分来计算，初值置为0*/
	}
	return i;                         /*返回实际读入的记录条数*/
}

void printche ( car  *che , int n)       /*输出所有车辆记录的值*/
{
    int i,j;
	for (i=0;i<n;i++)
	{
		printf("%8ld  ", che[i].number);
		printf("%8s", che[i].name);
		printf("%8s", che[i].color);
		for (j=0;j<3;j++)
		   printf("%6d",che[i].grade[j]);
	    printf("%7d",che[i].grade);
	    printf("%5d\n",che[i].rank);
	}
}

int equal(car s1,car s2,int condition)  /*如何判断两个car记录相等*/
{
	if (condition==1)                    /*如果参数condition的值为1，则比较车牌号*/
		return s1.number==s2.number;
	else if (condition==2)                /*如果参数condition的值为2，则比较车主名*/
     {
	     if (strcmp(s1.name,s2.name)==0) 	return 1;
		else return 0;
     }
 else if (condition==3)                /*如果参数condition的值为3，则比较颜色*/
	     return s1.rank==s2.rank;
 else if (condition==4)                /*如果参数condition的值为4，则比较车型*/
		return s1.chexing==s2.chexing;
	else return 1;                       /*其余情况返回1*/
} 

int larger(car s1,car s2,int condition)  /*根据condition条件比较两个car记录的大小*/
{
	if (condition==1)                    /*如果参数condition的值为1，则比较车牌号*/
		return s1.number>s2.number;
	if (condition==2)                    /*如果参数condition的值为2，则比较总扣分*/
		return s1.grade>s2.grade;	
	else return 1; /*其余情况返回1*/
}

void reverse(car che[],int n)             /*数组元素逆置*/
{
	int i;
	car temp;
	for (i=0;i<n/2;i++)                   /*循环次数为元素数量的一半*/
	{
		temp=che[i];
		che[i]=che[n-1-i];
		che[n-1-i]=temp;
	}
}


void calcuRank(car che[],int n)          /*根据总扣分计算所有车辆的排名，扣分相同者名次相同*/
{
	int i ;                       
	sortche(che,n,2);                     /*先调用sortche算法，按总分由小到大排序*/
	reverse(che,n);                      /*再逆置，则按总分由大到小排序了*/
	che[0].rank=1;                      /*第一条记录的名次一定是1*/
	for (i=1;i<n;i++)                     /*从第二条记录一直到最后一条进行循环*/
	{
		if (equal(che[i],che[i-1],4))         /*当前记录与其相邻的前一条记录如果总扣分相等*/
			che[i].rank=che[i-1].rank;     /*当前记录名次等于其相邻的前一条记录名次*/ 
	    else
			che[i].rank=i+1;             /*不相等时当前记录名次等于其下标号+1*/
	}
}


void sortche(car che[],int n,int condition)  /*选择法排序，按condition条件由小到大排序*/
{
	int i,j,minpos;                      /*minpos用来存储本趟最小元素所在的下标*/
	Student t;
	for (i=0;i<n-1;i++)                  /*控制循环的n-1趟*/
	{
		minpos=i;
		for (j=i+1;j<n;j++)             /*寻找本趟最小元素所在的下标*/
			if (larger(che[minpos],che[j],condition))
				minpos=j;
		if (i!=minpos)                 /*保证本趟最小元素到达下标为i的位置*/
		{
			t=che[i];
			che[i]=che[minpos];
			che[minpos]=t;
		}
	}
}

int searchche(car che[],int n,car s,int condition,int f[ ])  /*在che数组中依condition条件查找*/
/*与s相同的元素，由于不止一条记录符合条件，因此将这些元素的下标置于 f数组中*/
{
	int i,j=0,find=0;
	for (i=0;i<n;i++)                                 /*待查找的元素*/
		if (equal(che[i],s,condition))  
		{
			f[j++]=i;                          /*找到了相等的元素，将其下标放到f数组中*/
			find++;	                        /*统计找到的元素个数*/                              
		}
	 return find;                                /*返回find，其值为0则表示没找到*/ 
}

int insertche(car che[],int n,car s)              /*向che数组中依车牌号递增插入一个元素s*/
{
	int i;
	sortche(che,n,1);                              /*先按车牌号排序*/
	for (i=0;i<n;i++)
	{
		if (equal(che[i],s,1))                      /*车牌相同不允许插入，保证车牌号的唯一性*/
		{
		    printf("this record exist,can not insert again!\n");
		    return n;
		}
	}
	for (i=n-1;i>=0;i--)                          /*按车牌号从小到大有序*/
	{
		if (!larger(che[i],s,1))                    /*如果s大于当前元素che[i]，则退出循环*/
		break;
		che[i+1]=che[i];                         /*否则元素che[i]后移一个位置*/
	}
	che[i+1]=s;                                /*在下标i+1处插入元素s*/                                   
	n++;                                     /*元素个数增加1*/
	return n;                                  /*返回现有元素个数*/
}

int deleteche(car che[],int n,car s)            /*从数组中删除指定车牌号的一个元素*/
{
	int i,j;
	for (i=0;i<n;i++)                           /*寻找待删除的元素*/
		if (equal(che[i],s,1))   break;            /*如果找到相等元素则退出循环*/
	if (i==n)                                 /*如果找不到待删除的元素*/
	{
		printf("This record does not exist!\n");    /*给出提示信息然后返回*/
		return n;
	}
	for (j=i; j<n-1; j++)                        /*此处隐含条件为i<n且equal(che[i],s,1)成立*/ 
		che[j]=che[j+1];                       /*通过移动覆盖删除下标为i的元素*/
                                                                            
	n--;                                      /*元素个数减少加1*/
	return n;                                  /*返回现有个数*/
}
