#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

std::vector<int> topKFrequent(std::vector<int> nums, int k) {

	std::unordered_map<int, int> map;
	 for(int count : nums) {
		map[count]++;
	}	

	std::vector<std::pair<int, int>> freqVec(map.begin(), map.end());

	std::sort(freqVec.begin(), freqVec.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
		return a.second > b.second;
	});

 	std::vector<int> result;
	for(int i = 0; i < k; i++) result.push_back(freqVec[i].first);

	return result;
	


};

int main() {

	std::vector<int> nums = {1, 2, 2, 3};
	int k = 2;
	topKFrequent(nums, k);

	return 0;
};
