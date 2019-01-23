#include <bits/stdc++.h>

int main() {
    std::string s;
    std::cin >> s;
    int x, xmin = INT32_MAX;
    for (int i = 0; i + 2 < s.length(); ++i) {
        x = std::stoi(s.substr(i, 3));
        xmin = std::min(xmin, abs(753 - x));
    }
    printf("%d", xmin);
    return 0;
}