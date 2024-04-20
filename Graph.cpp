#include <iostream>
#include <vector>

using namespace std;
namespace ariel{
    class Graph{
        private:
            int vertecies;
            vector<vector<int>> adjMatrix;
        
        public:
            void loadGraph(const vector<vector<int>> &graph){
                vertecies = graph.size();
                adjMatrix = garph;

            }
            void printGraph(){
                int edges = 0;
                vector<vector<bool>> boolMat = NULL; //if graph is undirected, then we need a matrix to keep track of the "double counting edges" 
                for(int k=0;k<vertecies;k++){
                    for(int t=0;t<vertecies;t++){
                        boolMat[i][j] = false;
                    }
                }
                
                for(int i=0;i<vertecies;i++){
                    for(int j=0;j<vertecies;j++){
                        if(adjMatrix[i][j] == 1 && adjMatrix[j][i] == 1){
                            boolMat[j][i] == true; // for undirected graphs, count only once the edge that connects 2 vertecies.
                        }
                        if(adjMatrix[i][j] != 0 && boolMat[i][j] == false){ //check if it wasn't marked (undirected graph) and if there is an edge.
                            edges++;
                        }
                    }
                }
                cout << "Graph with " << vertices << " vertices and " << edges << " edges." << endl;
            }
                

    




    }
}