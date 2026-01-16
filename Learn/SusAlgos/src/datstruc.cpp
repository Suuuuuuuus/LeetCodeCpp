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
    
    UnionFind::UnionFind(int n) : m_parent(n), m_rank(n, 0) {
        for (int i = 0; i < n; ++i)
            m_parent[i] = i;
    }

    int UnionFind::find(int x) {
        if (m_parent[x] != x)
            m_parent[x] = find(m_parent[x]);
        return m_parent[x];
    }

    bool UnionFind::unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return false;

        if (m_rank[px] < m_rank[py]) {
            m_parent[px] = py;
        } else if (m_rank[px] > m_rank[py]) {
            m_parent[py] = px;
        } else {
            m_parent[py] = px;
            m_rank[px]++;
        }
        return true;
    }

    bool UnionFind::connected(int x, int y) {
        return find(x) == find(y);
    }

    Trie* Trie::searchPrefix(string prefix) {
        Trie* node = this;
        for (char ch : prefix) {
            ch -= 'a';
            if (node->m_children[ch] == nullptr) {
                return nullptr;
            }
            node = node->m_children[ch];
        }
        return node;
    }

    Trie::Trie() : m_children(26), m_isEnd(false) {}

    void Trie::insert(string word) {
        Trie* node = this;
        for (char ch : word) {
            ch -= 'a';
            if (node->m_children[ch] == nullptr) {
                node->m_children[ch] = new Trie();
            }
            node = node->m_children[ch];
        }
        node->m_isEnd = true;
    }
    
    bool Trie::search(string word) {
        Trie* node = this->searchPrefix(word);
        return node != nullptr && node->m_isEnd;
    }

    bool Trie::startsWith(string prefix) {
        return this->searchPrefix(prefix) != nullptr;
    }
}

