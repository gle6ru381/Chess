#pragma once
#include <stdbool.h>
#include <stdio.h>
#define SIZE 8

typedef enum { no = 0, p, r, h, e, q, k } Name;
typedef enum { empty, white, black } Side;

typedef struct {
    Name name;
    Side side;
    bool first_move;
} Figure;

typedef struct {
    char* str;
    size_t size;
} String;

typedef struct {
    String first;
    String second;
} Map;
