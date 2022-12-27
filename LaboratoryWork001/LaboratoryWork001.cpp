#include <iostream>
using namespace std;

double** CreatingDynamicArray(int n, int m);
void RemovArray(double** arr, int n);
void PrintArray(double** arr, int n, int m);
void FillingArrayRandomNumbers(double** arr, int n, int m);

//Завдання 1. Видалити з двовимірного масива парні рядки (четные строки)
//по индексу?
void DeleteEvenRows(double** &arr, int &lines,const int columns) {
    double** _arr = CreatingDynamicArray(lines/2, columns);
    int i2 = 0;
    for (size_t i = 1; i < lines; i+=2)
    {
        for (size_t j = 0; j < columns; j++)
        {

            _arr[i2][j] = arr[i][j];
        }
        i2++;
        /*cout << "изменено?" << endl;
        PrintArray(_arr, lines / 2, columns);*/
    }
    RemovArray(arr, lines);
    /*PrintArray(_arr, lines / 2, columns);*/
    arr = _arr;
    lines = lines/2;
 }

//Завдання 2. Видалити з двовимірного масива непарні стовбці (нечетные столбци)
//по индексу?
void RemoveOddColumns(double** &arr,const int lines, int &columns) {
    double** _arr = CreatingDynamicArray(lines, columns-columns/2);
    for (size_t i = 0; i < lines; i++)
    {
        int j2 = 0;
        for (size_t j = 0; j < columns; j+=2)
        {
            _arr[i][j2] = arr[i][j];
            j2++;
        }
    }
    RemovArray(arr, lines);
    arr = _arr;
    columns = columns- columns /2;
}

int main()
{
    setlocale(LC_ALL, "");
    int lines, columns;

    do
    {
        system("cls");
        cout << "Введите количество строк >> ";
        cin >> lines;
        cout << "Введите количество столбцов >> ";
        cin >> columns;
        system("cls");

        double** arr = CreatingDynamicArray(lines, columns);

        FillingArrayRandomNumbers(arr, lines, columns);
        cout << "Оригинальный массив" << endl;
        PrintArray(arr, lines, columns);

        DeleteEvenRows(arr, lines, columns);
        cout << "Массив после удаление четных строк" << endl;
        PrintArray(arr, lines, columns);

        RemoveOddColumns(arr, lines, columns);
        cout << "Массив после удаление не четных столбцов" << endl;
        PrintArray(arr, lines, columns);

        RemovArray(arr, lines);

        char choise;
        cout << "1 - повторить" << endl;
        cout << "2 - выход" << endl;
        cin >> choise;
        cin.clear();
        if (choise == '1') {
            continue;
        }
        else if (choise == '2')
        {
            break;
        }
        else
        {
            cout << "Не корректный ввод" << endl;
        }
    } while (true);


}

double** CreatingDynamicArray(int n, int m) {
    double** arr = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (double*)malloc(m * sizeof(double));
    }
    return arr;
}

void RemovArray(double** arr, int n) {
    for (size_t i = 0; i < n; i++)
    {
        free(arr[i]);
    }
    free(arr);
}

void FillingArrayRandomNumbers(double** arr, int n, int m) {
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            arr[i][j] = 0.001 * (rand() % 10000);
        }
    }
}

void PrintArray(double** arr, int n, int m) {
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}