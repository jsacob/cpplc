#include <iostream>
#include <string>

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> &strs) {
    
    for(std::string x : strs) std::cout<< x << ", ";
    

};

int main() {
    std::vector<std::string> strs = {"eat","tea","tan","ate","nat","bat"};
    groupAnagrams(strs);
    return 0;
};
