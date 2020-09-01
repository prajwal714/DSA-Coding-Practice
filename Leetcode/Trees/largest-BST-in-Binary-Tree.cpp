#include<bits/stdc++.h>
using namepsace std;

struct Data {
    int size, minVal, maxVal, ans;
    bool isBST;

    Data()
    {
        size=0, minVal=0, maxVal=0;
        isBST=false;
        ans=0;
    }
};

int main()
{
    //construct Tree
    Data res=postorder(root);

    return res.ans;
}

Data postorder(Node* root)
{
    
    if(root=NULL)
    {
        return { 0, INT_MIN, INT_MAX, 0, true};
        
    }

    if(root->left==NULL && root->right==NULL)
    {
        return {1, root->val, root->val, 1, true};
    }

    Data curr=new Data();
    
    Data left=postorder(root->left);
    Data right=postorder(root->right);

    curr.size=1+left.size()+right.size();

    if(left.isBST && right.isBST && left.maxVal<root->val && right.minVal>root->val)
    {
        curr.minVal=min(root->val, min(left.minVal, right.minVal));
        curr.maxVal=max(root->val, max(right.maxVal, left.maxVal));

        curr.ans=curr.size();
        curr.isBST=true;

        return curr;

    }
    else
    {
       curr.isBST=false;
       curr.ans=max(left.size, right.size);
       return curr;
    }


}

