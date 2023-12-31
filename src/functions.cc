/**
 * @file functions.cc
 * @author Pete Newman
 * @brief Functions for the homework 5 assignment
 * @date 12/4/23
 */

#include "functions.hh"
#include <climits>
#include <algorithm>
#include <set>

using namespace std;

void readData(EdgeData &container, string filename)
{
    ifstream instream(filename);

    if (!instream.is_open())
    {
        cout << "Error opening file" << endl;
        return;
    }

    string temp;
    int intNumVertices;
    getline(instream, temp);
    intNumVertices = stoi(temp);

    vector<Edge> edges;
    int source, destination, weight;
    while (getline(instream, temp))
    {
        size_t pos = temp.find(',');
        source = stoi(temp.substr(0, pos));
        temp.erase(0, pos + 1);

        pos = temp.find(',');
        destination = stoi(temp.substr(0, pos));
        temp.erase(0, pos + 1);

        weight = stoi(temp);

        Edge edge;
        edge.source = source;
        edge.destination = destination;
        edge.weight = weight;
        edges.push_back(edge);
    }

    instream.close();

    container.edges = edges;
    container.numVertices = intNumVertices;
}

int calculateNumVertices(vector<Edge> edges)
{
    set<int> vertices;
    for (const auto &edge : edges)
    {
        vertices.insert(edge.source);
        vertices.insert(edge.destination);
    }
    return vertices.size();
}

void printToFile(vector<Edge> edges, int numVertices, string filename)
{
    // open the file
    ofstream outstream(filename);

    // check if the file opened correctly
    if (!outstream.is_open())
    {
        cout << "Error opening file" << endl;
        return;
    }

    // print the data to the file
    outstream << numVertices << endl;
    for (const auto &edge : edges)
    {
        outstream << edge.source << "," << edge.destination << "," << edge.weight << endl;
    }

    outstream.close();
}

int find(vector<int> &parent, int i)
{
    if (i != parent[i])
    {
        i = parent[i];
    }
    return parent[i];
}

int findPathCompression(vector<int> &parent, int i)
{
    if (i != parent[i])
    {
        parent[i] = findPathCompression(parent, parent[i]);
    }
    return parent[i];
}

void unionSet(vector<int> &parent, int x, int y)
{
    int xset = find(parent, x);
    int yset = find(parent, y);
    if (xset != yset)
    {
        parent[xset] = yset;
    }
}

void unionSetPathCompression(vector<int> &parent, int x, int y)
{
    int xset = findPathCompression(parent, x);
    int yset = findPathCompression(parent, y);
    if (xset != yset)
    {
        parent[xset] = yset;
    }
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

// this function was a bitch for some reason... pardon my french
vector<Edge> EdgeData::prims()
{
    // Initialize the minimum spanning tree
    vector<Edge> mst;

    // Create a set of all vertices in the graph
    set<int> allVertices;
    for (const auto &edge : edges)
    {
        allVertices.insert(edge.source);
        allVertices.insert(edge.destination);
    }

    // Create a set of visited vertices and start from the source of the first edge
    set<int> visitedVertices;
    visitedVertices.insert(edges[0].source);

    // While there are still unvisited vertices
    while (visitedVertices != allVertices)
    {
        // Initialize the next edge to be added to the MST and its weight
        Edge nextEdge;
        int minWeight = INT_MAX;

        // For each edge in the graph
        for (const auto &edge : edges)
        {
            // If the edge connects a visited vertex with an unvisited vertex
            if ((visitedVertices.count(edge.source) && !visitedVertices.count(edge.destination)) ||
                (visitedVertices.count(edge.destination) && !visitedVertices.count(edge.source)))
            {
                // If the weight of the edge is less than the current minimum weight
                if (edge.weight < minWeight)
                {
                    // Update the next edge and the minimum weight
                    nextEdge = edge;
                    minWeight = edge.weight;
                }
            }
        }

        // Add the next edge to the MST
        mst.push_back(nextEdge);

        // Add the vertices of the next edge to the set of visited vertices
        visitedVertices.insert(nextEdge.source);
        visitedVertices.insert(nextEdge.destination);
    }

    // Return the MST
    return mst;
}

vector<Edge> EdgeData::kruskals()
{
    // sort the edges by weight
    sort(edges.begin(), edges.end(), [](Edge a, Edge b)
         { return a.weight < b.weight; });

    // create disjoint sets
    vector<int> parent(numVertices + 1);
    for (int i = 1; i <= numVertices; i++)
        parent[i] = i;

    // Kruskal's algorithm
    vector<Edge> mst;
    for (Edge &edge : edges)
    {
        int x = find(parent, edge.source);
        int y = find(parent, edge.destination);

        if (x != y)
        {
            mst.push_back(edge);
            unionSet(parent, x, y);
        }
    }

    return mst;
}

vector<Edge> EdgeData::kruskalsPathCompression()
{
    // sort the edges by weight
    sort(edges.begin(), edges.end(), [](Edge a, Edge b)
         { return a.weight < b.weight; });

    // create disjoint sets
    vector<int> parent(numVertices + 1);
    for (int i = 1; i <= numVertices; i++)
        parent[i] = i;

    // Kruskal's algorithm
    vector<Edge> mst;
    for (Edge &edge : edges)
    {
        int x = findPathCompression(parent, edge.source);
        int y = findPathCompression(parent, edge.destination);

        if (x != y)
        {
            mst.push_back(edge);
            unionSetPathCompression(parent, x, y);
        }
    }

    return mst;
}