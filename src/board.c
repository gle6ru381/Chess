#include "board.h"

void map_free(Map map)
{
    string_free(map.first);
    string_free(map.second);
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

int string_push_back(String* str, char c)
{
    if (str->size == str->capacity) {
        str->str = realloc(str->str, (str->capacity * 2) * sizeof(char));
        if (str->str == NULL)
            return -1;
        str->capacity *= 2;
    }

    str->str[str->size] = c;
    str->size++;
    return 0;
}