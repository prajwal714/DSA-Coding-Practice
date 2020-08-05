class Solution {
public:
    string reverseStr(string s, int k) {
        
        int n=s.length();
        int i;
        for(i=0;i<n;i+=2*k)
        {
            reverse(s,i,min(i+k-1,n-1));
        }
        
        return s;
    }
    
    
    void reverse(string &s, int start, int end)
    {
        while(start<end)
        {
            swap(s[start++], s[end--]);
        }
    }
};