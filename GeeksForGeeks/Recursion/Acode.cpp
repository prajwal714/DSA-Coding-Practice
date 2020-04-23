/*given a string of numbers 123434 non zero values, we have to output all the possible
 alphabetical equivalents it can have, such that 1--> A, 2-->B, .... 26--> Z */
#include<bits/stdc++.h>
 using namespace std;

void findStrings(string a, string out)
{
    cout<<a<<"-->"<<out<<endl;
    //base case
    if(a.length()==0){
        
        cout<<out<<endl;
        return;
    }

    //recursive case
    //include single char

    int digit=a[0]-'0';
    char ch=digit + ('A'-1); //char corresponding to digit
    out+=ch;

    findStrings(a.substr(1), out);



    //include 2 characters
    if(a.length()>1)
    {
        int second_digit=a[0]-'0';
        int num=10*digit+second_digit;

        if(num<=26)
        {
        ch=num+('A'-1);
        out+=ch;
        findStrings(a.substr(2), out);

        }
    }
    
}
int main()
 {
     string st;
     cout<<"Enter the sequence: "<<endl;
     cin>>st;

     string out="";

     findStrings(st, out);


 }