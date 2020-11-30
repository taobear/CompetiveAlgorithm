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


int main(int argc, char **argv)
{
    vector<int> input = {5, 4, 11, 7, 2, 8, 13, 1};

    TreeNode *root = build(input);

    cout << "test1(): " << endl;
    vector<int> preNums;
    preOrder(root, preNums);
    print_1d_nums(preNums);

    cout << "test2(): " << endl;
    vector<int> inNums;
    inOrder(root, inNums);
    print_1d_nums(inNums);

    return 0;
}