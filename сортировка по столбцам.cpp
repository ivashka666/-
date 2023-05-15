#include <iostream>   
#include <vector>     
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector < vector <int> > a(n, vector <int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        int ind = m;
        int max = -20000;

        for (int j = i; j < m; j++) {
            int temp = 0;
            for (int q = 0; q < n; q++) {
                temp += a[q][j];
            }
            if (temp > max) {
                max = temp;
                ind = j;
            }
        }

        for (int o = 0; o < n; o++) {
            int temp;
            temp = a[o][i];
            a[o][i] = a[o][ind];
            a[o][ind] = temp;
        }
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}