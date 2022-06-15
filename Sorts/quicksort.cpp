
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
         if(low<high)
        {
            int pi= partition(arr,low,high);
            quickSort(arr,low,pi-1);
            quickSort(arr,pi+1,high);
          
        }

    }
    
    public:
    int partition (int arr[], int low, int high)
    {
       int idx=low+ rand()%(high-low);
       swap(arr[idx],arr[high]);
       int pivot=arr[high];
       int i=low,j=low;
     
       while(j<high)
       {
           if(arr[j]>=pivot)j++;
           else swap(arr[i++],arr[j++]);
         
       }
       swap(arr[high],arr[i]);
   return i;
    }
};



    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}  // } Driver Code Ends