#include <iostream>
#include <vector>
#include <map>
#include <math.h>
using namespace std;
typedef long double ld;
const ld EPS = 1e-7;
const ld PI = 3.1415926536;
struct Recta{
    pair<ld, ld> pt;
    pair<ld, ld> inc;
};
map<string, vector<Recta>> edges;
pair<ld, ld> get_inter(Recta a, Recta b, string& x);

Recta get_recta(pair<ld, ld>& a, pair<ld, ld>& b, ld alpha, string& z) {
    if (a.first == b.first && b.first == 1e9) a = get_inter(edges[z][0], edges[z][1], z);
    Recta x;
    x.pt = a;
    ld beta;
    if (abs(a.first) <= b.first+EPS && abs(a.first) >= b.first-EPS) beta = 90;
    else {
        beta = atan2((b.second-a.second), (b.first-a.first))/(PI)*180;
        if (beta < 0) beta += 360;
    }
    beta += alpha;
    if (beta > 360) beta -= 360; // (x1+z*a.first) == (x2+w*b.first) -> ((x1-x2 + z*a.first)/b.first == w)
                                 // (y1+z*a.second) == (y2+w*b.second) -> ((y1+z*a.second == y2+b.second/b.first*(x1-x2+z*a.first))) -> (y1-y2)*b.first/b.second
    beta = beta/180*PI;         // (y1-y2)+(x2-x1)*b.second/b.first == b.second/b.first*a.first-a.second*z

}

pair<ld, ld> get_inter(Recta a, Recta b, string& x) {

    ld w = (a.pt.second-b.pt.second + (b.pt.first-a.pt.first)*b.inc.second/b.inc.first)/(a.inc.first*b.inc.second/b.inc.first-a.inc.second);
    return {b.pt.first + w*b.inc.first, b.pt.second + w*b.inc.second};
}

int main() {
    vector<string> places;
    map<string, pair<int,int>> mp;
    string s;
    ld x, y;
    for (int i = 0; i < 2; ++i) {
        cin >> s >> x >> y;
        mp[s] = {x, y};
    }
    string t, st;
    while (cin >> s >> t >> st) {
        ld angle;
        cin >> angle;

    }

}