		#include <iostream>
		#include <vector>

		std::vector<int> prefixProduct(std::vector<int>& nums) {
	 		int n = nums.size();

	 		std::vector<int> prefixSumList(n, 0);
	 		prefixSumList[0] = nums[0];

	 		for(int i = 1; i < n; i++) {
	 			prefixSumList[i] = prefixSumList[i - 1] * nums[i];

			}

			return prefixSumList;

		}

	 	std::vector<int> suffixProduct(std::vector<int>& nums) {
			int n = nums.size();

			std::vector<int> suffixProductList(n, 0);
			suffixProductList[n - 1] = nums[n - 1];

			for(int i = n - 2; i >= 0; --i) {
				suffixProductList[i] = suffixProductList[i + 1] * nums[i];
			}

			return suffixProductList;
		}

		std::vector<int> productExceptSelf(std::vector<int>& nums) {
			int n = nums.size();

			std::vector<int> prefix = prefixProduct(nums);
			std::vector<int> suffix = suffixProduct(nums);

			std::vector<int> output(n, 0);

			for(int i = 0; i < n; i++) {
				if(i == 0) {
					output[i] = suffix[i + 1];
				}
			else if(i == n - 1) {
			output[i] = prefix[i - 1];

			} else {
				output[i] = prefix[i - 1] * suffix[i + 1];
			}}

			return output;
		}

		int main () {
	 		std::vector<int> nums = {1,2,3,4};

	 		std::vector<int> print = productExceptSelf(nums);

	 		for(int k : print) std::cout<< k << ", ";


			return 0;
		}

