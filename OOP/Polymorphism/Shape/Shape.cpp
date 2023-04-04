#include <iostream>
#include <vector>
#include <string>

class Shape {
private:
    std::string color;
public:
    virtual void draw() = 0;
    virtual void rotate() = 0;
    virtual ~Shape() {};
};

class Open_Shape : public Shape {
public:
    virtual ~Open_Shape() {};
};

class Closed_Shape : public Shape {
public:
    virtual ~Closed_Shape() {};
};

class Line: public Open_Shape {
public:
    virtual void draw() override {
        std::cout << "Drawing a line" << std::endl;
    }
    virtual void rotate() override {
        std::cout << "Rotating a line" << std::endl;
    }
    virtual ~Line() {};
};

class Circle: public Closed_Shape {
public:
    virtual void draw() override {
        std::cout << "Drawing a circle" << std::endl;
    }
    virtual void rotate() override {
        std::cout << "Rotating a circle" << std::endl;
    }
    virtual ~Circle() {};
};


int main() {
    Shape *ptr = new Line();
    ptr->draw();
    ptr->rotate();

    Circle c;
    Shape &ref = c;
    ref.draw();
    ref.rotate();
    
    return 0;
}