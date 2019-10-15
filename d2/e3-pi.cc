#include <iostream>
#include <cmath>
// Approximating pi
// Compute an approximation of π using Leibniz’ formula.

using namespace std;

// Straight forward solution, where the pow function is used
double pi (int n) {
  double sum = 0;

  // The sum of the formula
  for (int i = 0; i < n; i++) {
    sum = sum + pow(-1, i)/(2.0*i + 1.0);
  }

  // Perform the multiplication
  sum = 4.0*sum;
  return sum;
}

// Optimized solution
// Looking at the formula: π/4 = 1 - 1/3 + 1/5 - 1/7 + 1/9 -  1/11 + ...
// it's seen how the terms alternate in sign and that the denominator grows by
// 2. This can be implemented very efficiently as follows
double pi_opt (int n) {
  double sum   = 0.0;
  double num   = 1.0;
  double denom = 1.0;

  for (int i = 0; i < n; i++) {
    sum = sum + num/denom;
    // Change the sign of the numerator and increment the denominator by 2
    num   = -num;
    denom = denom + 2.0;
  }

  // Perform the multiplication
  sum = 4.0*sum;
  return sum;
}

int main(int argc, char *argv[]) {
  int n;      // Number of terms to use in the approximation
  double est;

  cout << "How many terms to use? ";
  cin >> n;
  //est = pi(n);
  est = pi_opt(n);

  cout << "Pi estimated to be " << est << endl;

  return 0;
}
