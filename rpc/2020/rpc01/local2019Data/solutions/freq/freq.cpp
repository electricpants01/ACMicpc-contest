// Jim Geist
// 8/27/2019
// Solution to 2019 UCF Local Contest Problem: Freq
//

#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <vector>

int main()
{
    // read the line
    //
    std::string line;
    std::cin >> line;

    // count the occurance of each letter
    //
    int counts['z' + 1];
    for (char i = 'a'; i <= 'z'; i++) {
        counts[i] = 0;
    }

    for (int i = 0; i < line.length(); i++) {
        char ch = line[i];
        counts[ch]++;
    }

    while (true) {
        int max = 0;
        char maxIndex = 0;

        // look through the counts array for the highest value. note that
        // we only move to a new max if there's an increase. since the array
        // indexes are alphabetical, this means we get the alphabetic sorting
        // of equal counted letters for free.
        //
        for (char i = 'a'; i <= 'z'; i++) {
            if (counts[i] > max) {
                max = counts[i];
                maxIndex = i;
            }
        }

        // if all the counts are zero, we're done.
        //
        if (max == 0) {
            break;
        }

        // print out some repeated letters.
        //
        for (int j = 0; j < counts[maxIndex]; j++) {
            std::cout << maxIndex;
        }

        // remove the count we just consumed.
        //
        counts[maxIndex] = 0;
    }    

    std::cout << std::endl;
}