// Fibonacci
// Write a program, using recursion, that computes the Fibonacci numbers F_ni
// for a sequence: n_0, ... n_k given in the standard input.
#include <iostream>
#include <vector>

// Returns the nth element in the Fibonacci sequence
int fibonacci(const int n) {
  if (n <= 0) return 0;
  else if (n == 1) return 1;
  else return fibonacci(n-1) + fibonacci(n-2);
}

// For each element in the input vector, containing Fibonacci numbers, find the
// proceeding element in the sequence and append it to an ouput vector
std::vector<int> fib_vec(const std::vector<int> &v) {
  std::vector<int> output;

  for (int n : v) {
    output.push_back( fibonacci(n+1) );
  }

  return output;
}

int main(void) {
  std::vector<int> input = {0, 5, 7};
  std::vector<int> output = fib_vec(input);

  for (auto i : output) {
    std::cout << i << std::endl;
  }
}
