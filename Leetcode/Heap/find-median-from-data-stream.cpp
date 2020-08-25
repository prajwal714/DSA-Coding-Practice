class MedianFinder {
public:
    /** initialize your data structure here. */
    
     priority_queue<int, vector<int> , greater<int>> highers;
     priority_queue<int> lowers;
    
    
    MedianFinder() {
      
    }
    
    void addNum(int num) {
        
        
        if(lowers.size()==0 || num<lowers.top())
            lowers.push(num);
        else
           highers.push(num);
        
        //rebalance the two heaps
        rebalanceHeap();
       
            
    }
    
    void rebalanceHeap()
    {
        int lowSize=lowers.size(), highSize=highers.size();
         if(lowSize-highSize>1)
        {
         
            highers.push(lowers.top());
            lowers.pop();
        }
        else if(highSize-lowSize>1)
        {
            
            lowers.push(highers.top());
            highers.pop();
            
        }
    }
    
    double findMedian() {
        double median=0;
        if(lowers.size()==highers.size())
        {
            median=(lowers.top()+highers.top())/2.0;
        }
        else
        {
            if(lowers.size()>highers.size())
                median=lowers.top();
            else
                median=highers.top();
        }
        
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */