#include <QCoreApplication>
#include <iostream>
#include<stdlib.h>
#include<math.h>
#include <time.h>
#include <stdio.h>
using namespace std;
void radix(int *A, int *B, int *C, int sizeC, int sizeAB)
{
    int i,k,n;
    k = sizeC;
    n = sizeAB;
    for (i = 0; i <= k; i++)
        C[i]=0;
    for (i = 0; i < n; i++)
        C[A[i]]+=1;
    for (i = 1; i < k+1; i++)
        C[i]+=C[i-1];
    for (i = n-1; i >= 0; i--)
      {
         B[C[A[i]]-1]=A[i];
         C[A[i]]-=1;
      }
  }

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    setlocale(LC_ALL, "russian");
        int k=40000000;
        int *A= new int [k];
        int *C= new int [k];
    for (int i=0;i<k;i++)
        A[i]=1+rand()%1000;
     cout << "Первые 10 элементов:" << endl;
    for (int i=0;i<10;i++)
       cout << A[i] << "  ";
        cout << endl;
    cout << "Последние 10 элементов:" << endl;
    for (int i=39999990;i<40000000;i++)
       cout << A[i] << "  ";
        cout << endl;
       int  Max=A[1];
        for(int i=0; i<k;i++)
            {
            if (A[i]>Max)
                Max=A[i];
            }
           int *B=new int[Max];
        clock_t start = clock();
        radix(A,B,C,k,Max);
    clock_t end = clock();
          double seconds = (double)(end - start) / CLOCKS_PER_SEC;
          printf("The time: %f seconds\n", seconds);
     cout << "Отсортированные сортировкой подсчетом первые 10 элементов:" << endl;
        for (int i=0;i<10;i++)
        cout << B[i] << "  ";
        cout << endl;
        cout << "Отсортированныесортировкой подсчетом последние 10 элементов:" << endl;
    for (int i=Max-10;i<Max;i++)
       cout << B[i] << "  ";
        cout << endl;
        system("pause");
    return a.exec();
}
