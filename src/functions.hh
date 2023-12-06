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
    vector<Edge> prims();

    /**
     * @brief performs Kruskal's algorithm on the data without path compression
     *
     */
    vector<Edge> kruskals();

    /**
     * @brief performs Kruskal's algorithm on the data with path compression
     *
     */
    vector<Edge> kruskalsPathCompression();
};

/**
 * @brief reads the data from the file and stores it in the container
 * @param container the container to store the data in
 * @param filename the name of the file to read the data from
 * @return void
 */
void readData(EdgeData &container, string filename);

/**
 * @brief prints the data to the file
 * @param edges the edges to print
 * @param numVertices the number of vertices in the graph
 * @param filename the name of the file to print the data to
 * @return void
 */
void printToFile(vector<Edge> edges, int numVertices, string filename);

/**
 * @brief calculates the number of vertices in the graph (used for testing)
 * @param edges the edges in the graph
 * @return int the number of vertices in the graph
 */
int calculateNumVertices(vector<Edge> edges);

/**
 * @brief find function for disjoint set
 * @param parent the parent array
 * @param i the index to find the parent of
 * @return int the parent of the index
 */
int find(vector<int> &parent, int i);

/**
 * @brief find function for disjoint set with path compression
 * @param parent the parent array
 * @param i the index to find the parent of
 * @return int the parent of the index
 */
int findPathCompression(vector<int> &parent, int i);

/**
 * @brief union function for disjoint set
 * @param parent the parent array
 * @param x the first index to union
 * @param y the second index to union
 * @return void
 */
void unionSet(vector<int> &parent, int x, int y);

/**
 * @brief union function for disjoint set with path compression
 * @param parent the parent array
 * @param x the first index to union
 * @param y the second index to union
 * @return void
 */
void unionSetPathCompression(vector<int> &parent, int x, int y);