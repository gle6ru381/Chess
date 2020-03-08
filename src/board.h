#pragma once
#include <malloc.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
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
} Pair;

String* string_new(size_t);
int string_push_back(String*, char);
String* string_copy(const String*);
char strAt(String*, size_t);
void string_free(String*);
void pair_free(Pair);