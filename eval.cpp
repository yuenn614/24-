#include "eval.h"
#include <stack>
#include <cctype>
#include <algorithm>
#include <stdexcept>

using namespace std;

class Parser {
public:
    string s;
    int pos;

    Parser(string str) : s(str), pos(0) {}

    double parse() {
        return parseExpression();
    }

private:
    double parseExpression() {
        double val = parseTerm();
        while (pos < s.size()) {
            if (s[pos] == '+') {
                pos++;
                val += parseTerm();
            } else if (s[pos] == '-') {
                pos++;
                val -= parseTerm();
            } else break;
        }
        return val;
    }

    double parseTerm() {
        double val = parseFactor();
        while (pos < s.size()) {
            if (s[pos] == '*') {
                pos++;
                val *= parseFactor();
            } else if (s[pos] == '/') {
                pos++;
                val /= parseFactor();
            } else break;
        }
        return val;
    }

    double parseFactor() {
        if (s[pos] == '(') {
            pos++;
            double val = parseExpression();
            pos++; // skip ')'
            return val;
        }

        double num = 0;
        while (pos < s.size() && isdigit(s[pos])) {
            num = num * 10 + (s[pos] - '0');
            pos++;
        }
        return num;
    }
};

double Eval::calculate(string expr) {
    Parser p(expr);
    return p.parse();
}

---

vector<int> Eval::extractNumbers(string expr) {
    vector<int> nums;
    int i = 0;

    while (i < expr.size()) {
        if (isdigit(expr[i])) {
            int num = 0;
            while (i < expr.size() && isdigit(expr[i])) {
                num = num * 10 + (expr[i] - '0');
                i++;
            }
            nums.push_back(num);
        } else {
            i++;
        }
    }

    return nums;
}

bool Eval::checkValid(string expr, vector<int> cards) {

    vector<int> used = extractNumbers(expr);

    if (used.size() != cards.size())
        return false;

    sort(used.begin(), used.end());
    sort(cards.begin(), cards.end());

    return used == cards;   // ⭐ 完全一致才合法
}
