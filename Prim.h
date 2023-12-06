#include "MST.h"

#ifndef ALGO_HW5_PRIM_H
#define ALGO_HW5_PRIM_H


class Prim : public MST {
public:
    void loadGraph(string filepath) override;

    void generateMST() override;

    //void timedGenerateMST();
    void printMST(string fpOut) override;

    ~Prim();

protected:
    int source;
    double **weights;
    int *edges;
    double *edgeWeights;
};


#endif //ALGO_HW5_PRIM_H
