#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "tap.h"
#include "eval.h"
#include "ans.h"

using namespace std;

int main() {

    Tap tap;
    Eval eval;

    vector<int> cards = tap.generate();

    cout << "Cards: ";
    for (int x : cards) cout << x << " ";
    cout << endl;

    cout << "請輸入你的算式: ";
    string input;
    cin >> input;

    // ⭐ 檢查卡牌是否合法
    if (!eval.checkValid(input, cards)) {
        cout << "✘ 使用的數字不合法（必須剛好用這4張牌）" << endl;
        return 0;
    }

    try {
        double result = eval.calculate(input);

        cout << "結果 = " << result << endl;

        if (abs(result - 24.0) < 0.000001)
            cout << "✔ 正確！等於24" << endl;
        else
            cout << "✘ 不等於24" << endl;

    } catch (...) {
        cout << "✘ 算式錯誤" << endl;
    }

    return 0;
}
