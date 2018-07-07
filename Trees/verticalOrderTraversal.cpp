/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//use level order traversal
vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
    map<int,vector<int> > myMap;
    vector<vector<int> > result;
    int hd=0;
    queue<pair<TreeNode*,int> > q;
    q.push(make_pair(A,hd));
    while(q.empty()!=true)
    {
        pair<TreeNode*,int> temp=q.front();
        q.pop();
        myMap[temp.second].push_back(temp.first->val);
        hd=temp.second; //update hd as we have to push children of this node 
        if(temp.first->left)
        {
           q.push(make_pair(temp.first->left,hd-1)); //hence updating hd is required
        }
        if(temp.first->right)
        {
            q.push(make_pair(temp.first->right,hd+1)) ;//hence updating hd is required
        }
    }
    map< int,vector<int> > :: iterator it;
    for (it=myMap.begin(); it!=myMap.end(); it++)
    {
            result.push_back(it->second);
    }
    return result;
}
