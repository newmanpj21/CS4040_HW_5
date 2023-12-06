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
#include <chrono>
#include "functions.hh"

using namespace std;

int main()
{
    // create a vector of filenames to read from
    vector<string> filenames = {"./test/graph_v100_e150.txt", "./test/graph_v200_e300.txt", "./test/graph_v400_e1200.txt",
                                "./test/graph_v800_e3200.txt", "./test/graph_v1600_e6400.txt"};

    // for each file, read the data, time the execution of all three algorithms, and store the results while printing
    // times to the console
    for (const auto &filename : filenames)
    {
        EdgeData container;
        readData(container, filename);

        // prims
        auto start = chrono::high_resolution_clock::now();
        vector<Edge> edges = container.prims();
        auto stop = chrono::high_resolution_clock::now();
        auto duration = chrono::duration<double>(stop - start);
        cout << "Prim's algorithm on " << filename << " took " << duration.count() << " seconds" << endl;
        printToFile(edges, container.numVertices, "./results/v" + to_string(container.numVertices) + "_prims_results.txt");

        // kruskals
        start = chrono::high_resolution_clock::now();
        edges = container.kruskals();
        stop = chrono::high_resolution_clock::now();
        duration = chrono::duration<double>(stop - start);
        cout << "Kruskal's algorithm on " << filename << " took " << duration.count() << " seconds" << endl;
        printToFile(edges, container.numVertices, "./results/v" + to_string(container.numVertices) + "_kruskals_results.txt");

        // kruskals with path compression
        start = chrono::high_resolution_clock::now();
        edges = container.kruskalsPathCompression();
        stop = chrono::high_resolution_clock::now();
        duration = chrono::duration<double>(stop - start);
        cout << "Kruskal's algorithm with path compression on " << filename << " took " << duration.count() << " seconds" << endl;
        printToFile(edges, container.numVertices, "./results/v" + to_string(container.numVertices) + "_kruskals_path_compression_results.txt");

        cout << endl;
    }

    return 0;
}