//
// Created by Александр Широков on 04.05.2022.
//
#include "iostream"

void reverce(int* a) {
    for (int i=9; i>=0; i--) {
        std::cout<< *a + i << ' ';
    }
}
int main(){
int ar[10] = {1,2,3,4,5,6,7,8,9,10};
    reverce(ar);
}

