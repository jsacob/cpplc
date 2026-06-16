#include <iostream>
#include <vector>
#include <unordered_set>

bool containsDuplicate(std::vector<int> &nums) {
    std::unordered_set<int> set;

    for(int i : nums) {
        if (set.contains(i)) {
            std::cout << i << " was a duplicate";
            return true;
        }
        set.insert(i);
        std::cout << "inserted " << i << std::endl;
    };
    return false;
};

int main () {
    std::vector<int> nums = {1,2,3,1};
    containsDuplicate(nums);

    return 0;
}
