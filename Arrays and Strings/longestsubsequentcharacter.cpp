#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int lengthOfLongestSubstring(string s) {
    int n = s.length();
    unordered_map<char, int> charIndex;
    int maxLength = 0;
    int start = 0; 
    
    for (int end = 0; end < n; end++) {
        if (charIndex.find(s[end]) != charIndex.end() && charIndex[s[end]] >= start) {
            start = charIndex[s[end]] + 1;
        }
        
        charIndex[s[end]] = end;
        
        maxLength = max(maxLength, end - start + 1);
    }
    
    return maxLength;
}

int main() {
    string s = "abcabcbb";
    cout << "Length of longest substring without repeating characters: " << lengthOfLongestSubstring(s) << endl;
    return 0;
}
