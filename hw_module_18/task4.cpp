//
// Created by Александр Широков on 19.05.2022.
//
#include "iostream"

void evendigits(long n, int& ans)
{
    if (n==0) return;
    if (n%2 == 0 && n%10) ans++;
    evendigits(n/=10,ans);
};
int main()
{
    long long n = 1002022;
    int ans=0;
    evendigits(n,ans);
    std::cout<< ans;

}
