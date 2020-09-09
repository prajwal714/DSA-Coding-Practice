class Solution {
public:
    bool wordPattern(string pattern, string str) {
        
        unordered_map<string,char> stoc;
        unordered_map<char,string> ctos;
        
        vector<string> s;
        str+=" ";
        string wd="";
        for(char ch:str)
        {
            if(ch==' ')
            {
             s.push_back(wd);
                wd="";   
            }
            else
            {
                wd+=ch;
            }
                
        }
        
        bool res=true;
        if(pattern.length()!=s.size())
            return false;
        
        for(int i=0;i<s.size();i++)
        {
          
            string word=s[i];
            char c=pattern[i];
            
            if(stoc.find(word)==stoc.end())
            {
                if(ctos.find(c)!=ctos.end())
                    return false;
                else
                {
                    stoc[word]=c;
                    ctos[c]=word;
                }
            }
            else
            {
                if(word.compare(ctos[c])!=0)
                    return false;
            }
           
            
        }
        
        return true;
        
        
        
    }
};