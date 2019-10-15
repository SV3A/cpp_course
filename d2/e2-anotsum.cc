#include <iostream>
// Another sum
// Write a program that computes the sum of all even integers between 0 and n.
// For instance, for n = 6, the result is 0 + 2 + 4 + 6 = 12.

using namespace std;

int main(int argc, char *argv[])
{
  int n;
  int sum = 0;

  cout << "Please provide a positive integer\n";
  cin >> n;

  // Perform the sum
  for (int i = 1; i <= n; i++) {
    // Check if current i is even and if so add it to the sum
    if (i%2 == 0) {
      sum = sum + i;
    }
  }

  // Return the sum
  cout << "The sum is " << sum << endl;
  return 0;
}
