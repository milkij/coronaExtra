//
// Created by Александр Широков on 19.05.2022.
//
#include "iostream"
int jump(int n, int k=3)
{
    int res=0;
    if(n<0) return 0;
    if(n==0) return 1;
    for (int i=k; i>0; i--) {
        res+= jump(n-i);
    }
    return res;
}
int main()
{
    std::cout<<"Input count of steps and max junp: ";
    int n,k;
    std::cin >> n >> k;

    std::cout << jump(n,k);
    //fib(3);
}
