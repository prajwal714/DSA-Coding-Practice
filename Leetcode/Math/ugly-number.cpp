class Solution {
public:
    bool isUgly(int num) {
        
        int arr[]={5,3,2};
        if(num<=0)
            return false;
        
        for(int i=0;i<3;i++)
        {
           while(num%arr[i]==0)
           {
               num=num/arr[i];
           }
        }
        
        if(num>1)
            return false;
        else
        return true;
        
    }
};