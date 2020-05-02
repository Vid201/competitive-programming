#include <bits/stdc++.h>

int main() {
    std::string
        q = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./"
            "!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:\"ZXCVBNM<>?",
        d = "`123qjlmfp/"
            "[]456.orsuyb;=\\789aehtdck-0zx,inwvg'!@#QJLMFP?{}$%^>ORSUYB:+|&"
            "*(AEHTDCK_)ZX<INWVG\"",
        l;

    while (getline(std::cin, l)) {
        for (int i = 0; i < l.length(); i++) {
            auto j = q.find(l[i]);
            printf("%c", (j != std::string::npos) ? d[j] : l[i]);
        }
        printf("\n");
    }

    return 0;
}