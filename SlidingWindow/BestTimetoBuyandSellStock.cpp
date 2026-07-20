#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int left = 0;
        int maxProfit = 0;
        int size = prices.size();

        for(int right = 1; right < size; right++) {
            if(prices[left] < prices[right]) {
                int currentProfit = prices[right] - prices[left];
                maxProfit = std::max(maxProfit, currentProfit);
            }
            else {
                left = right;
            }
        }
        return maxProfit;
    }
};

int main() {

    std::vector<int> prices = {7, 1, 5, 3, 6, 4};
    Solution solution;
    int result = solution.maxProfit(prices);
    std::cout<< result;

    return 0;
}
