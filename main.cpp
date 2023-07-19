#include <iostream>
#include "math.h"
#include <vector>
#include <array>
#include <iostream>
#include "Point.hpp"

class Rectangle
{
private:
  int width;
  int height;

public:
  Rectangle(int width, int height)
  {
    this->width = width;
    this->height = height;
  }
  int area()
  {
    return width * height;
  }
};

int subtract(int x, int y)
{
  return x - y;
}

int multiply(int x, int y)
{
  return x * y;
}

int divide(int x, int y)
{
  return x / y;
}

class Circle
{
private:
  int radius;

public:
  Circle(int radius)
  {
    this->radius = radius;
  }
  int area(int radius)
  {
    return M_PI * pow(radius, 2);
  }
  void print()
  {
    std::cout << "The area is " << area(radius) << " when radius is " << radius << std::endl;
  }
};

class Line
{
private:
  Point p1;
  Point p2;
  /*double length(){
    return p1.distance_to_point(p2);
  }
  double distance_to_point(Point p){
   double numerator = abs((p2.y-p1.y)/ (p2.x-p1.x) )
  }
*/
public:
  Line(Point &p1, Point &p2) : p1(p1), p2(p2) {}

  // Line(){
  //  Point p1();
  //  Point p2();
  // }

  // double getp1() const{
  //   return p1.getX();
  // }

  double length()
  {
    return sqrt(pow((p1.x() - p2.x()), 2) + pow((p1.y() - p2.y()), 2));
  }
  double distance_to_point(Point p1, Point p2, Point p)
  {

    return abs((p2.x() - p1.x()) * (p1.y() - p.y()) - (p1.x() - p.x()) * (p2.y() - p1.y())) / sqrt(pow((p2.x() - p1.x()), 2) + pow((p2.y() - p1.y()), 2));
  }
};

class Triangle
{

private:
  Point p1;
  Point p2;
  Point p3;

public:
  Triangle(Point p1, Point p2, Point p3)
  {
    this->p1 = p1;
    this->p2 = p2;
    this->p3 = p3;
  }

  double area()
  {
    Line l(p2, p3);
    double base = l.length();
    double height = l.distance_to_point(p2, p3, p1);
    return 0.5 * base * height;
  }
};

class Polygon
{
private:
  std::vector<Point> p;

public:
  Polygon(std::vector<Point> p)
  {
    this->p = p;
  }

  double area()
  {
    int amt_of_points = p.size();
    double area = 0.0;
    for (int i = 0; i < amt_of_points - 1; i++)
    {
      Triangle t(p[0], p[i], p[i + 1]);
      area += t.area();
    }

    return area;
  }

  double perimeter()
  {

    int amt_of_points = p.size();
    double perimeter = 0.0;

    for (int i = 0; i < amt_of_points; i++)
    {
      Line ll(p[i], p[i + 1]);
      perimeter += ll.length(); // p[i].distance_to_point(p[i+1]);
    }
  Line j(p[amt_of_points - 1], p[0]);
    perimeter += j.length(); // p[0].distace_to_point(p[p.size()-1]);
    return perimeter;
  }
};

class AUV
{
private:
  std::string name;
  Point position;
  double depth;
  double heading;
  std::array<double, 3> speed;
  double angular_speed;

public:
  AUV(std::string name, Point position, double depth, double heading, std::array<double, 3> speed, double angular_speed)
  {
    this->name = name;
    this->position = position;
    this->depth = depth;
    this->heading = heading;
    this->speed = speed;
    this->angular_speed = angular_speed;
  }
  double step(double dt)
  {
     position.setX(position.x() + speed[0]*dt);
     position.setY(position.y() + speed[1]*dt);
     depth += speed[2]*dt;
     heading += angular_speed *dt;
  }
  void apply_acceleration(std:: array<double, 3> acceleration, double dt)
  {
    speed[0]+= acceleration[0]*dt;
    speed[1]+= acceleration[1]*dt;
    speed[2]+= acceleration[2]*dt;

  }
  void apply_angular_acceleration(double angular_acceleration, double dt){
    angular_speed += angular_acceleration *dt;

  }
};



int main()
{
  std::cout << "Elise Wendlandt, 115" << std::endl;

  int x = 5;
  int y = 7;
  int z = x + y;
  std::cout << "The sum of " << x << " and " << y << " is " << x + y << std::endl;
  std::cout << z << std::endl;

  int w = x * y * z;
  std::cout << "The product of " << x << " and " << y << "and " << z << " is " << w << std::endl;
  std::cout << w << std::endl;
  int v = x / y;
  std::cout << "The quotient of " << x << " and " << y << " is " << v << std::endl;
  std::cout << "This is " << v << std::endl;
  Circle c(2);
  c.print();

  return 0;
}

// class Person {
// public:
//   std::string name;
//   int age;
//   void print() {
//     std::cout << "My name is " << name << " and I am " << age << " years old." << std::endl;
//   }
// };

// int main() {
//   Person p;
//   p.name = "John";
//   p.age = 20;
//   p.print();
//   // My name is John and I am 20 years old.

//   return 0;