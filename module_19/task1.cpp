//
// Created by Александр Широков on 24.05.2022.
//
#include "iostream"
#include "fstream"
int countWordsInFile(std::string word)
{
    std::ifstream text;
    int count=0;
    text.open("//Users//alexander//CLionProjects//coronaExtra//module_19//words.txt");
    while (!text.eof()) {
        std::string wordForCompare;
        text>>wordForCompare;
        if(wordForCompare==word) count++;
    }
    text.close();
    return count;
}
int main()
{
    std::cout << "Input word for compare: ";
    std::string word;
    std::cin >> word;
    countWordsInFile(word) > 0 ? std::cout << "Text contains " << countWordsInFile(word) << " word/s" : std::cout << "There is no word "<<word;
}