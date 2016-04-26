/*②owner.c文件的完整内容*/
#include"owner.h"
#include<stdio.h>

int readOwn(Owner *own,int n)             /*读入车主记录值，车牌号为0或读满规定条数记录时停止*/
{
	int i,j;
	for (i=0;i<n;i++)
	{
		printf("Input one owner\'s information\n");
		printf("num: ");
		scanf("%ld",&own[i].num);
		if(own[i].num==0) break;
		printf("name: ");
		scanf("%s",own[i].name);
		printf("sex: ");
		scanf("%s",own[i].sxe);
		own[i].total=0;               /*总停车时间需要计算求得，初值置为0*/
		printf("Input ten scores of the owner:\n");
		for(j=0;j<10;j++)
		{
			scanf("%d",&own[i].time[j]);
		}
	}
	return i;                      /*返回实际读入的记录条数*/
}

void printOwn ( Own *own , int n)       /*输出所有学生记录的值*/
{
    int i,j;
	for (i=0;i<n;i++)
	{
		printf("%8ld  ", own[i].num);
		printf("%8s", own[i].name);
		printf("%8s", own[i].sex);
		for (j=0;j<10;j++)
		   printf("%6d",own[i].time[j]);
	    printf("%7d",own[i].total);
	    printf("%5d\n",stu[i].fee);
	}
}

int equal(Owner s1,Owner s2,int condition)  /*如何判断两个Owner记录相等*/
{
	if (condition==1)                    /*如果参数condition的值为1，则比较车牌号*/
		return s1.num==s2.num;
	else if (condition==2)                /*如果参数condition的值为2，则比较姓名*/
     {
	     if (strcmp(s1.name,s2.name)==0) 	return 1;
		else return 0;
     }
 else if (condition==3)                /*如果参数condition的值为3，则比较费用*/
	     return s1.fee==s2.fee;
 else if (condition==4)                /*如果参数condition的值为4，则比较总停车时间*/
		return s1.total==s2.total;
	else return 1;                       /*其余情况返回1*/
} 

void calcuTotal(Owner own[],int n)         /*计算所有车主的总停车时间*/
{
	int i,j;
	for (i=0;i<n;i++)                    /*外层循环控制所有车主记录*/
	{
		own[i].total =0;
		for (j=0;j<10;j++)               /*内层循环控制停车次数*/
			own[i].total +=own[i].time[j];
	}	
}

void cacluTimetable(double m[1][3],Owner Own[],int n);              /*求停车的最长、最短、平均时间*/
                       /*其中形式参数二维数组m的第一维代表停车次数，第二维代表最长、最短、平均时间*/
{
	int i,j;
	for (i=0;i<10;i++)                 /*求停车的最长时间*/		
	{ 
		m[i][0]=own[0].time[i];     
		for (j=1;j<n;j++)
			if (m[i][0]<own[j].time[i])
				m[i][0]=own[j].time[i];
	}
	for (i=0;i<10;i++)                  /*求停车的最短时间*/
	{ 
		m[i][1]=own[0].time[i];      
		for (j=1;j<n;j++)
			if (m[i][1]>own[j].time[i])
				m[i][1]=own[j].time[i];
	}
	for (i=0;i<10;i++)                 /*求停车的平均时间*/
	{ 
		m[i][2]=own[0].time[i];     
		for (j=1;j<n;j++)
			m[i][2]+=own[j].time[i];
		m[i][2]/=n;
	}
}

int searchOwn(Owner own[],int n,Owner s,int condition,int f[ ])            /*在stu数组中依condition条件查找*/
                                    /*与s相同的元素，由于不止一条记录符合条件，因此将这些元素的下标置于 f数组中*/
{
	int i,j=0,find=0;
	for (i=0;i<n;i++)                                 /*待查找的元素*/
		if (equal(own[i],s,condition))  
		{
			f[j++]=i;                          /*找到了相等的元素，将其下标放到f数组中*/
			find++;	                        /*统计找到的元素个数*/                              
		}
	 return find;                                /*返回find，其值为0则表示没找到*/ 
}