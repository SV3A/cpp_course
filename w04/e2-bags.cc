#include <iostream>
#include <set>
// Bag program 2
// Implements a "number bag" which stores integers (with repetitions allowed).
// The bag is implemented with both arrays and multisets (chosen via the
// CONTAINER variable).

using namespace std;

#define ARRAY_SIZE 1000

// Implementation of different container types
enum Container : unsigned char {
  Array = 0, Set
};

// Global variable
//const Container CONTAINER = Array;
const Container CONTAINER = Set;

// Struct object containing bag data
struct bag{
  // Array implementaion
  unsigned int array_container[ARRAY_SIZE];
  // Multiset implementation
  multiset<unsigned int> set_container;
  multiset<unsigned int>::iterator set_it;
};


void insert(bag &b, unsigned int x) {
  // Add to array- or set container
  if (CONTAINER == Array) {
    if (x < ARRAY_SIZE) b.array_container[x]++;
  } else if (CONTAINER == Set) {
    b.set_container.insert(x);
  }
}


void remove(bag &b, unsigned int x) {
  // Remove from array- or set container
  if (CONTAINER == Array) {
    if (x < ARRAY_SIZE) {
      if ( b.array_container[x] > 0 ) b.array_container[x]-- ;
    }
  } else if (CONTAINER == Set) {
    // Use iterator to only delete a single element even if multiple are present
    if (b.set_container.count(x)) {
      b.set_it = b.set_container.find(x);
      b.set_container.erase(b.set_it);
    }
  }
}


// Query function to return 'T' or 'F' in the console
void query(bag &b, unsigned int x) {
  char response = 'F';

  if (CONTAINER == Array) {
    if ( b.array_container[x] > 0 ) response = 'T';
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
      if (b.array_container[i] > 0){
        cout << i;
        if (b.array_container[i] > 1) {
          cout << "(" << b.array_container[i] << ")";
        }
        cout << " ";
      }
    }

  } else if (CONTAINER == Set) {
    int reps = 0; // variable used for counting the repetitions
    cout << endl << "Set = [ ";

    // Point iterator to beginning of the multiset
    b.set_it = b.set_container.begin();

    // Iterate over the multiset
    while (b.set_it != b.set_container.end()) {
      // Find repetitions of current element
      reps = b.set_container.count(*b.set_it);

      // Print element and potential repetitions
      cout << *b.set_it;
      if ( reps > 1 ) cout << "(" << reps << ")";
      cout << " ";

      // Increment iterator to next different element
      advance(b.set_it, reps);
    }
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
