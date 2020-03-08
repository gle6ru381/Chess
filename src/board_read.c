#include "board_read.h"

Map board_read()
{
    Map map;
    String* first = string_new(5);
    if (!first)
        exit(EXIT_FAILURE);
    String* second = string_new(5);
    if (!second)
        exit(EXIT_FAILURE);
    String* buff = string_new(10);
    if (!buff)
        exit(EXIT_FAILURE);
    char c;
    while ((c = getchar()) != '\n') {
        if ((string_push_back(buff, c)) == -1)
            exit(EXIT_FAILURE);
    }
    if ((string_push_back(buff, '\0')) == -1)
        exit(EXIT_FAILURE);
    int i = 0;
    for (; buff->str[i] != ' ' && buff->str[i] != '-'; i++) {
        if ((string_push_back(first, buff->str[i])) == -1)
            exit(EXIT_FAILURE);
    }
    if ((string_push_back(first, '\0')) == -1)
        exit(EXIT_FAILURE);
    i++;
    for (; buff->str[i] != '\0'; i++) {
        if ((string_push_back(second, buff->str[i])) == -1)
            exit(EXIT_FAILURE);
    }
    if ((string_push_back(second, '\0')) == -1)
        exit(EXIT_FAILURE);

    map.first = first;
    map.second = second;

    string_free(buff);
    return map;
}