#include <map>
#include <vector>

std::vector<int> twoSum(std::vector<int> *nums, int target) {

  std::map<int, int> map;

  for (int i = 0; i < nums->size(); i++) {
    int currentNum = (*nums)[i];
    int complement = target - currentNum;

    if (map.count(complement)) {
      return {map[complement], i};
    };
    map[currentNum] = i;
  };
  return {};
};

int main() {

  std::vector<int> vec = {2, 7, 11, 15};
  std::vector<int> *ptr_vec = &vec;
  int target = 9;

  twoSum(ptr_vec, target);

  return 0;
}
