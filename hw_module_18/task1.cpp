//
// Created by Александр Широков on 12.05.2022.
//
#include "iostream"
#include "vector"
void swapvec(std::vector<int>& a, int b[])
{
    for(int i=0; i<a.size(); i++)
    {
        a[i]^=b[i];
        b[i]^=a[i];
        a[i]^=b[i];
    }
}
int main()
{
    std::vector<int> a = {1,2,3,4};
    int b[] = {2,4,6,8};
    swapvec(a,b);
    for(int i = 0; i < 4; ++i)
        std::cout << a[i];
    std::cout << std::endl;
    for(int i = 0; i < 4; ++i)
        std::cout << b[i];
}

