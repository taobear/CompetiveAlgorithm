#include "Traversal.h"

#include <stack>

using namespace std;

void preOrder(TreeNode *root, vector<int> &nums)
{
    stack<TreeNode *> stk;

    TreeNode *node = root;

    // while (node != nullptr || !stk.empty()) {
    //     while (node != nullptr) {
    //         stk.push(node);
    //         nums.push_back(node->value);
    //         node = node->left;   
    //     }

    //     if (!stk.empty()) {
    //         node = stk.top();
    //         stk.pop();
    //         node = node->right;
    //     }
    // }

    // if (root == nullptr) {
    //     return;
    // }

    // nums.push_back(root->value);
    // preOrder(root->left, nums);
    // preOrder(root->right, nums);

    stk.push(node);
    while (!stk.empty()) {
        node = stk.top();
        stk.pop();

        nums.push_back(node->value);

        if (node->right) stk.push(node->right);
        if (node->left) stk.push(node->left);
    }
}