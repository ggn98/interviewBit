/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
stack<TreeNode *> path;
void push(TreeNode* root)
{
    while(root)
    {
        path.push(root);
        root=root->left;
    }
}
BSTIterator::BSTIterator(TreeNode *root) {
    push(root);
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    return path.empty()?false:true;
}

/** @return the next smallest number */
int BSTIterator::next() {
    TreeNode* temp=path.top();
    path.pop();
    push(temp->right);
    return temp->val;
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
