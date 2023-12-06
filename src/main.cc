/**
 * @file main.cc
 * @author Pete Newman
 * @brief main file for the homework 5 assignment
 * @date 12/4/23
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "functions.hh"

using namespace std;

int main()
{
    // read the data from the file (must use the relative path from the CS4040_HW5 directory)
    EdgeData container;
    readData(container, "./test/graph_v100_e150.txt");

    // execute Prim's algorithm on the data and store the result
    vector<Edge> edges = container.prims();
    printToFile(edges, container.numVertices, "./results/prims_results.txt");

    return 0;
}