#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string merged;
        int a = 0, b = 0;

        while (a < word1.size() || b < word2.size()) {
            if (a < word1.size()) {
                merged.push_back(word1[a]);
                a++;
            }
            if (b < word2.size()) {
                merged.push_back(word2[b]);
                b++;
            }
        }

        return merged;
    }
};

int main() {
    Solution sol;
// test cases to check the code functionality
    // Test case 1
    string word1 = "abc";
    string word2 = "pqr";
    cout << "Test 1: " << sol.mergeAlternately(word1, word2) << endl;
    // Expected: apbqcr

    // Test case 2
    word1 = "ab";
    word2 = "pqrs";
    cout << "Test 2: " << sol.mergeAlternately(word1, word2) << endl;
    // Expected: apbqrs

    // Test case 3
    word1 = "abcd";
    word2 = "pq";
    cout << "Test 3: " << sol.mergeAlternately(word1, word2) << endl;
    // Expected: apbqcd

    // Test case 4 (one empty string)
    word1 = "";
    word2 = "xyz";
    cout << "Test 4: " << sol.mergeAlternately(word1, word2) << endl;
    // Expected: xyz

    // Test case 5 (both empty)
    word1 = "";
    word2 = "";
    cout << "Test 5: " << sol.mergeAlternately(word1, word2) << endl;
    // Expected: (empty string)

    return 0;
}
