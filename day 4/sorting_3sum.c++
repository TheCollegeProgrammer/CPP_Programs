#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    int n = nums.size();

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 2; i++) {

        // Skip duplicate i
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum == 0) {
                result.push_back({nums[i], nums[left], nums[right]});

                // Skip duplicate left
                while (left < right && nums[left] == nums[left + 1])
                    left++;

                // Skip duplicate right
                while (left < right && nums[right] == nums[right - 1])
                    right--;

                left++;
                right--;
            }
            else if (sum < 0) {
                left++;   // need bigger value
            }
            else {
                right--;  // need smaller value
            }
        }
    }

    return result;
}

// Utility function to print result
void printResult(vector<vector<int>>& res) {
    cout << "[ ";
    for (auto& triplet : res) {
        cout << "[";
        for (int i = 0; i < 3; i++) {
            cout << triplet[i];
            if (i < 2) cout << ", ";
        }
        cout << "] ";
    }
    cout << "]\n";
}

int main() {

    // -------- Test Case 1 --------
    vector<int> nums1 = {-1, 0, 1, 2, -1, -4};
    cout << "Test Case 1: [-1, 0, 1, 2, -1, -4]\n";
    auto res1 = threeSum(nums1);
    printResult(res1);
    cout << "Expected: [[-1, -1, 2], [-1, 0, 1]]\n\n";

    // -------- Test Case 2 --------
    vector<int> nums2 = {0, 1, 1};
    cout << "Test Case 2: [0, 1, 1]\n";
    auto res2 = threeSum(nums2);
    printResult(res2);
    cout << "Expected: []\n\n";

    // -------- Test Case 3 --------
    vector<int> nums3 = {0, 0, 0};
    cout << "Test Case 3: [0, 0, 0]\n";
    auto res3 = threeSum(nums3);
    printResult(res3);
    cout << "Expected: [[0, 0, 0]]\n\n";

    // -------- Test Case 4 --------
    vector<int> nums4 = {-2, 0, 1, 1, 2};
    cout << "Test Case 4: [-2, 0, 1, 1, 2]\n";
    auto res4 = threeSum(nums4);
    printResult(res4);
    cout << "Expected: [[-2, 0, 2], [-2, 1, 1]]\n\n";

    // -------- Test Case 5 --------
    vector<int> nums5 = {3, -1, -7, 4, 5, -4, 2, -2};
    cout << "Test Case 5: [3, -1, -7, 4, 5, -4, 2, -2]\n";
    auto res5 = threeSum(nums5);
    printResult(res5);
    cout << "Expected: [[-7, 2, 5], [-4, -1, 5], [-4, 2, 2] (if 2 exists twice)]\n\n";

    return 0;
}
