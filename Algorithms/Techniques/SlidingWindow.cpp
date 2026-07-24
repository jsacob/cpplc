// these aren't the only ways to implement sliding window. Deque is a way to do fixed windows aswell

#include <algorithm>
#include <iostream>
#include <vector>

int fixedWindow(std::vector<int> &vec) {

    // Left window, Highest Sum of all windows, Fixed window Size, and calculate current SUM.
    int left = 0, maxSum = 0, windowSize = 2, size = vec.size(), currentSum = 0;

    // Right window
    for(int right = 0; right < size; right++){

        // calculates current window size. e.g first window size is 0 - 0 + 1 = 1 since both are on 0.
        // 0-0+1=1
        // 1-0+1=2
        // 2-0+1=3 <-- at [2] indx 2. Subtract currentSum -= vec[left] then left++. Then left can be at [6,2]
        // then we iterate again.
        // 3-1+1=3 and this continues

        // gets current window size.
        int currentWindow = right - left + 1;

        // adds current number to current sum. Now at 15.
        currentSum += vec[right];

        // this is false left stays 0 until the 4th iteration when right = 2 - 0 + 1 = 3
        // so the current window is [15, 6, 2]
        if(currentWindow > windowSize) {
            currentSum -= vec[left];
            left++;
        }
        maxSum = std::max(maxSum, currentSum);
    }
    return maxSum;
};

int dynamicWindow(std::vector<int> &vec, int k) {

    // go to excalidraw

    int left = 0, maxSum = 0, size = vec.size(), currentSum=0;

    for(int right = 0; right < size; right++) {

        currentSum += vec[right];

        if(currentSum > k) {
            currentSum -= vec[left];
            left++;
        }

        if(currentSum == k) {
            std::cout<< "LW: " << left << " RW: " << right << std::endl;
            return currentSum;
        }

    }
    return 0;
};

int main() {

    std::vector<int> vec={15,6,2,1,92,47,2,1,42,15};
    std::cout << "Max Sum: " << fixedWindow(vec) << std::endl;

    std::vector<int> vec2={15,6,2,1,92,47,2,1,42,15};
    int k = 92;
    std::cout << "Max Sum: " << dynamicWindow(vec2, k) << std::endl;

    return 0;
}
