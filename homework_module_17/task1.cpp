//
// Created by Александр Широков on 04.05.2022.
//
#include "iostream"
void swap(int* a, int* b) {
    *a ^= *b;
    std::cout<<*a<<std::endl;
    *b ^= *a;
    std::cout<<*b<<std::endl;
    *a ^= *b;
    std::cout<<*a<<std::endl;
    std::cout << *a << ' ' << *b << std::endl;
}
int main(){
    int a = 15;
    int b = 20;
    swap(&a, &b);
}

