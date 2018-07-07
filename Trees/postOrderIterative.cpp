/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::postorderTraversal(TreeNode* A) {
    /*
    TreeNode* root;
    root=A;
    vector<int> result;
    if(A==NULL)
    return result;
    stack<TreeNode* > s;
    do
    {
        //push root's right and root to the stack and make root=root->left till root!=NULL
        while(root)
        {
            if(root->right)
            {
                s.push(root->right);
            }
            s.push(root);
            
            root=root->left;
        }
        root=s.top();
        s.pop();
        //check if there is a right child of the top element of stack i.e root
        //and if it is there then check whether it is at the top
        //if it is at the top , it means that the right subtree of this root is still unvisited
        //in such a case we push the root back into stack after popping out the top element i.e its unvisited right half
        //make the root as this right subtree and then continue to push it's right child and itself in the stack
        //done in the upper while loop
        if(root->right &&root->right==s.top())
        {
            s.pop();
            s.push(root);
            root=root->right;
        }
        else 
        //it means that right half of this node is already explored so it means left is explored
        //right is explored so it is the turn of this node
        //set the root as null so that in next iteration top element is popped
        {
            result.push_back(root->val);
            root=NULL;
        }
    }
    while(s.empty()!=true);
    return result;
    Geeks for geeks solution doesn't work ,segmenetaion fault will update on figuring out :(
    */
    //Alternative appproach
    //postorder is LEFT/RIGHT/ROOT , now since like iterative preorder 
    //we can find ROOT/RIGHT/LEFT
    //ans then reverse the result obtained to get LEFT/RIGHT/ROOT
    stack<TreeNode* > s;
    vector<int> result;
    if(A==NULL)
    return result;
    s.push(A);
    while(s.empty()!=true)
    {
        TreeNode* temp=s.top();
        s.pop();
        result.push_back(temp->val);
        // since we want root , right , left , push left first then right
        //so that after root we get it's right
        if(temp->left!=NULL)
        {
            s.push(temp->left);
        }
        if(temp->right!=NULL)
        {
            s.push(temp->right);
        }
    }
    reverse(result.begin(),result.end());
    return result;
}
