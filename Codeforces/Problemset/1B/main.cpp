#include <bits/stdc++.h>
#define MAX 5

int main() {
    int n, rn, cn, i, len, k;
    char r[MAX + 2], c[MAX + 2];

    int pow26[MAX]{1, 26, 676, 17576, 456976};
    int prePow26[MAX]{0, 26, 702, 18278, 475254};

    scanf("%d\n", &n);

    while (n--) {
        rn = cn = 0;
        r[0] = c[0] = '\0';

        scanf("%[A-Z]%d", r, &rn);
        if (getchar() == 'C')
            scanf("%d\n", &cn);

        if (cn == 0) {
            len = strlen(r);
            for (i = 0; i < len; ++i)
                cn += (r[i] - 'A') * pow26[len - i - 1];

            if (len > 1)
                cn += prePow26[len - 1];

            printf("R%dC%d\n", rn, cn + 1);
        } else {
            for (i = 0;; ++i) {
                if (i == MAX || cn <= prePow26[i]) {
                    cn -= prePow26[i - 1];
                    len = i;
                    break;
                }
            }
            for (i = 0; i < len; ++i) {
                k = (cn - 1) / pow26[len - i - 1];
                c[i] = 'A' + k;
                cn -= k * pow26[len - i - 1];
            }
            c[len] = '\0';

            printf("%s%d\n", c, rn);
        }
    }

    return 0;
}