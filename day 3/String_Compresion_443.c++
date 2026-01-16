#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int write = 0;   // index to write compressed result
        int i = 0;       // index to read original chars

        while (i < n) {
            char current = chars[i];
            int count = 0;

            // count consecutive characters
            while (i < n && chars[i] == current) {
                i++;
                count++;
            }

            // write the character
            chars[write++] = current;

            // write the count if > 1
            if (count > 1) {
                string cnt = to_string(count);
                for (char c : cnt) {
                    chars[write++] = c;
                }
            }
        }

        return write;
    }
};

// helper function to print result
void runTest(vector<char> chars) {
    Solution sol;
    int newLength = sol.compress(chars);

    cout << "Compressed Length: " << newLength << endl;
    cout << "Compressed Array: ";
    for (int i = 0; i < newLength; i++) {
        cout << chars[i] << " ";
    }
    cout << endl << "------------------------" << endl;
}

int main() {

    // Test Case 1
    vector<char> test1 = {'a','a','b','b','c','c','c'};
    runTest(test1);

    // Test Case 2
    vector<char> test2 = {'a'};
    runTest(test2);

    // Test Case 3
    vector<char> test3 = {'a','b','b','b','b','b','b','b','b','b','b','b','b'};
    runTest(test3);

    // Test Case 4
    vector<char> test4 = {'x','x','x','y','z','z'};
    runTest(test4);

    // Test Case 5
    vector<char> test5 = {'A','A','A','A','A','A','A','A','A','A'};
    runTest(test5);
    //end of the Code
    return 0;
}
