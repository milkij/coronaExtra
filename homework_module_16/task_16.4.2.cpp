//
// Created by Александр Широков on 20.04.2022.
/*Задание 2. Сшиватель дробных чисел
Что нужно сделать
Напишите небольшую программу.
 Из целой и дробной частей числа, которые в отдельности вводит пользователь, составьте новое число с плавающей точкой (типа double)
 и выведите это число обратно в консоль для проверки. Целая часть — это часть числа, которая находится до точки (запятой), дробная — после.
Рекомендации
Вам потребуется функция StringToDouble — std::stod. Она принимает на вход строку, содержащую в себе число.*/
#include "iostream"
#include "string"
int main() {
    std::string integer, fractional;
    std::cin >> integer >> fractional;
    double number =std::stod(integer+'.'+fractional);
    std::cout<<number<<std::endl;
}

