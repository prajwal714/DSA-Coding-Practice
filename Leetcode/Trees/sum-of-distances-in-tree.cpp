class Solution {
public:
    
        vector<unordered_set<int>> tree;
        vector<int> count,res;
    
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        
        tree.resize(N);
        count.assign(N,1);
        res.assign(N,0);
        
        for(auto e: edges)
        {
            tree[e[0]].insert(e[1]);
            tree[e[1]].insert(e[0]);
        }
        
        dfs1(0,-1);
        dfs2(0,-1);
        
        return res;
        
    }
    
    void dfs1(int root, int parent)
    {
        
        for(int i:tree[root])
        {
            if(i==parent)
                continue;
            
            dfs1(i,root);
            
            count[root]+=count[i];
            res[root]+=res[i]+count[i];
        }
        return;
    }
    
    void dfs2(int root, int parent)
    {
        for(int i:tree[root])
        {
            if(i==parent)
                continue;
            
            res[i]=res[root]-count[i]+count.size()-count[i];
            dfs2(i,root);
        }
        return;
    }
};