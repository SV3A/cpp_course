#include <iostream>
// Write a program that reads three numbers (say, x, y and z) and prints number
// that results from evaluating (x + y) − z. For example, if you run the
// program and type ”1 2 3” the program should print ”0”.

using namespace std;

int main(int argc, char *argv[])
{
  double x;
  double y;
  double z;

  // Read the three numbers
  cin >> x;
  cin >> y;
  cin >> z;

  // Return the calculation
  cout << (x + y) - z << endl;

  return 0;
}
