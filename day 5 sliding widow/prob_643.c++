#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int windowSum = 0;

        // Step 1: Calculate sum of first k elements
        for (int i = 0; i < k; i++) {
            windowSum += nums[i];
        }

        int maxSum = windowSum;

        // Step 2: Slide the window
        for (int i = k; i < nums.size(); i++) {
            windowSum += nums[i];
            windowSum -= nums[i - k];
            maxSum = max(maxSum, windowSum);
        }

        // Step 3: Return maximum average
        return (double)maxSum / k;
    }
};

int main() {
    Solution sol;

    // ✅ Test Case 1
    vector<int> nums1 = {1, 12, -5, -6, 50, 3};
    int k1 = 4;
    cout << "Test Case 1 Output: "
         << sol.findMaxAverage(nums1, k1) << endl;

    // ✅ Test Case 2
    vector<int> nums2 = {5};
    int k2 = 1;
    cout << "Test Case 2 Output: "
         << sol.findMaxAverage(nums2, k2) << endl;

    // ✅ Test Case 3
    vector<int> nums3 = {-1, -2, -3, -4};
    int k3 = 2;
    cout << "Test Case 3 Output: "
         << sol.findMaxAverage(nums3, k3) << endl;

    // ✅ Test Case 4
    vector<int> nums4 = {0, 4, 0, 3, 2};
    int k4 = 1;
    cout << "Test Case 4 Output: "
         << sol.findMaxAverage(nums4, k4) << endl;
    //end of code
    return 0;
}
