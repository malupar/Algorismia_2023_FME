#include <iostream>
#include <vector>
using namespace std;

const int n = 9;

typedef vector<vector<int>> VVI;
typedef vector<int> VI;

typedef vector<vector<bool>> VVB;
typedef vector<bool> VB;

VVI sudoku (n, vector<int>(n));
VVB row(n, VB(n, false)), col(n, VB(n, false)), square(n, VB(n, false));

void print() {
    for (int i = 0; i < n; ++i) {
        if (i%3 == 0 && i) {
            cout << "------+-------+------" << endl;
        }
        for (int j = 0; j < n; ++j) {
            if (j%3 == 0 && j) {
                cout << " |";
            }
            if (j) cout << ' ';
            cout << sudoku[i][j];
        }
        cout << endl;
    }
}

void bt(int i, int j, bool& trobat) {
    if (trobat) return;
    if (i == n) {
        print();
        trobat = true;
        return;
    }
    if (j == n) {
        bt(i+1, 0, trobat);
        return;
    }
    if (sudoku[i][j]) {
        bt(i, j+1, trobat);
        return;
    }
    int sq = i/3*3+j/3;
    for (int k = 0; k < n; ++k) {
        if (!row[i][k] && !col[j][k] && !square[sq][k]) {
            row[i][k] = col[j][k] = square[sq][k] = true;
            sudoku[i][j] = k+1;
            bt(i, j+1, trobat);
            row[i][k] = col[j][k] = square[sq][k] = false;
            sudoku[i][j] = 0;
        }
    }
}

int main() {
    int test;
    cin >> test;
    while (test--) {
        bool trobat = false;
        row = VVB (n, VB(n, false));
        col = VVB (n, VB(n, false));
        square = VVB (n, VB(n, false));
        for (int i = 0; i < n; ++i) {
            if (i%3 == 0 && i) {
                string t;
                cin >> t;
            }
            for (int j = 0; j < n; ++j) {
                if (j%3 == 0 && j) {
                    char t;
                    cin >> t;
                }
                cin >> sudoku[i][j];
                if (sudoku[i][j]) {
                    row[i][sudoku[i][j]-1] = true;
                    col[j][sudoku[i][j]-1] = true;
                    square[i/3*3+j/3][sudoku[i][j]-1] = true;
                }
            }
        }
        bt(0, 0, trobat);
        cout << endl;
    }
}
