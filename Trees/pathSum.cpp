/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::hasPathSum(TreeNode* root, int B) {
    if(root==NULL)
    {
        return B==0; //as reqired sum can be 0
    }
    int sumLeft=B-root->val; //now this is the required path sum 
    if(sumLeft==0&&root->left==NULL&&root->right==NULL)//this means we are at a leaf node and the required sum is achieved
    {
        return 1;
    }
    int left=0,right=0;
    //first check that left or right exist or not
    //as if we call without checking , then we will hit the base case always
    //and some value will be returned tellling whether path sum exists or not , when actually the tree is itself not present
    //Hence check initially
    if(root->left)
    {
        if(hasPathSum(root->left,sumLeft))
            left=1;
    }
    if(root->right)
    {
        if(hasPathSum(root->right,sumLeft))
            right=1;
    }
    return left||right;
}
