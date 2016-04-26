/* ①player.h文件的完整内容 */
#ifndef _PLAYER             /*条件编译，防止重复包含的错误*/
#define _PLAYER
#include <string.h>
#define NUM 20                /*定义球员人数常量，此处可以根据实际需要修改常量值*/
struct Player                   /*学生记录的数据域*/
{
		long number;
		char name[20];
		int score[5];
		int assist[5];
		int rebounds[5];
		int steals[5];
            int  turnover[5];
              int sum;
              int rank;
};
typedef struct Player player;
#define sizeStu sizeof(Player)      /*一个球员记录所需要的内存空间大小*/
int readPla(Player pla[],int n);       /*读入球员记录值，球衣号为0或读满规定条数记录时停止*/
void printStu(Player  *pla , int n);   /*输出所有球员记录的值*/

int equal(Player s1,Player s2,int condition);  /*根据condition条件判断两个Player类型数据相等否*/
int larger(Player s1,Player s2,int condition);  /*根据condition比较Player类型数据大小*/
void reverse(Player pla[],int n);             /*球员记录数组元素逆置*/

void calcuTotal(Player pla[],int n);           /*计算所有球员的总得分*/
void calcuRank(Player pla[],int n);           /*根据总分计算学生的名次，允许有并列名次*/
void sortStu(Player pla[],int n,int condition);   /*选择法从小到大排序，按condition所规定的条件*/

int searchPla(Player pla[],int n,Player s,int condition,int f[]) ;  /*根据条件找数组中与s相等的各元素*/
/*下标置于f数组中，设f数组是因为查找结果可能不止一条记录*/
int insertPla(Player pla[],int n,Player s);                   /*向数组中插入一个元素按球衣号有序*/
int deletePla(Player pla[],int n,Player s);                   /*从数组中删除一个指定球衣号的元素*/
#endif
