//
// Created by Александр Широков on 24.05.2022.
//
#include "iostream"
#include "fstream"
void readBuffer(char letter[], int size) {
    for (int i =0; i < size;i++) {
        std::cout<<letter[i];
    }
}

int main() {
    int bufferSize = 10;
    std::ifstream fileTXT;
    std::string path = "//Users//alexander//CLionProjects//coronaExtra//module_19//TXT_task2.txt";
    std::cin >> path;
    fileTXT.open(path,std::ios::binary);
    if(fileTXT.is_open()) {
        std::cout<< "File is open;"<< std::endl<< std::endl;
    } else {
        std::cout<< "File is not exists;"<< std::endl;
        return 0;
    }
    char buffer[bufferSize];
    while (!fileTXT.eof()) {
        fileTXT.read(buffer,sizeof(buffer));
        readBuffer(buffer,fileTXT.gcount());
    }
    fileTXT.close();

}
