#include <bits/stdc++.h>

typedef long long ll;

ll n, cnt;

ll dfs(ll x, int cnt3, int cnt5, int cnt7) {
    if(x > n)
        return 0;
    if(cnt3 && cnt5 && cnt7) {
        cnt ++;
    }
    dfs(x * 10 + 3, 1, cnt5, cnt7);
    dfs(x * 10 + 5, cnt3, 1, cnt7);
    dfs(x * 10 + 7, cnt3, cnt5, 1);
}

int main() {
    scanf("%lld", &n);
    dfs(0, 0, 0, 0);
    printf("%lld", cnt);
    return 0;
}