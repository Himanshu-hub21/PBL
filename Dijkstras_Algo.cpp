#include <iostream>
#include <climits>
using namespace std;

//source vertex is 0
// initial distance of all vertex is infinite
// visit least distance first and explore the neighbour

int find_min_vertex(int *distance, bool *visited, int n)
{
    int min_vertex = -1;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && (min_vertex == -1 || distance[i] < distance[min_vertex]))
        {
            min_vertex = i;
        }
    }
    return min_vertex;
}

void dijkstra(int **edges, int n)
{
    int *distance = new int[n];
    bool *visited = new bool[n];

    for (int i = 0; i < n; i++)
    {
        distance[i] = INT_MAX;
        visited[i] = false;
    }
    distance[0] = 0;

    for (int i = 0; i < n - 1; i++)
    {

        int min_vertex = find_min_vertex(distance, visited, n);
        visited[min_vertex] = true;
        for (int j = 0; j < n; j++)
        {
            if ((edges[min_vertex][j] != 0) && !visited[j])
            {
                int dist = distance[min_vertex] + edges[min_vertex][j];
                if (dist < distance[j])
                {
                    distance[j] = dist;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << i << " , " << distance[i] << endl;
    }
    delete[] visited;
    delete[] distance;
}

int main()
{
    int n;
    int e;
    cout << "Enter the total number of vertices and edges you want to visit in the format of (Total_vertices Total_edges)." << endl;
    cin >> n >> e;
    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }
    cout << "Input the vertex to vertex connection with the weight on it in format of (vertex1 vertex2 weight)." << endl;

    for (int i = 0; i < e; i++)
    {
        int f, s, weight;
        cin >> f >> s >> weight;
        edges[f][s] = weight;
        edges[s][f] = weight;
    }
    cout << endl;
    cout << "This is final output in the form of (Vertex , Distance_of_vertex)" << endl;
    dijkstra(edges, n);
    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;
}
