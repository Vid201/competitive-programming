#include <bits/stdc++.h>

int main() {
    int N, m;
    std::string t, s, r;
    std::unordered_map<std::string, int> d;

    while (scanf("%d ", &N) == 1) {
        getline(std::cin, t);
        m = 0;

        for (int i = 0; i < t.length() - N + 1; ++i) {
            s = t.substr(i, N);
            d[s]++;
            if (d[s] > m) {
                m = d[s];
                r = s;
            }
        }

        printf("%s\n", r.c_str());
    }

    return 0;
}