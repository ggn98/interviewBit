/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int maxVal(TreeNode* root)
{
    if(root==NULL)
        return INT_MIN;
    int leftMin=maxVal(root->left);
    int rightMin=maxVal(root->right);
    return max(max(leftMin,rightMin),root->val);
}
int minVal(TreeNode* root)
{
    if(root==NULL)
        return INT_MAX;
    int leftMin=minVal(root->left);
    int rightMin=minVal(root->right);
    return min(min(leftMin,rightMin),root->val);
}
//for finding min and max ,we cant assume that the left and right subtree
//are BST , as swapping might be there within these subtrees
//Hence while finding min/max we do searching like Binary tree not like BST
vector<int> Solution::recoverTree(TreeNode* A) 
{
    vector<int> ans,left,right;
    if(A==NULL)
        return ans;
    int maxValueLeft=maxVal(A->left);
    int minValueRight=minVal(A->right);
    if(maxValueLeft>minValueRight)
    {
        ans.push_back(minValueRight);
        ans.push_back(maxValueLeft);
        return ans;
    }
    else
    {
        if(maxValueLeft>A->val)
        {
            ans.push_back(A->val);
            ans.push_back(maxValueLeft);
            return ans;
        }
        if(minValueRight<A->val)
        {
            ans.push_back(minValueRight);
            ans.push_back(A->val);
            return ans;
        }
    }
    
    left=recoverTree(A->left);
    if(left.size()==2)
    {
        return left;
    }
    
    return recoverTree(A->right);
}
