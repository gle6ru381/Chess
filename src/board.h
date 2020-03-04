#pragma once
#include <stdbool.h>
#include <stdio.h>
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
} String;

typedef struct {
    String first;
    String second;
} Map;
