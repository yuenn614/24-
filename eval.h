#ifndef EVAL_H
#define EVAL_H

#include <string>
#include <vector>
using namespace std;

class Eval {
public:
    double calculate(string expr);

    vector<int> extractNumbers(string expr);   // ⭐ 抓數字
    bool checkValid(string expr, vector<int> cards); // ⭐ 檢查是否合法
};

#endif
