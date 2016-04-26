/* ①player.h文件的完整内容 */
#ifndef _PLAYER             /*条件编译，防止重复包含的错误*/
#define _PLAYER
#include <string.h>
#define NUM 20                /*定义球员人数常量，此处可以根据实际需要修改常量值*/
struct Player                   /*球员统计的数据域*/
{
		long num;
		char name[20];
		char nation[10];
		int score[3];
		int total;
};
typedef struct Player Player;
#define sizePla sizeof(Player)      /*一个球员记录所需要的内存空间大小*/
int readPla(Player Pla[],int n);       /*读入球员记录值，读满规定条数记录时停止*/
void printPla(Player  *pla , int n);   /*输出所有球员记录的值*/

int equal(Player s1,Player s2,int condition);  /*根据condition条件判断两个Player类型数据相等否*/
int larger(Player s1，Player s2,int condition);  /*根据condition比较Player类型数据大小*/
void reverse(Player pla[],int n);             /*球员记录数组元素逆置*/

void calcuTotal(Player pla[],int n);           /*计算球队的总分*/
void calcuscore(double m[3][3],Player pla[],int n); /*求得分，助攻，篮板的最高、最低、平均，m数组第一维*/
/*表示哪类数据，第二维表示最高、最低、平均*/

void sortPla(Player pla[],int n,int condition);   /*选择法从小到大排序，按condition所规定的条件*/

int searchPla(Player pla[],int n,Player s,int condition,int f[]) ;  /*根据条件找数组中与s相等的各元素*/
/*下标置于f数组中，设f数组是因为查找结果可能不止一条记录*/
int insertPla(Player stu[],int n,Player s);                   /*向数组中插入一个元素按学号有序*/
int deletePla(Player stu[],int n,Player s);                   /*从数组中删除一个指定学号的元素*/
#endif
