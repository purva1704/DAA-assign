#include <iostream>
#include <vector>
using namespace std;

// Function to perform DFS and count paths
void countPathsDFS(vector<vector<int>>& graph, int current, int destination, int& pathCount, vector<int>& path) {
    path.push_back(current); // Add the current node to the path

    if (current == destination) {
        // Found a valid path, increment the count
        pathCount++;
        cout << "Path: ";
        for (int node : path) {
            cout << char(node + 'A') << " "; // Convert to character representation
        }
        cout << endl;
    } else {
        // Explore all adjacent vertices
        for (int neighbor : graph[current]) {
            countPathsDFS(graph, neighbor, destination, pathCount, path);
        }
    }

    path.pop_back(); // Backtrack
}

// Function to count all paths between two vertices
int countPaths(vector<vector<int>>& graph, int start, int end) {
    int pathCount = 0;
    vector<int> path; // To track the current path
    countPathsDFS(graph, start, end, pathCount, path);
    return pathCount;
}

int main() {
    // Define the graph as an adjacency list
    int vertices = 5; // Vertices: A, B, C, D, E (0 to 4)
    vector<vector<int>> graph(vertices);

    // Define edges based on the diagram
    graph[0] = {1, 2};       // A -> B, A -> C
    graph[1] = {3, 4};       // B -> D, B -> E
    graph[2] = {4};          // C -> E
    graph[3] = {2};          // D -> C
    graph[4] = {};           // E has no outgoing edges

    // Input vertices
    char startChar, endChar;
    cout << "Enter the start vertex (A-E): ";
    cin >> startChar;
    cout << "Enter the end vertex (A-E): ";
    cin >> endChar;

    // Convert input characters to integer indices
    int start = startChar - 'A';
    int end = endChar - 'A';

    // Count all paths from start to end
    int totalPaths = countPaths(graph, start, end);

    cout << "Total paths between " << startChar << " and " << endChar << " are: " << totalPaths << endl;

    return 0;
}
