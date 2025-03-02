#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
struct Node {
    string name;
    int distance;
};
int main() {
    map<string, vector<Node>> graph;
    graph["A"] = {{"B", 10}};
    graph["B"] = {{"A", 10}, {"C", 20}, {"D", 15}};
    graph["C"] = {{"B", 20}};
    graph["D"] = {{"B", 15}};
    string current = "A";
    map<string, bool> visited;
    visited[current] = true;
    int total_distance = 0;
    string path = current;
    while (true) {
        int min_distance = INT_MAX;
        string next_node;
        for (const auto& node : graph[current]) {
            if (!visited[node.name] && node.distance < min_distance) {
                min_distance = node.distance;
                next_node = node.name;
            }
        }
        if (next_node.empty()) {
            break;
        }
        current = next_node;
        visited[current] = true;
        total_distance += min_distance;
        path += "-" + current;
        // If the current node is 'D', go back to 'B' before going to 'C'
        if (current == "D") {
            current = "B";
            total_distance += graph["D"][0].distance; // Add distance from D to B
            path += "-B";
        }
    }
    cout << "Urutan Rute yang Paling Efisien adalah: " << path << "\nJumlah jarak yang ditempuh: " << total_distance << endl;
    return 0;
}
