#include <bits/stdc++.h>
using namespace std;

vector<int>calc(string input)
{
    int m=input.size();
    vector<int>z(m,0);
    int left=0,right=0;
    z[0]=0;
    for(int k=1;k<m;k++)
    {

	//if k out of Z box
        if(k>right)
        {
            left=right=k;
            while(right<m && input[right]==input[right-left]) right++;
            

	    // find the length of the box;
            z[k]=right-left;

            right--;
        }

	//if k is inside Z box
        else{

      
            int k1=k-left;
        
            // if  Z value  calculated for inside z box does not strech till right boundary
            if(z[k1]<right-k+1) z[k]=z[k1];
            

            // recalculate Z box;
            else 
            {
                left=k;
                while(right<m &&  input[right]==input[right-left])right++;
            }

	    // find the length of the box;
            z[k]=right-left;
            right--;
            
        }
    }
    return z;
    
}

bool patternMatching(string text,string pattern)
{
    
    int n=pattern.size();
    

    string res=pattern+'$'+text;
   
   // Z table
    vector<int>z=calc(res);

   
    for(int i=0;i<res.length();i++)
    {
        

           
        if(z[i]==n)
        {
  	         //Starting index of pattern matched  
  	        
             cout<<i-(n+1)<<" ";
             return true;
        }
    }
    return false;
}

int main()
{
    string text="abababc";
    string pattern="ab";
    if(!patternMatching(text,pattern))cout<<"NO PATTERN MATCHED";
    return 0;
}
