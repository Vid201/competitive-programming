#include <bits/stdc++.h>
#define MAX 1000

std::pair<int, int> count2And5(const unsigned long long &num) {
    static int pow2[30] = {
        2,        4,        8,         16,        32,        64,
        128,      256,      512,       1024,      2048,      4096,
        8192,     16384,    32768,     65536,     131072,    262144,
        524288,   1048576,  2097152,   4194304,   8388608,   16777216,
        33554432, 67108864, 134217728, 268435456, 536870912, 1073741824};

    static int pow5[13] = {5,        25,        125,       625,     3125,
                           15625,    78125,     390625,    1953125, 9765625,
                           48828125, 244140625, 1220703125};

    std::pair<int, int> f(0, 0);

    for (int i = 29; i >= 0; --i) {
        if ((num % pow2[i]) == 0) {
            f.first = i + 1;
            break;
        }
    }

    for (int i = 12; i >= 0; --i) {
        if ((num % pow5[i]) == 0) {
            f.second = i + 1;
            break;
        }
    }

    return f;
}

int main() {
    int n, i, j, num, bm, zi, zj = -1;
    char d;
    std::pair<int, int> m2[MAX] = {}, n2[MAX] = {}, m5[MAX] = {}, n5[MAX] = {};
    std::string bp;
    std::string p2[MAX] = {}, r2[MAX] = {}, p5[MAX] = {}, r5[MAX] = {};

    scanf("%d", &n);

    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            scanf("%d", &num);

            std::pair<int, int> f = count2And5(num);

            if (num == 0) {
                zi = i;
                zj = j;
                f.first = f.second = 1;
            }

            if (i == 0 && j == 0) {
                n2[j] = f;
                n5[j] = f;
            } else if (i == 0) {
                n2[j].first = n2[j - 1].first + f.first;
                n2[j].second = n2[j - 1].second + f.second;
                n5[j] = n2[j];
                r2[j] = r2[j - 1] + 'R';
                r5[j] = r2[j];
            } else if (j == 0) {
                n2[j].first = m2[j].first + f.first;
                n2[j].second = m2[j].second + f.second;
                n5[j] = n2[j];
                r2[j] = p2[j] + 'D';
                r5[j] = r2[j];
            } else {
                if (n2[j - 1].first < m2[j].first) {
                    n2[j].first = n2[j - 1].first + f.first;
                    n2[j].second = n2[j - 1].second + f.second;
                    r2[j] = r2[j - 1] + 'R';
                } else {
                    n2[j].first = m2[j].first + f.first;
                    n2[j].second = m2[j].second + f.second;
                    r2[j] = p2[j] + 'D';
                }

                if (n5[j - 1].second < m5[j].second) {
                    n5[j].first = n5[j - 1].first + f.first;
                    n5[j].second = n5[j - 1].second + f.second;
                    r5[j] = r5[j - 1] + 'R';
                } else {
                    n5[j].first = m5[j].first + f.first;
                    n5[j].second = m5[j].second + f.second;
                    r5[j] = p5[j] + 'D';
                }
            }
        }

        std::swap(m2, n2);
        std::swap(m5, n5);
        std::swap(p2, r2);
        std::swap(p5, r5);
    }

    if (m2[n - 1].first < m5[n - 1].second) {
        bm = std::min(m2[n - 1].first, m2[n - 1].second);
        bp = p2[n - 1].c_str();
    } else {
        bm = std::min(m5[n - 1].first, m5[n - 1].second);
        bp = p5[n - 1].c_str();
    }

    if (zj != -1 && bm > 0) {
        bm = 1;
        bp = "";
        for (i = 0; i < zi; ++i)
            bp += 'D';
        for (j = 0; j < n - 1; ++j)
            bp += 'R';
        for (i = zi + 1; i < n; ++i)
            bp += 'D';
    }

    printf("%d\n%s", bm, bp.c_str());

    return 0;
}