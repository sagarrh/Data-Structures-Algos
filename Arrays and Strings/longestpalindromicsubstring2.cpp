#include<iostream>
#include<vector>
#include<algorithm>

//expanding around center ie check for palindromic string from the center to the ends;

using namespace std;


int expandAroundCenter(string s,int left,int right){
    while(left>=0 && right <=s.size() && s[left]==s[right]){
        left--;
        right++;
    }
    return right-left-1;

}


string longest(string s){
    
    if(s.size()==1) return s;
    if(s.empty()) return "";
    int start=0,end=0;


    for(int i=0;i<s.size();i++){
        int len1=expandAroundCenter(s,i,i);  //odd length;
        int len2=expandAroundCenter(s,i,i+1);  //even length;
        int len=max(len1,len2);
        if(len>end-start){
            start=i-(len-1)/2;
            end=i+len/2;
        }
    }

    return s.substr(start,end-start+1);
}

int main(){
    string s = "nananaheyyeh";
    string result = longest(s);
    cout<<"the longest palindromic string is "<<result;
    return 0;
}