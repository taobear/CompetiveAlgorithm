#ifndef __TRAVERSAL_H_
#define __TRAVERSAL_H_

#include "Tree.h"

void preOrder(TreeNode *root, std::vector<int> &nums);

void inOrder(TreeNode* root, std::vector<int>& nums);

void postOrder(TreeNode* root, std::vector<int>& nums);

#endif