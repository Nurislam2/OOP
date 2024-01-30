#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Aeroflot {
public:
    string flight_number;
    string departure_city;
    string destination_city;
    string arrival_time;
    string departure_time;
    string registration_place;
};
class MyClass
{
public:


private:

};

bool compareByDestination(const Aeroflot& a, const Aeroflot& b) {
    return a.destination_city < b.destination_city;
}

void printFlightTable(const vector<Aeroflot>& flights) {
    if (flights.empty()) {
        cout << "Нет доступных рейсов." << endl;
        return;
    }

    cout << "Номер рейса\tОтправление\tНазначение\tПрибытие\tОтправление\tМесто регистрации" << endl;

    for (const Aeroflot& flight : flights) {
        cout << flight.flight_number << "\t\t" << flight.departure_city << "\t\t" << flight.destination_city
            << "\t\t" << flight.arrival_time << "\t\t" << flight.departure_time << "\t\t" << flight.registration_place << endl;
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    vector<Aeroflot> flights;

    // Ввод информации о рейсах с клавиатуры
    int n;
    cout << "Введите количество рейсов: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        Aeroflot flight;
        MyClass flight1;
        
        cout << "Номер рейса: ";
        cin >> flight.flight_number;
        cout << "Пункт отправления: ";
        cin >> flight.departure_city;
        cout << "Пункт назначения: ";
        cin >> flight.destination_city;
        cout << "Время прибытия: ";
        cin >> flight.arrival_time;
        cout << "Время отправления: ";
        cin >> flight.departure_time;
        cout << "Номер секции для регистрации: ";
        cin >> flight.registration_place;

        flights.push_back(flight);
    }
    
    // Сортировка по названию пунктов назначения
    sort(flights.begin(), flights.end(), compareByDestination);

    // Вывод таблицы рейсов
    printFlightTable(flights);

    return 0;
}
