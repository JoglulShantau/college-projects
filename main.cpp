//using Dsikstras algorithm 

#include <iostream>
#include <climits>
using namespace std;

int minimum(int *totalDist, bool *visited, int n) // returns the minimum distance in a vertex from all the unfamiliar vertices
{
  int minvertex = -1;
  for (int i = 0; i < n; i++)
  {
    if (!visited[i] && (minvertex == -1 || totalDist[i] < totalDist[minvertex]))
    {
      minvertex = i;
    }
  }
  return minvertex;
}

int DistanceAlgo(int **edgesMat, int n, int num) // calculates the shortest path according to Dijkstra's Algorithm
{
  int *totalDist = new int[n]; //  stores all the distances of the edges from inital point. 
  bool *visited = new bool[n]; // stores all the familiar areas.
  for (int i = 0; i < n; i++)
  {
    totalDist[i] = INT_MAX;
    visited[i] = false;
  }
  totalDist[0] = 0;
  for (int i = 0; i < n; i++)
  {
    int minvertex = minimum(totalDist, visited, n);
    visited[minvertex] = true;
    for (int j = 0; j < n; j++)
    {
      if (edgesMat[minvertex][j] != 0 && !visited[j])
      {
        int dist = totalDist[minvertex] + edgesMat[minvertex][j];
        if (dist < totalDist[j])
        {
          totalDist[j] = dist;
        }
      }
    }
  }
  return totalDist[num];
}

int main()
{
  //Inputting  the information we know which is the vertices and edges.
  int Vex, Edge, tempX, tempY;
  cout << "Enter Number of Vertices and edges: ";
  cin >> Vex >> Edge;
  int **edgesMat = new int *[Vex];
  for (int i = 0; i < Vex; i++)
  {
    edgesMat[i] = new int[Vex];
    for (int j = 0; j < Vex; j++)
    {
      edgesMat[i][j] = 0;
    }
  }
  /* Allows the user to put in the necessary information for the map provided and the destination.*/
  cout << "Enter all Edges: ";
  for (int i = 0; i < Edge; i++)
  {
    char x, y;
    int w;
    cin >> x >> y >> w;
    int a = x - 'A', b = y - 'A';
    edgesMat[a][b] = w;
    edgesMat[b][a] = w;
  }
  /* type in your destination and  it will provide the length of point A to whatever destination you may wish to go*/
  cout << "Enter destination edge name: ";
  char dest;
  cin >> dest;
  //Results will be printed
  cout << "Total Distance from A - " << dest << " is " << DistanceAlgo(edgesMat, Vex, (dest - 'A'));

  return 0;

  /* When it is asking for vertices and Edges put 11 13*/
  /* When it is asking to enter all edges copy paste into terminal 
  A B 40
  A G 30
  B F 20
  B C 15
  G J 50
  F E 30
  C D 20
  C J 40
  D K 5
  J K 40
  K H 45
  E I 30
  H I 10 */
  /* When it is asking for destination edge name it will be G */
}