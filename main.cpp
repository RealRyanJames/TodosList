#include <iostream>
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

int main() {
    Length auto len = 0;

    PrintMessageUpper("Enter Length of Todos Asked: ", NULL);
    std::cin >> len;

    for (constexpr std::vector<std::string> todos; const std::string& todo : todos) {
        constexpr std::string todo_1;
        constexpr std::string todo_2;
        PrintMessageUpper(todo, 0);
        PrintGet(len, todos, todo_1, todo_2);
    }
}