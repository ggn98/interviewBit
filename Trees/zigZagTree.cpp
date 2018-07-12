/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    vector<vector<int> > result;
    stack<TreeNode* > left2right;
    stack<TreeNode* > right2left;
    left2right.push(A);
    bool  leftToRight=true;
    bool  RightToLeft=false;
    while(1)
    {
        if(leftToRight)
        {
            vector<int> row;
            while(left2right.empty()!=true)
            {
                TreeNode* temp=left2right.top();
                left2right.pop();
                row.push_back(temp->val);
                if(temp->left)
                {
                    right2left.push(temp->left);
                }
                if(temp->right)
                {
                    right2left.push(temp->right);
                }
            }
            result.push_back(row);
            if(right2left.empty())
                return result;
            RightToLeft=true;
            leftToRight=false; // do this to use else if , if only using IF instead of ELSE-IF
                                //no need of this leftToRight=false;
        }
        else if(RightToLeft)
        {
            vector<int> row;
            while(right2left.empty()!=true)
            {
                TreeNode* temp=right2left.top();
                right2left.pop();
                row.push_back(temp->val);
                if(temp->right)
                {
                    left2right.push(temp->right);
                }
                if(temp->left)
                {
                    left2right.push(temp->left);
                }
            }
            result.push_back(row);
            if(left2right.empty())
                return result;
            leftToRight=true;
            RightToLeft=false; // do this to use else if , if only using IF instead of ELSE-IF
                                //no need of this RightToLeft=false;
        }
    }
    return result;
}
