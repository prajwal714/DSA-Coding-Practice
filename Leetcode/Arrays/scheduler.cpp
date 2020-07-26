class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mp;
        
        int i,size=tasks.size();
        int count=0, countOfMaxTasks=0;
        for(i=0;i<size;i++)
        {
            mp[tasks[i]]++;
            
            if(mp[tasks[i]]==count)
                countOfMaxTasks++;
                
          
            else if(count<mp[tasks[i]])
            {
                count=mp[tasks[i]];
                countOfMaxTasks=1;
            }
            
        }
        
        int partCount=count-1;
        int partSize=n-(countOfMaxTasks-1);
        int emptySlots=partCount*partSize;
        int availableTasks=size-count*countOfMaxTasks;
        int idles=max(0, emptySlots-availableTasks);
        
        return size+idles;
    }
};
