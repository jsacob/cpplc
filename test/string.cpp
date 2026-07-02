#include <iostream>
#include <string>
#include <vector>

int main () {

    std::vector<int> vec = {1,2,3,4,5,6,7,8,14,12,19,84,28,42,1};
    std::string str = "Apple Jacks Cereal.";
    auto st = std::find(str.begin(), str.end(), 'J');
    auto it = std::find(vec.begin(), vec.end(), 89);

    if(it != vec.end()) {
        std::cout<<"Element found: "<<*it<<"\n";
    } else {
        std::cout<<"Element not found"; 
    };

    return 0;
};
