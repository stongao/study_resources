// Source : leetcode https://leetcode.com/problems/binary-tree-right-side-view/
// Date : 2/21/2017
// Time : ~15min
// Errors: 1. Didn't mind NULL case
//          2. Didn't mind END case




class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> ret;
        if(root == NULL) {
            return ret;
        }
        q.push(root);
        q.push(NULL);
        TreeNode *temp;
        
        while(q.empty() != true) {
            temp = q.front();
            q.pop();
            if(temp->left != NULL) {
                q.push(temp->left);
            }
            if(temp->right != NULL) {
                q.push(temp->right);
            }
            if(q.front() == NULL) {
                ret.push_back(temp->val);
                q.pop();
                if(q.empty != true) {
                    q.push(NULL);
                }
            }
        }
        return ret;
    }
};
