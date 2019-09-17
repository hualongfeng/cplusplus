#include <iostream>

using std::cout;
using std::cendl;

class Shape{
  public:
    virtual void draw() = 0;
};

class Rectangle : public Shape{
  public:
    void draw() override {
      cout << "Shape: Rectangle" << endl;
    }
};

class Circle: public Shape{
  public:
    void draw() override {
      cout << "Shape: Circle" << endl;
    }
};

class ShapeDecorator : public Shape {
  protected:
    Shape decoratedShape;

  public:
    ShapeDecorator(Shape decoratedShape):decoratedShape(decoratedShape){}

    void draw(){
      decoratedShape.draw();
    }
};


