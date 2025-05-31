/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int sum=INT_MIN;
       int h= CostAtEachNode(root,sum);
        return sum;
    }
    int CostAtEachNode(TreeNode* root,int& sum){
        if(root==NULL) return 0;
        int lc=max(0,CostAtEachNode(root->left,sum));
        int rc=max(0,CostAtEachNode(root->right,sum));
        sum=max(sum,lc+rc+root->val);
        return root->val+(max(lc,rc));
    }
};