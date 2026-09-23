// 0 ms | 31.3 MB
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
    // this is recursive at each level spend O(logn) on two heights
    // and there are total O(logn) levels 
    // sop total time complexity is O(logn)* O(logn) = O(logn)^2
    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        int lh = findLeftHeight(root);
        int rh = findRightHeight(root);
        if(lh==rh){
            return (1<<lh)-1;
        }
        return 1+countNodes(root->left)+countNodes(root->right);
    }
    //finding leftheight takes time : O(logn)
    int findLeftHeight(TreeNode* node){
        int height=0;
        while(node){
            height++;
            node = node->left;
        }
        return height;
    }
    //finding right height takes time : O(logn)
    int findRightHeight(TreeNode*node){
        int height=0;
        while(node){
            height++;
            node=node->right;
        }
        return height;
    }
};