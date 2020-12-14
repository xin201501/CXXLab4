#pragma once
#include <cstring>
template<class T>
T minValue(T &a, T &b) {
    return a < b ? a : b;
}
char *minValue(char *a, char *b) {
    return strcmp(a, b) < 0 ? a : b;
}