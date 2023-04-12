#include <iostream>
#include <string>
#include <regex>

int main() {
    setlocale(LC_ALL, "Russian");
    std::string input;
    std::regex pattern(R"(^(\+7|8)(\s+)?(\(|\s+)?\d{3}(\)|\s+)?\d{3}(-|\s+)?\d{2}(-|\s+)?\d{2}$)");

    do {
        std::cout << "Введите номер мобильного телефона: ";
        std::getline(std::cin, input);

        if (std::regex_match(input, pattern)) {
            
            std::cout << "Введенный номер: " << input << std::endl;

           
            std::string phone_number = "";
            for (char c : input) {
                if (isdigit(c)) {
                    phone_number += c;
                }
            }
            std::cout << "Номер в формате 88005555550: " << phone_number << std::endl;

           
            break;
        }
        else {
            std::cout << "Некорректный ввод. Попробуйте еще раз." << std::endl;
        }
    } while (true);

    return 0;
}
