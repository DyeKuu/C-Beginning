
#include <stdio.h>
#include <math.h>
void swap(int *A, int i, int j);

int main(void)
{

}

void swap (int* A, int i, int j){
    int tmep;

    tmep = A[i];
    A[i] = A[j];
    A[j] = tmep;
}
