#include <cstdio>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

using std::cin;
using std::cout;
using std::endl;
using std::stack;
using std::string;
using std::unordered_map;

struct state {
    int wi[3];
    int pi;
    int count;
};

int statekey(const state &st)
{
    int k = 0;
    for (int i = 0; i < 3; i++) {
        k = k * 100 + st.wi[i];
    }
    k = k * 300 + st.pi;
    return k;
}

const int mod = 1000000007;

int main()
{
    string words[3], phrase;
    unordered_map<int, state> memo; 

    for (int i = 0; i < 3; i++) {
        cin >> words[i];
    }
    cin >> phrase;

    stack<state> work;
    state st = { { 0,0,0 }, 0, 0 };
    work.push(st);

    while (!work.empty()) {
        state st = work.top();

        if (st.pi == phrase.length()) {
            st.count = 1l;
            memo[statekey(st)] = st;
            work.pop();
            continue;
        }

        bool complete = true;

        for (int i = 0; i < 3; i++) {
            if (st.wi[i] == words[i].length()) {
                continue;
            }

            if (words[i][st.wi[i]] == phrase[st.pi]) {
                st.wi[i]++;
                st.pi++;

                auto it = memo.find(statekey(st));
                if (it != memo.end()) {
                    st.count = (st.count + it->second.count) % mod;
                } else {
                    complete = false;
                    st.count = 0;
                    work.push(st);
                }

                st.pi--;
                st.wi[i]--;
            }
        }

        if (complete) {
            memo[statekey(st)] = st;
            work.pop();
        }
    }

    cout << memo[statekey(st)].count << endl;
}
