#include <iostream>
#include <set>
// Bag program 3
// Implements a "number bag" which stores floats (with repetitions allowed).
// The bag is implemented with multisets.

using namespace std;

// Struct object containing bag data
struct bag{
  multiset<double> set_container;
  multiset<double>::iterator set_it;
};


// Add element from the multiset container
void insert(bag &b, double x) {
  b.set_container.insert(x);
}


// Remove element from the multiset container
void remove(bag &b, double x) {
  // Use iterator to only delete a single element even if multiple are present
  if (b.set_container.count(x)) {
    b.set_it = b.set_container.find(x);
    b.set_container.erase(b.set_it);
  }
}


// Query function to return 'T' or 'F' in the console
void query(bag &b, double x) {
  char response = 'F';

  if ( b.set_container.count(x) ) response = 'T';
  cout << response << endl;
}


// Parse user input and perform appropriate action asking for an integer if
// relevant
bool parse_cmd(string cmd, bag &b){
  double x = 0; // command argument

  if (cmd == "quit") return false;
  else if (cmd == "add") {cin >> x; insert(b, x);}
  else if (cmd == "del") {cin >> x; remove(b, x);}
  else if (cmd == "qry") {cin >> x;  query(b, x);}
  else cout << "Unknown command" << endl;
  return true;
}


// Displays the content of the bag
void bag_display(bag &b) {
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
  cout << "]" << endl;
}


int main(int argc, char *argv[])
{
  bag bag1;            // struct containing bag data
  string cmd = "";     // command
  bool run = true;     // termination flag
  bool verbose = true; // output switch

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
