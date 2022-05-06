//
// Created by Александр Широков on 04.05.2022.
//
#include "iostream"
#include "cstring"

bool substr(char* a, char* b) {
    int pos=0;
    bool equel;
    while (true) {
        equel=true;
        for (int i=pos; *(a+i)!='\0';) {
            //std::cout << *(a+i)  << ' ' << *b << ' ' ;
            if(*(a+i)==*b) {
                //std::cout << '1' << std::endl;
                pos=i;
                break;
            } //else std::cout << '0' << std::endl;
            i++;
            if(*(a+i)=='\0') pos=-1;
        }
            if (pos==-1) {
            equel=false;
            break;
        } else pos+=1;
        for (int y = 1; *(b+y)!='\0' && equel;) {
            if(*(b+y)==*(a+pos)) {
                y++;
            }
            else {
                equel==false;
                pos+=y;
                //std::cout<<std::endl<<"Not_equel"<<std::endl;
            }
        }
        if(equel) {
            //std::cout<<std::endl<<"Equel"<<std::endl;
            break;
        }
    }
    return equel;
}

int main() {
    char* a = "Hello world";
    char* b = "wor";
    char* c = "banana";
    std::cout << substr(a,b) << ' ' << substr(a,c);
    return 0;
}

