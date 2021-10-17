
#include<bits/stdc++.h>
using namespace std;
struct node {
    int u;
    int v;
    int wt; 
    node(int first, int second, int weight) {
        u = first;
        v = second;
        wt = weight;
    }
};

int main(){
    int N,m;
    cin >> N >> m;
    vector<node> edges; 
    for(int i = 0;i<m;i++) {
        int u, v, wt;
        cin >> u >> v >> wt; 
        edges.push_back(node(u, v, wt)); 
    }

    int src;
    cin >> src; 


    int inf = 10000000; 
    vector<int> dist(N, inf); 

    dist[src] = 0; 

    for(int i = 1;i<=N-1;i++) {
        for(auto it: edges) {
            if(dist[it.u] + it.wt < dist[it.v]) {
                dist[it.v] = dist[it.u] + it.wt; 
            }
        }
    }

    int fl = 0; 
    for(auto it: edges) {
        if(dist[it.u] + it.wt < dist[it.v]) {
            cout << "Negative Cycle"; 
            fl = 1; 
            break; 
        }
    }

    if(!fl) {
        for(int i =  0;i<N;i++) {
            cout << i << " " << dist[i] << endl;
        }
    }


    return 0;
}

// #include<bits/stdc++.h>
// using namespace std;

// struct edge{
// 	int src,dst,wt;
// };
// int V,E;

// void bellmanFord(vector<edge>& Edges)
// {
// 	int parent[V];		//Stores Shortest Path Structure
// 	int cost_parent[V];	//Cost of the node to parent edge weight
// 	vector<int> value(V,INT_MAX);	//Keeps shortest path values to each vertex from source
	
// 	//Assuming start point as Node-0
// 	parent[0] = -1;	//Start node has no parent
// 	value[0] = 0;	//start node has value=0 to get picked 1st

// 	//Include (V-1) edges to cover all V-vertices
// 	bool updated;
// 	for(int i=0;i<V-1;++i)
// 	{
// 		updated = false;
// 		for(int j=0;j<E;++j)
// 		{
// 			int U = Edges[j].src;
// 			int V = Edges[j].dst;
// 			int wt = Edges[j].wt;
// 			if(value[U]!=INT_MAX and value[U]+wt<value[V])
// 			{
// 				value[V] = value[U]+wt;
// 				parent[V] = U;
// 				cost_parent[V] = value[V];
// 				updated = true;
// 			}
// 		}
// 		if(updated==false)
// 			break;
// 	}
// 	//Now check by relaxing once more if we have a negative edge cycle
// 	for(int j=0;j<E and updated==true;++j)
// 		{
// 			int U = Edges[j].src;
// 			int V = Edges[j].dst;
// 			int wt = Edges[j].wt;
// 			if(value[U]!=INT_MAX and value[U]+wt<value[V])
// 			{
// 				cout<<"Graph has -VE edge cycle\n";
// 				return;
// 			}
// 		}
// 	//Print Shortest Path Graph
// 	for(int i=1;i<V;++i)
// 		cout<<"U->V: "<<parent[i]<<"->"<<i<<"  Cost to reach "<<"from source 0 = "<<value[i]<<"\n";
// }

// int main()
// {
// 	cin>>V>>E;	//Enter no of Vertices and Edges
// 	vector<edge> Edges(E);

// 	//Now input all E edges
// 	int src,dst,wt;
// 	for(int i=0;i<E;++i)
// 	{
// 		cin>>src>>dst>>wt;
// 		Edges[i].src = src;
// 		Edges[i].dst = dst;
// 		Edges[i].wt = wt;
// 	}

// 	bellmanFord(Edges);	
// 	return 0;
// }


