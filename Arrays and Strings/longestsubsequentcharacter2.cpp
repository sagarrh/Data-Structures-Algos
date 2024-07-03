#include <iostream>
#include <unordered_set>
#include <string>
#include <unordered_set>


//this is using brute force approach

using namespace std;

int lengthOfLongestSubstring(string s) {
    int maxLength = 0;
    int n = s.length();
    for(int i=0;i<n;i++){
        int currentlenght=0;
        unordered_set<char> something;
        for(int j=i;j<n;j++){

            if(something.find(s[j])!=something.end()){
                break;
            }
            something.insert(s[j]);
            currentlenght++;
        }
        maxLength=max(maxLength,currentlenght);
    }
    return maxLength;
}

int main() {
    string s = "abcabcbb";
    cout << "Length of longest substring without repeating characters: " << lengthOfLongestSubstring(s) << endl;
    return 0;
}
