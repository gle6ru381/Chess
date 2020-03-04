#include <stdio.h>
#pragma once

typedef enum { empty, white, black } Size;

typedef struct {
    char name;
    Size size;
} Figure;
