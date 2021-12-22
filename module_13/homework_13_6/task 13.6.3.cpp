//
// Created by Александр Широков on 13.12.2021.
//
#include "iostream"
#include "vector"


int main () {
    using namespace std;
    vector<int> databae = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int n=0;
    while (true) {
        cout << "Input a value into data base: ";
        cin >> n;
        if (n==-1) break;
        if (databae.size()>=20) {
            for (int i=0; i<databae.size()-1;i++){
                databae[i]=databae[i+1];
            }
            databae.back()=n;
        }
        else databae.push_back(n);
    }
    for (int i = 0; i<databae.size(); i++) {
        cout << databae[i] << ' ';
    }
    cout << endl;


}
