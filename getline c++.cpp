#include <iostream>
#include <string>

int main() {
    std::string str;
    while (std::getline(std::cin, str)) {
        std::cout << "Da doc: " << str << '\n';
    }
    return 0;
}

