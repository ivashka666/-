#include <iostream>   
#include <vector>     
using namespace std;

int main()
{
    int n1, m1, n2, m2;
    cin >> n1 >> m1;
    cin >> n2 >> m2;
    if (m1 != n2) {
        cout << "Error";
        return 0;
    }
    vector < vector <int> > a(n1, vector <int>(m1));

    for (int i = 0; i < n1; i++)
        for (int j = 0; j < m1; j++)
        {
            cin >> a[i][j];
        }

    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < m1; j++)
            cout << a[i][j] << ' ';
        cout << endl;
    }
    //
    vector < vector <int> > b(n2, vector <int>(m2));
    for (int i = 0; i < n2; i++)
        for (int j = 0; j < m2; j++)
        {
            cin >> b[i][j];
        }

    for (int i = 0; i < n2; i++)
    {
        for (int j = 0; j < m2; j++)
            cout << b[i][j] << ' ';
        cout << endl;
    }
    vector < vector <int> > ppp(m1, vector <int>(n2));
    for (int z = 0; z < n1; z++) {
        for (int x = 0; x < m1; x++) {
            int temp = 0;
            for (int c = 0; c < m1; c++) {
                temp += a[z][c] * b[c][x];
            }
            ppp[z][x] = temp;
        }
    }
    for (int i = 0; i < n2; i++)
    {
        for (int j = 0; j < m2; j++)
            cout << ppp[i][j] << ' ';
        cout << endl;
    }
    return 0;
}