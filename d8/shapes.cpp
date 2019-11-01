// Fun with shapes
// The goal of the exercise is to implement a family of classes
// of two-dimensional shapes.
#include <iostream>
#include <vector>
#include "shapes.h"

using namespace std;

int main(void)
{
  vector<Shape *> shapes;

  Rectangle u(2, 5);
  Square v(3);
  Circle w(2);

  shapes.push_back(&u);
  shapes.push_back(&v);
  shapes.push_back(&w);

  // Enumerating all areas
  cout << "Areas..." << endl;
  double area = 0;
  for (Shape *p : shapes){
    cout << p->area() << " ";
    area += p->area();
  }
  cout << endl << "Total area is " << area << endl;

  // Enumerating all areas
  cout << "Perimeters..." << endl;
  double perimeter = 0;
  for(Shape *p : shapes){
    cout << p->perimeter() << " ";
    perimeter += p->perimeter();
  }
  cout << endl << "Total perimeter is " << perimeter << endl;

  // Side-by-side how much space they use (width and height)
  cout << "Placing side-by-side..." << endl;
  double width  = 0;
  double height = 0;
  for (Shape * p : shapes) {
    width += p->width();
    if (height < p->height()) {
      height = p->height();
    }
  }
  cout << "Total width is " << width << endl;
  cout << "Total height is " << height << endl;

  // Doing the same, but minimizing width by rotating the shapes that need it
  for (Shape *p : shapes) {
    if (p->width() > p->height()) {
      p->rotate();
    }
  }

  // Proceeding as before
  cout << "Placing side-by-side..." << endl;
  width  = 0;
  height = 0;
  for (Shape *p : shapes) {
    width += p->width();
    if (height < p->height()) {
      height = p->height();
    }
  }
  cout << "Total width is " << width << endl;
  cout << "Total height is " << height << endl;
}
