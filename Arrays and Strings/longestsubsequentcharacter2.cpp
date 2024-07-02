#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int lengthOfLongestSubstring(string s) {
    int maxLength = 0;
    int n = s.length();

    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            unordered_set<char> seen;
            bool allUnique = true;
            for (int k = i; k <= j; ++k) {
                if (seen.find(s[k]) != seen.end()) {
                    allUnique = false;
                    break;
                }
                seen.insert(s[k]);
            }
            if (allUnique) {
                maxLength = max(maxLength, j - i + 1);
            }
        }
    }

    return maxLength;
}

int main() {
    string s = "abcabcbb";
    cout << "Length of longest substring without repeating characters: " << lengthOfLongestSubstring(s) << endl;
    return 0;
}
