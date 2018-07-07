/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::inorderTraversal(TreeNode* root) {
    stack<TreeNode* > s;
    TreeNode* currNode;
    currNode=root;
    vector<int> result;
    
    if(currNode==NULL)
        return result;
        
    while(s.empty()!=true||currNode!=NULL)
    //it can happen that cuurNode is not a null node
    //but stack is empty
    //in that case also we want to enter into the while loop
    //ex-  1
    //    / \ 
    //   2   3 --> when we come to 3 i.e set currNode as 3 , stack is empty but still we want to continue 
    {
        if(currNode!=NULL)
        {
            s.push(currNode);
            currNode=currNode->left;
        }
        else
        {
            TreeNode* temp=s.top();
            result.push_back(temp->val);
            s.pop();
            currNode=temp->right;
            //go to the right subtree of node found
            //if no right subtree
            //then this else part is executed again and next element is popped out
        }
    }
    return result;
}
