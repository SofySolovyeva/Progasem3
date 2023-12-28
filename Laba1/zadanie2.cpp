#include <iostream>
/*1) int *ptr = (int*)malloc(sizeof(int)); C++ : int *ptr = new int;
2) int *ptrArr = (int*)malloc(sizeof(int)*N); C++ : int *ptrArr = new int[N];
3) free(ptr); C++ : delete ptr;
4) free(ptrArr); C++ : delete[] ptrArr.
В C++ необходимо освобождать выделенную динамическую память. Нельзя освободить память дважды и освободить не выделенную память тоже нельзя.
*/

int main() {
    int numRows;
    std::cout << "Введите количество строк для треугольника Фибоначчи: ";
    std::cin >> numRows;

    int** triangle = new int*[numRows];

    for (int i = 0; i < numRows; i++) {
        triangle[i] = new int[i + 1];
    }

    for (int i = 0; i < numRows; i++) {
        int* row = triangle[i];
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                row[j] = 1;
            } else {
                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
        }
    }

    for (int i = 0; i < numRows; i++) {
        int* row = triangle[i];
        for (int j = 0; j <= i; j++) {
            std::cout << row[j] << " ";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < numRows; i++) {
        delete[] triangle[i];
    }
    delete[] triangle;

    return 0;
}