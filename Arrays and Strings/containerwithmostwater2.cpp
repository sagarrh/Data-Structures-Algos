//this is two pointer approach for solving this problem 
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;



int cwmw(vector<int> height){
    int left=0;
    int right=height.size()-1;
    int maxarea=0;
    while(left<right){
        int h=min(height[left],height[right]);
        int width=right-left;
        int area=h*width;
         maxarea=max(area,maxarea);

        if(height[left]<height[right]){
            left++;
        }
        else{
            right--;
        }

    }
    return maxarea;

}

int main() {
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int result = cwmw(height);
    cout << "Answer is " << result << endl;
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