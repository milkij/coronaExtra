//
// Created by Александр Широков on 13.04.2022.
/*Задание 1. Спидометр
Что нужно сделать
Реализуйте цифровой спидометр автомобиля.
 Сама модель автомобиля, которую нужно будет воссоздать, весьма проста. Начальная скорость — 0 км/ч.
 Пользователь вводит в стандартный ввод разницу (дельту) в скорости, и результирующая скорость показывается на спидометре в стандартный вывод.
 Так происходит до той поры, пока машина снова не остановится, то есть пока скорость не станет меньше или равна нулю (сравнение должно происходить с дельтой в 0,01).
 Диапазон возможных значений скорости машины от 0 до 150 км/ч.
 Сам показатель спидометра вместе с единицами измерения требуется записывать в отдельную строку-буфер, которая потом и будет показываться на экране.
 Точность отображения скорости — до 0,1 км/ч.
Рекомендации
Используйте цикл do … while для организации постоянного опроса пользователя.
 Для отображения числа с нужной точностью воспользуйтесь функцией std::sprintf(speed_str, "%.1f", speed_value);
 где speed_str — строка, в которую функция sprintf «печатает» значение скорости (speed_value) с одним знаком после десятичной точки (%.1f).
 */
#include "iostream"
#include "cstdio"

bool speed_limits(double delta_speed, double current_speed, double reference, double min_speed, double max_speed) {
    return current_speed+delta_speed<max_speed+reference && current_speed+delta_speed>min_speed-reference;
}
int main() {
    double cur_speed =0;
    double delta_speed =0;
    char result[100];
    do {
        std::cout<<"Ínput delta: ";
        std::cin>>delta_speed;
        if(speed_limits(delta_speed,cur_speed,0.1,0,150.0)) {
            cur_speed+=delta_speed;
            std::sprintf(result, "Current speed %.1f", cur_speed);
            std::cout<<result<<std::endl;
        } else {
            std::cout<<"Try again"
                       " Max speed 150 km/h"<<std::endl;
            std::cout<<"Input speed again"<<std::endl;

        }
    } while (cur_speed>0);

    std::cout<<"Thank u for using this program"<<std::endl;
}
