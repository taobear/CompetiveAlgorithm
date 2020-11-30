#include "Traversal.h"

#include <stack>

using namespace std;

void inOrder(TreeNode* root, vector<int>& nums)
{
    stack<TreeNode *> stk;

    TreeNode *node = root;
    while (node != nullptr || !stk.empty()) {
        while (node != nullptr) {
            stk.push(node);
            node = node->left;
        }

        if (!stk.empty()) {
            node = stk.top();
            stk.pop();
            nums.push_back(node->value);
            node = node->right;
        }
    }
}