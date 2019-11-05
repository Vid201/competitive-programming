#include <cstring>
#include <iostream>
#include <set>
#include <string>
#include <tuple>
#define VARS 3
using namespace std;

int main() {
    set<tuple<int, int, int>> t;

    for (int i = 1; i <= 23; i++) {
        for (int k = 1; 2 * (i + k) <= 50; k++) {
            t.insert(tuple<int, int, int>(i, k, i + k));
        }
    }

    int N, c[VARS], index;
    string line;

    cin >> N;
    cin.ignore();

    while (N--) {
        getline(cin, line);

        memset(c, 0, sizeof c);
        index = 0;

        for (unsigned int i = 0; i < line.length(); i++) {
            switch (line[i]) {
            case '?':
                c[index]++;
                break;
            case 'M':
            case 'E':
                if (line[i] == 'M' && index == 0 ||
                    line[i] == 'E' && index == 1) {
                    index++;
                    break;
                }
            default:
                index = -1;
                i = line.length();
                break;
            }
        }

        if (index != -1 &&
            t.find(tuple<int, int, int>(c[0], c[1], c[2])) != t.end())
            cout << "theorem" << endl;
        else
            cout << "no-theorem" << endl;
    }

    return 0;
}