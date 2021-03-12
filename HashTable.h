//
// Created by User on 11.03.2021.
//

#ifndef LAB2_2_HASHTABLE_H
#define LAB2_2_HASHTABLE_H
#include "LinkedList.h"
#include "Data.h"
#include <cmath>
#define M 10000
#define A 0.6180339887

struct HashTable{
    const float loadFactor = 0.647;
    const int alpha = 2;
    int m = 8;
    int n = 0;
    //LinkedList bucketsArray[M];
    LinkedList* bucketsArray = new LinkedList[m];

    int hash(long long k){
//        int index = floor(fmod((k*A), 1) * m);
        int index = k % m;
        return index;
    }

    float loadLevel(){
        return (float) n/m;
    }

    void insert(long long aKey, Data aValue){
        if (loadLevel() >= loadFactor){
            m *= alpha;
            n = 0;
            LinkedList* temp = bucketsArray;
            LinkedList* newArray = new LinkedList[m];
            bucketsArray = newArray;

            //  copy old array
            HashNode* currentNode;
            int index;
            for (int i = 0; i < m/alpha; ++i) {
                if (temp[i].head != nullptr){
                    currentNode = temp[i].head;
                    while (currentNode != nullptr){
                        index = hash(currentNode->key);
                        bucketsArray[index].push_back(currentNode->key, currentNode->value);
                        n++;
                        currentNode = currentNode->next;
                    }
                }
            }
            delete [] temp;
        }

        int index = hash(aKey); //  get index

        HashNode* currentNode = bucketsArray[index].head;
        while (currentNode != nullptr && currentNode->key != aKey) {
            currentNode = currentNode->next;
        }

        if (currentNode == nullptr) {
            bucketsArray[index].push_back(aKey, aValue);
            n++;
        } else {
            currentNode->value = aValue;
        }
    }

    HashNode* find(long long aKey){
        int index = hash(aKey); //  get index

        HashNode* currentNode = bucketsArray[index].head;
        if (bucketsArray[index].head != nullptr){
            while (currentNode != nullptr && currentNode->key != aKey){
                currentNode = currentNode->next;
            }
        }
        return currentNode;
    }

    void erase(long long aKey){
        int index = hash(aKey); //  get index

        HashNode* currentNode = bucketsArray[index].head;
        if (bucketsArray[index].head != nullptr) {
            while (currentNode != nullptr && currentNode->key != aKey) {
                currentNode = currentNode->next;
            }
            if (currentNode != nullptr) {
                bucketsArray[index].pop(currentNode);
                n--;
            }
        }
    }

    int size(){
        return n;
    }
};

#endif //LAB2_2_HASHTABLE_H
