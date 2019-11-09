#include <iostream>
// Prime factorization
// Write a program that computes the prime factorization of a given positive
// integer. For instance, the factorization of 60 is 2*2*3*5.

using namespace std;

void factorize(int n) {
  int f = 2;  // The factor

  // Check if n is a positive integer over 2
  if (n < 2) {
    cout << "n is not larger than 2" << endl;
    return;
  }

  // While something is left to factorize
  while (n != 1) {
    // While the current factor divides n
    while (n%f == 0) {
      cout << f;
      n = n/f;

      // Output * only if not finished
      if (n != 1) cout << " * ";
    }

    // Increment the factor
    f++;
  }

  cout << endl;
}

int main(int argc, char *argv[]) {
  int n; // Number to factorize

  cout << "Please provide a positive integer to be factorized ";
  cin >> n;
  factorize(n);
  return 0;
}
