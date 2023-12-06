#include <iostream>
#include <ctime>
#include <cstdio>


#include "Prim.h"
#include "Kruskal.h"

using namespace std;

#define PRIM 1
//#define PRIM 2
//#define PRIM 3

void algoTest(MST *algo, string fp, string fpOut) {
    clock_t start, end;
    cout << "Loading graph..." << endl;
    algo->loadGraph(fp);
    cout << "Generating MST, start timing" << endl;
    start = clock();
    algo->generateMST();
    end = clock();
    printf("Finished MST generation in: %.3f ms\n", (float) (end - start) * 1000 / CLOCKS_PER_SEC);
    cout << "Writing results to file..." << endl;
    algo->printMST(fpOut);
}

void primTest(string fp, string fpOut) {
    Prim prim;
    algoTest(&prim, fp, fpOut);
}

void kruskalTest() {
    Kruskal k;
    cout << "abc" << endl;
}


int main() {
    string testFiles[6] = {
            "graph1.txt",
            "graph_v100_e150.txt",
            "graph_v200_e300.txt",
            "graph_v400_e1200.txt",
            "graph_v800_e3200.txt",
            "graph_v1600_e6400.txt"
    };
    string test_name;
    string inFile;
    string outFile;
    {
        cout << "**************************** Prim [Question 2] ****************************** " << endl;
        for (int i = 0; i < 6; i++) {
            test_name = testFiles[i];
            inFile = "graphs/" + test_name;
            outFile = "outputs/prim_" + test_name;
            printf("=========== %s =========== \n", test_name.c_str());
            primTest(inFile, outFile);
            cout << endl;
        }
    }
//    kruskalTest();
}
