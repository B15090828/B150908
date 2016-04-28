#include<stdio.h>
#include<stdlib.h>
#include"file.h"
#include"player.h"

//void printHead( )      /*��ӡ��Ա��Ϣ�ı�ͷ*/
//printf("%3d%8s%2d%2d%2d%2%2d%2d\n","��Ա����","����","�÷�","����","����","����","ʧ��","����");
//}

void menu( )         /*����˵�����*/
{
		printf("******** 1. ��ʾ������Ϣ ********\n");
		printf("******** 2. ������Ϣ���� ********\n");
		printf("******** 3. ��Ա���ݹ��� ********\n");
        printf("******** 4. ����������ѯ ********\n");
		printf("******** 0. �˳�         ********\n");
}

void menuBase( )     /*2��������Ϣ����˵�����*/
{
		printf("%%%%%%%% 1. ������Ա��¼ %%%%%%%%\n");
		printf("%%%%%%%% 2. ɾ����Ա��¼ %%%%%%%%\n");
		printf("%%%%%%%% 3. �޸���Ա��¼ %%%%%%%%\n");
		printf("%%%%%%%% 0. �����ϲ�˵� %%%%%%%%\n");
}

void menuScore( )     /*3����Ա���ݹ���˵�����*/
{
		printf("@@@@@@@@ 1. ������Ա�ܵ÷� @@@@@@@@\n");
		printf("@@@@@@@@ 2. �����ܵ÷����� @@@@@@@@\n");
		printf("@@@@@@@@ 0. �����ϲ�˵� @@@@@@@@\n");
}
 

void menuSearch()    /*5������������ѯ�˵�����*/
{
		printf("######## 1. �����º����ѯ   ########\n");
		printf("######## 2. ����Ա������ѯ   ########\n");
		printf("######## 0. �����ϲ�˵� ########\n");
}

int baseManage(Player pla[],int n)    	     /*�ú�����ɻ�����Ϣ����*/
/*�����ºŽ��в���ɾ���޸ģ����º��벻���ظ�*/
{  
		int choice,t,find[NUM];
        Player s;
        do
	    {   
             menuBase( );                  /*��ʾ��Ӧ�Ķ����˵�*/
             printf("choose one operation you want to do:\n");
		     scanf("%d",&choice);	          /*����ѡ��*/
		     switch(choice)
		     {
			   case 1:	 readPla(&s,1);       /*����һ�����������Ա��¼*/
					 n=insertPla(pla,n,s);   /*���ú���������Ա��¼*/
					 break;
			   case 2:  printf("Input the number deleted\n");
					 scanf("%ld",&s.number);  /*����һ����ɾ������Ա���º���*/
					 n=deletePla(pla,n,s);   /*���ú���ɾ��ָ�����º������Ա��¼*/
					 break;
			   case 3:  printf("Input the number modified\n");
					 scanf("%ld",&s.number);  /*����һ�����޸ĵ���Ա���º���*/
				      t=searchPla(pla,n,s,1,find) ; /*���ú�������ָ�����º������Ա��¼*/
				      if (t)                 /*��������º���ļ�¼����*/
					 {
						  readPla(&s,1);   /*����һ����������Ա��¼��Ϣ*/
					      pla[find[0]]=s;    /*���ն���ļ�¼��ֵ����Ҫ�޸ĵ������¼*/ 					 
					  }					 
					 else                 /*��������º���ļ�¼������*/ 
            printf("this player is not in,can not be modified.\n"); /*�����ʾ��Ϣ*/
					 break;
			    case 0: break;
		    }
	}while(choice);
return n;                             /*���ص�ǰ�����������ʵ�ʼ�¼����*/
}

void scoreManage(Player pla[],int n)          /*�ú��������Ա���ݹ�����*/
{  
	int choice;
	do
	{
		menuScore( );                        /*��ʾ��Ӧ�Ķ����˵�*/
		printf("choose one operation you want to do:\n");
		scanf("%2d",&choice);/*�������ѡ��*/
		int k,m;
		switch(choice)
		{
			case 1:   calcuTotal(pla,n);/*��������Ա���ܵ÷�*/
				for( k=0;k<=5;k++)
				{
					printf("��Ա%s���ܵ÷�:%d",pla[k].name,pla[k].total);
				}
					  break;
			case 2:   calcuRank(pla,n);         /*����������Ա���ܵ÷�������*/
				for( m=0;m<=5;m++)
				{
					printf("��Ա%s��������:%d",pla[m].name,pla[m].rank);
				}
				      break;		
			case 0:   break;
		}
	}while(choice);
}




