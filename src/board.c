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