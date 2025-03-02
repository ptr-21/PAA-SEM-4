#include <iostream>
#include <vector>
#include <algorithm>

struct Node {
    char name;
    int distanceToB;
};

int main() {
    Node a = {'A', 10};
    Node d = {'D', 15};
    Node c = {'C', 20};

    std::vector<Node> nodes = {a, d, c}; // The order of nodes is set to A - B - D - B - C
    
    int totalDistance = 0;

    // Print starting node
    std::cout << "Start at node A" << std::endl;

    for (int i = 0; i < nodes.size(); ++i) {
        if (i == 0) { // For the first node, only add the distance from A to B
            totalDistance += nodes[i].distanceToB;
        } else { // For other nodes, add the distance from B to the current node
            totalDistance += nodes[i].distanceToB;
        }
        std::cout << "Go to node " << (nodes[i].name == 'A' ? 'B' : nodes[i].name) << ", Total Distance: " << totalDistance << std::endl;
        
        if (i < 2) { // After visiting a node, go back to B before visiting the next one
            totalDistance += nodes[i].distanceToB; 
            std::cout << "Go back to node B" << ", Total Distance: " << totalDistance << std::endl;
        }
        
        }

     // Do not add distance from last visited node back to B as per the instructions
        std::cout << "End at node C" ", Total Distance: " << totalDistance<<std::endl;

        return 0;
}
