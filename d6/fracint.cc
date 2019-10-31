#include <iostream>
// A class for fractions of integers
// The goal of the exercise of this week is to implement a class of fractions of
// integers supporting some basic operations like addition and multiplication.


class fraction
{
public:
  int numerator;
  int denominator;

  // Constructor with optional argument for n and d
  fraction () {
    numerator   = 1;
    denominator = 1;
  }

  fraction (int n, int d) {
    numerator   = n;
    denominator = d;
  }

  // Methods to update the fraction: add, subtract, multiply, and division
  void add(fraction f){
    if (denominator == f.denominator) {
      numerator += f.numerator;
    } else {
      numerator = numerator * f.denominator + f.numerator * denominator;
      denominator = denominator * f.denominator;
    }
    simplify();
  }

  void sub(fraction f){
    if (denominator == f.denominator) {
      numerator -= f.numerator;
    } else {
      numerator = numerator * f.denominator - f.numerator * denominator;
      denominator = denominator * f.denominator;
    }
    simplify();
  }

  void mult(fraction f) {
    numerator *= f.numerator;
    denominator *= f.denominator;
    simplify();
  }

  void div(fraction f) {
    numerator *= f.denominator;
    denominator *= f.numerator;
    simplify();
  }

  // Operator overloading associated with the methods above
  fraction operator+(fraction const &f){
    fraction res(numerator, denominator);
    res.add(f);
    return res;
  }

  fraction operator-(fraction const &f){
    fraction res(numerator, denominator);
    res.sub(f);
    return res;
  }

  fraction operator*(fraction const &f){
    fraction res(numerator, denominator);
    res.mult(f);
    return res;
  }

  fraction operator/(fraction const &f){
    fraction res(numerator, denominator);
    res.div(f);
    return res;
  }

  // Display fraction on the "a/b" format
  void display(void) {
    std::cout << numerator << "/" << denominator << std::endl;
  }

  // Simplification method
  void simplify(){
    if (numerator == 0){
      return;
    } else if (numerator == denominator) {
      // Return unity
      numerator   = 1;
      denominator = 1;
    } else {
      int r, gcd = 1;

      // Reorder fraction so that numerator is biggest
      int a = std::max(numerator, denominator);
      int b = std::min(numerator, denominator);

      // Determine greatest common divisor using Euclid's algorithm
      r = a % b;
      gcd = b; // Special case if remainder is 0 initially

      while (r != 0) {
        gcd = r;
        r = b%r;
        b = gcd;
      }

      numerator   = numerator/gcd;
      denominator = denominator/gcd;
    }

    // Place sign in the numerator
    if (denominator < 0) {
      numerator   = - numerator;
      denominator = - denominator;
    }
  }
};


int main(void)
{
  fraction f1(1, 4);
  fraction f2(1, 4);
  fraction f3;

  f3 = f2+f1;
  f3.display();

  f3.add(f1);
  f3.display();
}
