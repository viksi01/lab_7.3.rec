#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** a, const int High, const int Low, const int rowCount, const int colCount, int i, int j)
{
    {
        a[i][j] = Low + rand() % (High - Low + 1);
        if (j < colCount - 1)
            Create(a, High, Low, rowCount, colCount, i, j + 1);
        else
            if (i < rowCount - 1)
                Create(a, High, Low, rowCount, colCount, i + 1, 0);
    }
}

void Print(int** a, const int rowCount, const int colCount, int i, int j)
{
    cout << a[i][j] << "\t";
    if (j < colCount - 1)
        Print(a, rowCount, colCount, i, j + 1);
    else 
        if (i < rowCount - 1)
        {
            cout << "\n";
            Print(a, rowCount, colCount, i + 1, 0);
        }
           else
            cout << "\n" << "\n" << "\n";
}

int Sum(int** a, const int rowCount, const int colCount, int i, int j, int s, int s1)
{
    if (i < rowCount)
    {
        if (j < colCount)
        {
            if (a[i][j] >= 0)
            {
                s1 += a[i][j];

                return Sum(a, rowCount, colCount, i, j + 1, s, s1);
            }

            else
                return Sum(a, rowCount, colCount, i + 1, 0, s, 0);
        }
        else
        {
            s += s1;
            return Sum(a, rowCount, colCount, i + 1, 0, s, 0);
        }
    }

   return s;
}

int main()
{
    srand(time(NULL));

    const int High = 100;
    const int Low = -10;
    int rowCount;
    int colCount;
    cout << "Enter the matrix size: "; cin >> rowCount;
    colCount = rowCount;

    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];
    int i = 0;
    int j = 0;

    Create(a, High, Low, rowCount, colCount, i, j);
    Print(a, rowCount, colCount, i, j);
    int s = 0, s1 = 0;
    cout << "Sum = " << Sum(a, rowCount, colCount, i, j, s, s1) << endl;

     for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[]a;

    return 0;
}