void searchManage(Player pla[],int n)               /*�ú�����ɸ���������ѯ����*/
{
    int i,choice,findnum,f[NUM];
    Player s;
	do
{
			menuSearch( ); /*��ʾ��Ӧ�Ķ����˵�*/
			calcuTotal(pla,15);
	        calcuRank(pla,15);
			printf("choose one operation you want to do:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printf("Input a player\'s num will be searched:\n");
				      scanf("%2d",&s.number);         /*�������ѯ��Ա�����º���*/
					  break;
				case 2:   printf("Input a player\'s name will be searched:\n");
				      scanf("%8s",&s.name);/*�������ѯ��Ա������*/	
				      break;   
				case 0:   break;
			}
		 	if (choice>=1&&choice<=2)
			{ 
				findnum=searchPla(pla,n,s,choice,f);    /*���ҵķ�������Ԫ�ص��±����f������*/
				if (findnum)				     /*������ҳɹ�*/
				{
			   		 //printHead( );                  /*��ӡ��ͷ*/
					 for (i=0;i<findnum;i++)         /*ѭ������f������±�*/
					 { // print(&pla[f[i]],1);      /*ÿ�����һ����¼*/
					  
	
		printf("���º���:%3d   ", pla[f[i]].number);
		printf("����:%8s   ", pla[f[i]].name);
		printf("�ܷ�:%7d   ",pla[f[i]].total);
	    printf("����:%5d\n",pla[f[i]].rank);
		for (int j=1;j<=5;j++)
		{
		printf("��%d���÷�:%6d   ",j,pla[f[i]].score[j]);
		printf("��%d������:%6d   ",j,pla[f[i]].assist[j]);
		printf("��%d������:%6d   ",j,pla[f[i]].rebounds[j]);
		printf("��%d������:%6d   ",j,pla[f[i]].steals[j]);
		printf("��%d��ʧ��:%6d \n",j,pla[f[i]].turnover[j]);
		}
	
					 }
				}
		    		else
			    	    printf("this record does not exist!\n"); /*������Ҳ���Ԫ�أ��������ʾ��Ϣ*/
		     }		
	    }while (choice);
}

int runMain(Player pla[],int n,int choice)    /*����ģ�飬��Ӧ��һ���˵����¸�����ѡ��ִ��*/
{
		switch(choice)
		{
			case 1: //printHead( );           /* 1. ��ʾ������Ϣ*/
				    sortPla(pla,n,1);         /*�����º�����С�����˳�������¼*/ 
          	        printPla(pla,n);          /*�����º�����С�����˳��������м�¼*/
					break;
			case 2: n=baseManage(pla,n);    /* 2. ������Ϣ����*/
			   	    break;
			case 3: scoreManage(pla,n);     /* 3. ��Ա���ݹ���*/
					break;
			//case 4: countManage(pla,n);     /* 4. �����÷�ͳ��*/
					//break;
			case 4: searchManage(pla,n);     /* 4. ����������ѯ*/
				    break;
            case 0: break;
		}
		return n;
}

int main( )
{      
		Player pla[NUM];                /*����ʵ��һά����洢��Ա��¼*/
        int choice,n;
	    n=readFile(pla);                  /*���ȶ�ȡ�ļ�����¼�������ظ�ֵ��n*/
	 if (!n)                          /*���ԭ�����ļ�Ϊ��*/
	     {
		    n=createFile(pla);              /*������Ҫ�����ļ����Ӽ����϶���һϵ�м�¼�����ļ�*/
	 }	 	 
	do
	     {
	         menu();                      /*��ʾ���˵�*/
	         printf("Please input your choice: ");
	         scanf("%d",&choice);
	         if (choice>=0&&choice<=4)
	              n=runMain(pla,n,choice);    /*ͨ�����ô˺�������һ���������ѡ��ִ��*/
	         else 
		          printf("error input,please input your choice again!\n");
	} while (choice);
	     sortPla(pla,n,1);                   /*�����ļ�ǰ�����º�����С��������*/ 
	     saveFile(pla,n);                   /*����������ļ�*/
      return 0;
}
