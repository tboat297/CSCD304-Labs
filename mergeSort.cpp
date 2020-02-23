#include<bits/stdc++.h>

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <iostream>

using namespace std;



void Merge(int A[],int p, int q,int r)
{

    int n1,n2,i,j,k;
    //size of left array=n1
    //size of right array=n2
    n1=q-p+1;
    n2=r-q;
    int L[n1],R[n2];
    //initializing the value of Left part to L[]
    for(i=0;i<n1;i++)
    {
        L[i]=A[p+i];
    }
    //initializing the value of Right Part to R[]
    for(j=0;j<n2;j++)
    {
        R[j]=A[q+j+1];
    }
    i=0,j=0;
    //Comparing and merging them
    //into new array in sorted order
    for(k=p;i<n1&&j<n2;k++)
    {
        if(L[i]<R[j])
        {
            A[k]=L[i++];
        }
        else
        {
            A[k]=R[j++];
        }
    }
    //If Left Array L[] has more elements than Right Array R[]
    //then it will put all the
    // renaming elements of L[] into A[]
    while(i<n1)
    {
        A[k++]=L[i++];
    }
    //If Right Array R[] has more elements than Left Array L[]
    //then it will put all the
    // reamining elements of L[] into A[]
    while(j<n2)
    {
        A[k++]=R[j++];
    }
}
//This is Divide Part
//This part will Divide the array into
//Sub array and then will Merge them
//by calling Merge()
void MergeSort(int A[],int p,int r)
{
    int q;
    if(p<r)
    {
        q=(p+r)/2;
        MergeSort(A,p,q);
        MergeSort(A,q+1,r);
        Merge(A,p,q,r);
    }
}


void dispArray(int Array[], int Size) {
   for(int i = 0; i<Size; i++)
      cout << Array[i] << " ";
   cout << endl;
}


void RandomInput(int Array[], int Size)
{
    srand(time(NULL));
    for(int i=0; i < Size; i++)
    {
        Array[i] = rand()%10000;
    }
}

int main()
{
    FILE *fp;
    struct timeval tv;
    double dStart,dEnd;
    int Arr[50000], Size, Choice;


    cout << "\n1.Plot the Graph \n2.MergeSort \n3.Exit" << endl;
    cout << "\nEnter your choice\n" << endl;
    cin >> Choice;

    switch (Choice)
    {
        case 1:
            fp = fopen("MergePlot.DAT","w");

            for (int i=100; i<20000; i += 100)
            {
                RandomInput(Arr, i);
                gettimeofday(&tv,NULL);
                dStart = tv.tv_sec + (tv.tv_usec/1000000.0);
                MergeSort(Arr, 0, i-1);
                gettimeofday(&tv,NULL);
                dEnd = tv.tv_sec + (tv.tv_usec/1000000.0);
                fprintf(fp,"%d\t\t\t%fl\n",i,dEnd-dStart);
            }

            fclose(fp);

            cout << "\nData File generated and stored in file MergePlot.DAT \nUse a plotting utility\n";

            break;

        case 2:
            cout << "\nEnter the number of elements to sort\n";
            cin >> Size;

            cout << "\nUnsortedArray\n";
            RandomInput(Arr,Size);
            dispArray(Arr,Size);

            MergeSort(Arr, 0, Size-1);

            cout << "\nSortedArray\n" << endl;
            dispArray(Arr, Size);

            break;

        case 3:
            exit(0);
    }

    return 0;
}
