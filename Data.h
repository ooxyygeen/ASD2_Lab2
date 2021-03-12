//
// Created by User on 11.03.2021.
//

#ifndef LAB2_2_DATA_H
#define LAB2_2_DATA_H

#define max 18
#define min 10

struct Data{
    char post;
    float hours;
    int productivity;

    Data(){
        post = 'A' + rand() % 26;
        hours = (float) rand() / RAND_MAX * (max - min) + min;
        productivity = rand() % 101;
    }
};

#endif //LAB2_2_DATA_H
