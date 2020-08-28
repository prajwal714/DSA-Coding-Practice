class RandomizedSet {
public:
    /** Initialize your data structure here. */
    
    unordered_map<int,list<int>::iterator> mp;
    list<int> s;
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(mp.find(val)!=mp.end())
            return false;
        
        s.push_front(val);
        mp[val]=s.begin();
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(mp.size()==0 || mp.find(val)==mp.end())
            return false;
        
        s.erase(mp[val]);
        mp.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        
       auto it=mp.begin();
       advance(it, rand()%mp.size());
        
        return it->first;
        
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 * 
 * this is just a testing typing for wakatime
 */