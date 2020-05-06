int Solution::removeDuplicates(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int count=0;
    A.push_back(-1);
    int n=A.size();
    int i;
    int index=0;
   
    for(i=0;i<n-1;i++)
    {
        
        while(A[i]==A[i+1])
        {
            i++;
        }
        
        count++;
        A[index++]=A[i];
    }
    A.resize(count);
    return count;
}


===============================================================================

int count=0;

int n=A.size();

for(i=0;i<n;i++)
{
	if(i<n-1 &&A[i]==A[i+1])
	continue;
	
	else
	{
		A[count]=A[i];
		count++;
	}
}

return count;
