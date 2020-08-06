//we consider a window of size 10, and store all the substrings of that window
//we maintain a map to count the num of substrings
//if count==2 we add it to our result

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        
        vector<string> res;
        unordered_map<string,int> mp;
        int i=0;
        int n=s.length();
        while(i+10<=n)
        {
            string subs=s.substr(i,10);
            mp[subs]++;
            i++;
            
            if(mp[subs]==2)
                res.push_back(subs);
        }
        
        return res;
    }
};