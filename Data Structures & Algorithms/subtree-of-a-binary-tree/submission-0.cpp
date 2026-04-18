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

    bool isIdentical(TreeNode* curr,TreeNode* subRoot){
        if(curr==NULL && subRoot==NULL) return true;
        if(curr==NULL || subRoot==NULL) return false;
        if(curr->val!=subRoot->val) return false;
        return  isIdentical(curr->right,subRoot->right) && isIdentical(curr->left,subRoot->left);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
                //now it's check if two trees are identical or not
                if(root==NULL) return false;
                if(isIdentical(root,subRoot)){
                    return true;
                }
             return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};
