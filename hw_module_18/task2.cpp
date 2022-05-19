//
// Created by Александр Широков on 12.05.2022.
//
#include "iostream"
long jump(int n)
{
    if(n<0) return 0;
    if(n==0) return 1;
    return jump(n-3) + jump(n-2) + jump(n-1);
}
int main()
{
    std::cout<<"Input count of steps: ";
    int n;
    std::cin >> n;
    std::cout << jump(n);
}

