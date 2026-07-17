#include <algorithm>
#include <iostream>
#include <vector>

int trap(std::vector<int>& elevationMap) {

    int size = elevationMap.size();
    int left = 0, right = size - 1;

    int maxLeft = elevationMap[left];
    int maxRight = elevationMap[right];
    int totalHeight = 0;

    while (left < right) {
        if (maxLeft < maxRight) {
            left++;
            if (elevationMap[left] > maxLeft) {
                maxLeft = elevationMap[left];
            } else {
                totalHeight += maxLeft - elevationMap[left];
            }
        } else {
            right--;
            if (elevationMap[right] > maxRight) {
                maxRight = elevationMap[right];
            } else {
                totalHeight += maxRight - elevationMap[right];
            }
        }
    }

    return totalHeight;
}

int main() {
    std::vector<int> tc1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}; // Should output 6
    std::vector<int> tc2 = {4, 2, 0, 3, 2, 5};                 // Should output 9

    std::cout << "TC1: " << trap(tc1) << "\n";
    std::cout << "TC2: " << trap(tc2) << "\n";

    return 0;
}
