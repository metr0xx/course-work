#include <string>
#include <iostream>

#pragma once

using namespace std;

struct ConsoleInteraction {

    static void Start();

    template<typename K>
    static K GetValue(K &value);

    static void GetValue(char value[], bool afterInt = false);
};