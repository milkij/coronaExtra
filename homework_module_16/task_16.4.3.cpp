//
// Created by Александр Широков on 20.04.2022.
/*Задание 3. Калькулятор

Что нужно сделать

Создайте небольшую программу для вычисления простых действий с числами.
 При запуске программа ожидает пользовательского ввода во временную переменную строку.
 После ввода строки она распарсивается на отдельные члены.
 Строка записывается в форме “<число-1><действие><число-2>” (без пробелов). Оба числа — это значения с плавающей точкой, повышенной точности (double).
 Действие может быть одним из: +, −, /, *. Результат действия выводится в стандартный вывод cout.

Рекомендации

Чтобы разделить полученную строку на отдельные элементы — числа и оператор, воспользуйтесь строковым потоком.
 Для этого создайте пустую строку std::string buffer и дайте пользователю возможность при помощи std::cin ввести в неё команду.
 Затем оберните полученную строку так: std::stringstream buffer_stream(buffer);
 Это позволит вам  получить каждый из трёх компонентов команды: buffer_stream >> a >> operation >> b;*/
#include "iostream"
#include "sstream"
double calc(double a, double b, char operation){
    if(operation=='+') return a+b;
    if(operation=='-') return a-b;
    if(operation=='/') return a/b;
    if(operation=='*') return a*b;
}
int main(){
    std::string buffer;
    std::cin >> buffer;
    std::stringstream buffer_stream(buffer);
    double a,b;
    char operation;
    buffer_stream >> a >> operation >> b;
    if(operation=='-'||operation=='+'||operation=='/'||operation=='*') std::cout << calc(a,b,operation);
    else std::cout << "Incorrect operation";
}



