#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>

#include "Kruskal.h"

KruskalBase::~KruskalBase() {
    for (auto &innerVector: edges) {
        innerVector.clear();
    }
    for (auto &innerVector: mstEdges) {
        innerVector.clear();
    }
    delete[]parent;
    cout << "cleared" << endl;
}

void KruskalBase::loadGraph(string fp) {
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

    // init parent array
    parent = new int[vCount];
    for (int i = 0; i < vCount; i++) { parent[i] = -1; }

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

void KruskalBase::generateMST() {
    sort(edges.begin(), edges.end());

    int s, e, w;  // start, end and weight of an edge
    int tmp;

    bool selected = false;

    for (auto it = edges.begin(); it != edges.end(); it++) {
        s = it->at(1);
        e = it->at(2);
        w = it->at(0);
        selected = combine(s, e);
        if (selected) {
            if (e<s){
                tmp = e;
                e = s;
                s = e;
                cout << "swap" << endl;
            }
            mstEdges.push_back({s, e, w});
            totalWeight += w;
        }
    }
}

void KruskalBase::printMST(string fpOut) {
    cout << "----- Results:" << endl;
    cout << "\tMinimum spanning Tree Weight: " << totalWeight << endl;
    int s, e, w;

    fstream fOut;
    fOut.open(fpOut, ios::out);
    fOut << vCount << endl;
    for (auto it = mstEdges.begin(); it != mstEdges.end(); it++) {
        s = it->at(0);
        e = it->at(1);
        w = it->at(2);
        fOut << s+1 << ',' << e+1 << ',' << w << endl;
    }
    cout << "\tResult saved to: " << fpOut << endl;
}

bool KruskalBase::combine(int a, int b) {
    int ra, rb; // roots of trees
    ra = check(a);
    rb = check(b);
    if (ra != rb) { // not in the same set
        parent[rb] = ra;
        return true;
    } else {
        return false;
    }
}


int Kruskal::check(int nId) {
    while (parent[nId] != -1) {
        nId = parent[nId];
    }
    return nId;
}


int OptimizedKruskal::check(int nId) {
    int root = nId;
    while (parent[root] != -1) {
        root = parent[root];
    }
    if (root != nId){
        parent[nId] = root;
    }
    return root;
}