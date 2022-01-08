#include <bits/stdc++.h>
using namespace std;


vector<int>computeLPS(string pattern)
{
	vector<int>lps(pattern.length()+1);
	int j=0;
	lps[0]=0;
	for(int i=1;i<pattern.length();){
		if(pattern[i]==pattern[j])
		{
			lps[i]=j+1;
			i++;
			j++;
		}
		else{
			if(j!=0)
			{
				j=lps[j-1];
			}
			else{
				lps[i]=0;
				i++;
			}
		}
	}
	return lps;
}

bool KMP(string s, string pattern){
	
	vector<int>lps=computeLPS(pattern);
	int i=0;
	int j=0;
	while(i<s.length()&& j<pattern.length())
	{
		if(s[i]==pattern[j])
		{
			i++;
			j++;
			
		}
		else{
			if(j!=0)
			{
				j=lps[j-1];
			}
			else{
				i++;
			}
		}
	}
	if(j==pattern.length())return true;
	else return false;
}

int main() {

	string s,pattern;
	cin>>s;
	cin>>pattern;
	// string s="abababc";
	// string pattern="abc";
	cout<<KMP(s,pattern);
	
	return 0;
}