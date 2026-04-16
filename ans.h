#ifndef ANS_H
#define ANS_H

#include <vector>
#include <string>
using namespace std;

class Ans {
public:
    string answer;   // 存解法

    bool solve(vector<double> nums, vector<string> expr);
};

#endif
