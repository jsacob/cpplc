#include <iostream>
#include <vector>
#include <deque>

int main() {

    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::deque<int> deque;

    for (int i = 0; i < vec.size(); i++) {
        if(vec[i] % 2 == 0) {
            deque.push_back(vec[i]);
        }
    }

    for(int x : deque) std::cout<< x;





    return 0;
}
