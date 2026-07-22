#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

class Solution {
public:
    int characterReplacement(std::string s, int k) {

        std::unordered_map <int, int> map;

        int length = s.length();
        int maxWindow = 0;
        int maxFreq = 0;

        int left = 0;
        for(int right = 0; right < length; right++) {
            // a: 1
            map[s[right]]++;

            //maxFreq = 1
            maxFreq = std::max(maxFreq, map[s[right]]);

            // 1 - 0 + 1 = 2
            int windowSize = right - left + 1;

            // 2 - 1 = 1 > 2
            if(windowSize - maxFreq > k) {
                map[s[left]]--;
                left++;
            }
            // 0 > 1 - 0 + 1 = 2?
            maxWindow = std::max(maxWindow, right - left + 1);
             }
        return maxWindow;
        }
};



int main() {

    std::string sc1 = "ABAB";
    int k1 = 2;
    std::string sc2 = "AABABBA";
    int k2 = 4;
    Solution solution;
    solution.characterReplacement(sc1, k1);
    solution.characterReplacement(sc2, k2);

    return 0;
};
