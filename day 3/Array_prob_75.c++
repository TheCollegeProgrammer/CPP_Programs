#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0;
        int high = nums.size() - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1) {
                mid++;
            }
            else { // nums[mid] == 2
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

// Helper to print a vector
void printVector(const vector<int>& nums) {
    cout << "[ ";
    for (int x : nums) {
        cout << x << " ";
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;

    // Test case 1
    vector<int> nums1 = {2, 0, 2, 1, 1, 0};
    cout << "Input:  ";
    printVector(nums1);
    sol.sortColors(nums1);
    cout << "Output: ";
    printVector(nums1);
    cout << endl;

    // Test case 2
    vector<int> nums2 = {2, 0, 1};
    cout << "Input:  ";
    printVector(nums2);
    sol.sortColors(nums2);
    cout << "Output: ";
    printVector(nums2);
    cout << endl;

    // Test case 3 (already sorted)
    vector<int> nums3 = {0, 0, 1, 1, 2, 2};
    cout << "Input:  ";
    printVector(nums3);
    sol.sortColors(nums3);
    cout << "Output: ";
    printVector(nums3);
    cout << endl;

    // Test case 4 (all same)
    vector<int> nums4 = {1, 1, 1, 1};
    cout << "Input:  ";
    printVector(nums4);
    sol.sortColors(nums4);
    cout << "Output: ";
    printVector(nums4);
    cout << endl;

    // Test case 5 (reverse order)
    vector<int> nums5 = {2, 2, 1, 1, 0, 0};
    cout << "Input:  ";
    printVector(nums5);
    sol.sortColors(nums5);
    cout << "Output: ";
    printVector(nums5);
    cout << endl;

    return 0;
}
