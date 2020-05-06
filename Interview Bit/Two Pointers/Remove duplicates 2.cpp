int Solution::removeDuplicates(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int count=0;
    int n=A.size();
    
    int index=0;
    for(int i=0;i<n;i++)
    {
        int length=1;
       while(i<n-1 && A[i]==A[i+1])
       {
           length++;
           i++;
       }
       if(length>=2)
       {
           A[count++]=A[i];
           A[count++]=A[i];
       }
       else
       A[count++]=A[i];
    }
    
    return count;
    
    
}

========================================================================================

class Solution {
    public:
        int removeDuplicates(int A[], int n) {
            int count = 0;
            for (int i = 0; i < n; i++) { 
                if (i < n - 2 && A[i] == A[i+1] && A[i] == A[i+2]) continue;
                else {
                    A[count] = A[i];
                    count++;
                }
            }
            return count;
        }  
};
