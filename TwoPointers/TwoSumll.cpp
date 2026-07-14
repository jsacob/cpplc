#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> twoSum(std::vector<int>& nums, int target) {

    std::unordered_map<int, int> map;

    for (int i = 0; i < nums.size(); i++) {
        int currentNumber = nums[i];
        int complement = target - currentNumber;

        if(map.contains(complement)) {          //Checks if the map contains complement
            return{map[complement], i + 1};     //Returns index of complement & current index.
        };
        map[currentNumber] = i + 1;             //If not stores current number + 1 based index in map.
    }
    return {};
 };

int main() {

    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    std::vector<int> outcome = twoSum(nums, target);
    for(int k : outcome) std::cout<< k;

    return 0;

};
