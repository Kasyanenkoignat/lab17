#include <iostream>
#include <string>

class ColorPoint {
private:
    int x;
    int y;
    int red;
    int green;
    int blue;

public:
    ColorPoint(int x, int y, int red, int green, int blue) {
        this->x = x;
        this->y = y;
        setRed(red);
        setGreen(green);
        setBlue(blue);
    }

    ColorPoint() : ColorPoint(0, 0, 0, 0, 0) {}

    void setRed(int value) {
        if (value >= 0 && value <= 255)
            red = value;
        else
            std::cerr << "Invalid red value!" << std::endl;
    }

    void setGreen(int value) {
        if (value >= 0 && value <= 255)
            green = value;
        else
            std::cerr << "Invalid green value!" << std::endl;
    }

    void setBlue(int value) {
        if (value >= 0 && value <= 255)
            blue = value;
        else
            std::cerr << "Invalid blue value!" << std::endl;
    }

    void print() {
        std::cout << "Point(" << x << ", " << y << ") - RGB(" << red << ", " << green << ", " << blue << ")" << std::endl;
    }

    ~ColorPoint() {
        std::cout << "ColorPoint destructor called" << std::endl;
    }
};

class Line : public ColorPoint {
private:
    int length;

public:
    Line(int length, int x, int y, int red, int green, int blue) : ColorPoint(x, y, red, green, blue) {
        setLength(length);
    }

    Line(int length) : Line(length, 0, 0, 0, 0, 0) {}

    void setLength(int value) {
        if (value > 0)
            length = value;
        else
            std::cerr << "Invalid length value!" << std::endl;
    }

    void print() {
        ColorPoint::print();
        std::cout << "Length: " << length << std::endl;
    }

    ~Line() {
        std::cout << "Line destructor called" << std::endl;
    }
};

int main() {
    ColorPoint point1(3, 4, 100, 150, 200);
    point1.print();

    Line line1(5, 1, 1, 255, 0, 0);
    line1.print();

    return 0;
}