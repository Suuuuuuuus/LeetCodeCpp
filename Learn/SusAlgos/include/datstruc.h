#pragma once
#include <vector>

namespace susalgos {

    struct ListNode {
        int val;
        ListNode* next;

        ListNode() : val(0), next(nullptr) {}
        explicit ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode* nextNode) 
            : val(x), next(nextNode) {}
    };

    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;

        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode* left_node, TreeNode* right_node) 
            : val(x), left(left_node), right(right_node) {}
    };

    void tree_preorder(const TreeNode* root, std::vector<int>& res);
    void tree_inorder(const TreeNode* root, std::vector<int>& res);
    void tree_postorder(const TreeNode* root, std::vector<int>& res);
    std::vector<int> tree_preorder_traversal(const TreeNode* root);
    std::vector<int> tree_inorder_traversal(const TreeNode* root);
    std::vector<int> tree_postorder_traversal(const TreeNode* root);
    
    class UnionFind {
    private:
        std::vector<int> m_parent;
        std::vector<int> m_rank;

    public:
        explicit UnionFind(int n);

        int find(int x);
        bool unite(int x, int y);
        bool connected(int x, int y);
    };
}