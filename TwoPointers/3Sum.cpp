#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    if (nums.size() < 3) return {};

    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> vec{};
    int n = static_cast<int>(nums.size());

    for(int i = 0; i < n - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;   //If the current number is the same as just processed skip it and move straight to the next.

        int left = i + 1, right = n - 1;
        int target = -nums[i];

        while(left < right) {
            int sum = nums[left] + nums[right];

             if(sum == target) {
                vec.push_back({nums[i], nums[left], nums[right]});

                while (left < right && nums[left] == nums[left + 1]) left++;
                while (left < right && nums[right] == nums[right - 1]) right--;

                left++;
                right--;
            } else if(sum < target) {
                left++;
            } else if(sum > target) {
                right--;
            }
        }
    }
    return vec;
};

int main () {

    std::vector<int> nums = {-1,0,1,2,-1,-4};
    std::vector<std::vector<int>> result = threeSum(nums);

    for(const auto& row : result) {
        for(const auto& column : row) {
            std::cout<< column << ", ";
        }
    }
    return 0;

}
