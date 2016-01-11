#ifndef _H_MATRIX
#define _H_MATRIX

typedef struct
{
    int row;
    int col;
    int value;

}Term;
//Sparse-Matrix，左上角為(1,1)，沒有第0列、第0行

Term* getTranspose(Term* matrix);//轉置矩陣方法一
Term* multi(Term* a,Term* b);//乘法方法一,a * b

Term* fastTranspose(Term* m);//轉置矩陣方法二
Term* mmult(Term* a, Term* b);//乘法方法二,a * b
void storeSum(Term *m,int *total,int row,int col,int *sum,int max);//utility function

#endif // _H_MATRIX
