#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int fst = -1, lst = -1;
        int size = nums.size();
        int flag = 0;

        for (int i = 0; i < size; i++) {
            if (nums[i] == target && flag == 0) {
                fst = i;
                lst = i;
                flag++;
            } 
            else if (nums[i] == target) {
                lst = i;                
            }
        }

        vector<int> arr;
        arr.push_back(fst);
        arr.push_back(lst);
        return arr;
    }
};

void runTest(vector<int> nums, int target) {
    Solution sol;
    vector<int> result = sol.searchRange(nums, target);

    cout << "Array: ";
    for (int x : nums) cout << x << " ";
    cout << "\nTarget: " << target << endl;
    cout << "Output: [" << result[0] << ", " << result[1] << "]\n";
    cout << "-----------------------------\n";
}

int main() {
    // Test case 1: Target appears multiple times
    runTest({5, 7, 7, 8, 8, 10}, 8);

    // Test case 2: Target appears once
    runTest({1, 2, 3, 4, 5}, 3);

    // Test case 3: Target does not appear
    runTest({1, 2, 3, 4, 5}, 6);

    // Test case 4: All elements are target
    runTest({2, 2, 2, 2, 2}, 2);

    // Test case 5: Empty array
    runTest({}, 1);
    //end of code
    return 0;
}
