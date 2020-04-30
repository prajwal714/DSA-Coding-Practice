/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 bool compare(struct Interval A, struct Interval B)
 {
     return A.start<B.start;
 }
vector<Interval> Solution::merge(vector<Interval> &A) {
    
    sort(A.begin(), A.end(), compare);
    
    vector<Interval> sol;
    stack<Interval> s;
    s.push(A[0]);
    int start,end;
    for(int i=1;i<A.size();i++)
    {
        
        if(A[i].start<=s.top().end && A[i].end>s.top().end)
        {
            //merge both intervals
           
                Interval temp=s.top();
                s.pop();
                temp.end=A[i].end;
                s.push(temp);
           
        }
        else if(A[i].start<=s.top().end && A[i].end<=s.top().end)
        {
            //the next interval lies completely inside the current interval
            continue;
        }
        else
        {
            //both internvals cant be merged
            s.push(A[i]);
            
        }
        
        
        
    }
    while(!s.empty())
    {
        sol.push_back(s.top());
        s.pop();
    }
    
    reverse(sol.begin(), sol.end());
    
    return sol;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}

