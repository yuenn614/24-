#include "game.h"
#include <cmath>

using namespace std;

const double EPS = 0.000001;

bool is24(double x) {
    return abs(x - 24.0) < EPS;
}

bool Game24::solve(vector<double> nums, vector<string> expr) {

    if (nums.size() == 1) {
        return is24(nums[0]);
    }

    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < nums.size(); j++) {

            if (i == j) continue;

            vector<double> next;
            vector<string> nextExpr;

            for (int k = 0; k < nums.size(); k++) {
                if (k != i && k != j) {
                    next.push_back(nums[k]);
                    nextExpr.push_back(expr[k]);
                }
            }

            double a = nums[i];
            double b = nums[j];
            string sa = expr[i];
            string sb = expr[j];

            next.push_back(a + b);
            nextExpr.push_back("(" + sa + "+" + sb + ")");
            if (solve(next, nextExpr)) return true;
            next.pop_back(); nextExpr.pop_back();

            next.push_back(a - b);
            nextExpr.push_back("(" + sa + "-" + sb + ")");
            if (solve(next, nextExpr)) return true;
            next.pop_back(); nextExpr.pop_back();

            next.push_back(a * b);
            nextExpr.push_back("(" + sa + "*" + sb + ")");
            if (solve(next, nextExpr)) return true;
            next.pop_back(); nextExpr.pop_back();

            if (abs(b) > EPS) {
                next.push_back(a / b);
                nextExpr.push_back("(" + sa + "/" + sb + ")");
                if (solve(next, nextExpr)) return true;
                next.pop_back(); nextExpr.pop_back();
            }
        }
    }

    return false;
}
