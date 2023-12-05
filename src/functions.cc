/**
 * @file functions.cc
 * @author Pete Newman
 * @brief Functions for the homework 5 assignment
 * @date 12/4/23
 */

#include "functions.hh"

using namespace std;

void readData(EdgeData &container, string filename)
{
    // open the file
    ifstream instream;
    instream.open(filename);

    // check if the file is open
    if (!instream.is_open())
    {
        cout << "Error opening file" << endl;
        return;
    }

    // read the number of vertices
    string temp;
    int intNumVertices;
    getline(instream, temp);
    intNumVertices = stoi(temp);

    // read the edges
    vector<Edge> edges;
    int source;
    int destination;
    int weight;
    while (!instream.eof())
    {
        getline(instream, temp, ',');
        source = stoi(temp);
        getline(instream, temp, ',');
        destination = stoi(temp);
        getline(instream, temp);
        weight = stoi(temp);
        Edge edge;
        edge.source = source;
        edge.destination = destination;
        edge.weight = weight;
        edges.push_back(edge);
    }

    // close the file
    instream.close();

    // store the data in the container
    container.edges = edges;
    container.numVertices = intNumVertices;
}

EdgeData::EdgeData(vector<Edge> edges, int numVertices)
{
    this->edges = edges;
    this->numVertices = numVertices;
}

EdgeData::EdgeData()
{
    this->edges = vector<Edge>();
    this->numVertices = 0;
}

void EdgeData::prims()
{
    //
}