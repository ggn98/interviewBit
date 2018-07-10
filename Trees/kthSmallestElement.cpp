/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void inOrderTraversal(TreeNode* root,vector<int> &inorder)
{
    if(root==NULL)
        return ;
    inOrderTraversal(root->left,inorder);
    inorder.push_back(root->val);
    inOrderTraversal(root->right,inorder);
}
int Solution::kthsmallest(TreeNode* root, int k) {
    vector<int> inorder;
    inOrderTraversal(root,inorder);
    for(int i=0;i<inorder.size();i++)
    {
        if(i==k-1)
            return inorder[i];
    }
}
