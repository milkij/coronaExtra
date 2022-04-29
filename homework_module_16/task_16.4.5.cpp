//
// Created by Александр Широков on 26.04.2022.
/*
 * Умный дом

Что нужно сделать

Разработайте упрощённую модель умного дома для дачи. Выполните симуляцию его работы на протяжении двух дней. Стартовое время для симуляции умного дома 00:00. Есть несколько датчиков: датчик температуры снаружи, датчик температуры внутри дома. В доме расположен электронный умный щиток с автоматами. Каждый автомат отвечает за включение и отключение определённых устройств или групп устройств:

отключение и включение питания всего дома;
основные розетки дома;
свет внутри дома;
наружный свет в саду;
отопление в помещении;
отопление водопровода, идущего из скважины с насосом;
кондиционер в помещении.
Есть несколько условий по включению/отключению техники в доме и вне его.

Как только температура снаружи падает ниже 0 °С, надо включить систему обогрева водопровода.
Если температура снаружи поднялась выше 5 °С, то систему обогрева водопровода нужно отключить.
Если на дворе вечер (время больше 16:00 и меньше 5:00 утра) и снаружи есть какое-то движение, то необходимо включить садовое освещение.
Если движения нет или время не вечернее, то света снаружи быть не должно.
Если температура в помещении упала ниже 22 °С, должно включиться отопление.
Как только температура равна или поднимается выше 25 °С, отопление автоматически отключается.
Если температура в помещении поднялась до 30 °С, включается кондиционер. Как только температура становится 25 °С, кондиционер отключается.
Всё освещение в доме также умное и поддерживает настройку цветовой температуры для комфортного нахождения.
 Каждый день начиная с 16:00 и до 20:00 температура цвета должна плавно изменяться с 5000K до 2700К.
 Разумеется, это изменение должно происходить, если свет сейчас включён. В 00:00 температура сбрасывается до 5000К.
Все события по отключению и включению устройств должны выводиться в консоль явным образом.
 Если устройство не изменило своё состояние (осталось включённым или выключенным), событие генерироваться не должно! Если свет в доме включён, должна отображаться текущая цветовая температура.

Программа выполняется следующим образом:

Каждый час пользователь сообщает состояние всех основных датчиков и света
(температура снаружи, температура внутри, есть ли движение снаружи, включён ли свет в доме).
Данные параметры вводятся разом в одну строку через пробел, а потом парсятся в переменные из строкового буфера stringstream.
Информация о движении выводится в формате yes/no.
Включение и отключение света происходит с помощью on/off.


Рекомендации

Состояние переключателей можно хранить в перечислении вида:

enum switches
{
    LIGHTS_INSIDE = 1,
    LIGHTS_OUTSIDE = 2,
    HEATERS = 4,
    WATER_PIPE_HEATING = 8,
    CONDITIONER = 16
};
Чтобы включить обогреватель, нужно написать switches_state |= HEATERS; Чтобы выключить — switches_state &= ~HEATERS;
 * */

#include "iostream"
#include "sstream"

enum switches
{
    LIGHTS_INSIDE = 1,
    LIGHTS_OUTSIDE = 2,
    HEATERS = 4,
    WATER_PIPE_HEATING = 8,
    CONDITIONER = 16
};
int switches_state=0;
void checkStatesOfHouse(double temperatureInside, double temperatureOutside,
                        std::string movementOutside, std::string lightInsdie, int hours, int switches_state) {
        if(temperatureOutside<0) {
            switches_state |= WATER_PIPE_HEATING;
            std::cout<<"WATER_PIPE_HEATING IS ON"<<std::endl;
            std::cout<<switches_state<<std::endl;
        }
        if(temperatureOutside>5 && (switches_state & WATER_PIPE_HEATING)) {
            switches_state &= WATER_PIPE_HEATING;
            std::cout<<"WATER_PIPE_HEATING IS OFF"<<std::endl;
            std::cout<<switches_state<<std::endl;
        }
        if((hours>=16 || hours<=5) && movementOutside=="yes") {
            switches_state |= LIGHTS_OUTSIDE;
            std::cout<<"LIGHTS_OUTSIDE IS ON"<<std::endl;
            std::cout<<switches_state<<std::endl;
        }
        if(((hours>=16 || hours<=5) && movementOutside=="no" && (switches_state & LIGHTS_OUTSIDE))
                || (hours>5 && hours<16) && (switches_state & LIGHTS_OUTSIDE)) {
            switches_state &= LIGHTS_OUTSIDE;
            std::cout<<"LIGHTS_OUTSIDE IS OFF"<<std::endl;
            std::cout<<switches_state<<std::endl;
        }
        if(temperatureInside<22){
            switches_state|=HEATERS;
            std::cout<<"HEATERS IS ON"<<std::endl;
            std::cout<<switches_state<<std::endl;
        }
        if(temperatureInside>=25 && (switches_state & HEATERS)){
            switches_state&=HEATERS;
            std::cout<<"HEATERS IS OFF"<<std::endl;
            std::cout<<switches_state<<std::endl;
        }
        if(temperatureInside>=30){
            switches_state|=CONDITIONER;
            std::cout<<"CONDITIONER IS ON"<<std::endl;
            std::cout<<switches_state<<std::endl;
        }
        if(temperatureInside<=25 && (switches_state & CONDITIONER)){
            switches_state&=CONDITIONER;
            std::cout<<"CONDITIONER IS OFF"<<std::endl;
            std::cout<<switches_state<<std::endl;
        }
        if(lightInsdie=="on") {
            switches_state|=LIGHTS_INSIDE;
            std::cout<<"LIGHTS_INSIDE IS ON"<<std::endl;
            if(hours>=16 && hours <20) {
                std::cout<<"The temperature of light is 2500K."<<std::endl;
            } else std::cout<<"The temperature of light is 5000K."<<std::endl;
            std::cout<<switches_state<<std::endl;
        }
        if(lightInsdie=="off" && (switches_state & LIGHTS_OUTSIDE)) {
            switches_state&=LIGHTS_INSIDE;
            std::cout<<"LIGHTS_INSIDE IS OFF"<<std::endl;
            std::cout<<switches_state<<std::endl;
        }
}

int main() {
    int hours=0;
    int day=1;
    std::string parameters;
    while (day <=2){
        std::cout<<day<<" Day, "<<hours<<" o'clock. Input parametrs (temperatureInside, temperatureOutside, movementOutside,lightInsdie): ";
        std::getline(std::cin,parameters);
        std::stringstream buffer_stream(parameters);
        //температура снаружи, температура внутри, есть ли движение снаружи, включён ли свет в доме
        double temperatureInside, temperatureOutside;
        std::string movementOutside, lightInsdie;
        buffer_stream >> temperatureInside >> temperatureOutside >> movementOutside >> lightInsdie;
        //validation data?
        if(false) {
            std::cout<<"Input parametrs again: "<<std::endl;
        } else {
            checkStatesOfHouse(temperatureInside,temperatureOutside,movementOutside,lightInsdie,hours,switches_state);
            hours++;
            if(hours==24) {
                day++;
                hours=0;
            }
        }

    }
    return 0;
}
