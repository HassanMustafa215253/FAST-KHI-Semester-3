#include <iostream>
#include <vector>
using namespace std;

// Custom queue implementation
class Queue {
private:
    vector<int> data;
    int frontIndex;

public:
    Queue() : frontIndex(0) {}

    // Enqueue an element
    void enqueue(int x) {
        data.push_back(x);
    }

    // Dequeue an element
    void dequeue() {
        if (!isEmpty()) {
            frontIndex++;
        }
    }

    // Get the front element
    int front() {
        if (!isEmpty()) {
            return data[frontIndex];
        }
        throw out_of_range("Queue is empty");
    }

    // Check if the queue is empty
    bool isEmpty() {
        return frontIndex >= data.size();
    }
};

// BFS from given source s
void bfs(vector<vector<int>>& adj, int s) {
    // Create a custom queue for BFS
    Queue q;

    // Initially mark all the vertices as not visited
    vector<bool> visited(adj.size(), false);

    // Mark the source node as visited and enqueue it
    visited[s] = true;
    q.enqueue(s);

    // Iterate over the queue
    while (!q.isEmpty()) {
        // Dequeue a vertex from queue and print it
        int curr = q.front();
        q.dequeue();
        cout << curr << " ";

        // Get all adjacent vertices of the dequeued vertex
        // If an adjacent has not been visited, mark it visited and enqueue it
        for (int x : adj[curr]) {
            if (!visited[x]) {
                visited[x] = true;
                q.enqueue(x);
            }
        }
    }
}

// Function to add an edge to the graph
void addEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u); // Undirected Graph
    //if it's a directed graph than use only one direct edge 
     // adj[u].push_back(v); // Only one direction
}

int main() {
    // Number of vertices in the graph
    int V = 5;

    // Adjacency list representation of the graph
    vector<vector<int>> adj(V);

    // Add edges to the graph
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 4);

    // Perform BFS traversal starting from vertex 0
    cout << "BFS starting from 0 : \n";
    bfs(adj, 0);

    return 0;
}