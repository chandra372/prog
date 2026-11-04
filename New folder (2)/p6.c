#include<stdio.h>

#define MAX 10

int adjacencyMatrix[MAX][MAX];
int numNodes;

// Function to display adjacent nodes of a given node
void displayAdjacentNodes(int rootNode) {
    int i;

    printf("\nAdjacent nodes of node %d:\n", rootNode);

    for (i = 1; i <= numNodes; i++) {
        if (adjacencyMatrix[rootNode][i] == 1 || adjacencyMatrix[i][rootNode] == 1) {
            printf("%d\t", i);
        }
    }

    printf("\n");
}

int main() {
    int i, j, rootNode;

    // Input number of nodes
    printf("Enter number of nodes: ");
    scanf("%d", &numNodes);

    // Input the adjacency matrix
    printf("Enter adjacency matrix:\n");
    for (i = 1; i <= numNodes; i++) {
        for (j = 1; j <= numNodes; j++) {
            printf("Is there a connection from node %d to node %d (1=yes, 0=no): ", i, j);
            scanf("%d", &adjacencyMatrix[i][j]);
        }
    }

    // Input the root node
    printf("Enter root node (1 to %d): ", numNodes);
    scanf("%d", &rootNode);

    // Display adjacent nodes
    displayAdjacentNodes(rootNode);

    return 0;
}