#include <bits/stdc++.h>

int main() {
    std::set<std::tuple<int, int, int>> d;

    for (int i = 1; i <= 23; ++i) {
        for (int k = 1; 2 * (i + k) <= 50; ++k) {
            d.insert(std::tuple<int, int, int>{i, k, i + k});
        }
    }

    int N, c[3], i;
    std::string l;

    scanf("%d\n", &N);

    while (N--) {
        getline(std::cin, l);

        memset(c, 0, sizeof c);
        i = 0;

        for (int j = 0; j < l.length(); ++j) {
            switch (l[j]) {
            case '?':
                c[i]++;
                break;
            case 'M':
            case 'E':
                if (l[j] == 'M' && i == 0 || l[j] == 'E' && i == 1) {
                    i++;
                    break;
                }
            default:
                i = -1;
                j = l.length();
                break;
            }
        }

        if (i != -1 &&
            d.find(std::tuple<int, int, int>{c[0], c[1], c[2]}) != d.end())
            printf("theorem\n");
        else
            printf("no-theorem\n");
    }

    return 0;
}