#include<iostream>
#include<vector>
#include<algorithm>

//brute force;

using namespace std;

bool ispalindrome(string a){

    int front=0;
    int back=a.length()-1;
    while(front<back){
        if(a[front]==a[back]){
            front++;
            back--;
        }
        else{
            return false;
        }
    }
    return true;

}



string longest(string s){
    string longest;
    int maxlength=0;
    if(s.length()==1){
        return s;
    }

    if(s.length()==0){
        return "";
    }

    for(int i=0;i<s.length();i++){
        for(int j=i;j<s.length();j++){
            string hey = s.substr(i,j-i+1);
            if(ispalindrome(hey) && hey.length()>maxlength){
                maxlength=hey.length();
                longest=hey;
            }
        }
    }
    return longest;

}

int main(){
    string s = "nananaheyyeh";
    string result = longest(s);
    cout<<"the longest palindromic string is "<<result;
    return 0;
}