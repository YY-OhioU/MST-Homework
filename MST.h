#pragma once

#include <iostream>
#include <vector>

using namespace std;

class MST {
public:
    virtual void loadGraph(string filepath) = 0;

    virtual void generateMST() = 0;

    virtual void printMST(string fpOut) = 0;

protected:
    int vCount;

};
