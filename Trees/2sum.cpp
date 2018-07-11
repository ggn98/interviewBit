/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::t2Sum(TreeNode* root, int B) {
    stack<TreeNode* > normal;
    stack<TreeNode* > reverse;
    TreeNode* left1=root;
    TreeNode* right1=root;
    bool done1=false;
    bool done2=false;
    int val1,val2;
    while(1)
    {
        while(done1==false)
        {
           if(left1!=NULL)
           {
               while(left1)
                {
                    normal.push(left1);
                    left1=left1->left;
                } 
           }
            else
            {
                if(normal.empty())
                    done1=true;
                else
                {
                    left1=normal.top();
                    normal.pop();
                    val1=left1->val;
                    left1=left1->right;
                    done1=true;
                }
            }
        }
        while(done2==false)
        {
           if(right1!=NULL)
           {
               while(right1)
                {
                    reverse.push(right1);
                    right1=right1->right;
                } 
           }
            else
            {
                if(reverse.empty())
                    done2=true;
                else
                {
                    right1=reverse.top();
                    reverse.pop();
                    val2=right1->val;
                    right1=right1->left;
                    done2=true;
                }
            }
        }
        if(val1!=val2&&val1+val2==B)
        return true;
        else if(val1+val2<B)
        {
            done1=false;
        }
        else if(val1+val2>B)
        {
            done2=false;
        }
        if(val1>=val2)
        {
            return false;
        }
}
}
