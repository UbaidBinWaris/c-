#pragma once
#include <iostream>
#include "Node.h"
#include <iomanip>
#include <string>
using namespace std;

class LinkedList {
private:
    Node* head = NULL;
    Node* cur = NULL;
public:
    ~LinkedList();
    void AddNode();
    Node* Empty();
    Node* SearchNode(string input);
    void DeleteNode(string input);
    void Print();
    void PrintSpecific(string numplate);
    Node* gethead();
    void AddNodefromfile(car car);
};
