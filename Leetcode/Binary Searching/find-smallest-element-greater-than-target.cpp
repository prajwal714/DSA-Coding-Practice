class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        
        int n=letters.size();
        if(target>=letters[n-1] || target<letters[0])
            return letters[0];
        
       int left=0,right=n-1;
        int pos=-1;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            
            if(letters[mid]>target)
            {
                pos=mid;
                right=mid-1;
            }
            else
                left=mid+1;
        }
        
        return letters[pos];
    }
};