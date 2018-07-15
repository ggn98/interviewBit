/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int sum(TreeNode* root,int val)//maintain a value till you reach leaf node
{
    if(root==NULL)
        return 0;
        
    val = ( (val*10)%1003 +root->val)%1003; //update value as root is not null
    //while multiplying esisting value with 10 , it can exceed int range hence use mod
    if(root->left==NULL&&root->right==NULL) //it means we have reached a leaf node , return back this val
    {
        return val;
    }
    //use mod with each sum as each one could exceed int range
    //use mod with overall result as addition of the 2 halves may lead to overflow
    return (sum(root->left,val)%1003 + sum(root->right,val)%1003)%1003;
}
int Solution::sumNumbers(TreeNode* A) {
    return sum(A,0);
}
