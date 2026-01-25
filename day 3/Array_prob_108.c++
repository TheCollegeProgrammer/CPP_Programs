#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        auto buildBST = [&](auto& self, int l, int r) -> TreeNode* {
            if (l > r) return nullptr;
            int mid = l + (r - l) / 2;
            TreeNode* root = new TreeNode(nums[mid]);
            root->left = self(self, l, mid - 1);
            root->right = self(self, mid + 1, r);
            return root;
        };
        return buildBST(buildBST, 0, nums.size() - 1);
    }
};

// Helper function to print the tree in Level-Order (BFS) for testing
void printLevelOrder(TreeNode* root) {
    if (!root) {
        cout << "Empty Tree" << endl;
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();
        if (curr) {
            cout << curr->val << " ";
            q.push(curr->left);
            q.push(curr->right);
        } else {
            cout << "null ";
        }
    }
    cout << endl;
}

int main() {
    Solution sol;

    // Test Case 1: Standard odd-length array
    vector<int> nums1 = {-10, -3, 0, 5, 9};
    cout << "Test Case 1: [-10, -3, 0, 5, 9]" << endl;
    TreeNode* root1 = sol.sortedArrayToBST(nums1);
    cout << "Level Order Output: ";
    printLevelOrder(root1); 
    // Expected: 0 -10 5 null -3 null 9 (Order may vary slightly based on mid choice)

    // Test Case 2: Even-length array
    vector<int> nums2 = {1, 3};
    cout << "\nTest Case 2: [1, 3]" << endl;
    TreeNode* root2 = sol.sortedArrayToBST(nums2);
    cout << "Level Order Output: ";
    printLevelOrder(root2);

    // Test Case 3: Single element
    vector<int> nums3 = {42};
    cout << "\nTest Case 3: [42]" << endl;
    TreeNode* root3 = sol.sortedArrayToBST(nums3);
    cout << "Level Order Output: ";
    printLevelOrder(root3);

    return 0;
}