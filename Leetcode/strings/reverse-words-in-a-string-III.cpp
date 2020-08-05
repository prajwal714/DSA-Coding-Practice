class Solution {
public:
    string reverseWords(string s) {
        
        s+=" ";
        
        int i=0;
        int n=s.length();
        string wd="";
        string rev="";
        for(i=0;i<n;i++)
        {
            if(s[i]!=' ')
                wd+=s[i];
            else
            {
                rev=rev+reverse(wd)+" ";
                wd="";
            }
        }
        
        return rev.substr(0,n-1);
    }
    
    string reverse(string wd)
    {
        int start=0,end=wd.length()-1;
        while(start<end)
        {
            swap(wd[start++],wd[end--]);
        }
        
        return wd;
    }
};