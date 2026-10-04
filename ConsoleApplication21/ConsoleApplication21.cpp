#include <iostream>
#include <windows.h>

using namespace std;

void print_array(int** arr, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

void add_column(int**& arr, int rows, int& cols, int position)
{
    int** newArr = new int* [rows];

    for (int i = 0; i < rows; i++)
    {
        newArr[i] = new int[cols + 1];

        for (int j = 0; j < position; j++)
        {
            newArr[i][j] = arr[i][j];
        }

        newArr[i][position] = 0;

        for (int j = position; j < cols; j++)
        {
            newArr[i][j + 1] = arr[i][j];
        }
    }

    for (int i = 0; i < rows; i++)
        delete[] arr[i];

    delete[] arr;

    arr = newArr;
    cols++;
}

void delete_column(int**& arr, int rows, int& cols, int position)
{
    int** newArr = new int* [rows];

    for (int i = 0; i < rows; i++)
    {
        newArr[i] = new int[cols - 1];

        for (int j = 0; j < position; j++)
        {
            newArr[i][j] = arr[i][j];
        }

        for (int j = position; j < cols - 1; j++)
        {
            newArr[i][j] = arr[i][j + 1];
        }
    }

    for (int i = 0; i < rows; i++)
        delete[] arr[i];

    delete[] arr;

    arr = newArr;
    cols--;
}


void shift_rows(int** arr, int rows, int cols, int count, char direction)
{
    for (int k = 0; k < count; k++)
    {
        if (direction == 'r')
        {
            int* temp = arr[rows - 1];

            for (int i = rows - 1; i > 0; i--)
            {
                arr[i] = arr[i - 1];
            }

            arr[0] = temp;
        }
        else
        {
            int* temp = arr[0];

            for (int i = 0; i < rows - 1; i++)
            {
                arr[i] = arr[i + 1];
            }

            arr[rows - 1] = temp;
        }
    }
}


void shift_columns(int** arr, int rows, int cols, int count, char direction)
{
    for (int k = 0; k < count; k++)
    {
        if (direction == 'r')
        {
            for (int i = 0; i < rows; i++)
            {
                int temp = arr[i][cols - 1];

                for (int j = cols - 1; j > 0; j--)
                {
                    arr[i][j] = arr[i][j - 1];
                }

                arr[i][0] = temp;
            }
        }
        else
        {
            for (int i = 0; i < rows; i++)
            {
                int temp = arr[i][0];

                for (int j = 0; j < cols - 1; j++)
                {
                    arr[i][j] = arr[i][j + 1];
                }

                arr[i][cols - 1] = temp;
            }
        }
    }
}

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int rows = 3;
    int cols = 4;

    int** arr = new int* [rows];

    for (int i = 0; i < rows; i++)
    {
        arr[i] = new int[cols];

        for (int j = 0; j < cols; j++)
        {
            arr[i][j] = i + j + 1;
        }
    }

    int a;

    do
    {
        cout << "Введіть номер завдання (1-3)(Вихід - 0): ";
        cin >> a;

        switch (a)
        {
        case 1:
        {
            cout << "Початковий масив:" << endl;
            print_array(arr, rows, cols);

            int position;
            cout << "Введіть позицію: ";
            cin >> position;

            add_column(arr, rows, cols, position);

            cout << "Після додавання:" << endl;
            print_array(arr, rows, cols);

            break;
        }

        case 2:
        {
            cout << "Початковий масив:" << endl;
            print_array(arr, rows, cols);

            int position;
            cout << "Введіть номер стовпчика: ";
            cin >> position;

            delete_column(arr, rows, cols, position);

            cout << "Після видалення:" << endl;
            print_array(arr, rows, cols);

            break;
        }

        case 3:
        {
            int choice;
            int count;
            char direction;

            cout << "1 - Зсув рядків" << endl;
            cout << "2 - Зсув стовпчиків" << endl;
            cout << "Ваш вибір: ";
            cin >> choice;

            cout << "Кількість зсувів: ";
            cin >> count;

            cout << "Напрямок (r - вправо/вниз, l - вліво/вгору): ";
            cin >> direction;

            cout << "Початковий масив:" << endl;
            print_array(arr, rows, cols);

            if (choice == 1)
            {
                shift_rows(arr, rows, cols, count, direction);
            }
            else if (choice == 2)
            {
                shift_columns(arr, rows, cols, count, direction);
            }

            cout << "Після зсуву:" << endl;
            print_array(arr, rows, cols);

            break;
        }
        case 0:
            cout << "Вихід з програми.";
            break;

        default:
            cout << "Неправильний вибір!";
        }

    } while (a != 0);

    

    delete[] arr;
}