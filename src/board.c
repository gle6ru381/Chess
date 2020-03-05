#include "board.h"

void map_free(Map map)
{
    string_free(map.first);
    string_free(map.second);
}

String* string_new(size_t size)
{
    String* string = (String*)(malloc(sizeof(String)));
    string->str = (char*)(calloc(size, sizeof(char)));
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
        String* temp = string_copy(str);
        if (temp == NULL)
            return -1;
        string_free(str);
        *str = *string_new(temp->capacity * 2);
        if (str == NULL)
            return -1;
        memcpy(str->str, temp->str, temp->size * sizeof(char));
        str->size = temp->size;
        string_free(temp);
    }

    str->str[str->size++] = c;
    return 0;
}