#include <iostream>
#include <vector>
#include <limits>
#include <climits>

using namespace std; // This removes the need for std::

bool hasIncreasingTriplet(vector<int>& nums) {
    // Start with the biggest possible values
    int small = INT_MAX; 
    int mid = INT_MAX;

    for (int current : nums) {
        if (current <= small) {
            // Found a new smallest number
            small = current;
        } 
        else if (current <= mid) {
            // Found a number bigger than 'small' but smaller than 'mid'
            mid = current;
        } 
        else {
            // Found a number bigger than both!
            return true;
        }
    }

    return false;
}

int main() {
    // Test Case
    vector<int> nums = {2, 1, 5, 0, 4, 6};
    
    if (hasIncreasingTriplet(nums)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    // end of prob

    return 0;
}