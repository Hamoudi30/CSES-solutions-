#include <bits/stdc++.h>
using namespace  std;
#define ll long long
int n, m;
int res[109][109];
char a[109][109];
int main () {
    int increase = 0;
    while (scanf("%d%d", &n, &m), n) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
                res[i][j] = 0;
            }
        }
        if(increase)
            printf("\n");
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (a[i][j] == '*') {
                    if (i + 1 < n && j - 1 >= 0) // 1
                        res[i + 1][j - 1]++;
                    if (j - 1 >= 0) // 2
                        res[i][j - 1]++;
                    if (i - 1 >= 0 && j - 1 >= 0) // 3
                        res[i - 1][j - 1]++;
                    if (i - 1 >= 0) // 4
                        res[i - 1][j]++;
                    if (i - 1 >= 0 && j + 1 < m) // 5
                        res[i - 1][j + 1]++;
                    if (j + 1 < m) // 6
                        res[i][j + 1]++;
                    if (i + 1 < n && j + 1 < m) // 7
                        res[i + 1][j + 1]++;
                    if (i + 1 < n) // 8
                        res[i + 1][j]++;
                }
            }
        }
        printf("Field #%d:\n", ++increase);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (a[i][j] == '*')
                    cout << a[i][j];
                else
                    cout << res[i][j];
            }
            cout << '\n';
        }
    }
    return 0;
}
// UVa 10189
// 2d grid 
// valid bounds test
