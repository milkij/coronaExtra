//
// Created by Александр Широков on 19.05.2022.
//
#include "iostream"

void evendigits(long n, int& ans)
{
    assert(n>=0);
    if (n==0) return;
    if (n%2 == 0 || n%10==0) ans++;
    evendigits(n/=10,ans);
};
int main()
{
    long long n = 9223372036854775806;
    int ans=0;
    evendigits(n,ans);
    std::cout<< ans;

}
