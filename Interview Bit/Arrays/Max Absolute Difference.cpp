int Solution::maxArr(vector<int> &arr) {
    
    int i,j;
    int val;
    int max1=INT_MIN,max2=INT_MIN,max3=INT_MIN,max4=INT_MIN;
    int min1=INT_MAX,min2=INT_MAX,min3=INT_MAX,min4=INT_MAX;
    for(i=0;i<arr.size();i++)
    {
       max1=max(max1,arr[i]+i);
       max2=max(max2,arr[i]-i);
       max3=max(max3,-arr[i]+i);
       max4=max(max4,-arr[i]-i);
       
       min1=min(min1,arr[i]+i);
       min2=min(min2,arr[i]-i);
       min3=min(min3,-arr[i]+i);
       min4=min(min4, -arr[i]-i);
    }
    
    return max(max1-min1,max(max2-min2,max(max3-min3,max4-min4)));
    
    
}
