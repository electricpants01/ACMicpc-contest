#include <iostream>
#include <limits>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::numeric_limits;
using std::streamsize;
using std::string;
using std::vector;

int main()
{
    string probname;
    string infname;
    int i, r, d, e, c, t;
    vector<string> key;
    vector<string> user;

    getline(cin, probname);
    getline(cin, infname);

    cin >> r >> d >> e >> c;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < c; i++) {
        string line;
        getline(cin, line);
        key.push_back(line);
    }

    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < t; i++) {
        string line;
        getline(cin, line);
        user.push_back(line);
    }
    
    int dot = infname.rfind('.');
    string ext = infname.substr(dot+1);
    infname = infname.substr(0, dot);

    if (infname != probname || (ext != "c" && ext != "cpp" && ext != "java" && ext != "py")) {
        cout << "Compile Error" << endl;
        return 0;
    }

    if (r) {
        cout << "Run-Time Error" << endl;
        return 0;
    }

    if (e > d) {
        cout << "Time Limit Exceeded" << endl;
        return 0;
    }
    
    bool wa = c != t;
    for (int i = 0; i < c && !wa; i++) {
        wa = key[i] != user[i];
    }

    if (wa) {
        cout << "Wrong Answer" << endl;
        return 0;
    }

    cout << "Correct" << endl; 
}
