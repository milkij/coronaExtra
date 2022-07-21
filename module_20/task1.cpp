//
// Created by Александр Широков on 05.07.2022.
//
#include "iostream"
#include "fstream"
#include "string"
int curr_year=2022;
bool check_date(std::string date){
    if(date.length()!=10) return false;
    if(date[2]!='.' || date[5]!='.') return false;
    if (std::stoi(date.substr(0,2)) < 1 || std::stoi(date.substr(0,2)) > 31) return false;
    if (std::stoi(date.substr(3,2)) < 1 || std::stoi(date.substr(0,2)) > 12) return false;
    return true;
}
int count_of_emploees;
int main(){
    std::cout << "Input count of emploees in file: ";
    std::cin >> count_of_emploees;
    std::ofstream billing_2022("//Users//alexander//CLionProjects//coronaExtra//module_20//billing_2022.txt");
    if(!billing_2022.is_open()) {
        std::cout << "File wan't open" << std::endl;
        return 0;
    }
    billing_2022 << "--- This is a billing of " << curr_year << " year ---" << std::endl;
    int line=0;
    //char* end_of_string;
    std::string first_name;
    std::string last_name;
    std::string date;
    int sum;
    while(line<count_of_emploees){
        std::cout<<"String "<<line+1<<"\n Input first name and last name: ";
        std::cin >> first_name >> last_name;
        billing_2022 << first_name << ' ' << last_name << ' ';
        std::cout<<" Input date in format DD.MM.YYYY: ";
        std::cin >> date;
        while(!check_date(date)) {
            std::cout<<"Incorrect date! Input date in format DD.MM.YYYY: ";
            std::cin >> date;
        }
        billing_2022 << date << ' ';
        std::cout<<" Input Sum: ";
        double sum;
        std::cin >> sum;
        billing_2022 << sum;
        billing_2022 << " RUB" << std::endl ;
        line++;
    }
    billing_2022.close();
}

