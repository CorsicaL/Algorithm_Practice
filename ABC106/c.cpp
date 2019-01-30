#include <bits/stdc++.h>

int main() {
    std::string s;
    std::cin >> s;
    int k;
    std::cin >> k;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != '1') {
            std::cout << s[i] << std::endl;
            return 0;
        }
        if (i == k - 1) {
            std::cout << 1 << std::endl;
            return 0;
        }
    }
}