class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
        vector<int>ans;
        int left=l,right=m+1;
        while(left<=m && right<=r)
        {
            if(arr[left]<arr[right])
            {
                ans.push_back(arr[left]);
                left++;
            }
            else{
                ans.push_back(arr[right]);
                right++;
            }
        }
        while(left<=m)
        {
            ans.push_back(arr[left++]);
        }
        while(right<=r)
        {
            ans.push_back(arr[right++]);
        }
        int j=0;
        for(int i=l;i<=r;i++)
        {
            arr[i]=ans[j++];
        }
        return;
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
       if(l<r)
       {
           int mid=(l+r)/2;
           mergeSort(arr,l,mid);
           mergeSort(arr,mid+1,r);
           merge(arr,l,mid,r);
       }
       return;
    }
}
