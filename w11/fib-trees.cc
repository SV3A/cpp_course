#include <iostream>
#include <fstream>
#include <deque>
#include <iomanip>
#include <sstream>
#include <string>
#include <math.h>
#include <vector>
#include "fib-trees.h"

using namespace std;

Fibtree::Fibtree() {
  empty = true;
  left  = nullptr;
  right = nullptr;
}

Fibtree::Fibtree(int n) {
  empty = true;
  left  = nullptr;
  right = nullptr;
  maketree(n);
}

Fibtree::~Fibtree() {
}

void Fibtree::maketree(int n) {
  if (empty) {
    content = fibonacci(n);
    empty   = false;
    left    = new Fibtree;
    right   = new Fibtree;

    // Populate right subtree
    right->content = fibonacci(n-2);
    right->empty   = false;

    // Base case
    if (n == 2) {
      left->content = 1;
      left->empty   = false;
      return;
    }

    // Make recursive call
    left->maketree(n-1);
    return;
  }
}

int Fibtree::size(void) {
  int res = 0;
  // The size of an empty tree is 0
  if(empty) return 0;

  // The size of a non-empty tree is 1 (the root) plus the size of the subtrees
  if (left != nullptr)  res = res + left->size();
  if (right != nullptr) res = res + right->size();

  return 1 + res;
}

int Fibtree::depth(void){
  // The height of an empty tree is 0
  if(empty) return 0;

  // The height of a non-empty tree is 1 (the root) plus the height of the left
  // subtrees
  if (left != nullptr) return 1 + left->depth();

  return 1;
}

int Fibtree::leafs(void) { return depth(); }

// Methods that implement the pre traversal methods
void Fibtree::traverse_pre(void) {
  if(empty) return ;
  cout << content << " " ;
  if (left  != nullptr) left->traverse_pre();
  if (right != nullptr) right->traverse_pre();
}
