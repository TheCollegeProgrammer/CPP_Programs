#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int i = 0;
        int j = nums.size() - 1;
        int count = 0;

        while (i < j) {
            int sum = nums[i] + nums[j];

            if (sum == k) {
                count++;
                i++;
                j--;
            }
            else if (sum < k) {
                i++;
            }
            else {
                j--;
            }
        }
        return count;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<int> nums1 = {1, 2, 3, 4};
    int k1 = 5;
    cout << "Test Case 1 Output: " << sol.maxOperations(nums1, k1) << endl;
    // Expected: 2  -> (1+4), (2+3)

    // Test Case 2
    vector<int> nums2 = {3, 1, 3, 4, 3};
    int k2 = 6;
    cout << "Test Case 2 Output: " << sol.maxOperations(nums2, k2) << endl;
    // Expected: 1  -> (3+3)

    // Test Case 3
    vector<int> nums3 = {2, 2, 2, 3, 1, 1, 4, 1};
    int k3 = 4;
    cout << "Test Case 3 Output: " << sol.maxOperations(nums3, k3) << endl;
    // Expected: 2

    // Test Case 4 (Edge Case)
    vector<int> nums4 = {};
    int k4 = 5;
    cout << "Test Case 4 Output: " << sol.maxOperations(nums4, k4) << endl;
    // Expected: 0

    return 0;
}
