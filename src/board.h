#include <stdio.h>
#pragma once

enum Size { empty, white, black };

typedef struct {
    char name;
    enum Size size;
} Figure;
