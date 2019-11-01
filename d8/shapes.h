#pragma once

// Definition of pi used in circle class
#ifndef M_PI
#define M_PI 3.14159265359
#endif

// Interface (abstract class) defining the shapes objects
class Shape
{
  public:
    Shape(double x) {
      this->x = x;
    };
    virtual double area() = 0;
    virtual double perimeter() = 0;
    virtual double height() = 0;
    virtual double width() = 0;
    virtual void rotate() = 0;
  protected:
    double x; // Primary dimension (width or radius)
};

class Rectangle : public Shape
{;
  public:
    Rectangle(double x, double y) : Shape(x){
      this->y = y; // Add secondary dimension (height)
    }
    double area() {
      return x*y;
    }
    double perimeter() {
      return 2*(x+y);
    }
    double width() {
      return x;
    }
    double height() {
      return y;
    }
    void rotate() {
      double t;
      t = x;
      x = y;
      y = t;
    }
  private:
    double y;
};

class Square : public Rectangle
{
  public:
    Square(double x) : Rectangle(x, x) {};
};

class Circle : public Shape
{
  public:
    Circle(double r) : Shape(r){
      pi = M_PI;
    }
    double area() {
      return pi*x*x;
    }
    double perimeter() {
      return x*pi;
    }
    double width() {
      return 2*x;
    }
    double height() {
      return width();
    }
    void rotate(){ }
  private:
    double pi;
};
