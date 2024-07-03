#include <iostream>
#include <vector>
#include <algorithm>

//using brute force 
int trap(std::vector<int>& height) {
    int n = height.size();
    if (n <= 2) {
        return 0;
    }

    int waterTrapped = 0;
    for (int i = 1; i < n - 1; ++i) {
        int leftMax = 0, rightMax = 0;

        // Find the maximum height to the left of the current element
        for (int j = 0; j <= i; ++j) {
            leftMax = std::max(leftMax, height[j]);
        }

        // Find the maximum height to the right of the current element
        for (int j = i; j < n; ++j) {
            rightMax = std::max(rightMax, height[j]);
        }

        // Water trapped at current element
        waterTrapped += std::min(leftMax, rightMax) - height[i];
    }

    return waterTrapped;
}

int main() {
    std::vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    std::cout << "Total water trapped: " << trap(height) << std::endl;  // Output: 6
    return 0;
}
