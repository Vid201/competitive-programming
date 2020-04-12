#include <bits/stdc++.h>
#define MAX 100000

int main() {
    int n, m, a, b, w, p[MAX], c;
    std::vector<std::pair<int, int>> g[MAX];
    unsigned long long int d[MAX], e;
    std::priority_queue<std::pair<unsigned long long int, int>,
                        std::vector<std::pair<unsigned long long int, int>>,
                        std::greater<std::pair<unsigned long long int, int>>>
        q;

    scanf("%d%d", &n, &m);

    while (m--) {
        scanf("%d%d%d", &a, &b, &w);
        --a;
        --b;
        g[a].emplace_back(w, b);
        g[b].emplace_back(w, a);
    }

    d[0] = 0;
    q.emplace(d[0], 0);

    for (int i = 1; i < n; ++i)
        d[i] = ULONG_LONG_MAX;

    while (!q.empty()) {
        std::pair<unsigned long long int, int> v = q.top();
        q.pop();

        if (v.second == n - 1)
            break;

        if (v.first <= d[v.second]) {
            for (const std::pair<int, int> &n : g[v.second]) {
                e = d[v.second] + n.first;
                if (e < d[n.second]) {
                    d[n.second] = e;
                    p[n.second] = v.second;
                    q.emplace(e, n.second);
                }
            }
        }
    }

    if (d[n - 1] == ULONG_LONG_MAX)
        printf("-1");
    else {
        std::stack<int> s;

        c = n - 1;
        s.emplace(c + 1);

        while (c != 0) {
            c = p[c];
            s.emplace(c + 1);
        }

        while (!s.empty()) {
            printf("%d", s.top());
            s.pop();
            if (!s.empty())
                printf(" ");
        }
    }

    return 0;
}