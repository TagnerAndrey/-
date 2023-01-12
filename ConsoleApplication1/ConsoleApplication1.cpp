
#include <iostream>
#include <string>
#include <cassert>

int main() {
    
    std::string card_number;
    std::cout << "номер карты (4561261212345467) = ";
    std::getline(std::cin, card_number);
    if (card_number.empty()) {
        card_number = "4561261212345467";
    }

    unsigned cnt = 1, n = 0, sum = 0;
    
    for (std::string::reverse_iterator it = card_number.rbegin();
        it != card_number.rend();
        ++it, ++cnt) {
        
        assert(*it >= '0' && *it <= '9');
        n = *it - '0';
        
        sum += (cnt % 2) ? n : ((n * 2) % 9);
    }

    
    std::cout
        << "контрольная сумма (" << sum
        << ") для карты " << card_number
        << (sum % 10 ? " НЕ " : " ") << "верна"
        << std::endl;
}