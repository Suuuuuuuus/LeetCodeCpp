#include "datstruc.h"
#include <iostream>
#include <vector>

using namespace std;

namespace susalgos {

    void tree_preorder(const TreeNode* root, vector<int>& res) {
        if (root == nullptr) {
            return;
        }
        res.push_back(root->val);
        tree_preorder(root->left, res);
        tree_preorder(root->right, res);
    }

    void tree_inorder(const TreeNode* root, vector<int>& res) {
        if (root == nullptr) {
            return;
        }

        tree_inorder(root->left, res);
        res.push_back(root->val);
        tree_inorder(root->right, res);
    }

    void tree_postorder(const TreeNode* root, vector<int>& res) {
        if (root == nullptr) {
            return;
        }
        
        tree_postorder(root->left, res);
        tree_postorder(root->right, res);
        res.push_back(root->val);
    }

    vector<int> tree_preorder_traversal(const TreeNode* root) {
        vector<int> res;
        tree_preorder(root, res); 
        return res;       
    }

    vector<int> tree_inorder_traversal(const TreeNode* root) {
        vector<int> res;
        tree_inorder(root, res); 
        return res;       
    }

    vector<int> tree_postorder_traversal(const TreeNode* root) {
        vector<int> res;
        tree_postorder(root, res); 
        return res;       
    }
}
