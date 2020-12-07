#include "Traversal.h"

#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

void postOrder(TreeNode *root, vector<int> &nums)
{
    // TreeNode *node;
    // stack<TreeNode *> stk;

    // stk.push(root);
    // while (!stk.empty()) {
    //     node = stk.top();
    //     stk.pop();

    //     nums.push_back(node->value);

    //     if (node->left) stk.push(node->left);
    //     if (node->right) stk.push(node->right);
    // }

    // reverse(nums.begin(), nums.end());

    TreeNode *node = root;
    TreeNode *lastVisit = root;
    stack<TreeNode *> stk;

    while (node != nullptr || !stk.empty()) {
        while (node != nullptr) {
            stk.push(node);
            node = node->left;
        }

        node = stk.top();
        if (node->right == nullptr || node->right == lastVisit) {
            nums.push_back(node->value);
            stk.pop();
            lastVisit = node;
            node = nullptr;
        } else {
            node = node->right;
        }
    }

}