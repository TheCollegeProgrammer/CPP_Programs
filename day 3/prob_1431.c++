#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandies = 0;

        // Step 1: Find maximum candies
        for (int c : candies) {
            if (c > maxCandies)
                maxCandies = c;
        }

        // Step 2: Check each kid
        vector<bool> result;
        for (int c : candies) {
            result.push_back(c + extraCandies >= maxCandies);
        }

        return result;
    }
};

// Helper function to print boolean vector
void printResult(vector<bool>& result) {
    cout << "[ ";
    for (bool b : result) {
        cout << (b ? "true " : "false ");
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;

    // 🔹 Test Case 1
    vector<int> candies1 = {2, 3, 5, 1, 3};
    int extraCandies1 = 3;
    cout << "Test Case 1 Output: ";
    vector<bool> result1 = sol.kidsWithCandies(candies1, extraCandies1);
    printResult(result1);

    // 🔹 Test Case 2
    vector<int> candies2 = {4, 2, 1, 1, 2};
    int extraCandies2 = 1;
    cout << "Test Case 2 Output: ";
    vector<bool> result2 = sol.kidsWithCandies(candies2, extraCandies2);
    printResult(result2);

    // 🔹 Test Case 3
    vector<int> candies3 = {12, 1, 12};
    int extraCandies3 = 10;
    cout << "Test Case 3 Output: ";
    vector<bool> result3 = sol.kidsWithCandies(candies3, extraCandies3);
    printResult(result3);

    return 0;
}
