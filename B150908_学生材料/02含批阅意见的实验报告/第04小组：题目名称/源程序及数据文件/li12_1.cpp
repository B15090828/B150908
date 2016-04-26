/*li12_1.c不完全文件1*/
#include<stdio.h>
#include<stdlib.h>
#include"file.h"
#include"owner.h"

void printHead( )      /*打印车主信息的表头*/
{
printf("%8s%10s%8s%6s%10s\n","车牌号","姓名","性别","单次时间","总时间");
}

void menu( )         /*顶层菜单函数*/
{
		printf("******** 1. 显示基本信息 ********\n");
		printf("******** 2. 基本信息管理 ********\n");
		printf("******** 3. 车主信息管理 ********\n");
		printf("******** 4. 停车信息统计 ********\n");
		printf("******** 5. 根据条件查询 ********\n");
		printf("******** 0. 退出         ********\n");
}

void menuBase( )     /*2、基本信息管理菜单函数*/
{
		printf("%%%%%%%% 1. 添加车主信息 %%%%%%%%\n");
		printf("%%%%%%%% 2. 删除车主信息 %%%%%%%%\n");
		printf("%%%%%%%% 3. 修改车主信息 %%%%%%%%\n");
		printf("%%%%%%%% 0. 返回上层菜单 %%%%%%%%\n");
}

void menuInformation( )     /*3、车主信息管理菜单函数*/
{
		printf("@@@@@@@@ 1. 计算停车总时间 @@@@@@@@\n");
		printf("@@@@@@@@ 0. 返回上层菜单 @@@@@@@@\n");
}
 
void menuCount( )    /*4、停车信息统计菜单函数*/
{
		printf("&&&&&&&& 1. 计算停车最长时间 &&&&&&&&\n");
		printf("&&&&&&&& 2. 计算停车最短时间 &&&&&&&&\n");
		printf("&&&&&&&& 3. 计算停车平均平均时间 &&&&&&&&\n");
		printf("&&&&&&&& 0. 返回上层菜单 &&&&&&&&\n");
}

void menuSearch()    /*5、根据条件查询菜单函数*/
{
		printf("######## 1. 按车牌号查询   ########\n");
		printf("######## 2. 按姓名查询   ########\n");
		printf("######## 0. 返回上层菜单 ########\n");
}

int baseManage(Owner own[],int n)    	     /*该函数完成基本信息管理*/
/*按车牌号进行插入删除修改，车牌号不能重复*/
{  
		int choice,t,find[NUM];
     Owner s;
do
	    {   
menuBase( );                  /*显示对应的二级菜单*/
printf("choose one operation you want to do:\n");
		     scanf("%d",&choice);	          /*读入选项*/
		     switch(choice)
		     {
			   case 1:	 readOwn(&s,1);       /*读入一条待插入的车主记录*/
					 n=insertOwn(own,n,s);   /*调用函数插入车主记录*/
					 break;
			   case 2:  printf("Input the number deleted\n");
					 scanf("%ld",&s.num);  /*读入一个待删除的车主车牌号*/
					 n=deleteOwn(own,n,s);   /*调用函数删除指定车牌号的车主记录*/
					 break;
			   case 3:  printf("Input the number modified\n");
					 scanf("%ld",&s.num);  /*读入一个待修改的车主车牌号*/
				      t=searchOwn(own,n,s,1,find) ; /*调用函数查找指定车牌号的车主记录*/
				      if (t)                 /*如果该车牌号的记录存在*/
					 {
						  readOwn(&s,1);   /*读入一条完整的车主记录信息*/
					      own[find[0]]=s;    /*将刚读入的记录赋值给需要修改的数组记录*/ 					 
					  }					 
					 else                 /*如果该车牌号的记录不存在*/ 
 printf("this owner is not in,can not be modified.\n"); /*输出提示信息*/
					 break;
			    case 0: break;
		    }
	}while(choice);
return n;                             /*返回当前操作结束后的实际记录条数*/
}

void informationManage(Owner own[],int n)          /*该函数完成车主信息管理功能*/
{  
	int choice;
	do
	{
		menuInformatiom( );                        /*显示对应的二级菜单*/
		printf("choose one operation you want to do:\n");
		scanf("%d",&choice);	                 /*读入二级选项*/
		switch(choice)
		{
			case 1:   calcuTotal(own,n);         /*求所有车主的总停车时间*/
				break;		
			case 0:   break;
		}
	}while(choice);
}