#include <bits/stdc++.h>

int main() {
    unsigned long long int n, m, a;
    scanf("%llu%llu%llu", &n, &m, &a);
    printf("%llu", ((n + a - 1) / a) * ((m + a - 1) / a));
}