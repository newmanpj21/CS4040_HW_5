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
    // create a vector to store the vertices that have been visited
    vector<int> visited;

    // create a vector to store the vertices that have not been visited
    vector<int> notVisited;
    for (int i = 0; i < this->numVertices; i++)
    {
        notVisited.push_back(i);
    }

    // choose the first vertex to be the starting vertex
    visited.push_back(notVisited[0]);
    notVisited.erase(notVisited.begin());
    int distance = 0;

    // loop until all vertices have been visited
    while (notVisited.size() > 0)
    {
        // find the edge with the smallest weight that has one vertex in visited and one vertex in notVisited
        int smallestWeight = 1000000;
        int smallestWeightIndex = 0;
        for (int i = 0; i < this->edges.size(); i++)
        {
            // check if the edge has one vertex in visited and one vertex in notVisited
        }