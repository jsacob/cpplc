// just introduced to deque. Honestly pretty amazing kinda like a doubled sided O(1) vector

#include <deque>
#include <iostream>
#include <vector>

class Solution{
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        std::vector<int> result;
        std::deque<int> deque;

        // 1. Remove indices that have left the window.
        for(int i = 0; i < nums.size(); i++) {
            if(!deque.empty() && deque.front() == i - k) {
                deque.pop_front();
            }

            // 2. Remove indices whose values are smaller than nums[i].
            while(!deque.empty() && nums[deque.back()] < nums[i]) {
                deque.pop_back();
            }

            // 3. Add the current index.
            deque.push_back(i);

            // 4. Once we've seen a full window, record the maximum.
            if(i >= k - 1) {
                result.push_back(nums[deque.front()]);
            }
        }
        return result;
    }
};

int main() {

    std::vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    Solution solution;
    std::vector<int> sol = solution.maxSlidingWindow(nums, k);
    for(int x : sol) std::cout<< x << " ";

    std::vector<int> tc1 = {1, -1};
    int tk1 = 1;
    std::vector<int> soltc = solution.maxSlidingWindow(tc1, tk1);
    for(int x : soltc) std::cout<< x << " ";

    return 0;
}
