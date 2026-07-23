// just introduced to deque. Honestly pretty amazing kinda like a doubled sided O(1) vector

#include <deque>
#include <iostream>
#include <vector>

class Solution{
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        std::vector<int> result;
        std::deque<int> dq;

        for(int i = 0; i < nums.size(); i++) {
            if(!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }

            while(!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);

            if(i >= k - 1) {
                result.push_back(nums[dq.front()]);
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
