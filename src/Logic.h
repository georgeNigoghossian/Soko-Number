#include "Structure.h"
#include "Stack"
#include "Queue"
#include <time.h>


 
class Comp 
{ 
public: 
	bool operator () (int lhs, int rhs) { 
		return lhs < rhs; 
	} 
}; 
 

class GameLogic {

	
public : void userPlay(GameStructure structure){
	char letter;
	cout << "Move Up,Down,Right,Left using w,s,d,a or q to exit"<<endl;
	cin>>letter;
	
	while(letter!='q'){
		
		bool success=structure.userMove(letter);
		structure.printGrid(structure.b);
		if(success==true){
			cout<<"Level Finished"<<endl;
			break;
		}
		cout << "Move Up,Down,Right,Left using w,s,d,a or q to exit"<<endl;
		cin >> letter;

		}
	}


public : void DFS(GameStructure structure){
		
		time_t start,end;
		time (&start);
		
		int idNumbers=0;
		stack <GameStructure> open;
		vector<GameStructure> visited;
		GameStructure temp,opt;
		map <int,GameStructure> nodes;
		map <int,int> childToParent;

		int inc=0;
		 
		open.push(structure);

		while(!open.empty()){
			GameStructure st = open.top();
			
			open.pop();
			
			if(std::find(visited.begin(), visited.end(), st) == visited.end()){
				visited.push_back(st);
				
			}
			
			vector<GameStructure>states = st.getNextStates2(st,idNumbers,nodes,childToParent);  
			
			for (GameStructure s : states) {
				
				
				if(std::find(visited.begin(), visited.end(), s) == visited.end()){
				    
				   s.depth++;	
				   temp =s;
				   open.push(s);
				   inc++;
			   
			   }

				if(s.checkForOptimality(s.b)){
					int num=s.id;
					
					while(true){		
						if(num>0){
							GameStructure element = nodes[num];
							element.printGrid(element.b);
							num = childToParent[num] ;	
						}else{

							time (&end);
							double dif = difftime (end,start);
							printf ("Elasped time is %.2lf seconds.", dif );
							cout<<endl;
							cout <<"Cost = "<<inc <<endl;
							cout <<"Depth = "<< temp.depth <<endl;
							return;
						}
					}
				}

			}
		}

		

		

		
	}

public : void BFS(GameStructure structue)
{
		time_t start,end;
		time (&start);

		int inc =0;
		int idNumbers=0;
		vector<GameStructure> visited;
		GameStructure temp;
		map <int,GameStructure> nodes;
		map <int,int> childToParent;
 
   
		queue<GameStructure> queue;

		visited.push_back(structue);
		queue.push(structue);
 
		while(!queue.empty())
		{
        
			GameStructure structure = queue.front(); 
       
			queue.pop();
 
			vector<GameStructure>states = structure.getNextStates2(structure,idNumbers,nodes,childToParent);   
	
			for (GameStructure s : states) {  
        
				if (std::find(visited.begin(), visited.end(), s) == visited.end())
					{ 
						
						s.depth++;
						temp =s; 
					 
						visited.push_back(s);
						queue.push(s);
						inc++;
					}

				if(s.checkForOptimality(s.b)){
					int num=s.id;
					
					while(true){		
						if(num>0){
							GameStructure element = nodes[num];
							element.printGrid(element.b);
							num = childToParent[num] ;	
						}else{

							time (&end);
							double dif = difftime (end,start);
							printf ("Elasped time is %.2lf seconds.", dif );
							cout<<endl;
							cout <<"Cost = "<<inc <<endl;
							cout <<"Depth = "<< temp.depth <<endl;
							return;
							}
						}
					}
				}
			 }

		
	}


		 
	struct cmpDepth {
	public : bool operator()(const GameStructure& a, const GameStructure& b) {
			return a.getDepth() < b.getDepth();
		 }
	};

	public : void UCS (GameStructure struc){

		time_t start,end;
		time (&start);

		int inc =0;
		int c = 0 ;
		int idNumbers=0;
		vector<GameStructure> visited;
		GameStructure temp;
		map <int,GameStructure> nodes;
		map <int,int> childToParent;
 
   
		priority_queue<GameStructure, vector<GameStructure>, cmpDepth > queue;
		map <GameStructure*,int> cost;

		cost[&struc] = c;
		
		visited.push_back(struc);
		queue.push(struc);

		while(!queue.empty())
		{
        
			GameStructure structure = queue.top(); 
			
			queue.pop();
 
			vector<GameStructure>states = structure.getNextStates2(structure,idNumbers,nodes,childToParent);   
			

			for (GameStructure s : states) {  
				
				cost[&s]=++c;
				

				if (std::find(visited.begin(), visited.end(), s) == visited.end())
					{ 
						s.depth++;
						temp =s;
						if (cost[&s] >= s.depth ){							
							cost[&s] = s.depth  ;
						}

						visited.push_back(s);
						queue.push(s);
						inc++;
									
					}

				if(s.checkForOptimality(s.b)){
					int num=s.id;
					
					while(true){		
						if(num>0){
							GameStructure element = nodes[num];
							element.printGrid(element.b);
							num = childToParent[num] ;	
						}else{

							time (&end);
							double dif = difftime (end,start);
							printf ("Elasped time is %.2lf seconds.", dif );
							cout<<endl;
							cout <<"Cost = "<<inc <<endl;
							cout <<"Depth = "<< temp.depth <<endl;
							return;
							}
						}
					}
				}
			 }
	
	}
	
};

