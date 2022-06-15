#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int>&arr,int i,int n)
{
	int largest=i;
	int left=2*i+1;
	int right=2*i+2;
	
	if(right<n)
	{
		if(arr[largest]<arr[right])	largest=right;
	
	}
	if(left<n)
	{
		if(arr[largest]<arr[left])	largest=left;
	
	}

        
	if(largest!=i)
	{
		swap(arr[i],arr[largest]);
		heapify(arr,largest,n);
	}
	
}
void heapsort(vector<int>&arr)
{
	int n=arr.size();
	for(int i=n/2-1;i>=0;i--)
	{
		heapify(arr,i,n);
	}
	for(int i=n-1;i>=0;i--)
	{
		swap(arr[0],arr[i]);
		heapify(arr,0,i);
	}
}
int main() {
	
	vector<int>arr={1,3,4,6,8,2,5};
	heapsort(arr);
	for(auto x:arr)cout<<x<<" ";
	return 0;
}