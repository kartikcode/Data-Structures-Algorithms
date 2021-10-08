#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define V 4	

void floyd_warshall(int graph[V][V]){

	int dist[V][V];

	for(int i=0; i<V; i++){
		for(int j=0; j<V; j++){
			dist[i][j] = graph[i][j];
		}
	}

	for(int k=0; k<V; k++){
		for(int i=0; i<V; i++){
			for(int j=0; j<V; j++){	
				if(dist[i][k]==INT_MAX || dist[k][j]==INT_MAX){
					continue;
				}	
				else if(dist[i][k]+dist[k][j] < dist[i][j]){
					dist[i][j] = dist[i][k] + dist[k][j];
				}	
					
			}
		}
	}	

	// check for negative edge weight cycle
	for(int i=0;i<V;++i){
		if(dist[i][i] < 0){		
			cout << "negative edge weight cycle is present\n";
			return;
		}
	}

	// print shortest path graph
	// INT_MAX means no path

	for(int i=0;i<V;++i){	
		for(int j=0;j<V;++j)
			cout << dist[i][j] << " ";
		cout << "\n";
	}
}

int main(){

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
	int graph[V][V] = { {0, 9, -4, INT_MAX},
						{6, 0, INT_MAX, 2},
						{INT_MAX, 5, 0, INT_MAX},
						{INT_MAX, INT_MAX, 1, 0}};

	floyd_warshall(graph);
	return 0;
}