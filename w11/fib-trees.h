#ifndef __fib_trees__
#define __fib_trees__

#include <iostream>
#include <fstream>
#include <deque>
#include <iomanip>
#include <sstream>
#include <string>
#include <math.h>
#include <vector>

using namespace std;

// Fibonacci function prototype
int fibonacci(const int n);

class Fibtree {

  public:
    Fibtree();               // constructor
    Fibtree(int n);          // constructor
    ~Fibtree();              // destructor
    void maketree(int n);    // build tree recursively
    int size(void);          // size of the tree
    int depth(void);         // height of the tree
    int leafs(void);         // number of leafs on the tree
    void traverse_pre(void); // print nodes in pre-order

    #include "pretty_print_tree.cc"

  private:
    bool empty;     // flag to specify it tree is empty
    int content;    // content of the node
    Fibtree *left;     // pointer to left sub-tree
    Fibtree *right;    // pointer to right sub-tree
};

#endif
