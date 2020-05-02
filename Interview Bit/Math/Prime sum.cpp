
bool isprime(int n)
{
for(int i=2; i*i<=n; i++)
if(n%i==0) return 0;
return 1;
}
vector<int> Solution::primesum(int A) {
vector <int> v;
for(int i=2; i<=A/2; i++)
if(isprime(i) && isprime(A-i))
v.push_back(i),v.push_back(A-i),i=A;
return v;
}
