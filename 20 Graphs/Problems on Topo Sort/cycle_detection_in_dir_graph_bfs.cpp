/*
    ============================================================
    TOPIC   : Graphs - Topo Sort
    PROBLEM : Cycle Detection in Directed Graph (using Kahn's BFS Topo Sort)
    ============================================================

    INTUITION:
    ----------
    - Kahn's algorithm (BFS, indegree-based) can only fully
      topologically sort a DAG (no cycles). If the graph has a cycle,
      some nodes will NEVER reach indegree 0 (they depend circularly on
      each other), so Kahn's BFS processes fewer than V nodes.
    - So: run Kahn's algorithm, count how many nodes got processed; if
      count < V, a cycle exists.

    STEPS:
    ----------
    1. Compute indegree of every node from the adjacency list.
    2. Push all 0-indegree nodes into the queue.
    3. Kahn's BFS: pop, count++, decrement indegree of neighbors, push
       any that hit 0.
    4. If count != V at the end, a cycle exists -> return true.

    VARIATIONS TO REMEMBER:
    ----------
    - This is the BFS/Kahn's alternative to the DFS + pathVis technique
      in cycle_detection_in_dir_graph_dfs.cpp -- same result, different
      mechanism.
    - This is also literally how Course Schedule I works internally.

    TIME COMPLEXITY  : O(V + E)
    SPACE COMPLEXITY : O(V + E) -> adjacency list + indegree array + queue
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasCycle(int V, vector<vector<int>>& adj) {
        vector<int> indegree(V, 0);

        // Calculate in-degrees
        for(int i = 0; i < V; i++){
            for(int nbr : adj[i])
                indegree[nbr]++;
        }

        // Queue for nodes with indegree = 0
        queue<int> q;
        for(int i = 0; i < V; i++){
            if(indegree[i] == 0)
                q.push(i);
        }

        int count = 0; // Count of nodes processed

        // Kahn's Algorithm
        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;

            for(int nbr : adj[node]){
                indegree[nbr]--;
                if(indegree[nbr] == 0)
                    q.push(nbr);
            }
        }

        // If all nodes are processed -> No cycle
        return (count != V); // If count < V → cycle exists
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> adj(V);
    cout << "Enter directed edges (u v):\n";
    for(int i = 0; i < E; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    Solution obj;
    if(obj.hasCycle(V, adj))
        cout << "Graph contains Cycle → Not a DAG\n";
    else
        cout << "No Cycle found → DAG\n";

    return 0;
}
