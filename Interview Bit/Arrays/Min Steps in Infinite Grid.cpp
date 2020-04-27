int Solution::coverPoints(vector<int> &A, vector<int> &B) {
    
    int step=0;
    int i,j;
    
    int startX=A[0];
    int startY=B[0];
    for(i=0;i<A.size()-1;i++){
        
        step+=max(abs(A[i+1]-A[i]),abs(B[i+1]-B[i]));
    }
    return step;
}
