#include <iostream>
#include <string>
#include <vector>

bool isAnagram(std::string s, std::string t) {

  if (s.length() != t.length()) {
    return false;
  }

  std::vector<int> alphabet(26, 0);

  for (char x : s) {
    alphabet[x - 'a']++;
  };

  for (char x : t) {
    alphabet[x - 'a']--;
    ;
  }

  for (int count : alphabet) {
    if (count != 0) {
      return false;
    }
  }
  return true;
};

int main() {
  std::string s = "racecar";
  std::string t = "carrace";
  isAnagram(s, t);

  return 0;
}
