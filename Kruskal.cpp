#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "Kruskal.h"

Kruskal::~Kruskal() {
    for (auto &innerVector: edges) {
        innerVector.clear();
    }
    for (auto &innerVector: mstEdges) {
        innerVector.clear();
    }
    cout << "cleared" << endl;
}

void Kruskal::loadGraph(string fp) {
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

    // read the weights of edges and set adj matrix
    while (getline(file, strLine)) {
        stringstream lineStream(strLine);
        getline(lineStream, cell, ',');
        s = stoi(cell) - 1;

        getline(lineStream, cell, ',');
        d = stoi(cell) - 1;
        getline(lineStream, cell, ',');
        w = stoi(cell);
        edges.push_back({w, s, d}); // weight, source, destination
    }
}

void Kruskal::generateMST() {
    sort(edges.begin(), edges.end());
//    for (auto)

}

void Kruskal::printMST(string fpOut) {

}