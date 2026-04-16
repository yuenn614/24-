#include "tap.h"
#include <cstdlib>
#include <ctime>

vector<int> Tap::generate() {
    vector<int> cards(4);

    srand(time(0));

    for (int i = 0; i < 4; i++) {
        cards[i] = rand() % 13 + 1; // 1~13
    }

    return cards;
}
