//#include <iostream>
//#include <limits>
//#include <stdexcept>
//
//class Int {
//private:
//    int value;
//
//public:
//    Int(int val = 0) : value(val) {}
//
//    Int operator+(const Int& other) const {
//        long double result = static_cast<long double>(value) + other.value;
//        if (result > std::numeric_limits<int>::max() || result < std::numeric_limits<int>::min()) {
//            throw std::overflow_error("Arithmetic overflow occurred.");
//        }
//
//        return Int(value + other.value);
//    }
//
//    Int operator-(const Int& other) const {
//        long double result = static_cast<long double>(value) - other.value;
//        if (result > std::numeric_limits<int>::max() || result < std::numeric_limits<int>::min()) {
//            throw std::overflow_error("Arithmetic overflow occurred.");
//        }
//        return Int(value - other.value);
//    }
//
//    Int operator*(const Int& other) const {
//        long double result = static_cast<long double>(value) * other.value;
//        if (result > std::numeric_limits<int>::max() || result < std::numeric_limits<int>::min()) {
//            throw std::overflow_error("Arithmetic overflow occurred.");
//        }
//        return Int(value * other.value);
//    }
//
//    Int operator/(const Int& other) const {
//        if (other.value == 0) {
//            throw std::invalid_argument("Division by zero.");
//        }
//        return Int(value / other.value);
//    }
//
//    Int& operator++() {
//        if (value == std::numeric_limits<int>::max()) {
//            throw std::overflow_error("Arithmetic overflow occurred.");
//        }
//        ++value;
//        return *this;
//    }
//
//    Int operator++(int) {
//        Int temp(*this);
//        ++(*this);
//        return temp;
//    }
//
//    friend std::ostream& operator<<(std::ostream& out, const Int& obj) {
//        out << obj.value;
//        return out;
//    }
//};
//
//int main() {
//    // Пример использования класса Int
//    Int a(2), b(10), c;
//    try {
//        c = a + b  ;
//        std::cout << "a + b = " << c << std::endl;
//
//        // Проверка арифметического переполнения
//        //c = Int(std::numeric_limits<int>::max()) + Int(1); // Вызовет исключение
//    }
//    catch (const std::exception& e) {
//        std::cerr << "Exception caught: " << e.what() << std::endl;
//    }
//
//    return 0;
//}



//////////////////////////////////////////////////////////////////////
//
//#include <iostream>
//
//class Fraction {
//private:
//    double chislo;
//
//public:
//
//    double get() const {
//        return this->chislo;
//    }
//
//    Fraction() : chislo(0.0) {}
//    Fraction(double num) : chislo(num) {}
//
//    // Binary arithmetic operators
//    Fraction operator+(const Fraction& other) const {
//        return Fraction(chislo + other.chislo);
//    }
//
//    Fraction operator-(const Fraction& other) const {
//        return Fraction(chislo - other.chislo);
//    }
//
//    Fraction operator*(const Fraction& other) const {
//        return Fraction(chislo * other.chislo);
//    }
//
//    Fraction operator/(const Fraction& other) const {
//        if (other.chislo == 0.0) {
//            throw std::invalid_argument("Division by zero");
//        }
//        return Fraction(chislo / other.chislo);
//    }
//
//    // Prefix increment operator
//    Fraction& operator++() {
//        ++chislo;
//        return *this;
//    }
//
//    // Postfix increment operator
//    Fraction operator++(int) {
//        Fraction temp = *this;
//        ++(*this);
//        return temp;
//    }
//
//    void display() const {
//        std::cout << "Value: " << chislo << std::endl;
//    }
//};
//
//Fraction operator+( double a ,const Fraction& other)  {
//    return Fraction( a+other.get());
//}
//
//Fraction operator-(double a, const Fraction& other) {
//    return Fraction(a - other.get());
//}
//
//Fraction operator/(double a, const Fraction& other) {
//    if (other.get() == 0.0) {
//        throw std::invalid_argument("Division by zero");
//    }
//    return Fraction(a / other.get());
//}
//
//Fraction operator*(double a, const Fraction& other) {
//    return Fraction(a * other.get());
//}
//
//int main() {
//    Fraction a(0.5);
//    Fraction b(0.25);
//
//    Fraction c = 2 + a + b + 2;
//    c.display();
//
//    Fraction d = a - b;
//    d.display();
//
//    Fraction e = a * b;
//    e.display();
//
//    Fraction f = a / b;
//    f.display();
//
//    ++a;
//    a.display();
//
//    a++;
//    a.display();
//
//    return 0;
//}


////////////////////////////

#include <iostream>

class Rectangle {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double rect_area() const {
        return length * width;
    }

    // Overloaded rect_area() method for square
    double rect_area(double side) const {
        return side * side;
    }
};

int main() {
    Rectangle rectangle(3.0, 4.0);
    std::cout << "Rectangle area: " << rectangle.rect_area() << std::endl;

    // For square
    std::cout << "Square area: " << rectangle.rect_area(5.0) << std::endl;

    return 0;
}
