//
// Created by  Milkij on 09.09.2021.
//
#include "iostream"

// Функция быстрой сортировки
void quickSort(int numbers[], int left, int right)
{
    int pivot; // разрешающий элемент
    int l_hold = left; //левая граница
    int r_hold = right; // правая граница
    pivot = numbers[left];
    while (left < right) // пока границы не сомкнутся
    {
        while ((numbers[right] >= pivot) && (left < right))
            right--; // сдвигаем правую границу пока элемент [right] больше [pivot]
        if (left != right) // если границы не сомкнулись
        {
            numbers[left] = numbers[right]; // перемещаем элемент [right] на место разрешающего
            left++; // сдвигаем левую границу вправо
        }
        while ((numbers[left] <= pivot) && (left < right))
            left++; // сдвигаем левую границу пока элемент [left] меньше [pivot]
        if (left != right) // если границы не сомкнулись
        {
            numbers[right] = numbers[left]; // перемещаем элемент [left] на место [right]
            right--; // сдвигаем правую границу вправо
        }
    }
    numbers[left] = pivot; // ставим разрешающий элемент на место
    pivot = left;
    left = l_hold;
    right = r_hold;
    if (left < pivot) // Рекурсивно вызываем сортировку для левой и правой части массива
        quickSort(numbers, left, pivot - 1);
    if (right > pivot)
        quickSort(numbers, pivot + 1, right);
}

int main(){
    int numbers[15];
    int X;
    std::cout << "Input the first number:" << std::endl;
    std::cin >> X;
    std::cout << std::endl;
    for (int i = 0; i<15; i++) {
        numbers[i]=X+i;
    }
    int randomIndex,randomPlace;
    while (true) {
        randomIndex = rand() % 15;
        randomPlace = rand() % 15;
      if(randomIndex!=randomPlace) {
          numbers[randomIndex] = numbers[randomPlace];
          break;
      }
    }

    std::cout << "The X number is " << X << " and ";
    quickSort(numbers, 0, 14);
    for (int i = 0; i<15; i++)
        if(numbers[i]==numbers[i+1]) std::cout << "the coincidence number is " << numbers[i] << "." << std::endl;
        return 0;
    }

