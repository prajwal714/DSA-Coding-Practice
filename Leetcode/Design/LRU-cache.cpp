class LRUCache {
public:
    int capacity;
    //store the key to iterator value in LRU list
    unordered_map<int, list<int>::iterator> mp;
    //store the key, value 
    unordered_map<int, int> kv;
    //stores the LRU list, MFU(front)----LRU(back)
    list<int> lru;
    
    LRUCache(int capacity) {
        this->capacity=capacity;
    }
    
    int get(int key) {
        
        if(kv.find(key)==kv.end())
            return -1;
        
        updateLRU(key);
        return kv[key];
    }
    
    void put(int key, int value) {
        
        if(kv.size()==capacity && kv.find(key)==kv.end())
        {
            evict();
        }
        kv[key]=value;
        updateLRU(key);
    }
    
    void updateLRU(int key)
    {
        //if the key is already present
        if(mp.find(key)!=mp.end())
        {
            //we find the iterator of the key using mp[key] and erase it from the list.
            lru.erase(mp[key]);
        }
        
        //then we push front the key again in front of LRU and update the iterator value in mp[key]
        lru.push_front(key);
        mp[key]=lru.begin();
    }
    
    void evict()
    {
        //lru.back() stores the key for Least recently used item
        // we remove the LRU value from mp, kv and pop_back the value from LRU list
        mp.erase(lru.back());
        kv.erase(lru.back());
        lru.pop_back();
    }
    
    
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */