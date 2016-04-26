/*li12_1.c不完全文件2*/
void printTimetableCourse(char *s,double m[1][3],int k)   /*打印分数通用函数，被countManage 调用*/
                                                   /*0、1、2分别对应最长时间、最短时间、平均时间*/
{                 
    printf(s);                                  /*这里的s传入的是输出时间的提示信息*/
	printf("%10.2lf",m[1][k]);
	printf("\n");
}

void countManage(Owner own[],int n)               /*该函数完成停车信息统计功能*/
{
		int choice;
		double timetable[1][3];
		do
		{
			menuCount( );                        /*显示对应的二级菜单*/
			calcuTimetable(timetable,own,n);                 /*调用此函数求最长时间、最短时间、平均时间*/
			printf("choose one operation you want to do:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printTimetableCourse("最长时间是:\n",timetable,0);  /*输出最长时间*/
				      break;
				case 2:   printTimetableCourse("最短时间是:\n",timetable,1);  /*输出最短时间*/
				      break;
				case 3:   printTimetableCourse("平均时间是:\n",timetable,2);  /*输出平均时间*/
				      break;
				case 0:   break;
			}
		}while (choice);
}

void searchManage(Owner own[],int n)               /*该函数完成根据条件查询功能*/
{
    int i,choice,findnum,f[NUM];
	Owner s;
	do
	{
			menuSearch( );                         /*显示对应的二级菜单*/
			printf("choose one operation you want to do:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printf("Input a owner\'s num will be searched:\n");
				      scanf("%ld",&s.num);         /*输入待查询车主的车牌号*/
					  break;
				case 2:   printf("Input a owner\'s name will be searched:\n");
				      scanf("%s",s.name);	          /*输入待查询车主的姓名*/		  
				      break;   
				case 0:   break;
			}
		 	if (choice>=1&&choice<=3)
			{ 
				findnum=searchOwn(own,n,s,choice,f);    /*查找的符合条件元素的下标存于f数组中*/
				if (findnum)				     /*如果查找成功*/
				{
			   		 printHead( );                  /*打印表头*/
					 for (i=0;i<findnum;i++)         /*循环控制f数组的下标*/
						 printOwn(&own[f[i]],1);      /*每次输出一条记录*/
				}
		    		else
					printf("this record does not exist!\n"); /*如果查找不到元素，则输出提示信息*/
		     }		
	   
	}while (choice);
}

int runMain(Owner own[],int n,int choice)    /*主控模块，对应于一级菜单其下各功能选择执行*/
{
	switch(choice)
	{
	case 1: printHead( );           /* 1. 显示基本信息*/
		printOwn(own,n);          /*按车牌号输入顺序输出所有记录*/
		break;
	case 2: n=baseManage(own,n);    /* 2. 基本信息管理*/
		break;
	case 3: informationManage(own,n);     /* 3. 车主信息管理*/
		break;
	case 4: countManage(own,n);     /* 4. 停车信息统计*/
		break;
	case 5: searchManage(own,n);     /* 5. 根据条件查询*/
		break;
	case 0: break;
	}
	return n;
}

int main( )
{
	Owner own[NUM];                /*定义实参一维数组存储车主记录*/
	int choice,n;
	n=readFile(own);                  /*首先读取文件，记录条数返回赋值给n*/
	if (!n)                          /*如果原来的文件为空*/
	{
		n=createFile(own);              /*则首先要建立文件，从键盘上读入一系列记录存于文件*/
	}	 	 
	do
	{
		menu();                      /*显示主菜单*/
		printf("Please input your choice: ");
		scanf("%d",&choice);
		if (choice>=0&&choice<=5)
			n=runMain(own,n,choice);    /*通过调用此函数进行一级功能项的选择执行*/
		else 
			printf("error input,please input your choice again!\n");
	} while (choice); 
	saveFile(own,n);                   /*将结果存入文件*/
	return 0;
}
