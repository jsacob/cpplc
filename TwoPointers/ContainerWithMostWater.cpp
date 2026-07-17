#include <iostream>
#include <vector>
#include <algorithm>

int maxArea(std::vector<int>& height) {

    int size = height.size();
    int left = 0, right = size - 1;
    int maximumArea = 0;

    while(left < right) {
        int currentWidth = right - left;
        int minHeight = std::min(height[left], height[right]);
        int currentArea = currentWidth * minHeight;

        maximumArea = std::max(maximumArea, currentArea);
        if(height[left]< height[right]) {
            left++;

        } else {
            right--;
        }
    };

    return maximumArea;
}
 int main() {

    std::vector<int> height = {1,8,6,2,5,4,8,3,7};
    std::vector<int> testCase = {4,3,2,1,4};
    std::cout<< maxArea(height);

    return 0;
}
