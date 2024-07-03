#include <iostream>
#include <vector>
#include <algorithm>

//using brute force

using namespace std;

int trapping(vector<int> height){
    int n = height.size();

    int totalwater=0;
    for(int i=1;i<height.size()-1;i++){
        int leftmax =0,rightmax=0;
        for(int j=0;j<=i;j++){
            leftmax=max(leftmax,height[j]);
        }
        for(int j=i;j<n;j++){
            rightmax=max(rightmax,height[j]);
        }
        totalwater+=min(leftmax,rightmax)-height[i];
    }
    return totalwater;
}

int main(){
    vector<int> height= {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int result = trapping(height);
    cout<<"total water trapped is "<<result;
    return 0;
}
