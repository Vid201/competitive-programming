#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    unsigned int l, i;
    string p, mx, line;
    unordered_map<string, int> d;

    while (cin >> l) {
        p = "";
        cin.ignore();
        getline(cin, line);

        for (i = 0; i < l; i++) {
            p += line[i];
        }

        d[p] = 1;
        mx = p;

        for (; i < line.length(); i++) {
            p.erase(0, 1);
            p += line[i];
            d[p] = d[p] + 1;
            mx = (d[p] > d[mx]) ? p : mx;
        }

        cout << mx << endl;
        d.clear();
    }

    return 0;
}