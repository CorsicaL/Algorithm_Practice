#include <bits/stdc++.h>
using namespace std;

#define MAXN (100010)

int n, m;
int y[MAXN], p[MAXN];

vector<pair<int, int>> arr[MAXN];


int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d", p + i, y + i);
        arr[p[i]].emplace_back(y[i], i);
    }
    for (int j = 1; j <= n; ++j) {
        int k = 1;
        sort(arr[j].begin(), arr[j].end());
        for (auto i : arr[j]) {
            y[i.second] = k ++;
        }
    }
    for (int k = 1; k <= m; ++k) {
        printf("%06d%06d\n", p[k], y[k]);
    }
    return 0;
}
