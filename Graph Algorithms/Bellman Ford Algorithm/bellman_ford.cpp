#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct edge{
	int src, dst, wt;
};

int V,E;

void bellmanFord(vector<edge>& Edges){

	int parent[V];
	int cost_parent[V];
	vector<int> value(V,INT_MAX);	

	parent[0] = -1;	
	value[0] = 0;	

	bool updated;
	for(int i=0; i<V-1; i++){
	
		updated = false;
		for(int j=0; j<E; j++){
		
			int U = Edges[j].src;
			int V = Edges[j].dst;
			int wt = Edges[j].wt;
			if(value[U]!=INT_MAX and value[U]+wt<value[V]){
			
				value[V] = value[U]+wt;
				parent[V] = U;
				cost_parent[V] = value[V];
				updated = true;
			}
		}
		if(updated==false)
			break;
	}

	// check if we have a negative edge cycle
	for(int j=0; j<E and updated==true; j++){
		
			int U = Edges[j].src;
			int V = Edges[j].dst;
			int wt = Edges[j].wt;
			if(value[U]!=INT_MAX and value[U]+wt<value[V]){
			
				// graph has -VE edge cycle
				return;
			}
	}

	// shortest path graph
	for(int i=0; i<V; i++){
		cout<<value[i]<<"\n";
	}
}

int main(){


	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

	cin >> V >> E;	
	vector<edge> Edges(E);

	int src, dst, wt;
	for(int i=0; i<E; ++i){
	
		cin >> src >> dst >> wt;
		Edges[i].src = src;
		Edges[i].dst = dst;
		Edges[i].wt = wt;
	}

	bellmanFord(Edges);	
	return 0;
}