#include "dijkstras.h"
#include <iostream>

int main() {
    string filename = "../src/small.txt";
    Graph G;
    
    try {
        file_to_graph(filename, G);
        int source = 0;
        vector<int> previous;
        vector<int> distances = dijkstra_shortest_path(G, source, previous);
        
        cout << source << endl;
        cout << "Total cost is 0" << endl;
        
        for (int destination = 0; destination < G.numVertices; destination++) {
            if (destination == source) continue;
            
            if (distances[destination] == INF) continue;
            
            vector<int> path = extract_shortest_path(distances, previous, destination);
            
            print_path(path, distances[destination]);
        }
        
    } catch (const exception& e) {
        std::cerr << "Error: " << e.what() << endl;
        return 1;
    }
    
    return 0;
}