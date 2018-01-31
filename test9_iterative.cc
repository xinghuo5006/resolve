/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> ans;
        stack<TreeNode*> sta;
        //insert root in vector
        if (root ==NULL)
            return {};
        //ans.push_back(root->val);
        //sta.push(root);
        TreeNode * temp  =root;
        while(!sta.empty() || temp!=NULL)
        {
            while(temp!=NULL)
            {
                ans.push_back(temp->val);
                sta.push(temp);
                temp = temp->left;
            }
            if(!sta.empty())
            {
             temp = sta.top();
             sta.pop();
             temp = temp->right;
            }
            
        }
        return ans;
    }
};
