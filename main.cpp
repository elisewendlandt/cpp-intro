#include <iostream>
#include "math.h"
#include <vector>

class Rectangle
{
private:
  int width;
  int height;
public: Rectangle(int width, int height){
  this -> width = width;
  this -> height = height;
}
  int area()
  {
    return width * height;
  }
};


int subtract(int x, int y){
      return x-y;
    }
  
  
  int multiply(int x, int y){
    return x * y;
  }

  int divide(int x, int y){
    return x/y;
  }

  class Circle
{
  private:
  int radius;
  public: Circle(int radius){
    this -> radius = radius;
  }
  int area(int radius)
  {
    return M_PI* pow(radius,2);
  }
  void print()
{
  std::cout << "The area is " << area(radius) << " when radius is " << radius << std::endl;
}  

};

class Point{
  private:
  double x;
  double y;
  public: Point(double x, double y){
    this -> x =x;
    this -> y = y;
  }


  int distance_to_origin(){
    return sqrt(pow((x-0),2) + pow((y-0),2));
  }
  int distance_to_point(Point p){
    return sqrt(pow((x-p.x),2) + pow((y-p.y),2));
  }

};

class Line{
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
public: Line(Point p1, Point p2){
  this -> p1 = p1;
  this -> p2 = p2;
}
  double length(Point p1, Point p2){
    return sqrt(pow((p1.x-p2.x),2) + pow((p1.y-p2.y),2));
  }
  int distance_to_point(Point p1, Point p2, Point p){

    return abs((p2.x -p1.x)*(p1.y - p.y) - (p1.x-p.x)*(p2.y - p1.y ))/sqrt(pow((p2.x-p1.x),2) + pow((p2.y - p1.y),2));
  }
};

class Triangle{
  public:
  Point p1;
  Point p2;
  Point p3;
  /*
  Triangle(Point a, Point b, Point c){
    p1 = a;
    p2 = b;
    p3 = c;
  }
  
  */

  double area(Point p1, Point p2, Point p3){
    Line l;
    double base = l.length( p2, p3);
    double height = l.distance_to_point(p2,p3, p1);
    return 0.5 * base * height;
  }

};

class Polygon{
  public:
  std::vector<Point> p ;
  
  double area(){
    int amt_of_points = p.size();
    double area = 0.0;
    for (int i = 0; i < amt_of_points -2; i++){
      Triangle t;
      area += t.area(p[0],p[i],p[i+1]);
    }
        return area;
  }

  double perimeter(){
    int amt_of_points = p.size();
    double perimeter = 0.0;
    Line ll;
    for(int i = 0; i< amt_of_points; i++){
      perimeter += ll.length(p[i],p[i+1]);//p[i].distance_to_point(p[i+1]);

    }

    perimeter += ll.length(p[amt_of_points -1], p[0]);// p[0].distace_to_point(p[p.size()-1]);
    return perimeter;
  }
  
};









int main()
{
  std::cout << "Elise Wendlandt, 115" << std::endl;

  int x = 5;
  int y = 7;
  int z = x + y;
  std::cout << "The sum of " << x << " and " << y << " is " << x+y<< std::endl;
  std::cout << z<< std::endl;

  int w = x * y * z;
  std::cout << "The product of " << x << " and " << y << "and " << z << " is " << w << std::endl;
  std::cout << w << std::endl;
  int v = x/y;
  std::cout << "The quotient of " << x << " and " << y << " is " << v << std::endl;
  std::cout << "This is " << v << std::endl;
  Circle c;
  c.radius = 2;
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