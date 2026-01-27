#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int insert = 0;

        // Move all non-zero elements forward
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[insert] = nums[i];
                insert++;
            }
        }

        // Fill the remaining positions with zeros
        while (insert < nums.size()) {
            nums[insert] = 0;
            insert++;
        }
    }
};

// Helper function to print a vector
void printVector(const vector<int>& nums) {
    cout << "[";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i < nums.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;

    // Test case 1
    vector<int> nums1 = {0, 1, 0, 3, 12};
    sol.moveZeroes(nums1);
    cout << "Test case 1 output: ";
    printVector(nums1);   // Expected: [1, 3, 12, 0, 0]

    // Test case 2
    vector<int> nums2 = {0};
    sol.moveZeroes(nums2);
    cout << "Test case 2 output: ";
    printVector(nums2);   // Expected: [0]

    // Test case 3
    vector<int> nums3 = {1, 2, 3, 4};
    sol.moveZeroes(nums3);
    cout << "Test case 3 output: ";
    printVector(nums3);   // Expected: [1, 2, 3, 4]

    // Test case 4
    vector<int> nums4 = {0, 0, 0, 1};
    sol.moveZeroes(nums4);
    cout << "Test case 4 output: ";
    printVector(nums4);   // Expected: [1, 0, 0, 0]

    // Test case 5
    vector<int> nums5 = {4, 0, 5, 0, 0, 3, 0, 1};
    sol.moveZeroes(nums5);
    cout << "Test case 5 output: ";
    printVector(nums5);   // Expected: [4, 5, 3, 1, 0, 0, 0, 0]

    return 0;
}
