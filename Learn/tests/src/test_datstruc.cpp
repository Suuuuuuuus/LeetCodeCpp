#include <iostream>
#include <vector>
#include "datstruc.h"
#include "print.h"

using namespace std;
using namespace susalgos;
using namespace susprint;

int main() {
    cout << ">>>Testing data structures:" << endl;

    cout << "+++Testing TreeNode:" << endl;
    vector<int> x{1,2,3};
    print_numeric_array(x);

    TreeNode node6(6);
    TreeNode node7(7);
    TreeNode node9(9);
    TreeNode node4(4);
    TreeNode node5(5, &node6, &node7);
    TreeNode node2(2, &node4, &node5);
    TreeNode node8(8, &node9, nullptr);
    TreeNode node3(3, nullptr, &node8);
    TreeNode node1(1, &node2, &node3);

    cout << "Preorder Traversal:" << endl;
    vector<int> preorder_res = tree_preorder_traversal(&node1);
    print_numeric_array(preorder_res);
    cout << "Inorder Traversal:" << endl;
    vector<int> inorder_res = tree_inorder_traversal(&node1);
    print_numeric_array(inorder_res);
    cout << "Postorder Traversal:" << endl;
    vector<int> postorder_res = tree_postorder_traversal(&node1);
    print_numeric_array(postorder_res);
    cout << "TreeNode works!" << endl;

    ListNode first(1);
    ListNode second(1, &first);
    cout << "ListNode works!" << endl;

    cout << "+++Testing UnionFind:" << endl;
    vector<vector<int>> isConnected{{1,1,0}, {1,1,0}, {0,0,1}};
    int n = isConnected.size();
    int count = 0;
    UnionFind uf(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (isConnected[i][j] == 1) {
                count += uf.unite(i, j);
            }
        }
    }
    cout << "LeetCode 547: " << (n - count) << " different circles" << endl;

    cout << ">>>Finished!" << endl;
    return 0;
}
