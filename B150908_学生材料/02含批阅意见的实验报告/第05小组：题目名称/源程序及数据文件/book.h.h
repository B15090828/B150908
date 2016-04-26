/* ①book.h文件的完整内容 */
#ifndef _BOOK             /*条件编译，防止重复包含的错误*/
#define _BOOK
#include <string.h>
#define NUM 20                /*定义图书常量，此处可以根据实际需要修改常量值*/
struct Student                   /*学生记录的数据域*/
{
		long num;              /*学号 */
		char name[20];        /*姓名 */
		 
};
struct Book
{
	char title[20];          /*书名 */
	long number[20];            /*索引号 */
	char state[4];             /*借阅状态 */
	int kc;                    /*库存*/
};
typedef struct Book Book;
#define sizeBook sizeof(Book)      /*一条图书记录所需要的内存空间大小*/
int readBook(Book book[],int n);       /*读入书书籍名称*/
void printB00k( Book  *Book , int n);   /*输出所有书籍记录的值*/
void sortBook(Book book[],int n,int condition);   /*选择法从大到小排序，按condition所规定的条件*/
int searchBook(Book book[],int n,Book b,int condition,int f[]) ;  /*根据条件找数组中与b相等的各元素*/
int addBook(Book book[],int n,Book b);                   /*向数组中增加一条图书信息*/
int deleteBook(Book book[],int n,Book b);                   /*从数组中删除一条图书信息*/
#endif