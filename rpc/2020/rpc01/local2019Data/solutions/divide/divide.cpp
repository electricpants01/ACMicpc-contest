// Jim Geist
// 8/27/2019
// Solution to 2019 UCF Local Contest Problem: Divide
//

#include <iostream>

int main()
{
    int n, d;

    // read n and d
    std::cin >> n >> d;

    int solved[30];

    // read how many problems each student solved, and also compute
    // the total number of problems solved
    //
    int total_problems = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> solved[i];
        total_problems += solved[i];
    }

    // how much money to award for each problem
    //
    int award = d / total_problems;

    // now we can give out money!
    //
    for (int i = 0; i < n; i++) {
        std::cout << award * solved[i] << std::endl;
    }
}