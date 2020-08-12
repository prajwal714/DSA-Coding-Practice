class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        
        int level=1;
        
        while(1<<level <= label)
            level++;
        vector<int> res(level);
        for(;label>=1; label=label/2)
        {
            res[level-1]=label;
           
            
            label=(1<<level)-1 + (1<<(level-1))-label;
            
             level--;
            
        }
        
        return res;
        
    }
};