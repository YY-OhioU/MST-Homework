#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <limits>
#include <map>

#include "Prim.h"

using namespace std;

#define INF numeric_limits<double>::infinity()

Prim::~Prim() {
	cout << "free up memory" << endl;
    for (int i = 0; i < vCount; i++) {
        delete[] weights[i];
    }
    delete[]weights;
    delete[]edges;
    delete[]edgeWeights;
    cout << "freed memory" << endl;
}

void Prim::loadGraph(string fp) {
    cout << "open file: " << fp << endl;
    ifstream file;
    file.open(fp, ios::in);
    if (!file.is_open()) {
        cout << "Failed to open file: " << fp << endl;
        return;
    }
    string cell;
    string strLine;

    int s, d, w; // source destination weight

    // read first line in file
    string verticesCount;
    getline(file, verticesCount);
    vCount = stoi(verticesCount);

    // initialize ajd matrix and others
    edges = new int[vCount];
    edgeWeights = new double [vCount];
    weights = new double *[vCount];
    for (int i = 0; i < vCount; i++) {
        weights[i] = new double[vCount];
        for (int j = 0; j < vCount; j++) {
            weights[i][j] = INF;
        }
    }

    // read the weights of edges and set adj matrix
    int lineCount = 0;
    while (getline(file, strLine)) {
        stringstream lineStream(strLine);
        getline(lineStream, cell, ',');
        s = stoi(cell) - 1;

        if (lineCount == 0) { source = s; }
        getline(lineStream, cell, ',');
        d = stoi(cell) - 1;
        getline(lineStream, cell, ',');
        w = stoi(cell);
        weights[s][d] = w;
        weights[d][s] = w;
        lineCount++;
    }
}

void Prim::generateMST() {
    int startVertex, endVertex;
    double minWeight;
    bool *mstv;
    int gSize = vCount;
    mstv = new bool[gSize];
    for (int j = 0; j < gSize; j++) {
        mstv[j] = false;
        edges[j] = source;
        edgeWeights[j] = weights[source][j];
    }

    mstv[source] = true;
    edgeWeights[source] = 0;
    for (int i = 0; i < gSize - 1; i++) {
        minWeight = INF;
        for (int j = 0; j < gSize; j++)
            if (mstv[j]) {
                for (int k = 0; k < gSize; k++) {
                    if (!mstv[k] && weights[j][k] < minWeight) {
                        endVertex = k;
                        startVertex = j;
                        minWeight = weights[j][k];
                    }
                }
            }
        mstv[endVertex] = true;
        edges[endVertex] = startVertex;
        edgeWeights[endVertex] = minWeight;
    }
}

void Prim::printMST(string fpOut) {
    cout << "----- Results:" << endl;
    cout << "\tSource Vertex: " << source + 1 << endl;
    map<int, int> outEdges;
    int gSize = vCount;
    double treeWeight = 0;
    fstream fOut;
    fOut.open(fpOut, ios::out);

    // num of vertices
    fOut << vCount << endl;
    // write the edges
    int s, e, tmp;
    for (int j = 0; j < gSize; j++) {
        if (edges[j] != j) {
            s = edges[j] +1;
            e = j+1;
            if (e<s){
                cout<<"swap"<<endl;
                tmp = e;
                e = s;
                s = tmp;
            }
            if (outEdges.find(s) != outEdges.end()){
                if (outEdges[s] == e){cout<< "!!!!!!!!!!!!!! collision " << s << ' ' << e <<endl;}
            }
            outEdges[s] = e;
            treeWeight = treeWeight + edgeWeights[j];
            fOut << edges[j] + 1 << ',' << j + 1 << ','
                 << edgeWeights[j] << endl;
        }
    }
    cout << "\tMinimum spanning Tree Weight: "
         << treeWeight << endl;
    cout << "\tResult saved to: " << fpOut << endl;
}