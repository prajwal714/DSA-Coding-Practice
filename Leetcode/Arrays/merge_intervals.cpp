class Solution {
public:
   
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> res;
        int n=intervals.size();
        if(n<2)
            return intervals;
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){return a[0]<b[0];});
        res.push_back(intervals[0]);
        
        for(int i=1;i<n;i++)
        {
            if(res.back()[1]<intervals[i][0])
                res.push_back(intervals[i]);
            else
                res.back()[1]=max(res.back()[1], intervals[i][1]);
        }
        
        return res;
        
    }
};

//complexity O(nlogn) and space: O(1)

//==========facebook followup question, how do we handle case where their is a stream of intervals========

class IntervalTree{
public:
    int middle;
    int start, end;
    IntervalTree *left, *right;
    IntervalTree(int s, int e): start(s), end(e), middle((s+e)/2){
        this->left=this->right=NULL;
    }
};

void InsertInterval(IntervalTree *node, Interval ¤tInterval){
if(node == NULL)
    return;

if(currentInterval.end<node->middle){
    if(node->left)
        return InsertInterval(node->left, currentInterval);
    else{
        IntervalTree *newnode = new IntervalTree(currentInterval.start, currentInterval.end);
        node->left = newnode;
        return;
    }
}

if(currentInterval.start>node->middle){
    if(node->right)
        return InsertInterval(node->right, currentInterval);
    else{
        IntervalTree *newnode = new IntervalTree(currentInterval.start, currentInterval.end);
        node->right = newnode;
        return;
    }
}

//insert it to current node
node->start=min(node->start, currentInterval.start);
node->end=max(node->end, currentInterval.end);
}

So, when you want to merge the intervals, you will do something like below:

void QueryInterval(vector<Interval> &retV, IntervalTree *node){
//retV is the return vector
vector<Interval> leftIntervals;
vector<Interval> rightIntervals;

bool mergeleft = false; //whether current node merge with any intervals from left child. 
if(node->left){
    //return the merge of all intervals in left child. 
    QueryInterval(leftIntervals, node->left);
    //merge left interval with myself. 
    MergeLeftInterval(leftIntervals, node, retV, mergeleft);
}
if(!mergeleft){ //if we did not merge left intervals, add a new one
    Interval newinterval;
    newinterval.start = node->start;
    newinterval.end = node->end;
    retV.push_back(newinterval);
}

if(node->right){
    QueryInterval(rightIntervals, node->right);
    MergeRightInterval(rightIntervals, node, retV);
}

return;
}

And finally, the 2 child functions used above:

void MergeLeftInterval(vector<Interval> &leftIntervals, IntervalTree *node, vector<Interval> &retV, bool &merged){
for(int i=0; i<leftIntervals.size(); i++){
    if(leftIntervals[i].end>=node->start){
        Interval newinterval;
        newinterval.start = min(leftIntervals[i].start, node->start);
        newinterval.end = node->end;
        retV.push_back(newinterval);
        merged = true;
        break;
    }
    else{
        retV.push_back(leftIntervals[i]);
    }
}
}

void MergeRightInterval(vector &rightIntervals, IntervalTree *node, vector &retV){
for(int i=0; i<rightIntervals.size(); i++){
if(rightIntervals[i].start<=node->end){
retV[retV.size()-1].end = max(rightIntervals[i].end, node->end);
}
else{
retV.push_back(rightIntervals[i]);
}
}
}
