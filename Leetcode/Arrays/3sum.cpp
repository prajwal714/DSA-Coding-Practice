#include<bits/stdc++.h>

using namespace std;

int main()
{
vector<int> arr={1,2,-3,4,5,-6,7};
int target=5;
  cout<<three_sum(arr,target)<<endl;
}

int three_sum(vector<int> arr, int target)
{
    int i,j,k;
    int res=INT_MAX;
    int n=arr.size();
    sort(arr.begin(), arr.end());
    for(k=n-1;k>=2;k--)
    {
        i=0;j=k-1;
        while(i<j)
        {
            int sum=arr[i]+arr[j]+arr[k];
            if(abs(target-sum)==0)
            return sum;

            if(sum<target)
            i++;
            else
            {
                j--;
            }
            

        }
    }

    return -1;
}