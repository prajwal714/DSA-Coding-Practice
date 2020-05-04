int Solution::cpFact(int a, int b) {
int i=1;
while(a/i>0){
int x=a/i;
if(i*x==a && __gcd(x,b)==1)
return x;
i++;
}
}
