#include <bits/stdc++.h>

long long a[110][110], num[110];

void div(int x) {

    for (int i = 2; i <= x; ++i) {
        while (x % i == 0) {
            num[i] ++;
            x /= i;
        }
    }
}

int main() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        div(i);
    }
    a[0][1] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= 75; ++j) {
            for (int k = 0; k <= num[i]; ++k) {
                if (j * (k + 1) <= 75) {
                    a[i][j * (k + 1)] += a[i - 1][j];
                }
            }
        }
    }
    printf("%lld", a[n][75]);
    return 0;
}
