#include <bits/stdc++.h>
#define MAX_VERTICES 50
#define MAX_NETWORK_SIZE 2 + 1000 + 50
#define Game std::tuple<int, int, int>

std::vector<Game> g[MAX_VERTICES];
std::vector<std::pair<int, int>> nf_g[MAX_NETWORK_SIZE],
    nf_rg[MAX_NETWORK_SIZE];
int p[MAX_VERTICES], m[MAX_VERTICES] = {0}, ps[MAX_NETWORK_SIZE], ns;
bool v[MAX_NETWORK_SIZE];

bool bfs() {
    memset(v, 0, sizeof v);

    std::queue<int> q;
    q.push(0);
    v[0] = true;
    ps[0] = -1;

    while (!q.empty()) {
        auto u = q.front();
        q.pop();

        for (const auto &e : nf_rg[u]) {
            if (v[e.first] == false && e.second > 0) {
                q.push(e.first);
                ps[e.first] = u;
                v[e.first] = true;
            }
        }
    }

    return v[ns - 1] == true;
}

int edmondsKarp() {
    for (int i = 0; i < ns; ++i) {
        for (auto &e : nf_g[i]) {
            nf_rg[i].emplace_back(e);
            nf_rg[e.first].emplace_back(std::pair<int, int>{i, 0});
        }
    }

    int pf, mf = 0, u, pu;

    while (bfs()) {
        pf = INT_MAX;

        for (u = ns - 1; u != 0; u = ps[u]) {
            auto it = std::find_if(
                nf_rg[ps[u]].begin(), nf_rg[ps[u]].end(),
                [&u](const std::pair<int, int> &el) { return el.first == u; });
            pf = std::min(pf, it->second);
        }

        for (u = ns - 1; u != 0; u = ps[u]) {
            auto it = std::find_if(
                nf_rg[ps[u]].begin(), nf_rg[ps[u]].end(),
                [&u](const std::pair<int, int> &el) { return el.first == u; });
            it->second -= pf;

            pu = ps[u];
            it = std::find_if(nf_rg[u].begin(), nf_rg[u].end(),
                              [&pu](const std::pair<int, int> &el) {
                                  return el.first == pu;
                              });
            it->second += pf;
        }

        mf += pf;
    }

    return mf;
}

int main() {
    int N, Z, P, num, gs = 0, ms = 0;

    scanf("%d%d%d", &N, &Z, &P);
    Z -= P;

    for (int i = 0; i < N; ++i)
        scanf("%d", &p[i]);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            scanf("%d", &num);
            p[i] += num * P;

            if (num > 0) {
                m[i] += num;
                g[i].emplace_back(Game(gs, j, num));

                if (i < j) {
                    ++gs;
                    ms += num;
                }
            }
        }
    }

    ns = 2 + gs + 50;

    for (int i = 0; i < N; ++i) {
        for (auto &v : nf_g)
            v.clear();
        for (auto &v : nf_rg)
            v.clear();

        for (int j = 0; j < N; ++j) {
            if (j == i)
                continue;

            for (const Game &g : g[j]) {
                if (std::get<1>(g) == i || std::get<1>(g) < j)
                    continue;

                nf_g[0].emplace_back(
                    std::pair<int, int>{1 + std::get<0>(g), std::get<2>(g)});
                nf_g[1 + std::get<0>(g)].emplace_back(
                    std::pair<int, int>{1 + gs + j, INT_MAX});
                nf_g[1 + std::get<0>(g)].emplace_back(
                    std::pair<int, int>{1 + gs + std::get<1>(g), INT_MAX});
            }

            nf_g[1 + gs + j].emplace_back(
                std::pair<int, int>{ns - 1, ((p[i] + m[i] * Z) - p[j]) / Z});
        }

        if (ms - m[i] == edmondsKarp())
            printf("%d\n", i + 1);
    }

    return 0;
}