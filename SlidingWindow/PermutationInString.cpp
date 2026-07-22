#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
    bool checkInclusion(std::string s1, std::string s2) {
        if (s1.length() > s2.length()) return false;

        std::unordered_map<char, int> s1Map;
        for (char x : s1) s1Map[x]++;

        std::unordered_map<char, int> windowMap;
        int left = 0;
        int length = s2.length();

        for (int right = 0; right < length; right++) {
            windowMap[s2[right]]++;

            int windowSize = right - left + 1;

            if (windowSize > s1.length()) {
                windowMap[s2[left]]--;

                if (windowMap[s2[left]] == 0) {
                    windowMap.erase(s2[left]);
                }

                left++;
                windowSize--;
            }

            if (windowSize == s1.length()) {
                if (s1Map == windowMap) {
                    return true;
                }
            }
        }

        return false;
    }
};

int main() {

    std::string s1 = "ab", s2="eidbaooo";
    Solution solution;
    std::cout<< solution.checkInclusion(s1, s2) << std::endl;

    return 0;
}
