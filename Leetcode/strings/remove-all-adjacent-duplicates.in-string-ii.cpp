class Solution {
public:
    string removeDuplicates(string st, int k) {
        
        stack<pair<int,char>> s;
        int count=0;
        for(int i=0;i<st.length();i++)
        {
           
           if(s.empty())
               s.push(make_pair(1,st[i]));
            else
            {
                if(s.top().second!=st[i])
                {
                    s.push(make_pair(1,st[i]));
                }
                else
                {
                    s.top().first++;
                    if(s.top().first==k)
                        s.pop();
                }
            }
            
        }
        string res="";
       while(!s.empty())
       {
           for(int i=0;i<s.top().first;i++)
           res=s.top().second+res;
           
           s.pop();
       }
        
        return res;
        
    }
};