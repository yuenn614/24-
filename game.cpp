#include "game.h"
#include "ans.h"

bool Game24::hasSolution(vector<double> nums, vector<string> expr) {
    Ans ans;
    return ans.solve(nums, expr);
}
