#include "Traversal.h"

#include <vector>
#include <iostream>

using namespace std;

void print_1d_nums(const vector<int>& nums)
{
    if (nums.size() == 0) {
        cout << "[]" << endl;
        return;
    }

    cout << "[";
    for (size_t i = 0; i < nums.size() - 1; i++) {
        cout << nums[i] << ", ";
    }

    cout << nums.back() << "]" << endl;
}

void test1(TreeNode *root)
{
    cout << "test1(): " << endl;
    vector<int> nums;
    preOrder(root, nums);
    print_1d_nums(nums);
}

void test2(TreeNode *root)
{
    cout << "test2(): " << endl;
    vector<int> nums;
    inOrder(root, nums);
    print_1d_nums(nums);
}

void test3(TreeNode* root)
{
    cout << "test2(): " << endl;
    vector<int> nums;
    postOrder(root, nums);
    print_1d_nums(nums);
}

int main(int argc, char **argv)
{
    vector<int> input = {5, 4, 11, 7, 2, 8, 13, 1};

    TreeNode *root = build(input);

    test1(root);

    test2(root);

    test3(root);

    return 0;
}