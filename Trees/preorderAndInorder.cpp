/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* util(vector<int> &A, vector<int> &B,int start,int end,int *preOrderIndex)
{
    if(start>end)
        return NULL;

    TreeNode* root=new TreeNode(B[*preOrderIndex]);
    (*preOrderIndex)++;

    int pos;
    for(int i=start;i<=end;i++)
    {
        if(A[i]==root->val)
        {
            pos=i;
            break;
        }
    }
    root->left=util(A,B,start,pos-1,preOrderIndex);
    root->right=util(A,B,pos+1,end,preOrderIndex);

    return root;
}
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    if(A.size()==0)
    return NULL;
    int preOrderIndex=0;
    return util(B,A,0,A.size()-1,&preOrderIndex);
}
