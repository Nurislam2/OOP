#include <iostream>
#include <iomanip>
#include <string>

class Tatra;

class Kamaz {
private:
    int speed;
    std::string name;

public:
    Kamaz(int spd, const std::string& nm) : speed(spd), name(nm) {}

    void display() const {
        std::cout << std::setw(10) << name << ": " << std::setw(3) << speed << " км/ч";
    }

    friend int FrCreater(const Kamaz& kamaz, const Tatra& tatra);
    friend int FrCreater(const Kamaz& kamaz, const Tatra& tatra);
    friend class Tatra;
};

class Tatra {
private:
    int speed;
    std::string name;

public:
    Tatra(int spd, const std::string& nm) : speed(spd), name(nm) {}

    void display() const {
        std::cout << std::setw(10) << name << ": " << std::setw(3) << speed << " км/ч";
    }

    friend int FrCreater(const Kamaz& kamaz, const Tatra& tatra);
};

int FrCreater(const Kamaz& kamaz, const Tatra& tatra) {
    if (kamaz.speed > tatra.speed)
        return 1;
    else if (kamaz.speed < tatra.speed)
        return -1;
    else
        return 0;
}

int main() {
    setlocale(LC_ALL, "Ru");
    Kamaz kamaz(120, "КАМАЗ");
    Tatra tatra(110, "Tatra");

    std::cout << std::setw(20) << "Участок трассы" << std::setw(20) << "Победитель" << std::endl;
    std::cout << "-----------------------------------------" << std::endl;

    std::cout << std::setw(20) << "Равнина: ";
    int resultPlain = FrCreater(kamaz, tatra);
    if (resultPlain == 1)
        std::cout << std::setw(20) << "КАМАЗ";
    else if (resultPlain == -1)
        std::cout << std::setw(20) << "Tatra";
    else
        std::cout << std::setw(20) << "Ничья";
    std::cout << std::endl;
    // Повторяем для других участков трассы: горы и пустыня
    kamaz.display();
    tatra.display();

    return 0;
}
