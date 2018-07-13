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
    while(root) //PUSH THE ROOT AND ALL ITS LEFT CHILD  , IF ROOT IS NULL THEN NO NEW ADDITION IN STACK
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
    //THIS WILL GET THE SMALLEST ELEMENT
    //NOW THE NEXT SMALLER ELEMENT WILL BE THE LEFTEST ELEMENT 
    //OF THE RIGHT SUBTREE OF THIS NODE
    //THIS IS LIKE ROOT , LEFT PART IS ALREADY POPPED OUT AND NOW THE ROOT IS POPPED OUT
    //NOW THE NEXT SMALLER ELEMENT AFTER THIS NODE IS THE LEFTEST ELEMENT OF RIGHT SUBTREE
    path.pop();
    push(temp->right);
    return temp->val;
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
