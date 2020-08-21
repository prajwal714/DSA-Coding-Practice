class Solution {
public:
    bool isValid(string st) {
        
        
        stack<char> s;
        
        for(int i=0;i<st.length();i++)
        {
            if(st[i]=='(' || st[i]=='{' || st[i]=='[')
                s.push(st[i]);
            else
            {
               
          
                if(!s.empty())
                {
                    if(st[i]==')' && s.top()=='(')
                    s.pop();

                    else if(st[i]=='}' && s.top()=='{')
                    s.pop();

                   else if(st[i]==']' && s.top()=='[')
                    s.pop();
                    else
                        return false;


                }
                else
                    return false;
            }
           
            
        }
        
        
        if(!s.empty())
            return false;
        else
            return true;
        
    }
};