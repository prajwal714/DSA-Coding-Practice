class Solution {
public:
    int res;
    bool valid=false;
    string largestTimeFromDigits(vector<int>& arr) {
        
        unordered_map<int,bool> used;
        vector<int> temp;
        res=0;
        backtrack(arr, temp, used);
        
        string ans="";
        
        if(!valid)
            return "";
        
        int hr=res/100;
        int min=res%100;
        
            if(hr==0)
                ans+="00";
            else if(hr/10==0)
                ans+="0"+to_string(hr);
            else
                ans+=to_string(hr);
        
            ans+=":";
        
            if(min==0)
                ans+="00";
            else if(min/10==0)
                ans+="0"+to_string(min);
            else
                ans+=to_string(min);
        
        return ans;
                
                
            
        
    }
    
    void backtrack(vector<int> arr, vector<int> temp, unordered_map<int,bool> used)
    {
        if(temp.size()==arr.size())
        {
            int hr=temp[0]*10+temp[1];
            int min=temp[2]*10+temp[3];
            
            if(hr<24 && min < 60)
            {
                res=max(res,hr*100+min);
                valid=true;
                return;
            }
        }
            
            for(int i=0;i<arr.size();i++)
            {
                if(used[i] || (i>0 && arr[i]==arr[i-1] && !used[i-1]))
                    continue;
                
                temp.push_back(arr[i]);
                used[i]=true;
                backtrack(arr, temp, used);
                used[i]=false;
                temp.pop_back();
            }
            
            return;
                
        }
    
};