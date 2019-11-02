#include <iostream>
#include <string>
using namespace std;

int main() {
    string q = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./"
               "!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:\"ZXCVBNM<>?",
           d = "`123qjlmfp/"
               "[]456.orsuyb;=\\789aehtdck-0zx,inwvg'!@#QJLMFP?{}$%^>ORSUYB:+|&"
               "*(AEHTDCK_)ZX<INWVG\"",
           line;
    int index;

    while (getline(cin, line)) {
        for (unsigned int i = 0; i < line.length(); i++) {
            index = q.find(line[i]);

            if (index != string::npos)
                cout << d[index];
            else
                cout << line[i];
        }
        cout << endl;
    }

    return 0;
}