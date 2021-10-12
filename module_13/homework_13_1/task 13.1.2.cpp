#include "iostream"
#include "vector"

int main(){
    int N;
    std::cin >> N;
    std::vector<float> vec(N);
    for (int i=0;i<N;i++){
        std::cin >> vec[i];
    }
    for (int i=N-1;i>=0;i--){
        std::cout << vec[i] << std::endl;
    }
}