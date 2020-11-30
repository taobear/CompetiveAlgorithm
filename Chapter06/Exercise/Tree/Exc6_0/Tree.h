#ifndef __TREE_H_
#define __TREE_H_

#include <vector>

struct TreeNode {
    TreeNode(const int val) : value(val) 
    { left = nullptr; right = nullptr; }

    TreeNode* left;
    TreeNode* right;
    int value;
};

TreeNode* build(const std::vector<int> &input);

TreeNode* insert(TreeNode *root, int value);

void destroy(TreeNode *root);

#endif