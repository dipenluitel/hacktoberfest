import java.util.*;

public class DijkstraAlgorithm {
    public static void main(String[] args) {
        int[][] graph = {
            {0, 4, 0, 0, 0, 0, 0, 8, 0},
            {4, 0, 8, 0, 0, 0, 0, 11, 0},
            {0, 8, 0, 7, 0, 4, 0, 0, 2},
            {0, 0, 7, 0, 9, 14, 0, 0, 0},
            {0, 0, 0, 9, 0, 10, 0, 0, 0},
            {0, 0, 4, 14, 10, 0, 2, 0, 0},
            {0, 0, 0, 0, 0, 2, 0, 1, 6},
            {8, 11, 0, 0, 0, 0, 1, 0, 7},
            {0, 0, 2, 0, 0, 0, 6, 7, 0}
        };
        int[] shortestDistances = dijkstra(graph, 0);
        System.out.println("Shortest distances from vertex 0:");
        for (int i = 0; i < shortestDistances.length; i++) {
            System.out.println("Vertex " + i + ": " + shortestDistances[i]);
        }
    }

    public static int[] dijkstra(int[][] graph, int source) {
        int V = graph.length;
        int[] distances = new int[V];
        boolean[] shortestPathTreeSet = new boolean[V];

        for (int i = 0; i < V; i++) {
            distances[i] = Integer.MAX_VALUE;
            shortestPathTreeSet[i] = false;
        }

        distances[source] = 0;

        for (int count = 0; count < V - 1; count++) {
            int u = minDistance(distances, shortestPathTreeSet);
            shortestPathTreeSet[u] = true;

            for (int v = 0; v < V; v++) {
                if (!shortestPathTreeSet[v] && graph[u][v] != 0 && distances[u] != Integer.MAX_VALUE
                        && distances[u] + graph[u][v] < distances[v]) {
                    distances[v] = distances[u] + graph[u][v];
                }
            }
        }

        return distances;
    }

    public static int minDistance(int[] distances, boolean[] shortestPathTreeSet) {
        int min = Integer.MAX_VALUE;
        int minIndex = -1;

        for (int v = 0; v < distances.length; v++) {
            if (!shortestPathTreeSet[v] && distances[v] <= min) {
                min = distances[v];
                minIndex = v;
            }
        }

        return minIndex;
    }
}
