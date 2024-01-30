#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <windows.h>



using namespace std;

class Student {
public:
    string firstName;
    string lastName;
    string dateOfBirth;
    string phoneNumber;
};

class StudentGroup {
private:
    vector<Student> students;

public:
    void addStudent(const string& firstName, const string& lastName, const string& dateOfBirth, const string& phoneNumber) {
        students.push_back({ firstName, lastName, dateOfBirth, phoneNumber });
    }

    void removeStudentByLastName(const string& lastName) {
        students.erase(remove_if(students.begin(), students.end(),
            [lastName](const Student& student) { return student.lastName == lastName; }),
            students.end());
    }

    Student* findStudentByLastName(const string& lastName) {
        auto it = find_if(students.begin(), students.end(),
            [lastName](const Student& student) { return student.lastName == lastName; });

        return (it != students.end()) ? &(*it) : nullptr;
    }

    void sortStudentsByLastName() {
        sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
            return a.lastName < b.lastName;
            });
    }

    void displayStudents() {
        if (students.empty()) {
            cout << "Группа пуста." << endl;
            return;
        }

        cout << "Фамилия\t\tИмя\t\tДата рождения\t\tНомер телефона" << endl;
        for (const auto& student : students) {
            cout << student.lastName << "\t" << student.firstName << "\t\t"
                << student.dateOfBirth << "\t\t" << student.phoneNumber << endl;
        }
    }
};

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Ru");
    StudentGroup group;

    while (true) {
        cout << "\nМеню:\n";
        cout << "1. Добавить студента\n";
        cout << "2. Удалить студента по фамилии\n";
        cout << "3. Найти студента по фамилии\n";
        cout << "4. Сортировать студентов по фамилии\n";
        cout << "5. Вывести список студентов\n";
        cout << "0. Выйти из программы\n";

        int choice;
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string firstName, lastName, dateOfBirth, phoneNumber;
            cout << "Введите имя студента: ";
            cin >> firstName;
            cout << "Введите фамилию студента: ";
            cin >> lastName;
            cout << "Введите дату рождения студента: ";
            cin >> dateOfBirth;
            cout << "Введите номер телефона студента: ";
            cin >> phoneNumber;

            group.addStudent(firstName, lastName, dateOfBirth, phoneNumber);
            break;
        }
        case 2: {
            string lastName;
            cout << "Введите фамилию студента для удаления: ";
            cin >> lastName;

            group.removeStudentByLastName(lastName);
            break;
        }
        case 3: {
            string lastName;
            cout << "Введите фамилию студента для поиска: ";
            cin >> lastName;

            Student* foundStudent = group.findStudentByLastName(lastName);
            if (foundStudent != nullptr) {
                cout << "Студент найден: " << foundStudent->firstName << " " << foundStudent->lastName << endl;
            }
            else {
                cout << "Студент не найден." << endl;
            }
            break;
        }
        case 4:
            group.sortStudentsByLastName();
            cout << "Студенты отсортированы по фамилии." << endl;
            break;
        case 5:
            group.displayStudents();
            break;
        case 0:
            return 0;
        default:
            cout << "Неверный выбор. Повторите попытку." << endl;
        }
    }

    return 0;
}
