#include <iostream>
// Write a program that reads two integer numbers (say, x and y) and prints
// ”x is equal to y” if x is equal to y;
// ”x is bigger than y” if x is greater than y;
// ”x is smaller than y” otherwise.

using namespace std;

int main(int argc, char *argv[])
{
  int x;
  int y;

  cout << "Enter two numbers, please: ";

  // Read the two numbers
  cin >> x;
  cin >> y;

  // Return appropriate message
  if (x == y) {
    printf("%d is equal to %d\n", x, y);
  } else if (x > y) {
    printf("%d is larger than %d\n", x, y);
  } else {
    printf("%d is smaller than %d\n", x, y);
  }

  return 0;
}
