//
// Created by User on 11.03.2021.
//

#ifndef LAB2_2_LINKEDLIST_H
#define LAB2_2_LINKEDLIST_H
#include "Data.h"

struct HashNode{
    long long key;
    Data value;
    HashNode* next = nullptr;
    HashNode* prev = nullptr;
};

struct LinkedList{
    HashNode* head = nullptr;
    HashNode* tail = nullptr;
    int size = 0;

    void push_back(long long aKey, Data aData){
        // create new HashNode
        HashNode* newHashNode = new HashNode;
        newHashNode->key = aKey;
        newHashNode->value = aData;

        if (head == nullptr){
            head = newHashNode;
            tail = newHashNode;
        } else{
            // push back
            tail->next = newHashNode;
            newHashNode->prev = tail;
            tail = newHashNode;
        }

        size++;
    }

    void pop(HashNode* aNode){
        if (head == tail){
            head = nullptr;
            tail = nullptr;
        } else if (aNode == head){
            head = head->next;
            head->prev = nullptr;
        } else if (aNode == tail){
            tail = aNode->prev;
            tail->next = nullptr;
        } else {
            aNode->prev->next = aNode->next;
            aNode->next->prev = aNode->prev;
        }
        size--;
        delete aNode;
    }
};

#endif //LAB2_2_LINKEDLIST_H
