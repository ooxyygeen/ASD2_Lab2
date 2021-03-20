//
// Created by User on 11.03.2021.
//

#ifndef LAB2_2_OPENADDRESSINGTABLE_H
#define LAB2_2_OPENADDRESSINGTABLE_H
#include "Data.h"

struct Item{
    long long key;
    Data value;
    short flag = 0; // 0 - empty; 1 - in use; 2 - deleted
};

struct HashTable{
    const float loadFactor = 0.45;
    const int alpha = 2;
    int m = 8;
    int n = 0;
    Item* bucketsArray = new Item[m];

    long long hash(long long k, int i = 0){
        return fmod(((k % m) + (0.5 * i) + (0.5 * i * i)),m);
    }

    float loadLevel(){
        return (float)n/m;
    }

    void insert(long long aKey, Data aValue){
        if (loadLevel() >= loadFactor){
            m *= alpha;
            n = 0;
            Item* temp = bucketsArray;
            Item* newArray = new Item[m];
            bucketsArray = newArray;

            //  copy old array
            long long index;
            int j;
            for (int i = 0; i < m/alpha; ++i) {
                if (temp[i].flag == 1){
                    index = hash(temp[i].key);
                    j = 1;
                    while (true){
                        if (bucketsArray[index].flag == 0){
                            bucketsArray[index].key = temp[i].key;
                            bucketsArray[index].value = temp[i].value;
                            bucketsArray[index].flag = 1;
                            n++;
                            break;
                        }
                        index = hash(temp[i].key, j);
                        ++j;
                    }
                }
            }
            delete [] temp;
        }

        long long index = hash(aKey); //  get index
        int i = 1;
        while (true){
            if (bucketsArray[index].flag == 1 && bucketsArray[index].key == aKey){
                bucketsArray[index].value = aValue;
                break;
            } else if (bucketsArray[index].flag != 1){
                bucketsArray[index].key = aKey;
                bucketsArray[index].value = aValue;
                bucketsArray[index].flag = 1;
                n++;
                break;
            }
            index = hash(aKey, i);
            ++i;
        }
    }

    Item* find(long long aKey){
        int index = hash(aKey); //  get index
        int i = 1;

        while (bucketsArray[index].flag != 0){
            if (bucketsArray[index].key == aKey && bucketsArray[index].flag == 1){
                return &bucketsArray[index];
            }
            index = hash(aKey, i);
            ++i;
        }

        return nullptr;
    }

    void erase(long long aKey){
        int index = hash(aKey); //  get index
        int i = 1;

        while (bucketsArray[index].flag != 0){
            if (bucketsArray[index].key == aKey && bucketsArray[index].flag == 1){
                bucketsArray[index].flag = 2;
                n--;
            }
            index = hash(aKey, i);
            ++i;
        }
    }

    int size(){
        return n;
    }
};

#endif //LAB2_2_OPENADDRESSINGTABLE_H
