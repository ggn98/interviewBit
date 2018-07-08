/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int findMaxIndex(vector<int> &A,int start,int end)
{
    int maxPos;
    int max=INT_MIN;
    for(int i=start;i<=end;i++)
    {
        if(A[i]>max)
        {
            max=A[i];
            maxPos=i;
        }
    }
    return maxPos;
}
TreeNode* buildTreeUtil(vector<int> &A,int start,int end)
{
    if(start>end)
        return NULL;
    int indexOfMax=findMaxIndex(A,start,end);
    TreeNode *root=new TreeNode(A[indexOfMax]);
    root->left=buildTreeUtil(A,start,indexOfMax-1);
    root->right=buildTreeUtil(A,indexOfMax+1,end);
    return root;
}
TreeNode* Solution::buildTree(vector<int> &A) {
    if(A.size()==0)
        return NULL;
    return buildTreeUtil(A,0,A.size()-1);
}
//get the maximum node , this will act as root elemennt
//now recursively do the same in left and right half of this max element
//set the left half as left subtree and the right half as right subtree
