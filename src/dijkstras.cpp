#include "dijkstras.h"

std::vector<int> dijkstra_shortest_path(const Graph& G, int source, std::vector<int>& previous) {
    int n = G.numVertices;

    std::vector<int> distance(n, INF);
    previous.resize(n, -1);
    std::vector<bool> visited(n, false);

    struct Node {
        int vertex;
        int weight;
        
        Node(int v, int w) : vertex(v), weight(w) {}
        
        bool operator>(const Node& other) const {
            return weight > other.weight;
        }
    };
    
    std::priority_queue<Node, vector<Node>, greater<Node>> pq;

    pq.push(Node(source, 0));
    distance[source] = 0;

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();
        
        int u = current.vertex;
        
        if (visited[u]) {
            continue;
        }
        
        visited[u] = true;
        
        for (const Edge& edge : G[u]) {
            int v = edge.dst;
            int weight = edge.weight;
            
            if (!visited[v] && distance[u] != INF && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                previous[v] = u;
                pq.push(Node(v, distance[v]));
            }
        }
    }

    return distance;
}

std::vector<int> extract_shortest_path(const std::vector<int>& distances, const std::vector<int>& previous, int destination) {
    vector<int> path;
    
    if (distances[destination] == INF) {
        return path;
    }
    
    for (int at = destination; at != -1; at = previous[at]) {
        path.push_back(at);
    }
    
    return path;
}

void print_path(const vector<int>& path, int total) {
    if (path.empty()) {
        cout << "\nTotal cost is " << total << endl;
        return;
    }
    
    vector<int> reversed_path = path;
    std::reverse(reversed_path.begin(), reversed_path.end());
    for (size_t i = 0; i < reversed_path.size(); i++) {
        cout << reversed_path[i] << " ";
    }
    cout << endl;
    cout << "Total cost is " << total << endl;
}