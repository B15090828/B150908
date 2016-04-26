int insertOwn(Owner Own[],int n,Owner s)        /*从数组中增加指定车牌号的一个元素*/
{
	int i;
	for(i=0;i<n;i++)                            /*车牌号相同不允许插入，保证车牌号的唯一性*/
	{
		if(equal(Own[i],s,1))
		{
			printf("this record exist,can not insert again!\n");
			return n;
		}
	}
	for(i<n-1;i>=0;i--)
	{
		Own[i+1]=Own[i];                            /*元素stu[i]后移一个位置*/
	}
	Own[i+1]=s;                                      /*在下标i+1处插入元素s*/ 
	n++;                                            /*元素个数增加1*/
	return n;                                         /*返回现有元素个数*/
}
int deleteOwn(Owner Own[],int n,Owner s)            /*从数组中删除指定车牌号的一个元素*/
{
	int i,j;
	for (i=0;i<n;i++)                           /*寻找待删除的元素*/
		if (equal(Own[i],s,1))   break;            /*如果找到相等元素则退出循环*/
	if (i==n)                                 /*如果找不到待删除的元素*/
	{
		printf("This record does not exist!\n");    /*给出提示信息然后返回*/
		return n;
	}
	for (j=i; j<n-1; j++)                        /*此处隐含条件为i<n且equal(stu[i],s,1)成立*/ 
		Own[j]=Own[j+1];                       /*通过移动覆盖删除下标为i的元素*/
                                                                            
	n--;                                      /*元素个数减少加1*/
	return n;                                  /*返回现有个数*/
}
