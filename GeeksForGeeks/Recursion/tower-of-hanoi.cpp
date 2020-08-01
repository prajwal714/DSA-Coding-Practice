#include<bits/stdc++.h>
using namespace std;
void solve(int,int,int,int);
int main()
{
    int n=5;
    solve(1,3,2,n);
}

void solve(int s, int d, int h, int n)
{
    //base condition, when their is single plate in s, we movie it simply to dest
    if(n==1)
    {
        cout<<"Moving Plate "<<n<<" From "<<s<<" to "<<d<<endl;
        return;
    }

    //induction step, we first move ni1 plates from src to helper
    solve(s,h,d,n-1);
    //then we put the remaining 1 plate to des
        cout<<"Moving Plate "<<n<<" From "<<s<<" to "<<d<<endl;
    //then we put the n-1 plate to dest from helper
    solve(h,d,s,n-1);

    return;
}
