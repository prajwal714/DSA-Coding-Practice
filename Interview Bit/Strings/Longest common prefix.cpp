string Solution::longestCommonPrefix(vector<string> &A) {
    
  string current=A[0];
  int min=INT_MAX;
  
  int i,j;
  
      for(j=1;j<A.size();j++)
     {
         int k=0;
         while(current[k]==A[j][k] && k<current.length()&&k<A[j].length())
         {
             k++;
         }
         
         if(k<min)
         min=k;
         
     }
     
     string res=current.substr(0,min);
     return res;
 
}

