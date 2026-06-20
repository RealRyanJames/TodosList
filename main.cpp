#include <fstream>
#include <iostream>
#include <list>
#include <utility>
#include <vector>

template<typename T>
concept Length = requires(T length)
{
    length;
};

static std::string UpperMessage(std::string str) {
    std::ranges::transform(str, str.begin(), ::toupper);

    return str;
}


static void PrintMessageUpper(const std::string& message, int index) {
    std::println("{}{}", UpperMessage(message), index);
}

static void PrintGet(const int len, std::vector<std::string> todos, std::string todo_1, std::string todo_2) {
    for (auto i = 0; i < len; i++) {
        i++;
        PrintMessageUpper("Enter Todo ", i);
        std::cin >> todo_1;

        PrintMessageUpper("Enter Todo ", i);
        std::cin >> todo_2;

        todos.emplace_back(todo_1);
        todos.emplace_back(todo_2);
    }
}

namespace {

    struct TodosList {
        std::string todo_1;
        std::string todo_2;
        bool isRunning;
    };
};

static std::string PrintTitle(std::string str) {
    return UpperMessage(std::move(str));
}

int main() {
    Length auto len = 0;

    PrintTitle("Todo List | CLI");

    PrintMessageUpper("Enter Length of Todos Asked: ", NULL);
    std::cin >> len;

    if (const TodosList todos_List {"", "", true}; todos_List.isRunning) {
        for (constexpr std::vector<std::string> todos; const std::string& todo : todos) {
            std::string todo_one = todos_List.todo_1;
            std::string todo_two = todos_List.todo_2;
            PrintMessageUpper(todo, 0);
            PrintGet(len, todos, todo_one, todo_one);

            if (std::fstream fFile("file.todos"); fFile.is_open()) {
                fFile << "Todo 1: " << todo_one << "\n";
                fFile << "Todo 2: " << todo_two << "\n";
            }
        }
    }
}