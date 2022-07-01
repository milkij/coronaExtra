//
// Created by Александр Широков on 28.06.2022.
//
#include "iostream"
#include "fstream"

bool substr(std::string path) {
    int size = path.size();
    std::string result;
    for (int i = size-4; i<size; i++){
        result +=path[i];
    }
    return result==".png" ? true : false;
}

int main() {
    std::ifstream png;
    std::string path = "//Users//alexander//CLionProjects//coronaExtra//module_19//123.png";
    std::cin >> path;
    if(!substr(path)) {
        std::cout << "this is not png file";
        return 0;
    };
    int num;
    char buffer[3];
    png.open(path,std::ios::binary);
    png >> num;
    png.read(buffer,3);
    if(num==-119 && buffer=="PNG") {
        std::cout << "This is png file";
    } else {
        std::cout << "this is not png file";
    }
    png.close();
}

