#include <iostream>
#include <ctime>

using namespace std;
const int SIZE = 10;
int* createArray(int* mas, int SIZE);
void printArray(int* a);
void hoarasort(int* a, int first, int last);

int main() {
    setlocale(LC_ALL, "rus");
    int mas[SIZE] = {};
    int* pMas = createArray(mas, SIZE);
    printArray(mas);
    hoarasort(mas, 0, SIZE - 1);
    printArray(mas);
    return 0;
}

void hoarasort(int* a, int first, int last) //сортировка Хоара
{

    int i = first, j = last;
    double tmp, x = a[(first + last) / 2];

    do {
        while (a[i] < x)
            i++;
        while (a[j] > x)
            j--;

        if (i <= j)
        {
            if (i < j)
            {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
            i++;
            j--;
        }
    } while (i <= j);

    if (i < last)
        hoarasort(a, i, last);
    if (first < j)
        hoarasort(a, first, j);
}

void printArray(int* a)
{
    for (int i = 0; i < SIZE; i++) {
        cout << a[i] << endl;
    }
    cout << endl;
}

int* createArray(int* mas, int SIZE)
{
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        mas[i] = rand() % 20;
    }
    return mas;
}