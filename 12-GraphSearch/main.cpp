#include "Graph.h"

int main(){
	char a;
	Graph<int,int> new_graph;

	for(int i=0; i<10; i++){
		new_graph.insert_node(i);
	}

	new_graph.print_Graph();
	cin>>a;
	return 0;
}