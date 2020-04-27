int Solution::maxSpecialProduct(vector<int> &arr) {
    
    vector<long long int> left_max,right_max;
    stack< pair<int,int>> s;
    
    
    
    int i;
    for(i=0;i<arr.size();i++)
    {
        if(s.empty())
        left_max.push_back(0);
        
        else if(s.top().first>arr[i])
        left_max.push_back(s.top().second);
        
        else if(s.top().first<=arr[i])
        {
            while(!s.empty()&&s.top().first<=arr[i])
            {
                s.pop();
            }
            if(s.empty())
            left_max.push_back(0);
            else
            left_max.push_back(s.top().second);
        }
        
        s.push(make_pair(arr[i],i));
    }
    
    while(!s.empty())
    s.pop();
    
    
    for(i=arr.size()-1;i>=0;i--)
    {
        if(s.empty())
        right_max.push_back(0);
        
        else if(s.top().first>arr[i])
        right_max.push_back(s.top().second);
        
        else if(s.top().first<=arr[i])
        {
            while(!s.empty()&&s.top().first<=arr[i])
            {
                s.pop();
            }
            if(s.empty())
            right_max.push_back(0);
            else
            right_max.push_back(s.top().second);
        }
        
        s.push(make_pair(arr[i],i));
    }
    reverse(right_max.begin(), right_max.end());
    
    long long int res=INT_MIN;
    for(i=0;i<arr.size();i++)
    {
        res=max(res,((left_max[i])*(right_max[i])));
    }
    return (int)(res%1000000007);
}
