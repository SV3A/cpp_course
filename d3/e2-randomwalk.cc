#include <iostream>
// Random Walk
// A mini text-based game.

using namespace std;

// Global variables of the player position
int x = 5, y = 5;

#define n 16
#define m 12

// Material (integer) type
enum material {
  space = 0, wall, player
};

// Struct for each field in the playground
struct field{
  int x, y;      // Coordinates
  bool isWall;   // Whether field is boundary
  material type; // Material type 0, 1, 2 for space, wall, player
};

// Define array for the playground
field playground[n][m];


// Translate materials into characters
char character(material type){
  switch(type){
    case space:
      return ' ';
    case wall:
      return '#';
    case player:
      return 'O';
    default:
      return '?';
  }
}


// printing the playground
void print_playground() {
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      cout << character(playground[i][j].type);
    }
    cout << endl;
  }
}


int main(int argc, char *argv[]) {
  bool quit = false;
  char gamectrl[1] = {'z'};

  while (!quit) {
    // Define playground and print it
    for (int i = 0; i < n; i++){
      for (int j = 0; j < m; j++){
        // Set coordinate
        playground[i][j].x = i;
        playground[i][j].y = j;

        // Determine the state of the coordinate
        playground[i][j].isWall = ( i==0 || i==(n-1) || j==0 || j==(m-1) );
        if (playground[i][j].isWall)
          playground [i][j].type = wall;
        else if (i==y-1 && j==x-1)
          playground [i][j].type = player;
        else
          playground [i][j].type = space;
      }
    }

    print_playground();

    // Get user input
    cin >> gamectrl;

    if ( gamectrl[0] == 'q' )
      quit = true;
    else if ( gamectrl[0] == 'r' )
      x ++;
    else if ( gamectrl[0] == 'l' )
      x --;
    else if ( gamectrl[0] == 'u' )
      y --;
    else if ( gamectrl[0] == 'd' )
      y ++;
    else
      cout << "Unknown input" << endl;
  }
}
