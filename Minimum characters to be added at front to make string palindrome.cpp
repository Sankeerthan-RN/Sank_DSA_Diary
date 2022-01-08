 vector<int>lps(string s)
{
    int m=s.length();
    vector<int> arr(m);
    arr[0]=0;
    int i=1,j=0;
    while(i<m)
    {
        if(s[i]==s[j])
        {
            arr[i]=j+1;
            i++;
            j++;
        }
        else {
            if(j!=0)
                j=arr[j-1];

            else
            {
                arr[i]=0;
                i++;  
            }
        }  
        
    }
    return arr;
       
}



int Solution::solve(string s) {

   string p=s;
   reverse(p.begin(),p.end());
   string res=s+"$"+p;
   vector<int> ans=lps(res);

   return( s.length()-ans.back() );
}


