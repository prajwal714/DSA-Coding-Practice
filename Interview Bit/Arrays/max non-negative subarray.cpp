vector<int> Solution::maxset(vector<int> &A) {
    
   
    vector <int> sol;
    long long int max=0;
    int min_index=A.size();
    int start=0;
    
    long long int sum=0;
    int i,j;
    int begin=-1,end=-1;
    int size=-1;
    for(i=0;i<A.size();i++)
    {
        if(A[i]<0)
        continue;
        
         
        if(A[i]>=0)
        start=i;
        while(A[i]>=0&&i<A.size())
        {
            sum+=A[i];
            
            i++;

        }
        
        
        if(sum>max)
        {
            
            max=sum;
            begin=start;
            end=i;
            size=(end-begin);
            sum=0;
            
            
        }
        else if(sum==max)
        {
            // max=sum;
            sum=0;
            if((i-start)>size)
            {
                size=(i-start);
                begin=start;
                end=i;
                
            }
                //if both solution size is same
             else if(start<begin)
                {
                    begin=start;
                    end=i;
                }
            
            
           
            }
            else
            sum=0;
           
            
            
    }
    for(i=begin;i<end;i++)
    sol.push_back(A[i]);
    
    return sol;
    
}

