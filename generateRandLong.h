//
// Created by User on 11.03.2021.
//


#ifndef LAB2_2_GENERATERANDLONG_H
#define LAB2_2_GENERATERANDLONG_H
#include <cmath>

long long generateRandLong(){
    long long key = 0;

    for (int i = 0; i < 12; ++i){
        key += (rand() % 10) * pow(10, i);
    }
    key += ((rand() % 9) + 1) * pow(10, 12);

    return key;
}

#endif //LAB2_2_GENERATERANDLONG_H
