#include <iostream>
#include <climits>
#include <algorithm>


using namespace std;



int rBinarySearch(int sortedArray[], int first, int last, int key)
{
    if (first <= last)
    {
       int mid = (first + last) / 2;
       if (key == sortedArray[mid])
           return mid;
       else if (key < sortedArray[mid])
           return rBinarySearch(sortedArray, first, mid-1, key);
       else
           return rBinarySearch(sortedArray, mid+1, last, key);
   }
   return -(first + 1);    // failed to find key
}




int LinearSearch(int Array[],int key,int Size)
{
    Size = Size - 1;

    if (Size < 0)
    {
      return -1;
    }

    else if (Array[Size] == key)
    {
      return 1;
    }

    else
    {
      return LinearSearch(Array, key, Size);
    }
}



void MinMax(int Array[], int Size)
{
  int min = INT_MAX, max = INT_MIN;


	for (int i=0; i<Size; i++)
	{
		if (Array[i] < min)
    {
			min = Array[i];
		}
	}


	for (int k = 0; k < Size; k++)
  {
    if (Array[k] > max)
    {
      max = Array[k];
    }
  }

	cout << "Minimum is: " << min << " and Maximum is: " << max << endl;
  
}