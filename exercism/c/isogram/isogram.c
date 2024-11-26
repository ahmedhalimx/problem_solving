#include <ctype.h>
#include "isogram.h"

#define ALPHABET_SIZE ('z' - 'a' + 1)

bool is_isogram(const char phrase[]) {
    bool ascii_map[ALPHABET_SIZE] = {false};

    if (!phrase) return false;
    while (*phrase) {
        char character = *phrase;
        int ascii_index = 'z' - tolower(character);

        if (!isalpha(character)) {
            ++phrase;
            continue;
        }

        if (ascii_map[ascii_index] == true)
            return false;

        ascii_map[ascii_index] = true;
        ++phrase;
    }
    return true;
}
