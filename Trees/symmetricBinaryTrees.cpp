/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int util(TreeNode* A,TreeNode* B)
{
    if(A==NULL&&B==NULL)
    return 1;
    if(A==NULL||B==NULL)
    return 0;
    if(A->val!=B->val)
    return 0;
    return util(A->left,B->right)*util(A->right,B->left);
}
int Solution::isSymmetric(TreeNode* A) {
    if(A==NULL)
    return 1;
    return util(A->left,A->right);
}
