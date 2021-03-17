#include<iostream>
#include<vector>
#include<queue>

using namespace std;


class Graph{

	
	private:
	
		int numVertices;
		vector<int>* adj;
		
		
		bool hascycle(int s, bool * visited, int parent){
		
		
			visited[s] = true;
			
			for( int u : adj[s]){
			
				if(visited[u] == false){
				
					if(hascycle(u,visited,s) == true){
					
						return true;
					}
				
				
				}
			    
			    else if( u != parent){
			    	return true;
			    } 
			
			}
			
			return false;
		
		
		
		
		
		
		}
		
		void DFSRec(int s, bool* visited){
		
			visited[s] = true;
			cout<<s<<" ";
			for(int u : adj[s]){
			
				if(visited[u] == false){
					
					DFSRec(u,visited);
				
				}
			
			
			}
		
		}
		
		void BFSIt(int s, bool* visited){
		
			queue<int> q;
			
			visited[s] = true;
			
			q.push(s);
			
			while(q.empty() == false){
				
				int u = q.front();
				q.pop();
		         cout<<u<<" ";	
				for(int i : adj[u]){
				
					if(visited[i] == false){
					
						q.push(i);
						visited[i] = true;
					
					}
				
				
				}
			
			
			}
		
		
		
		
		
		}
		
		
	public:
	
		Graph(int numVertices){
		
			this->numVertices = numVertices;
			adj = new vector<int> [numVertices];
		
		}
		
		
		void addEdge(int u, int v){
		
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		
		
		void DFS(){
			
			bool* visited = new bool [numVertices];
			
			for(int u = 0; u< numVertices; u++){
			   
			   visited[u] = false;
			
			}
			
			for(int u = 0; u< numVertices; u++){
			
				if(visited[u] == false){
				    
					DFSRec(u,visited);
				
				}
			
			}
			
		
		}
		
		
		void BFS(){
		
		
			bool* visited = new bool[numVertices];
			
			for(int u = 0; u< numVertices; u++){
			
			
				visited[u] = false;
				
			
			}
			
			
			for(int u = 0; u< numVertices; u++){
			    
				if(visited[u] == false){
				
					BFSIt(u,visited);
				
				}
			
			}
		
		
		
		
		
		
		}
		
		
		
		bool detect_cycle(){
		
		
			bool* visited = new bool[numVertices];
			
			for(int i = 0; i < numVertices; ++i){
			
				visited[i] = false;
			
			}
			
			for(int i = 0; i < numVertices; ++i){
			
				if(visited[i] == false){
				
					if(hascycle(i,visited,-1) == true ){
					
						return true;
					} 
					
				
				
				}
			
			}
		
		    return false;
		}
	
};

int main(){




	Graph g(9);
	
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,8);
	g.addEdge(8,1);
	g.addEdge(2,3);
	g.addEdge(3,7);
	g.addEdge(3,4);
	g.addEdge(7,4);
	g.addEdge(4,5);
	
	if(g.detect_cycle()){
		
		cout<<"cycle exist"<<endl;
	
	}
	
	
	else{
	
		cout<<"cycle not exist"<<endl;
	
	}





    return 0;




}



