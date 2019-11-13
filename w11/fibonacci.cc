// Fibonacci
// Write a program that, given a non-negative integer n, provides some
// information about the computation of the straightforward implementation of
// the Fibonacci function via binary trees.
//
// Example with F(5):
//                 _______________5______________
//                /                              \
//         _______3______                         2
//        /              \
//     ___2__             1
//    /      \
//   _1       1
//  /  \
//  1   0
// Pre-order: 5 3 2 1 1 0 1 1 2
// Size: 9
// Depth: 5
// Leafs: 5
#include <iostream>
#include "fib-trees.h"

// Function for calculating the Fibonacci sequence recursively
int fibonacci(const int n) {
  if (n <= 0) return 0;
  else if (n == 1) return 1;
  else return fibonacci(n-1) + fibonacci(n-2);
}

int main(void) {
  // Build the tree
  Fibtree fibtree(5);

  // Print tree and info
  fibtree.pretty_print();

  cout << "Pre-order: ";
  fibtree.traverse_pre();
  cout << endl;

  cout << "Size: " << fibtree.size() << endl;
  cout << "Depth: " << fibtree.depth() << endl;
  cout << "Leafs: " << fibtree.leafs() << endl;
}
