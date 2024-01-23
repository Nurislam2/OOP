////№1
//#include <iostream>
//using namespace std;
//double power(double n, int p) {
//        double nn = n;
//        for (int i = 1; i < p; i++) {
//            n = nn * n;
//        }
//        return n;
//    }
//
//int main()
//{
//    setlocale(0, "");
//    double n;
//    int p;
//    cout << "Введите число и степень в которую ее надо возвести!\n";
//    cout << "double: ";
//    cin >> n;
//    cout << "степень: ";
//    cin >> p;
//    cout << "Ответ: ";
//    cout << power(n,p);
//    return 0;
//}
//
//2
//#include <iostream>
//using namespace std;
//double power(double n, int p=2);
//char power(char n, int p=2);
//long int power(long int n, int p=2);
//float power(float n, int p=2);
//
//int main()
//{
//    setlocale(0, "");
//    int p;
//    double n;
//    char c;
//    long int l;
//    float f;
//    cout << "Введите число и степень в которую ее надо возвести!\n";
//    cout << "double: ";
//    cin >> n;
//    cout << "Ответ: "<< power(n)<<endl;
//    cout << "Char: ";
//    cin >> c;
//    cout << "Ответ: " << power(c)<<endl;
//    cout << "Long int: ";
//    cin >> l;
//    cout << "Ответ: " << power(l)<<endl;
//    cout << "Float: ";
//    cin >> f;
//    cout << "Ответ: "<< power(f);
//}
//double power(double n, int p) {
//    double nn = n;
//    for (int i = 1; i < p; i++) {
//        n = nn * n;
//    }
//    return n;
//}
//
//char power(char n, int p) {
//    char nn = n;
//    for (int i = 1; i < p; i++) {
//        n = nn * n;
//    }
//    return n;
//}
//long int power(long int n, int p) {
//    long int nn = n;
//    for (int i = 1; i < p; i++) {
//        n = nn * n;
//    }
//    return n;
//}
//float power(float n, int p) {
//    float nn = n;
//    for (int i = 1; i < p; i++) {
//        n = nn * n;
//    }
//    return n;
//}
//int power(int n, int p) {
//    int nn = n;
//    for (int i = 1; i < p; i++) {
//        n = nn * n;
//    }
//    return n;
//}



//№3
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Employee {
    string lastName;
    int age;
    string specialty;
    double averageSalary;
};

int main() {
    setlocale(0, "");

    int N; // number of factories
    cout << "Enter the number of factories: ";
    cin >> N;

    // Create a vector to store information about employees
    vector<vector<Employee>> factories(N);

     //Input information about employees for each factory
    for (int i = 0; i < N; ++i) {
        int M; // number of employees in the current factory
        cout << "Enter the number of employees at factory " << i + 1 << ": ";
        cin >> M;

        // Input information about each employee
        for (int j = 0; j < M; ++j) {
            Employee employee;
            cout << "Enter information for employee " << j + 1 << " at factory " << i + 1 << ":" << endl;
            cout << "Last Name: ";
            cin >> employee.lastName;
            cout << "Age: ";
            cin >> employee.age;
            cout << "Specialty: ";
            cin >> employee.specialty;
            cout << "Average Salary: ";
            cin >> employee.averageSalary;

            factories[i].push_back(employee);
        }
    }

    // Count the number of locksmiths and turners
    int countLocksmith = 0;
    int countTurner = 0;

    for (const auto& factory : factories) {
        for (const auto& employee : factory) {
            if (employee.specialty == "locksmith") {
                countLocksmith++;
            }
            else if (employee.specialty == "turner") {
                countTurner++;
            }
        }
    }

    // Display the results
    cout << "Number of locksmiths: " << countLocksmith << endl;
    cout << "Number of turners: " << countTurner << endl;

    return 0;
}
