#include <vector>

#include "MST.h"

#ifndef ALGO_HW5_KRUSKAL_H
#define ALGO_HW5_KRUSKAL_H

using namespace std;


class Kruskal : public MST {

public:
    void loadGraph(string filepath) override;

    void generateMST() override;

    //void timedGenerateMST();
    void printMST(string fpOut) override;

    ~Kruskal();

protected:
    vector<vector<int>> edges;
    vector<vector<int>> mstEdges;

};


#endif //ALGO_HW5_KRUSKAL_H
