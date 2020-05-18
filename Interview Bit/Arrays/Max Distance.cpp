int Solution::maximumGap(const vector<int> &A) {
   int n = A.size();
if(n==1)
return 0;
vector<pair<int, int>> ans;

//vector pair is made so that we dont lose original index after sorting of array
//make vector pair to store key and value
for(int i=0;i<n;i++){
    ans.push_back(make_pair(A[i], i));
}

//sort vector pair based on value
sort(ans.begin(), ans.end());

//create array to find max index from i to n
int max_index[n];
int mx = INT_MIN;
for(int i=n-1;i>=0;i--){
    mx = max(mx, ans[i].second);
    max_index[i] = mx;
}

//iterate vector pair and find max index from i to n
int mil_gaya = INT_MIN;
for(int i=0;i<n-1;i++){
    mil_gaya = max(mil_gaya, max_index[i] - ans[i].second);
}
return mil_gaya;
}

