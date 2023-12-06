#include <vector>

#include "MST.h"

#ifndef ALGO_HW5_KRUSKAL_H
#define ALGO_HW5_KRUSKAL_H

using namespace std;


class KruskalBase : public MST {

public:
    void loadGraph(string filepath) override;

    void generateMST() override;

    //void timedGenerateMST();
    void printMST(string fpOut) override;

    ~KruskalBase();

protected:
    vector<vector<int>> edges;
    vector<vector<int>> mstEdges;
    int* parent;
    virtual int check(int nId) = 0;
    int totalWeight = 0;
    bool combine(int a, int b); // union collide with c++ keyword

};

class Kruskal: public KruskalBase{
protected:
    int check(int nId) override;
};

class OptimizedKruskal : public KruskalBase{
protected:
    int check(int nId) override;
};


#endif //ALGO_HW5_KRUSKAL_H
