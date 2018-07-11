/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::invertTree(TreeNode* A) {
    if(A==NULL)
    return A;
    TreeNode* leftSide=A->left;
    A->left=invertTree(A->right);
    A->right=invertTree(leftSide);
    return A;
}
