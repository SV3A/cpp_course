#include <iostream>
// Gausian sum
// Write a program that computes the sum 1 + 2 + ... + n for a given positive
// integer n.  For example, for n = 100, the result is 5050.

using namespace std;

int main(int argc, char *argv[])
{
  int n;
  int sum = 0;

  cout << "Please provide a positive integer\n";
  cin >> n;

  // Perform the sum
  for (int i = 1; i <= n; i++) {
    sum = sum + i;
  }

  // Return the sum
  cout << "The sum is " << sum << endl;
  return 0;
}
