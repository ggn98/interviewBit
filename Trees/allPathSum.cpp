/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    vector<vector<int> > result;
    if(A==NULL)
    {
       return result; 
    }
    if(A->val==B&&A->left==NULL&&A->right==NULL) //if this is a leaf node with the required sum 
    {
        vector<int> a;
        a.push_back(A->val);
        result.push_back(a);
        return result;
    }
    vector<vector<int> > leftPath=pathSum(A->left,B-A->val); //all the left paths vectors , with required sum i.e sum-rootVal
    vector<vector<int> > rightPath=pathSum(A->right,B-A->val);//all the right paths vectors , with required sum i.e sum-rootVal
    if(leftPath.size()!=0) //there are some paths in left
    {
        for(int i=0;i<leftPath.size();i++)
        {
            leftPath[i].insert(leftPath[i].begin(),A->val); //append the root value at front of each leftPath
            result.push_back(leftPath[i]);//include this path in final result
        }
    }
    if(rightPath.size()!=0) //there are some paths in right
    {
        for(int i=0;i<rightPath.size();i++)
        {
            rightPath[i].insert(rightPath[i].begin(),A->val);//append the root value at front of each rightPath
            result.push_back(rightPath[i]);//include this path in final result
        }
    }
    return result;
}
