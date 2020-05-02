int Solution::isPalindrome(int A) {

string s = to_string(A);

int l=0,r=s.size()-1;

while(l<r)
{
    if(s.at(l) != s.at(r))return 0;
    
    l++;r--;
}

return 1;
}
