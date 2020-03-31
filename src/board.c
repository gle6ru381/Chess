#include "board.h"

void pair_free(Pair pair)
{
    string_free(pair.first);
    string_free(pair.second);
}

String* string_new(size_t size)
{
    String* string = (String*)(malloc(sizeof(String)));
    if (string == NULL)
        return NULL;
    string->str = (char*)(calloc(size, sizeof(char)));
    if (string->str == NULL) {
        free(string);
        return NULL;
    }
    string->capacity = size;
    string->size = 0;
    return string;
}

void string_free(String* string)
{
    free(string->str);
    free(string);
}

String* string_copy(const String* string)
{
    String* s = string_new(string->capacity);
    if (s == NULL)
        return NULL;

    memcpy(s->str, string->str, string->size * sizeof(char));

    s->size = string->size;
    return s;
}

char strAt(String* string, size_t index)
{
    if (string->size > index)
        return string->str[index];
    exit(EXIT_FAILURE);
}

int string_push_back(String* str, char c)
{
    if (str->size == str->capacity) {
        char* temp = str->str;
        str->str = realloc(str->str, (str->capacity * 2) * sizeof(char));
        if (str->str == NULL) {
            free(temp);
            return -1;
        }
        str->capacity *= 2;
    }

    str->str[str->size] = c;
    str->size++;
    return 0;
}

void swap(Figure* first, Figure* second)
{
    Figure temp = *first;
    *first = *second;
    *second = temp;
}

bool move(Figure board[SIZE][SIZE], Pair pair, Side side)
{
    char typeFigure = '\0', totalFigure = '\0';
    bool enPassant = false, shah = false, mate = false;
    if (isupper(strAt(pair.first, 0))) {
        if (strAt(pair.first, 0) >= 'A' && strAt(pair.first, 0) <= 'H') {
            pair.first->str[0] = tolower(pair.first->str[0]);
        } else if (
                (strAt(pair.first, 0) & ('K' | 'Q' | 'R' | 'B' | 'N' | 'P'))
                == strAt(pair.first, 0)) {
            typeFigure = strAt(pair.first, 0);
        } else {
            return false;
        }
    }
    size_t i;
    if (typeFigure == '\0')
        i = 0;
    else
        i = 1;

    char bCh, bNum, eCh, eNum;
    size_t iCh, iNum;
    while (i < pair.first->size) {
        if (strAt(pair.first, i) >= 'a' && strAt(pair.first, i) <= 'h') {
            bCh = strAt(pair.first, i);
            iCh = i;
        }
        if (strAt(pair.first, i) >= '1' && strAt(pair.first, i) <= '9') {
            bNum = strAt(pair.first, i);
            iNum = i;
        }
        i++;
    }
    if (iCh > iNum)
        return false;
    if (typeFigure != '\0'
        && toupper(typeFigure) != board[bNum - '1'][bCh - 'a'].name)
        return false;

    i = 0;
    while (i < pair.second->size) {
        if (strAt(pair.second, i) >= 'a' && strAt(pair.second, i) <= 'h') {
            if (strAt(pair.second, i + 1) == '.')
                continue;
            eCh = strAt(pair.second, i);
            iCh = i;
        }
        if (strAt(pair.second, i) >= '1' && strAt(pair.first, i) <= '9') {
            eNum = strAt(pair.second, i);
            iNum = i;
        }
        if ((strAt(pair.second, i) & ('K' | 'Q' | 'R' | 'B' | 'N' | 'P'))
            == strAt(pair.second, i)) {
            if (i < iCh && i < iNum)
                return false;
            totalFigure = strAt(pair.second, i);
        }
        i++;
    }
    if (iCh > iNum)
        return false;
    if (board[eNum - '1'][eCh - 'a'].name == ' ' && pair.separator == 'x')
        return false;
    if (eNum - bNum > 2)
        return false;

    char* tempPtr = strstr(pair.second->str, "e.p.");
    if (tempPtr != NULL) {
        if (tempPtr > (pair.second->str + iNum))
            enPassant = true;
        else
            return false;
    }

    if (enPassant) {
        swap(&board[bNum - '1'][bCh - 'a'], &board[eNum - '1'][eCh - 'a']);
    }

    tempPtr = strstr(pair.second->str, "+");
    if (tempPtr != NULL) {
        if (tempPtr > (pair.second->str + iNum))
            shah = true;
        else
            return false;
    }

    if (shah) {
        swap(&board[bNum - '1'][bCh - 'a'], &board[eNum - '1'][eCh - 'a']);
    }

    tempPtr = strstr(pair.second->str, "#");
    if (tempPtr != NULL) {
        if (tempPtr > (pair.second->str + iNum))
            mate = true;
        else
            return false;
    }

    if (mate) {
        swap(&board[bNum - '1'][bCh - 'a'], &board[eNum - '1'][eCh - 'a']);
    }

    if (totalFigure) {
        board[eNum - '1'][bCh - 'a'].name = totalFigure;
    }

    swap(&board[bNum - '1'][bCh - 'a'], &board[eNum - '1'][eCh - 'a']);

    return true;
}