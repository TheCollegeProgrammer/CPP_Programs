#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // Found target
            if (nums[mid] == target)
                return mid;

            // Left half is sorted
            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;  // search left half
                } else {
                    left = mid + 1;   // search right half
                }
            }
            // Right half is sorted
            else {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;   // search right half
                } else {
                    right = mid - 1;  // search left half
                }
            }
        }

        return -1;  // target not found
    }
};

void runTest(vector<int> nums, int target, int expected) {
    Solution sol;
    int result = sol.search(nums, target);

    cout << "nums = [ ";
    for (int x : nums) cout << x << " ";
    cout << "], target = " << target << endl;

    cout << "Expected: " << expected << ", Got: " << result;

    if (result == expected)
        cout << "  ✅ PASS\n";
    else
        cout << "  ❌ FAIL\n";

    cout << "---------------------------\n";
}

int main() {
    // Test case 1 (from problem statement)
    runTest({4, 5, 6, 7, 0, 1, 2}, 0, 4);

    // Test case 2 (from problem statement)
    runTest({4, 5, 6, 7, 0, 1, 2}, 3, -1);

    // Test case 3 (from problem statement)
    runTest({1}, 0, -1);

    // Additional test cases
    runTest({1, 2, 3, 4, 5, 6, 7}, 5, 4);      // no rotation
    runTest({6, 7, 1, 2, 3, 4, 5}, 3, 4);      // rotation in middle
    runTest({6, 7, 1, 2, 3, 4, 5}, 6, 0);      // target at start
    runTest({6, 7, 1, 2, 3, 4, 5}, 5, 6);      // target at end
    runTest({3, 1}, 1, 1);                    // small array
    runTest({3, 1}, 3, 0);                    // small array, target at start
    runTest({5, 1, 2, 3, 4}, 1, 1);            // rotated at index 1
    runTest({5, 1, 2, 3, 4}, 5, 0);            // target at pivot
    //end of code
    return 0;
}
