#include <iostream>
#include <vector>
#include <algorithm>


//using dynamic programming
using namespace std;

int trap(vector<int>& height) {
     int n = height.size();
        int totalwater=0;

        vector<int> leftmax(n);
        vector<int> rightmax(n);

        leftmax[0]=height[0];
        for(int i=1;i<n;i++){
            leftmax[i]=max(height[i],leftmax[i-1]);
        }
        rightmax[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            rightmax[i]=max(rightmax[i+1],height[i]);
        }

        for(int i=0;i<n;i++)
        {
            totalwater+=min(leftmax[i],rightmax[i])-height[i];
        }
        


        return totalwater;
}

int main() {
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << "Total water trapped: " << trap(height) << endl;  // Output: 6
    return 0;
}
