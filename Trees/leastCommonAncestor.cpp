/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* util(TreeNode* root,int B,int C,bool &b1,bool &b2)
{
    if(root==NULL)
        return NULL;
    if(root->val==B)
    {
        b1=true;
        return root;
    }
    if(root->val==C)
    {
        b2=true;
        return root;
    }
    TreeNode* leftSide=util(root->left,B,C,b1,b2);
    TreeNode* rightSide=util(root->right,B,C,b1,b2);
    if(leftSide!=NULL&&rightSide!=NULL)
    return root;
    return (leftSide!=NULL)?leftSide:rightSide;
}
bool find(TreeNode* root,int val)
{
    if(root==NULL)
    return false;
    if(root->val==val)
    {
        return true;
    }
    return find(root->left,val)||find(root->right,val);
}
int Solution::lca(TreeNode* A, int B, int C) {
    bool b1,b2;
    b1=false;
    b2=false;
    TreeNode* result=util(A,B,C,b1,b2);
    if(b1&&b2||b1&&find(A,C)||b2&&find(A,B))
    {
        return result->val;
    }
    return -1;
}
