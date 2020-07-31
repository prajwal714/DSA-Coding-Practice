#include<bits/stdc++.h>
using namespace std;

int main()
{

}

int goal;
int min=INT_MAX;

void closestValue(TreeNode* root, int target){

    if(root==NULL)
    return;

    if(abs(target-root->val<min))
    {
        min=abs(target-root->val);
        goal=root->val;
    }

    if(target<root->val)
    closestValue(root->left, target);
    else
    {
        closestValue(root->right, target);
    }
    
  
}

