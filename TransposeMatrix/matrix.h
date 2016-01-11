#ifndef _H_MATRIX
#define _H_MATRIX

typedef struct
{
    int row;
    int col;
    int value;

}Term;
//Sparse-Matrix�A���W����(1,1)�A�S����0�C�B��0��

Term* getTranspose(Term* matrix);//��m�x�}��k�@
Term* multi(Term* a,Term* b);//���k��k�@,a * b

Term* fastTranspose(Term* m);//��m�x�}��k�G
Term* mmult(Term* a, Term* b);//���k��k�G,a * b
void storeSum(Term *m,int *total,int row,int col,int *sum,int max);//utility function

#endif // _H_MATRIX
