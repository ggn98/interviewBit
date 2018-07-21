/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void inOrderTraversal(TreeNode* root,int k,int &count,int &ans)
{
    if(root==NULL)
        return ;
    inOrderTraversal(root->left,k,count,ans);
    count++;
    //each time an element is hot during inorder traversal we incremement the count
    //if count becomes equal to k then it means this is the required element
    if(count==k)
    {
        ans=root->val;
        return ;
    }
    inOrderTraversal(root->right,k,count,ans);
}
int Solution::kthsmallest(TreeNode* root, int k) {
    int count=0,ans;
    inOrderTraversal(root,k,count,ans);
    return ans;
}
