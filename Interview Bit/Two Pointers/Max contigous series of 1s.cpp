vector<int> Solution::maxone(vector<int> &A, int B) {
    
    int wl = 0;
int wr = 0;
int zeroCount = 0;
int bestLeft;
int bestRight;
int maxValue = INT_MIN;
while(wr < A.size())
{
if(zeroCount<=B)
{
if(A[wr] == 0)
{
zeroCount++;
}
wr++;
}
else if(zeroCount>B)
{
if(A[wl]==0)
{
zeroCount--;
}
wl++;
}
if(((wr - wl) > maxValue) && (zeroCount<=B))
{
maxValue = wr - wl;
bestLeft = wl;
bestRight = wr;
}
}
vector<int> v;
for(int i=bestLeft;i<bestRight;i++)
{
v.push_back(i);
}
return v;
}
    
    


