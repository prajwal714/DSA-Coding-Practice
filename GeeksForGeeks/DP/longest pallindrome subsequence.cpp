#include<bits/stdc++.h>
using namespace std;


int getlp(string s,int i,int j,map<string,int> &m)
{
	cout<<s.substr(i,j+1)<<endl;
	auto it=m.find(s.substr(i,j+1));
	if(it!=m.end())
	return it->second;
	
	
	if(i==j)
	{
		m[s.substr(i,j+1)]=1;
		return 1;
	}

	
	if(s[i]==s[j])
	{
		
		if(i+1==j)
		{
			m[s.substr(i,j+1)]=2;

			return 2;
		}
		
		else
		{
			
			return 2+getlp(s,i+1,j-1,m);
		}
		
	}
	else
	return max(getlp(s,i+1,j,m),getlp(s,i,j-1,m));
}


int main()
{
	string s;
	cin>>s;
	map<string,int> m;
	cout<<getlp(s,0,s.length(),m);
	
	return 0;
}
