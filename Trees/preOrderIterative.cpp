/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::preorderTraversal(TreeNode* A) {
    stack<TreeNode* > s;
    s.push(A);
    vector<int> res;
    while(s.empty()!=true)
    {
        TreeNode* temp=s.top();
        s.pop();
        res.push_back(temp->val);
        //push right node then left as from stack pop is from top
        if(temp->right!=NULL)
        {
            s.push(temp->right);
        }
        if(temp->left!=NULL)
        {
            s.push(temp->left);
        }
    }
    return res;
}
