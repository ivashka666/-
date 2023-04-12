#include <iostream>

using namespace std;
int main()
{
    int mas[] = { -2, -2, 0, 1, 1, 2, 4, 4, 5 };
    int n = (sizeof(mas) / sizeof(*mas));
    int  i = 0;
    for (int x = 0; x < n; x++)
        if (0 == count(mas, mas + i, mas[x]))
            mas[i++] = mas[x];

    for (int x = 0; x < i; x++)
        cout << mas[x] << "  ";
    cout << endl;
    system("pause");
    return 0;
    //сложность О(n)
} 