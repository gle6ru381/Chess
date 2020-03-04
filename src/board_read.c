#include "board_read.h"

Map board_read()
{
    Map map = {string_new(5), string_new(5)};
    String* first = map.first;
    String* second = map.second;
    String* buff = string_new(10);
    char c;
    while ((c = getchar()) != '\n') {
        string_push_back(buff, c);
    }
    string_push_back(buff, '\0');
    int i = 0;
    for (; buff->str[i] != ' ' && buff->str[i] != '-'; i++) {
        string_push_back(first, buff->str[i]);
    }
    string_push_back(first, '\0');
    i++;
    for (; buff->str[i] != '\0'; i++) {
        string_push_back(second, buff->str[i]);
    }
    string_push_back(second, '\0');

    return map;
}