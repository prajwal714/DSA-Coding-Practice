void Solution::merge(vector<int> &A, vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
   int i = A.size() - 1, j = B.size() - 1, index = A.size() + B.size() - 1;
    A.resize(A.size() + B.size());
    while(i >= 0 and j >= 0)
        A[index--] = (A[i] > B[j]) ? A[i--] : B[j--];
    while(j >= 0)
        A[index--] = B[j--];
}

