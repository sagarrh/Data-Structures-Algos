#include<iostream>
#include<vector>
using namespace std;
//this is brute force approach for solvind this problem
int max(int a,int b){
    return (a>b)?a:b;
}
int min(int a,int b){
    return (a>b)?b:a;
}
int cwmw(vector<int> height){
    int maxarea=0;
    for(int i=0;i<height.size();i++){
        for(int j=i+1;j<height.size();j++){
            int maxh=min(height[i],height[j]);
            int width=j-i;
            int area= maxh*width;
            maxarea=max(area,maxarea);
        }
    }
    return maxarea;
}
int main(){
    vector<int> height ={5, 4, 3, 2, 1};
    int result=cwmw(height);
    cout<<"Answer is "<<result;
    return 0;
}

//test cases and answers
/*
{1, 8, 6, 2, 5, 4, 8, 3, 7} -> 49
{3, 1, 2, 4, 5} -> 9
{1, 1, 1, 1} -> 3
{5, 4, 3, 2, 1} -> 6
{2, 3, 10, 5, 7, 8, 9} -> 36
*/