/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
//This is O(N) space complexity solution 
//will update on understandind constant time solution
//it gets accepted though :P 
void Solution::connect(TreeLinkNode* root) {
    queue<TreeLinkNode* > q;
    q.push(root);
    q.push(NULL);
    while(q.empty()!=true)
    {
        root=q.front();
        q.pop();
        if(root!=NULL)
            root->next=q.front();
        if(root&&root->left)
        {
            q.push(root->left);
        }
        if(root&&root->right)
        {
            q.push(root->right);
        }
        if(root==NULL)
        {
            if(q.empty()!=true)
            {
                q.push(NULL);
            }
        }
    }
}
