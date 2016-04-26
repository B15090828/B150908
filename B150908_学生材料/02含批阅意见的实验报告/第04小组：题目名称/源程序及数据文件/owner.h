/* ①Owner.h文件的完整内容 */
#ifndef _OWNER              /*条件编译，防止重复包含的错误*/
#define _OWNER
#include <string.h>
#define NUM 20              /*定义车主人数常量，此处可以根据实际需要修改常量值*/
struct Owner                /*车主记录的数据域*/
{
	long num;
	char name[20];
	char sex[10];
	int time[10];
	int total;
}
typedef struct Owner Owner;            
#define sizeOwn sineof(Owner)          /*一个车主记录所需要的内存空间大小*/
int readOwn(Owner Own[],int n);        /*读入车主记录值，车牌号为0或读满规定条数记录时停止*/
void printOwn(Owner *Own,int n);        /*输出所有车主记录的值*/
void calcuTotal(Owner Own[],int n);         /*计算所有车主的总分*/
void cacluTimetable(double m[1][3],Owner Own[],int n);                /*求车主的最长、最短、平均停车时间*/
int searchOwn(Owner Own[],int n,Owner s,int condition,int f[]);        /*根据条件找数组中与s相等的各元素*/
                                                /*下标置于f数组中，设f数组是因为查找结果可能不止一条记录*/
int insertOwn(Owner Own[],int n,Owner s);           /*向数组中插入一个元素按车牌号有序*/
int deletOwn(Owner Own[],int n,Owner s);            /*从数组中删除一个指定车牌号的元素*/
#endif