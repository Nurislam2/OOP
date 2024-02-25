//////1 задание
//#include <iostream>
//#include <ctime>
//#include <cstdlib>
//#include <iomanip>
//
//using namespace std;
//
//class Timer {
//private:
//    int seconds;
//
//public:
//    // Конструкторы
//    Timer(int initialSeconds) : seconds(initialSeconds) {}
//
//    Timer(const string& timeString) {
//        parseTimeString(timeString);
//    }
//
//    Timer(int minutes, int seconds) : seconds(minutes * 60 + seconds) {}
//
//    // Функция для запуска таймера
//    void run() {
//        while (seconds > 0) {
//            displayTime();
//            sleep(1);  // Задержка на 1 секунду
//            --seconds;
//        }
//        cout << "\aTime's up! Ding ding ding!" << endl;  // Звонок
//    }
//
//private:
//    // Функция для отображения времени
//    void displayTime() const {
//        int minutes = seconds / 60;
//        int remainingSeconds = seconds % 60;
//        cout << setw(2) << setfill('0') << minutes << ":"
//            << setw(2) << setfill('0') << remainingSeconds << "\r" << flush;
//    }
//
//    // Функция для парсинга времени из строки в формате "mm:ss"
//    void parseTimeString(const string& timeString) {
//        size_t colonPos = timeString.find(':');
//        if (colonPos != string::npos) {
//            char* end;
//            long minutes = strtol(timeString.c_str(), &end, 10);
//            if (*end == ':' && end != timeString.c_str()) {
//                // Преобразование минут успешно, продолжаем с секундами
//                long seconds = strtol(end + 1, &end, 10);
//                if (*end == '\0') {
//                    // Преобразование секунд успешно, устанавливаем значение таймера
//                    this->seconds = minutes * 60 + seconds;
//                    return;
//                }
//            }
//        }
//
//        // Обработка ошибки
//        cerr << "Invalid time string format. Use \"mm:ss\"." << endl;
//        exit(EXIT_FAILURE);
//    }
//
//    // Функция для создания задержки
//    void sleep(int seconds) const {
//        clock_t delay = seconds * CLOCKS_PER_SEC;
//        clock_t start = clock();
//        while ((clock() - start) < delay) {}
//    }
//};
//
//int main() {
//    // Примеры использования конструкторов
//    Timer timer1(10);  // Таймер на 3 минуты
//    Timer timer2("05:30");  // Таймер на 5 минут 30 секунд
//    Timer timer3(2, 30);  // Таймер на 2 минуты 30 секунд
//
//    // Запуск таймеров
//    cout << "Timer 1: ";
//    timer1.run();
//
//    cout << "Timer 2: ";
//    timer2.run();
//
//    cout << "Timer 3: ";
//    timer3.run();
//
//    return 0;
//}

//// 2 задание
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//class Nomenclature {
//private:
//    string productName;
//    double wholesalePrice;
//    double retailMarkup;
//    int quantityInStock;
//
//public:
//    // Конструктор по умолчанию
//    Nomenclature() : productName(""), wholesalePrice(0.0), retailMarkup(0.0), quantityInStock(0) {}
//
//    // Конструктор с параметрами
//    Nomenclature(const string& name, double wholesale, double markup, int quantity)
//        : productName(name), wholesalePrice(wholesale), retailMarkup(markup), quantityInStock(quantity) {}
//
//    // Деструктор
//    ~Nomenclature() {
//        // Дополнительные действия по очистке, если необходимо
//    }
//
//    // Функция подсчета возможного чистого дохода при продаже товара
//    double calculateNetIncome(int quantitySold) const {
//        double retailPrice = calculateRetailPrice();
//        return quantitySold * (retailPrice - wholesalePrice);
//    }
//
//    // Функция вывода всех данных о товаре на экран
//    void displayProductInfo() const {
//        cout << "Product Name: " << productName << endl;
//        cout << "Wholesale Price: $" << wholesalePrice << endl;
//        cout << "Retail Markup: " << retailMarkup << "%" << endl;
//        cout << "Quantity in Stock: " << quantityInStock << endl;
//        cout << "Retail Price: $" << calculateRetailPrice() << endl;
//    }
//
//private:
//    // Функция подсчета розничной цены
//    double calculateRetailPrice() const {
//        return wholesalePrice * (1 + retailMarkup / 100);
//    }
//};
//
//int main() {
//    // Пример использования класса
//    Nomenclature product1("Laptop", 800.0, 20.0, 50);
//    product1.displayProductInfo();
//
//    cout << "Net Income for selling 10 units: $" << product1.calculateNetIncome(10) << endl;
//
//    return 0;
//}

// 3 задание
#include <iostream>
#include <string>
#include <chrono> // Для работы с временем
#include <ctime>  // Для работы с временем

class Soft {
private:
    std::string name;       // Название программы
    std::string developer;  // Разработчик
    double size;            // Занимаемый объем
    std::tm expiryDate;     // Дата завершения лицензии

public:
    // Конструктор с параметрами
    Soft(const std::string& _name, const std::string& _developer, double _size, const std::tm& _expiryDate)
        : name(_name), developer(_developer), size(_size), expiryDate(_expiryDate) {}

    // Деструктор
    ~Soft() {
        std::cout << "Destructor called for software: " << name << std::endl;
    }

    // Функция для подсчета количества дней до завершения лицензии
    int daysUntilExpiry() const {
        // Получаем текущую дату
        std::time_t now = std::time(nullptr);
        std::tm currentTime;
        localtime_s(&currentTime, &now);

        // Преобразуем даты в std::chrono::system_clock::time_point
        std::tm expiry = expiryDate;
        std::time_t t_expiry = std::mktime(&expiry);
        std::time_t t_current = std::mktime(&currentTime);

        // Разница в секундах между текущей датой и датой завершения лицензии
        double difference = std::difftime(t_expiry, t_current);
        // Переводим секунды в дни
        return static_cast<int>(difference / (60 * 60 * 24));
    }

    // Функция для вывода всех данных на экран
    void printData() const {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Developer: " << developer << std::endl;
        std::cout << "Size: " << size << " MB" << std::endl;
        std::cout << "Expiry Date: " << expiryDate.tm_mday << "/" << expiryDate.tm_mon + 1 << "/" << expiryDate.tm_year + 1900 << std::endl;
    }
};

int main() {
    // Создание объекта класса Soft
    std::tm expiryDate = { 0, 0, 0, 15, 1, 124 }; // Пример даты: 10/2/2024
    Soft software("Example Software", "Example Developer", 100.5, expiryDate);

    // Вывод данных об установленном программном обеспечении
    software.printData();

    // Подсчет количества дней до завершения лицензии
    std::cout << "Days until expiry: " << software.daysUntilExpiry() << std::endl;

    return 0;
}

