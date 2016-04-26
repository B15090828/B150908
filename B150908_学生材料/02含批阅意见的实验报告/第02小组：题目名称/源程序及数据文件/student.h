/* ①car.h文件的完整内容 */
#ifndef _car             /*条件编译，防止重复包含的错误*/
#define _car
#include <string.h>
#define NUM 20                /*定义车辆常量，此处可以根据实际需要修改常量值*/
struct car 
{
	long number;													//车牌号
	char name[20];												   //车主姓名
    char chexing[10]                                          //车型
    char color                                               //颜色
	int grade;													      //扣分
	int money;													     //罚款
	Char weigui[10]；                                   		//违规情况
} ;

typedef struct car car;
#define sizeche sizeof(car)      /*车辆记录所需要的内存空间大小*/
int readche(car che[],int n);       /*读入车辆记录值，车牌号为0或读满规定条数记录时停止*/
void printche(car  *che , int n);   /*输出所有车辆记录的值*/

int equal(car s1,car s2,int condition);  /*根据condition条件判断两个car类型数据相等否*/
int larger(car s1,car s2,int condition);  /*根据condition比较car类型数据大小*/
void reverse(car stu[],int n);             /*车辆记录数组元素逆置*/

void calcuTotal(car che[],int n);           /*计算所有车辆的总扣分*/
void calcuRank(car che[],int n);           /*根据扣分多少进行排列，允许有并列名次*/


void sortche(car che[],int n,int condition);   /*选择法从小到大排序，按condition所规定的条件*/

int searchche(car che[],int n,car s,int condition,int f[]) ;  /*根据条件找数组中与s相等的各元素*/
/*下标置于f数组中，设f数组是因为查找结果可能不止一条记录*/
int insertche(car che[],int n,car s);                   /*向数组中插入一个元素按车牌号有序*/
int deleteStu(car che[],int n,car s);                   /*从数组中删除一个指定车牌号的元素*/
#endif
