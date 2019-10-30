//
//  main.cpp
//  Shortest Path Graphs
//
//  Created by Spencer on 4/19/19.
//  Copyright © 2019 Spencer. All rights reserved.
//

#include <iostream>
#include <string>
#include<sstream>
#include <limits.h>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <utility>


using namespace std;

vector<char> elements;
int nodes = 0;
string graphName;

struct Edge {
    char src, dest;double weight;
};

vector<Edge> edges;


class Graph
{
    bool completeGraph = false;
public:
    int vertices;
    double graph[100][100] = {0};
    Graph(vector<Edge> const &edges, int N)
    {
        vertices = N;
        for (auto &edge: edges){
            char src = edge.src;
            char dest = edge.dest;
            double weight = edge.weight;
            vector<char>::iterator elementIndex;
            elementIndex = find(elements.begin(), elements.end(), src);
            long srcIndex = elementIndex - elements.begin();
            elementIndex = find(elements.begin(), elements.end(), dest);
            long destIndex = elementIndex - elements.begin() ;
            graph[srcIndex][destIndex] = weight;
        }
        
        for(int i = 0; i < nodes; i++){
            for(int j = 0; j < nodes; j++){
                if(graph[i][j] != 0){
                completeGraph = true;
                }
            }
            if(!completeGraph){
                cout << "Error: Orphaned Vertex!" << endl;
                exit (EXIT_FAILURE);
                break;
            }
            cout << endl;
            completeGraph = false;

        }
    }
    
};

//LINES 78-144 = DIJKSTRA ALGORITHM I FOUND FROM
// https://www.geeksforgeeks.org/c-program-for-dijkstras-shortest-path-algorithm-greedy-algo-7/
//I SLIGHTLY MODIFIED IT TO FIT MY GRAPH ADT

int minDistance(double dist[], bool sptSet[])
{
    // Initialize min value
    double min = INT_MAX;
    int min_index = 0;
    
    for (int v = 0; v < nodes; v++)
        if (sptSet[v] == false && dist[v] <= min){
            min = dist[v];
            min_index = v;
        }
    
    return min_index;
}

// A utility function to print the constructed distance array
void printSolution(double dist[], int n, int src)
{
    cout << "Vertex   Distance from Vertex: " << elements[src] << endl;
    for (int i = 0; i < nodes; i++)
        printf("%4c %15f\n", elements[i], dist[i]);
    cout << endl;
}

void printtoCSV(double dist[], int n){
    ofstream myfile;
    myfile.open("myoutput.csv");
    myfile << " ,";
    for (int i = 0; i < nodes; i++){
        myfile << "Destination, =  " << elements[i] << ",";
    }
    myfile << endl;
    for (int i = 0; i < nodes; i++){
        myfile << ", Path: , Weight: ";
    }
    myfile << endl;
        myfile << "Source =  " << elements[0] << ", ,";
        for (int i = 0; i < nodes; i++){
            myfile << dist[i] << ", ,";
        }
        myfile << endl;
}

void addtoCSV(double dist[], int n){
    ofstream myfile;
    myfile.open("myoutput.csv", ofstream::app);
    myfile << "Source =  " << elements[n] << ", ,";
    for (int i = 0; i < nodes; i++){
            myfile << dist[i] << ", ,";
        }
    myfile << endl;
    }


// Function that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra(Graph matrix, int src)
{
    double graph[100][100];
    memcpy(graph, matrix.graph, sizeof(graph));
    double dist[nodes]; // The output array.  dist[i] will hold the shortest
    // distance from src to i
    
    bool sptSet[nodes]; // sptSet[i] will be true if vertex i is included in shortest
    // path tree or shortest distance from src to i is finalized
    
    // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < nodes; i++){
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }
    
    // Distance of source vertex from itself is always 0
    dist[src] = 0;
    
    // Find shortest path for all vertices
    for (int count = 0; count < nodes - 1 ; count++) {
        // Pick the minimum distance vertex from the set of vertices not
        // yet processed. u is always equal to src in the first iteration.
        int u = minDistance(dist, sptSet);
        
        // Mark the picked vertex as processed
        sptSet[u] = true;
        
        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < nodes; v++)
            
            // Update dist[v] only if is not in sptSet, there is an edge from
            // u to v, and total weight of path from src to  v through u is
            // smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]){
                dist[v] = dist[u] + graph[u][v];
            }
    }
    
    // print the constructed distance array
//    printSolution(dist, nodes, src);
    if(src == 0){
        printtoCSV(dist, src);
        dijkstra(matrix, src+1);
    }
    else if(src < nodes-1){
        addtoCSV(dist, src);
        dijkstra(matrix, src+1);
    }
    else if(src == nodes-1){
        addtoCSV(dist, src);
    }
    
}


void printDOT(Graph graph, int N){
    cout << "digraph " << graphName << "{" << endl;
    for (auto &edge: edges){
        char src = edge.src;
        char dest = edge.dest;
        double weight = edge.weight;
        cout << src << " -> " << dest <<
        "[label=\"" << weight << "\",weight=\"" << weight << "\"];" << endl;
    }
    cout << "};" << endl;
}



//READ INPUT FROM FILE
Graph input(string file){
    ifstream input(file);
    for(string line; getline( input, line ); )
    {
        stringstream ss(line);
        string token, token2, token3;
        ss >> token;

        if(token.compare("GRAPH:") == 0){
            ss >> token2;
            token2 = token2.substr(5);
            graphName = token2;
        }
        else if(token.compare("VERTEX:") == 0){
            ss >> token2;
            token2 = token2.back();
            char tempToken2 = token2.back();
            elements.push_back(tempToken2);
            nodes++;
            }
        else if(token.compare("EDGE:") == 0){
            ss >> token2;
            char tempToken2 = token2.at(1);
            if(find(elements.begin(), elements.end(), tempToken2)== elements.end()){
                cout << "ERROR: Malformed Graph! No vertex: " << tempToken2 << endl;
                exit (EXIT_FAILURE);
                break;
            }
            ss >> token3;
            char tempToken3 = token3.at(0);
            if(find(elements.begin(), elements.end(), tempToken3)== elements.end()){
                cout << "ERROR: Malformed Graph! No vertex: " << tempToken3 << endl;
                exit (EXIT_FAILURE);
                break;
            }
            double token4;
            ss >> token4;
            Edge tempEdge = {tempToken2, tempToken3, token4};
            edges.push_back(tempEdge);
            }
        }
    Graph graph(edges, nodes);
    return graph;
};

void printDOTFile(Graph graph, int N){
    //WRITE RESULTS TO CSV FILE
    ofstream myfile;
    myfile.open("myoutput.txt");
    myfile << "digraph " << graphName << "{" << endl;
    for (auto &edge: edges){
        char src = edge.src;
        char dest = edge.dest;
        double weight = edge.weight;
        myfile << src << " -> " << dest <<
        "[label=\"" << weight << "\",weight=\"" << weight << "\"];" << endl;
    }
    myfile << "};" << endl;
    
    myfile.close();
};



int main()
{
    Graph graph = input("test case 2.txt");
    printDOTFile(graph, graph.vertices);
    dijkstra(graph, 0);
    return 0;
}
