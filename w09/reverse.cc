// Reverse
// Write a program that reverses a sequence of integers, as provided in the
// standard input, using recursion.
#include <iostream>
#include <vector>

void display(std::vector<int> v) {
  for (auto i : v) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}


// Perform the flipping of the sub vectors
std::vector<int> flip(std::vector<int> v1, std::vector<int> v2){
  std::vector<int> v;

  std::vector<int>::iterator it1 = v1.begin();
  std::vector<int>::iterator it2 = v2.begin();

  while (it2 != v2.end()) {
    v.push_back(*it2);
    it2++;
  }

  while (it1 != v1.end()) {
    v.push_back(*it1);
    it1++;
  }
  return v;
}


std::vector<int> split_and_flip(const std::vector<int> &v) {
  // Base case
  if (v.size() == 1) return v;

  // Split input vector into two sub vectors
  std::vector<int> v1(v.begin(), v.begin()+(v.size()/2));
  std::vector<int> v2(v.begin()+((v.size()/2)), v.end());

  // Call split_and_flip() recursively
  return flip(split_and_flip(v1), split_and_flip(v2));
}


int main(void) {
  std::vector<int> vec = {1, 2, 3, 4};
  display(vec);

  std::vector<int> vec_r = split_and_flip(vec);
  display(vec_r);
}
