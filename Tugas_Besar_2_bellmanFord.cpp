#include <iostream>
#include <vector>
#include <climits>
#include <map>
#include <string>
#include <stack>

using namespace std;

class Edge {
public:
    int src, dest, weight, cost;
};

class Graph {
public:
    int V, E;
    vector<Edge> edges;
    Graph(int V, int E) {
        this->V = V;
        this->E = E;
    }
    void addEdge(int u, int v, int w, int c) {
        Edge edge;
        edge.src = u;
        edge.dest = v;
        edge.weight = w;
        edge.cost = c;
        edges.push_back(edge);
    }
    void bellmanFord(int src, int dest, bool optimizeCost) {
        vector<int> distance(V, INT_MAX);
        vector<int> cost(V, INT_MAX);
        vector<int> parent(V, -1);
        distance[src] = 0;
        cost[src] = 0;

        for (int i = 1; i <= V - 1; i++) {
            for (int j = 0; j < E; j++) {
                int u = edges[j].src;
                int v = edges[j].dest;
                int weight = edges[j].weight;
                int edgeCost = edges[j].cost;

                if (!optimizeCost) {
                    if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
                        distance[v] = distance[u] + weight;
                        cost[v] = cost[u] + edgeCost;
                        parent[v] = u;
                    }
                } else {
                    if (cost[u] != INT_MAX && cost[u] + edgeCost < cost[v]) {
                        cost[v] = cost[u] + edgeCost;
                        distance[v] = distance[u] + weight;
                        parent[v] = u;
                    }
                }
            }
        }

        // Cetak jalur dari tujuan ke inisial
        stack<int> path;
        for (int v = dest; v != -1; v = parent[v]) {
            path.push(v);
        }

        cout << "Path: ";
        while (!path.empty()) {
            cout << char('a' + path.top()) << " ";
            path.pop();
        }
        cout << endl;

        if (optimizeCost) {
            cout << "Total Distance: " << distance[dest] << " km\n";
            cout << "Total Cost: " << cost[dest] << "\n";
        } else {
            cout << "Total Distance: " << distance[dest] << " km\n";
            cout << "Total Cost: " << cost[dest] << "\n";
        }
    }
};

int main() {
    int V = 10; // Jumlah vertex
    int E = 19; // Jumlah edge

    Graph graph(V, E);

    // Menambahkan edges berdasarkan data yang diberikan
    graph.addEdge(0, 1, 3, 27); // A -> B
    graph.addEdge(0, 2, 5, 18); // A -> C
    graph.addEdge(0, 3, 7, 9);  // A -> D
    graph.addEdge(1, 4, 8, 12); // B -> E
    graph.addEdge(1, 5, 2, 6);  // B -> F
    graph.addEdge(1, 6, 4, 18); // B -> G
    graph.addEdge(2, 4, 9, 6);  // C -> E
    graph.addEdge(2, 5, 6, 3);  // C -> F
    graph.addEdge(2, 6, 1, 9);  // C -> G
    graph.addEdge(3, 4, 10, 36);// D -> E
    graph.addEdge(3, 5, 4, 12); // D -> F
    graph.addEdge(3, 6, 8, 24); // D -> G
    graph.addEdge(4, 7, 7, 18); // E -> H
    graph.addEdge(4, 8, 3, 9);  // E -> I
    graph.addEdge(5, 7, 5, 27); // F -> H
    graph.addEdge(5, 8, 6, 12); // F -> I
    graph.addEdge(6, 8, 2, 6);  // G -> I
    graph.addEdge(6, 7, 9, 12); // G -> H
    graph.addEdge(7, 9, 10, 30);// H -> J
    graph.addEdge(8, 9, 4, 12); // I -> J

    map<char, int> cityIndex = {
        {'a', 0}, {'b', 1}, {'c', 2}, {'d', 3}, {'e', 4}, {'f', 5},
        {'g', 6}, {'h', 7}, {'i', 8}, {'j', 9}
    };

    char startCity, endCity;
    string priority;

    cout << "Enter start city (a-j): ";
    cin >> startCity;
    cout << "Enter end city (a-j): ";
    cin >> endCity;
    cout << "Enter priority (distance/cost): ";
    cin >> priority;

    int start = cityIndex[startCity];
    int end = cityIndex[endCity];
    bool optimizeCost = (priority == "cost");

    graph.bellmanFord(start, end, optimizeCost);

    return 0;
}
