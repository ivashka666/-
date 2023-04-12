#include <iostream>
#include <fstream>
using namespace std;
double** prodMatr(double** a, double** b, int n1, int m1, int n2, int m2)
{
    double** res;
    int i, j;
    res = new double* [n1];
    for (i = 0; i < m2; i++)
    {
        res[i] = new double[m2];
    }

    for (i = 0; i < n1; i++)
    {
        for (j = 0; j < m2; j++)
        {
            res[i][j] = 0;
            for (int k = 0; k < m1; k++)
                res[i][j] += a[i][k] * b[k][j];
        }
    }

    return res;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int n1, n2, m1, m2;
    int i, j;
    double** a, ** b, ** c;
    ifstream file1, file2;

    file1.open("matr1.txt");
    file2.open("matr2.txt");
    cout << "Введите количество строк матрицы 1: ";
    cin >> n1;
    cout << "Введите количество столбцов матрицы 1: ";
    cin >> m1;
    cout << "Введите количество строк матрицы 2: ";
    cin >> n2;
    cout << "Введите количество столбцов матрицы 2: ";
    cin >> m2;

    if (m1 != n2)
    {
        cout << "умножение невозможно\n";
        return 0;
    }

    a = new double* [n1];
    for (i = 0; i < n1; i++)
    {
        a[i] = new double[m1];
    }

    b = new double* [n2];
    for (i = 0; i < n2; i++)
    {
        b[i] = new double[m2];
    }

    for (i = 0; i < n1; i++)
    {
        for (j = 0; j < m1; j++)
        {
            file1 >> a[i][j];
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    for (i = 0; i < n2; i++)
    {
        for (j = 0; j < m2; j++)
        {
            file2 >> b[i][j];
            cout << b[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
    file1.close();
    file2.close();

    c = prodMatr(a, b, n1, m1, n2, m2);
    for (i = 0; i < n1; i++)
    {
        for (j = 0; j < m2; j++)
        {
            cout << c[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}