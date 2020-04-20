#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector <string> result;
void permutateHelper(string s,string chosen)
{
    if(s=="")
    {
            result.push_back(chosen);
           
           
    }
        else
        {
            for(int i=0;i<s.length();i++)
            {
                char ch=s[i];
                chosen+=ch;
                s.erase(i,1);
                permutateHelper(s,chosen);
                
                s.insert(i,1,ch);
                chosen.erase(chosen.length()-1,1);
                
            }
            
        }
    
}

void permutate(string s)
{
    
    permutateHelper(s,"");
    sort(result.begin(),result.end());
     for(int i=0;i<result.size();i++)
         {
             cout<<result[i]<<" ";
         }
}
int main()
 {
     int t;
     cin>>t;
     
     while(t--)
     {
         string st;
         cin>>st;
         
         permutate(st);
         
        
         cout<<endl;
         result.clear();
     }
	//code
	return 0;
}
