#pragma once
#include <malloc.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define SIZE 8

typedef enum { empty, white, black } Side;

typedef struct {
    char name;
    Side side;
    bool first_move;
} Figure;

typedef struct {
    char* str;
    size_t size;
    size_t capacity;
} String;

typedef struct {
    String* first;
    String* second;
} Map;

String* string_new(size_t);
int string_push_back(String*, char);
String* string_copy(const String*);
void string_free(String*);
void map_free(Map);