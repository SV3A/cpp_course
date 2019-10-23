#include <iostream>
#include <set>
// Bag program 1
// Implements a "number bag" which can store unique integers.  The bag is
// implemented with both arrays and sets (chosen via the CONTAINER variable).

using namespace std;

#define ARRAY_SIZE 1000

// Implementation of different container types
enum Container : unsigned char {
  Array = 0, Set
};

const Container CONTAINER = Array; // Global variable
//const Container CONTAINER = Set;

// Struct object containing bag data (either as an array or using sets)
struct bag{
  bool array_container[ARRAY_SIZE];
  set<unsigned int> set_container;
};


void insert(bag &b, unsigned int x) {
  // Add to array- or set container
  if (CONTAINER == Array) {
    if (x > ARRAY_SIZE) {
      cout << "Exceeded array bounds (" << ARRAY_SIZE << ")" << endl;
    } else {
      b.array_container[x] = true;
    }
  } else if (CONTAINER == Set) {
    b.set_container.insert(x);
  }
}


void remove(bag &b, unsigned int x) {
  // Remove from array- or set container
  if (CONTAINER == Array) {
    if (x < ARRAY_SIZE) b.array_container[x] = false;
  } else if (CONTAINER == Set) {
    b.set_container.erase(x);
  }
}


// Query function to return 'T' or 'F' in the console
void query(bag &b, unsigned int x) {
  char response = 'F';

  if (CONTAINER == Array) {
    if ( b.array_container[x] ) response = 'T';
  } else if (CONTAINER == Set) {
    if ( b.set_container.count(x) ) response = 'T';
  }

  cout << response << endl;
}


// Parse user input and perform appropriate action asking for an integer if
// relevant
bool parse_cmd(string cmd, bag &b){
  unsigned int x = 0; // command argument

  if (cmd == "quit") return false;
  else if (cmd == "add") {cin >> x; insert(b, x);}
  else if (cmd == "del") {cin >> x; remove(b, x);}
  else if (cmd == "qry") {cin >> x;  query(b, x);}
  else cout << "Unknown command" << endl;
  return true;
}


void bag_init(bag &b) {
  // If array is used as bag initialize it
  if (CONTAINER == Array) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
      b.array_container[i] = false;
    }
  }
}


// Displays the content of the bag
void bag_display(bag &b) {

  if (CONTAINER == Array) {
    cout << endl << "Array = [ ";
    for (int i = 0; i < ARRAY_SIZE; i++) {
      if ( b.array_container[i] ) cout << i << " ";
    }

  } else if (CONTAINER == Set) {
    cout << endl << "Set = [ ";
    for(auto i : b.set_container)
      cout << i << " " ;
  }
  cout << "]" << endl;
}


int main(int argc, char *argv[])
{
  bag bag1;            // struct containing bag data
  string cmd = "";     // command
  bool run = true;     // termination flag
  bool verbose = true; // output switch

  bag_init(bag1);

  while(run) {
    if (verbose) {
      bag_display(bag1);
      cout << "What to do? ";
    }
    // Read command and parse it
    cin >> cmd;
    run = parse_cmd(cmd, bag1);
  }
  return 0;
}
