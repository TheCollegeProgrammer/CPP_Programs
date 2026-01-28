#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;

        while (i < s.size() && j < t.size()) {
            if (s[i] == t[j]) {
                i++;
            }
            j++;
        }

        return i == s.size();
    }
};

int main() {
    Solution sol;

    // Test cases
    cout << sol.isSubsequence("abc", "ahbgdc") << endl; // true (1)
    cout << sol.isSubsequence("axc", "ahbgdc") << endl; // false (0)
    cout << sol.isSubsequence("", "ahbgdc") << endl;    // true (1)
    cout << sol.isSubsequence("abc", "") << endl;       // false (0)
    cout << sol.isSubsequence("aaaa", "aaa") << endl;   // false (0)
    // end of code
    return 0;
}
