#include "iostream"
#include "vector"

int main(){
    int N;
    std::cin >> N;
    std::vector<int> vec(N);
    float sum=0;
    for (int i=0; i<N; i++){
        std::cin >> vec[i];
        sum+=vec[i];
    }
    std::cout << sum / N;
}