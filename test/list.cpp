#include <iostream>
#include <random>
#include <vector>
#include <list>

int main () {
    std::vector<int> nums = {1,2,3,4,5};
    std::list<int> lis = {1,2,3,4,5};

    for(int x : nums) std::cout << x;
    std::cout << '\n';
    for(int x : lis) std::cout << x;
    return 0;
};
