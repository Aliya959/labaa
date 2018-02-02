#include <QCoreApplication>
#include <iostream>
#include<stdlib.h>
#include<math.h>
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
    const int k=10000;
        int A[k];
    for (int i=0;i<k;i++)
        A[i]=1+rand()%1000;
    for (int i=0;i<k;i++)
        cout << A[i] << "  ";
        cout << endl;
        selection(A,k);
    for (int i=0;i<k;i++)
        cout << A[i] << "  ";
        cout << endl;
        system("pause");
    return a.exec();
}
