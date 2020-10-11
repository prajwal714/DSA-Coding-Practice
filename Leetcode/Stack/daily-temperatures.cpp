class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        
        stack<pair<int,int>> s;
        int n=T.size();
        vector<int> res;
        
        for(int i=n-1;i>=0;i--)
        {
            if(s.empty())
            {
                res.push_back(-1);
            }
            else
            {
                if(s.top().first>T[i])
                {
                    res.push_back(s.top().second);
                }
                else
                {
                    while(!s.empty() && s.top().first<=T[i])
                        s.pop();
                    
                    if(s.empty())
                        res.push_back(-1);
                    else
                        res.push_back(s.top().second);
                }
            }
            
            s.push(make_pair(T[i], i));
        }
        reverse(res.begin(), res.end());
        
        for(int i=0;i<n;i++)
        {
            if(res[i]==-1)
                res[i]=0;
            else
                res[i]=res[i]-i;
        }
        return res;
        
    }
};

//==========shorter code for Next Greatest Element using stack

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        
        stack<pair<int,int>> s;
        int n=T.size();
        vector<int> res(n);
        
        for(int i=n-1;i>=0;i--)
        {
            
            while(!s.empty() && s.top().first<=T[i])
                s.pop();
            
            if(s.empty())
                res[i]=0;
            else
                res[i]=s.top().second-i;
            
            
            s.push({T[i], i});
        }

        return res;
        
    }
};