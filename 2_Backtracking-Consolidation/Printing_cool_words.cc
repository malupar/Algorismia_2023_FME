#include <iostream>
#include <vector>
using namespace std;

bool is_vowel(char a) {
    return a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u';
}

void bt(int i, int cnt_v, int x, int n, vector<char>& words, bool last_consonant, int max_v) {
    if (n-i < max_v-cnt_v || (2*(max_v-cnt_v) < (n-i) && last_consonant) || 2*(max_v-cnt_v)+1 < (n-i)) return;
    if (i == n && cnt_v == max_v) {
        for(auto& x: words) cout << x;
        cout << endl;
        return;
    }

    for (int j = 0; j < x; ++j) {
        if (is_vowel('a'+j) && cnt_v < max_v) {
            words.push_back('a'+j);
            bt(i+1, cnt_v+1, x, n, words, false, max_v);
            words.pop_back();
        }
        else if (not is_vowel('a'+j) && not last_consonant) {
            words.push_back('a'+j);
            bt(i+1, cnt_v, x, n, words, true, max_v);
            words.pop_back();
        }
    }
}

int main() {
    int n,v,x;
    cin >> n >> v >> x;
    vector<char> words;
    bt(0,0,x,n,words,false,v);
}
