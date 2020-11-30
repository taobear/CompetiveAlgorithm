#include "Tree.h"

#include <new>

TreeNode* build(const std::vector<int> &input)
{
    if (input.empty()) {
        return nullptr;
    }

    TreeNode *root = nullptr;
    for (auto e : input) {
        root = insert(root, e);
    }

    return root;
}

TreeNode* insert(TreeNode *root, int val)
{
    if (root == nullptr) {
        return new TreeNode(val);
    }

    if (root->value < val) {
        root->right = insert(root->right, val);
    } else {
        root->left = insert(root->left, val);
    }

    return root;
}


void destroy(TreeNode *root)
{
    if (root == nullptr) {
        return;
    }

    destroy(root->left);
    destroy(root->right);

    delete(root);
}