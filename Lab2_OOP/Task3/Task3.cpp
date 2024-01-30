#include <iostream>
#include <fstream>
#include <stack>
#include <vector>

class Stack {
private:
    std::vector<int> data;

public:
    void push(int value) {
        data.push_back(value);
    }

    void pop() {
        if (!isEmpty()) {
            data.pop_back();
        }
    }

    bool isEmpty() const {
        return data.empty();
    }

    int top() const {
        if (!isEmpty()) {
            return data.back();
        }
        else {
            // Возвращаем какой-то специальный флаг или выбрасываем исключение,
            // так как в пустом стеке нет вершины
            // В данном примере вернем -1 как флаг ошибки
            return -1;
        }
    }
};

void formTrain(Stack& inputStack, Stack& outputStackA, Stack& outputStackB) {
    while (!inputStack.isEmpty()) {
        int currentWagon = inputStack.top();
        inputStack.pop();

        // Пример условия для разделения по направлениям
        if (currentWagon % 2 == 0) {
            outputStackA.push(currentWagon);
        }
        else {
            outputStackB.push(currentWagon);
        }
    }
}

int main() {
    Stack inputStack;
    Stack outputStackA;
    Stack outputStackB;

    int choice;
    std::cout << "Choose input method:\n"
        << "1. Manual input\n"
        << "2. Read from file\n";
    std::cin >> choice;

    if (choice == 1) {
        // Ручной ввод
        int wagon;
        std::cout << "Enter wagon numbers (enter a non-integer to stop):\n";
        while (std::cin >> wagon) {
            inputStack.push(wagon);
        }
    }
    else if (choice == 2) {
        // Ввод из файла
        std::ifstream inputFile("train_composition.txt");
        int wagon;
        while (inputFile >> wagon) {
            inputStack.push(wagon);
        }
        inputFile.close();
    }
    else {
        std::cout << "Invalid choice. Exiting program.\n";
        return 1;
    }

    formTrain(inputStack, outputStackA, outputStackB);

    // Выводим результаты
    std::cout << "Train for Direction A:" << std::endl;
    while (!outputStackA.isEmpty()) {
        std::cout << outputStackA.top() << " ";
        outputStackA.pop();
    }
    std::cout << std::endl;

    std::cout << "Train for Direction B:" << std::endl;
    while (!outputStackB.isEmpty()) {
        std::cout << outputStackB.top() << " ";
        outputStackB.pop();
    }
    std::cout << std::endl;

    return 0;
}
