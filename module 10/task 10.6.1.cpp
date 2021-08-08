#include <iostream>

std::string encrypt_caesar (std::string str, int number) {
    std::string result;
    int spliter = 26;
    number %= spliter;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] + number > 'z' && str[i] >= 'a' && str[i] <= 'z') {
            result += 'a' + (((str[i] - 96) + number) % spliter) - 1;
        } else if (str[i] + number < 'a' && str[i] >= 'a' && str[i] <= 'z') {
            result += (char) ('z'  + ((str[i] - 96) + number));
        } else if (str[i] + number > 'Z' && str[i] >= 'A' && str[i] <= 'Z') {
            result += 'A' + (((str[i] - 64) + number) % spliter) - 1;
        } else if (str[i] + number < 'A' && str[i] >= 'A' && str[i] <= 'Z') {
            result += (char) ('Z'  + ((str[i] - 64) + number));
        } else if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z') {
            result += str[i] + number;
        } else {
            result += str[i];
        }
    }
    return result;
}

std::string decrypt_caesar (std::string str, int number) {
    return encrypt_caesar(str, number * -1);
}

int main {
    std::cout << "Input a string: " << std::endl;
    std::string str;
    std::getline(std::cin, str) ;
    std::cout << "Input a number: " << std::endl;
    int number;
    std::cin >> number;

    std::cout << encrypt_caesar(str,number) << std::endl;
    std::cout << decrypt_caesar(encrypt_caesar(str,number), number);

}
