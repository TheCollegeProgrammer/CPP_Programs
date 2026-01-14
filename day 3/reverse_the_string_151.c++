#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        string result = "";

        while (ss >> word) {
            if (result.empty()) {
                result = word;
            } else {
                result = word + " " + result;
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    // Test case 1
    string s1 = "the sky is blue";
    cout << sol.reverseWords(s1) << endl;   // Expected: "blue is sky the"

    // Test case 2 (leading & trailing spaces)
    string s2 = "  hello world  ";
    cout << sol.reverseWords(s2) << endl;   // Expected: "world hello"

    // Test case 3 (multiple spaces between words)
    string s3 = "a good   example";
    cout << sol.reverseWords(s3) << endl;   // Expected: "example good a"

    // Test case 4 (single word)
    string s4 = "word";
    cout << sol.reverseWords(s4) << endl;   // Expected: "word"

    // Test case 5 (only spaces around one word)
    string s5 = "   leetcode   ";
    cout << sol.reverseWords(s5) << endl;   // Expected: "leetcode"
    // end of test cases
    return 0;
}
