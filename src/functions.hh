/**
 * @file functions.cc
 * @author Pete Newman
 * @brief Functions for the homework 5 assignment
 * @date 12/4/23
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief struct to hold the data for an edge
 */
struct Edge
{
    int source;
    int destination;
    int weight;
};

/**
 * @brief A class that holds all of the extracted data from the file
 */
class EdgeData
{
private:
public:
    // the data variables
    vector<Edge> edges;
    int numVertices;

    // the constructors
    EdgeData(vector<Edge> edges, int);
    EdgeData();

    /**
     * @brief performs Prim's algorithm on the data
     *
     */
    void prims();
};

/**
 * @brief reads the data from the file and stores it in the container
 * @param container the container to store the data in
 * @param filename the name of the file to read the data from
 * @return void
 */
void readData(EdgeData &container, string filename);