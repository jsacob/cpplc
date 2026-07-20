#include <cctype>
#include <iostream>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {

        std::unordered_map<int, int> map;
        int length = s.length();

        int left = 0;
        int maxSubString = 0;

        for(int right = 0; right < length; right++) {

            if(map.contains(s[right])) {
                left = std::max(left, map[s[right]] + 1);
            }
            int currentSubString = right - left + 1;
            maxSubString = std::max(maxSubString, currentSubString);
            map[s[right]] = right;
        }
        return maxSubString;
    }
};


int main() {

    std::string s = "abcabcbb";
    std::string st = "pwwkew";
    Solution solution;
    int result = solution.lengthOfLongestSubstring(s);
    std::cout << result << std::endl;;
    int result2 = solution.lengthOfLongestSubstring(st);
    std::cout << result2 << std::endl;

    return 0;
}
