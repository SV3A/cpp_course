// Palindrome
// Write a program, using recursion, that decides whether a sequence of integers
// is a palindrome, i.e. if reading the sequence from right to left results in 
// the very same sequence.
#include <iostream>
#include <vector>

void reduce_and_check(std::vector<int> &v) {
  static bool state = true;

  // Base case
  if (v.size() <= 1) {
    if (state) std::cout << "Yes" << std::endl;
    else       std::cout << "No"  << std::endl;
    state = true; // Reset static variable
    return;
  };

  // Compare head and tail of the vector
  std::vector<int>::iterator fi = v.begin();
  std::vector<int>::iterator la = v.end()-1;

  if (*fi != *la) state = false;

  // Reduce vector and make recursive call
  std::vector<int> subvec(++fi, la);
  reduce_and_check(subvec);
}


int main(void) {
  std::vector<int> v1 = {13, 22, 22, 13};
  std::vector<int> v2 = {12, 22, 22, 13};

  reduce_and_check(v1);
  reduce_and_check(v2);
}
