#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

int longestConsecutive(std::vector<int>& nums) {

	// initalize map
	std::unordered_map<int, int> map;

	// frequency couting.
	for(int num : nums) {
		map[num]++;
	};

	int maxStreak = 0;

	// iterates through the map.
	for (const auto& [key, value] : map) {
    
    // if the map does not contain the key - 1 (e.g 5 - 1 = 4) 5 is our current smallest 
    if (!map.contains(key - 1)) {
        
    	// current number is our key, and our current streak is 1 because if 5 is our current smallest, it's our first count.
        int currentNum = key;
        int currentStreak = 1;
        
        // we check through the map and see if our current number (5 + 1 = 6) exist. If it does we increment and continue checking until it's no more
        // we also increase our current steak count
        while (map.contains(currentNum + 1)) {
            currentNum++;
            currentStreak++;
        }
        
        // if we have 3 different consecutive sequences, each new longest consecutive will be stored, the next sequence will be either > or < then current streak.
        // if the current streak is > maxStreak we asign maxSreak to currentStreak.
        maxStreak = std::max(maxStreak, currentStreak);
    	}

	}

 	return maxStreak;
 };

int main() {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::vector<int> nums = {0,3,7,2,5,8,4,6,0,1};

	int print = longestConsecutive(nums);

	std::cout << print;

	return 0;
};

// additional note. Remember this solution has local and global variables. It's very helpful when you learn where to initalize those variables.