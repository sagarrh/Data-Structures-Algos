#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//using two pointer ...most efficient approach for solving

int trap(vector<int> height) {
    int n = height.size();  
    if (n <= 2) {
        return 0;
    }

    int left = 0, right = n - 1;
    int leftMax = 0, rightMax = 0;
    int waterTrapped = 0;

    while (left < right) {
        if (height[left] < height[right]) {
            if (height[left] >= leftMax) {
                leftMax = height[left];
            } else {
                waterTrapped += leftMax - height[left];
            }
            ++left;
        } else {
            if (height[right] >= rightMax) {
                rightMax = height[right];
            } else {
                waterTrapped += rightMax - height[right];
            }
            --right;
        }
    }
    return waterTrapped;
}

int main() {
   vector<int> height = {3, 1, 2, 4, 0, 1, 3, 2, 1, 2, 1, 2, 3};
    cout << "Total water trapped: " << trap(height);
    return 0;
}
