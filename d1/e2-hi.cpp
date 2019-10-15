#include <iostream>
// Write a program that reads a string (say name) from the command line prints
// ”Hello name!”. For example, if you run the program and type ”buddy” the 
// program should print ”Hello buddy!”

using namespace std;

int main(int argc, char *argv[])
{
  string name;

  cout << "Hi, what is your name? ";
  cin >> name;
  cout << "Hello " + name + "!\n";
  return 0;
}
