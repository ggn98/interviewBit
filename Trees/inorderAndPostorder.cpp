/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
//A->inOrder , B->postOrder
//take a pointer postOrderIndex as with each call we have to decrease it's value
TreeNode* util(vector<int> &A, vector<int> &B,int start,int end,int *postOrderIndex)
{
    if(start>end)
        return NULL;
    //find this root in inorder 
    TreeNode* root=new TreeNode(B[*postOrderIndex]);
    (*postOrderIndex)--;

    //search position in Inorder and then divide the problem into left and right subProblem
    int pos;
    for(int i=start;i<=end;i++)
    {
        if(A[i]==root->val)
        {
            pos=i;
            break;
        }
    }
    
    root->right=util(A,B,pos+1,end,postOrderIndex);
    //after builduing right the postOrderIndex points to the val of 
    //root node of left subtree
    //as with each right call its value is decreased
    root->left=util(A,B,start,pos-1,postOrderIndex);
    return root;
}
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    if(A.size()==0)
    return NULL;
    int postOrderIndex=A.size()-1;
    return util(A,B,0,A.size()-1,&postOrderIndex);
}
