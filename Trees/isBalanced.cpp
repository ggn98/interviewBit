/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int height(TreeNode* A)
{
    if(A==NULL)
    return 0;
    return 1+max(height(A->left),height(A->right));
}
int Solution::isBalanced(TreeNode* A) {
    if(A==NULL)
        return 1;
    int heightOfLeft=height(A->left);
    int heightOfRight=height(A->right);
    if(abs(heightOfLeft-heightOfRight)>1)
        return 0;
    return isBalanced(A->left)*isBalanced(A->right);
}
