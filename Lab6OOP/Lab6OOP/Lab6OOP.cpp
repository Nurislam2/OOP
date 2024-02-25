//#include <iostream>
//#include <string>
//
//using namespace std;
//
//// Родительский класс Employee
//class Employee {
//protected:  
//    string name;
//    string position;
//    double salary;
//
//public:
//    Employee() {}
//
//    Employee(const string& name, const string& position, double salary)
//        : name(name), position(position), salary(salary) {}
//
//    ~Employee() {}
//
//    double calculateAnnualSalary() {
//        return salary * 12;
//    }
//
//    void display() {
//        cout << "Name: " << name << endl;
//        cout << "Position: " << position << endl;
//        cout << "Salary: $" << salary << "/month" << endl;
//    }
//};
//
//// Класс-потомок Manager
//class Manager : public Employee {
//private:
//    double annual_bonus;
//    string company_car;
//    int stock_options;
//
//public:
//    Manager() {}
//
//    Manager(const string& name, const string& position, double salary, double annual_bonus,
//        const string& company_car, int stock_options)
//        : Employee(name, position, salary), annual_bonus(annual_bonus), company_car(company_car), stock_options(stock_options) {}
//
//    ~Manager() {}
//
//    void display() {
//        Employee::display(); // Вызов метода display() из родительского класса
//        cout << "Annual Bonus: $" << annual_bonus << endl;
//        cout << "Company Car: " << company_car << endl;
//        cout << "Stock Options: " << stock_options << endl;
//    }
//};
//
//int main() {
//    // Пример использования классов
//    Manager manager("John Doe", "Manager", 5000, 2000, "Toyota", 100);
//    manager.display();
//
//    return 0;
//}


/////////////////////////////////////////////////////////
#include <iostream>
#include <string>

using namespace std;

// Родительский класс Display
class Display {
protected:
    string type;
    long colors;
    int x_resolution;
    int y_resolution;

public:
    Display(const string& type, long colors, int x_resolution, int y_resolution)
        : type(type), colors(colors), x_resolution(x_resolution), y_resolution(y_resolution) {}

    void display() {
        cout << "Type: " << type << endl;
        cout << "Colors: " << colors << endl;
        cout << "Resolution: " << x_resolution << "x" << y_resolution << endl;
    }
};

// Родительский класс MotherBoard
class MotherBoard {
protected:
    int processor;
    int speed;
    int RAM;

public:
    MotherBoard(int processor, int speed, int RAM)
        : processor(processor), speed(speed), RAM(RAM) {}

    void display() {
        cout << "Processor: " << processor << endl;
        cout << "Speed: " << speed << " GHz" << endl;
        cout << "RAM: " << RAM << " GB" << endl;
    }
};

// Класс-потомок Computer
class Computer : public Display, public MotherBoard {
private:
    string name;
    int hard_disk;

public:
    Computer(const string& type, long colors, int x_resolution, int y_resolution,
        int processor, int speed, int RAM, const string& name, int hard_disk)
        : Display(type, colors, x_resolution, y_resolution), MotherBoard(processor, speed, RAM), name(name), hard_disk(hard_disk) {}

    void Show() {
        cout << "Computer Name: " << name << endl;
        Display::display(); // Вызов метода display() из класса Display
        MotherBoard::display(); // Вызов метода display() из класса MotherBoard
        cout << "Hard Disk: " << hard_disk << " GB" << endl;
    }
};

int main() {
    // Пример использования класса Computer
    Computer computer("LED", 16777216, 1920, 1080, 8, 3, 16, "HP", 1000);
    computer.Show();

    return 0;
}
