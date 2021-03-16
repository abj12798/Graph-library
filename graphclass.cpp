#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Graph{

	
	private:
	
		int numVertices;
		vector<int>* adj;
		
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
				    //cout<<"check";
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
	
};




int main(){



	Graph g(7);
	 

	
	
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,4);
	g.addEdge(4,0);
	g.addEdge(0,6);
	g.addEdge(5,6);
	g.addEdge(6,4);
	
	
	cout<<"*****************************************************DFS***********************************************"<<endl;
	
	g.DFS();
	
	cout<<endl<<"*********************************************************************************************************"<<endl;
	
	cout<<"******************************************************BFS***********************************************"<<endl;
	
	g.BFS();
	
	cout<<endl<<"*********************************************************************************************************"<<endl;
	
	

    return 0;




}
