#include <QCoreApplication>
#include <iostream>
#include<stdlib.h>
#include<math.h>
#include <time.h>
#include <stdio.h>
using namespace std;
void selection(int *A, int size)
 {
     int i, j, mx, nmx;
     for(i = 0; i < size-1; i++)
       {
         mx=A[i];
         nmx=i;
         for(j = i+1; j < size; j++)
           {
             if (A[j]<mx)
                {
                 mx=A[j];
                 nmx=j;
                 }
           }
          A[nmx]=A[i];
          A[i]=mx;
           }
     }
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    setlocale(LC_ALL, "russian");
        const int k=200000;
        int A[k];
    for (int i=0;i<k;i++)
        A[i]=1+rand()%1000;
     cout << "Первые 10 элементов:" << endl;
    for (int i=0;i<10;i++)
       cout << A[i] << "  ";
        cout << endl;
    cout << "Последние 10 элементов:" << endl;
    for (int i=199990;i<200000;i++)
       cout << A[i] << "  ";
        cout << endl;
        clock_t start = clock();
        selection(A,k);
       clock_t end = clock();
          double seconds = (double)(end - start) / CLOCKS_PER_SEC;
          printf("The time: %f seconds\n", seconds);
     cout << "Отсортированные первые 10 элементов:" << endl;
        for (int i=0;i<10;i++)
        cout << A[i] << "  ";
        cout << endl;
        cout << "Отсортированные последние 10 элементов:" << endl;
    for (int i=199990;i<200000;i++)
       cout << A[i] << "  ";
        cout << endl;
        system("pause");
    return a.exec();
}
