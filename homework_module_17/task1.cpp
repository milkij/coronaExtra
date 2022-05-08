//
// Created by Александр Широков on 04.05.2022.
//
#include "iostream"
void swap(int* a, int* b) {
    *a ^= *b;
    *b = *a&~*b;
    *a &=~ *b;
    std::cout << *a << ' ' << *b << std::endl;
}
int main(){
    int a = 10;
    int b = 20;
    swap(&a, &b);
}

