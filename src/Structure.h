#ifndef STRUCTURE_HEADER
#define STRUCTURE_HEADER

#include "Cell.h"
#include "stack"
#include <map>

 struct Board{
	 Board(){
		for(int i=0;i<sizeX;i++){
			for(int j=0;j<sizeY;j++){
				numbers[i][j]=0;
				boxes[i][j]=0;
			}
		}
	 }
	 Cell cells[sizeX][sizeY] ;
	 int numbers[sizeX][sizeY];
	 int boxes[sizeX][sizeY];
	};

class GameStructure {
	
	public : Board b ;
	public : GameStructure *parent;
	public : int depth;
	public : int id;

	int GameStructure::getDepth() const{
		return this->depth;
	}


	GameStructure()
	{
		depth = 0;
		id =0;
	};


	
	/**
	GameStructure::GameStructure (const GameStructure &s)
    {
		this->b = s.b;
		this->parent = s.parent;

    }**/

	bool GameStructure::operator==(GameStructure const &structure) const {
		for(int i=0;i<sizeX;i++){
			for(int j=0;j<sizeY;j++){
				if(b.boxes[i][j] != structure.b.boxes[i][j]){
					return false;
					}
				}
			}
		return true;
	}


	
	public : GameStructure deepCopy(GameStructure oldS){
		GameStructure s;
		s.b = oldS.b;
		s.depth = oldS.depth;
		s.id=oldS.id;
		return s;

	}

	public : GameStructure deepCopyWithParent(GameStructure &oldS,GameStructure par){
		GameStructure s;
		s.b = oldS.b;
		s.depth = oldS.depth;
		s.parent = &par;
		return s;

	}
	/**Initializing states**/
	
	public : void initLevel1(){
	initBoard(b);
	b.numbers[3][5]=1;
	b.boxes[3][1]=1;
	for(int i=0;i<sizeX;i++){
		
		for(int j=0;j<sizeY;j++){
			b.cells[i][j].position.first=i;
			b.cells[i][j].position.second=j;
			b.cells[i][j].type="wall";
			if(i==3 && (j>=1 && j<=5)){
				b.cells[i][j].type="empty";
			}
			
		}
	}
	b.cells[3][5].type="number";
	b.cells[3][1].type="box";
	}

	public : void initLevel2(){
		initBoard(b);
		b.boxes[1][1]=1;
		b.boxes[1][3]=2;
		b.numbers[4][1]=1;
		b.numbers[4][3]=2;
		for(int i=0;i<sizeX;i++){
			
			for(int j=0;j<sizeY;j++){
				b.cells[i][j].position.first=i;
				b.cells[i][j].position.second=j;
				b.cells[i][j].type="wall";
				if((j==1 && (i>0&&i<4)) || (j==3 &&  (i>0&&i<4)) ){
					b.cells[i][j].type="empty";
				}

			}
		}
		b.cells[1][1].type="box";
		b.cells[1][3].type="box";
		b.cells[4][1].type="number";
		b.cells[4][3].type="number";
	}

	public : void initLevel3(){
		initBoard(b);
		b.boxes[1][1]=1;
		b.numbers[1][2]=2;
		b.numbers[3][2]=1;
		b.boxes[3][3]=2;
		for(int i=0;i<sizeX;i++){
			
			for(int j=0;j<sizeY;j++){
				b.cells[i][j].position.first=i;
				b.cells[i][j].position.second=j;
		
				b.cells[i][j].type="wall";
				if(i==1 && (j>=1 && j<=3)){
					b.cells[i][j].type="empty";	
				}
				if(i==2 && j==2){
					b.cells[i][j].type="empty";
				}
		
				if(i==3 && (j>=1 && j<=3)){
					b.cells[i][j].type="empty";
					
				}
				
			}
		}
		b.cells[1][1].type="box";
		b.cells[1][2].type="number";
		b.cells[3][2].type="number";
		b.cells[3][3].type="box";
	}	
	
	public :void initLevel4(){
		initBoard(b);
		b.boxes[2][1]=1;
		b.boxes[2][3]=2;
		b.boxes[2][5]=3;
	
		b.numbers[3][1]=3;
		b.numbers[3][3]=2;
		b.numbers[3][5]=1;
	
		for(int i=0;i<sizeX;i++){
			
			for(int j=0;j<sizeY;j++){
				b.cells[i][j].position.first=i;
				b.cells[i][j].position.second=j;
				
				b.cells[i][j].type="wall";
				
				if(i==3 && (j>=1 && j<=5)){
					b.cells[i][j].type="empty";
					
				}
	
				if(i==4 && j==3){
					b.cells[i][j].type="empty";
				}
			}
		}
		b.cells[2][1].type="box";
		b.cells[2][3].type="box";
		b.cells[2][5].type="box";
	
		b.cells[3][1].type="number";
		b.cells[3][3].type="number";
		b.cells[3][5].type="number";
	}
	
	public : void initLevel5(){
		initBoard(b);
		b.boxes[2][1]=1;
		b.numbers[3][1]=1;
		b.boxes[3][2]=2;
		b.numbers[4][2]=2;
		b.boxes[4][3]=3;
		b.numbers[4][4]=4;
		b.numbers[5][3]=3;
		b.boxes[5][4]=4;
	
		for(int i=0;i<sizeX;i++){
			
			for(int j=0;j<sizeY;j++){
	
				b.cells[i][j].position.first=i;
				b.cells[i][j].position.second=j;
	
				b.cells[i][j].type="wall";
				
				if(i==3 && j==4){
					b.cells[i][j].type="empty";
				}
				if(i==4 && (j>=1 && j<=4)){
					b.cells[i][j].type="empty";				
				}
				if(i==5 && (j>=1 && j<=4)){
					b.cells[i][j].type="empty";
				}
			}
		}
		b.cells[2][1].type="box";
		b.cells[3][1].type="number";
		b.cells[3][2].type="box";
		b.cells[4][2].type="number";
		b.cells[4][3].type="box";
		b.cells[4][4].type="number";
		b.cells[5][3].type="number";
		b.cells[5][4].type="box";
	}
	
	public : void initLevel6(){
		initBoard(b);
		b.boxes[2][4]=2;
		b.boxes[3][3]=1;
		b.numbers[3][4]=1;
		b.boxes[3][5]=5;
		b.boxes[4][2]=3;
		b.boxes[4][4]=4;
		b.numbers[4][5]=4;
		b.numbers[4][4]=3;
		b.numbers[3][5]=5;
		b.numbers[2][4]=2;
	
		for(int i=0;i<sizeX;i++){
			
			for(int j=0;j<sizeY;j++){
	
				b.cells[i][j].position.first=i;
				b.cells[i][j].position.second=j;
	
				b.cells[i][j].type="wall";
				
				if(i==2 && (j>=2 && j<=4)){
					b.cells[i][j].type="empty";
				}
				if(i==3 && (j>=2 && j<=5)){
					b.cells[i][j].type="empty";	
				}
			}
		}
	
		b.cells[2][4].type="box";
		b.cells[3][3].type="box";
		b.cells[3][4].type="number";
		b.cells[3][5].type="box";
		b.cells[4][2].type="box";
		b.cells[4][4].type="box";
		b.cells[4][5].type="number";
		b.cells[4][4].type="number";
		b.cells[3][5].type="number";
		b.cells[2][4].type="number";
	}
	
	public : void initBoard(Board b){
		b = Board();
	}
	
	public : void printGrid(Board b) {
	
    int i,j;
	
	cout << endl;

	for(i=0;i<sizeX;i++){
		cout<<"________________";
	}
	cout<<endl;
	for (i = 0; i < sizeX; i++) {
		
		for(j=0;j<sizeY;j++){

			
			cout<<"|";

			if(b.boxes[i][j]!=0){
				cout<<"\t"<<"B"<<b.boxes[i][j]<<"\t" ;
			}
			else if(b.numbers[i][j]!=0){
				if(b.numbers[i][j]==b.boxes[i][j]){
					
					cout<<"\t"<<"B"<<b.boxes[i][j]<<"\t" ;
				}else{
					cout<<"\t"<<"N"<<b.numbers[i][j]<<"\t" ;
				}
			 
			}else if (b.cells[i][j].type=="empty"){
				cout<<"\t"<<" "<<"\t"  ;	
			}else{
				if(b.cells[i][j].type=="box"){
					cout<<"\t"<<" "<<"\t"  ;	
				}else{
				cout<<"\t"<<"*"<<"\t" ;
				}
			}
		
	  }
		cout<<"|";
		cout<<"\n";	    
    }
	for(i=0;i<sizeX;i++){
		cout<<"________________";
	}
	cout<<"\n";
}
	

	/**Computer Part**/
	
	public : pair<int,int> checkMoveUp(Board b,int i,int j){
	pair<int,int> position;
	position.first=-1;
	position.second=-1;
	if(i-1>=0 && b.cells[i-1][j].type!="wall"  && b.boxes[i][j]!=0 && b.boxes[i-1][j]==0){
			position.first=i-1;
			position.second=j;
	}
	return position;
}
		   
	public : pair<int,int> checkMoveDown(Board b,int i,int j){
	pair<int,int> position;
	position.first=-1;
	position.second=-1;
	
	//cout << "2st cond "<<b.cells[i+1][j].type << " "<<"3rd cond "<<b.boxes[i][j]<<" " << "4th cond "<<b.boxes[i+1][j];
	if(i+1<=sizeX && b.cells[i+1][j].type!="wall" && b.boxes[i][j]!=0 && b.boxes[i+1][j]==0){
		
			position.first=i+1;
			position.second=j;
		
	}
	return position;
}
		   
	public : pair<int,int> checkMoveRight(Board b,int i,int j){
	pair<int,int> position;
	position.first=-1;
	position.second=-1;
	if(j+1<=sizeY && b.cells[i][j+1].type!="wall"  && b.boxes[i][j]!=0 && b.boxes[i][j+1]==0){
		
			position.first=i;
			position.second=j+1;
		
	}
	
	return position;
}
		   
	public : pair<int,int> checkMoveLeft(Board b,int i,int j){
	pair<int,int> position;
	position.first=-1;
	position.second=-1;
	if(j-1>=0 && b.cells[i][j-1].type!="wall" && b.boxes[i][j]!=0 && b.boxes[i][j-1]==0){
		
			position.first=i;
			position.second=j-1;

	}
	return position;
}
		   
	public : void move(Board &b,int i,int j,int new_i,int new_j){
	b.boxes[new_i][new_j]=b.boxes[i][j];
	b.boxes[i][j]=0;
	//cout<<"new i = "<<new_i << " j= " << new_j << " box is " << b.boxes[new_i][new_j] <<endl;
}
		   
	public : list<pair<int,int>> checkMovesForSingleCell(Board b,int i ,int j){
	list<pair<int,int>> possible_positions_single;

	pair <int,int>moveUp = checkMoveUp(b,i,j);
	pair <int,int>moveDown = checkMoveDown(b,i,j);
	pair <int,int>moveRight = checkMoveRight(b,i,j);
	pair <int,int>moveLeft = checkMoveLeft(b,i,j);
	
	if(moveUp.first!=-1 && moveUp.second!=-1){
		possible_positions_single.push_front(moveUp);
	}
	if(moveDown.first!=-1 && moveDown.second!=-1){
		possible_positions_single.push_front(moveDown);
	}
	if(moveRight.first!=-1 && moveRight.second!=-1){
		possible_positions_single.push_front(moveRight);
	}
	if(moveLeft.first!=-1 && moveLeft.second!=-1){
		possible_positions_single.push_front(moveLeft);
	}
	return possible_positions_single;
}
		
	public : map<pair<int,int>,list<pair<int,int>>> checkMoves(Board b){	
	map<pair<int,int>,list<pair<int,int>>> possible_positions;
	for(int i=0;i<sizeX;i++){
		for(int j=0;j<sizeY;j++){
			possible_positions.insert(make_pair(make_pair(i,j), checkMovesForSingleCell(b,i,j)));
			
		}
	}
		/**for(int i=0;i<sizeX;i++){
		for(int j=0;j<sizeY;j++){
			for (std::list<pair<int,int>>::iterator it = possible_positions[make_pair(i,j)].begin(); it != possible_positions[make_pair(i,j)].end(); ++it){
				if(i!=0 && i!=1 &&  i!=6){
				cout<< "i= "<<i<<" j= "<< j << endl;
				cout << "pair = ("<<it->first << ","<<it->second<<")";
				cout << endl<<endl;
				}
			}
		}
		
	}**/
		return possible_positions;
	}
	
	public : vector <GameStructure> getNextStates(GameStructure s){
		vector <GameStructure> nextStates ;
		map<pair<int,int>,list<pair<int,int>>> possiblePositions = checkMoves(b);
		for(int i=0;i<sizeX;i++){
			for(int j=0;j<sizeY;j++){
				for (std::list<pair<int,int>>::iterator it = possiblePositions[make_pair(i,j)].begin(); it != possiblePositions[make_pair(i,j)].end(); ++it){
					
					/**cout<< "i= "<<i<<" j= "<< j << endl;
					cout << "pair = ("<<it->first << ","<<it->second<<")";
					cout << endl<<endl;
					
					s.printGrid(s.b);
					
					if(newS==s){
						cout<<"Equal"<<endl;
					}else{
						cout<<"Not Equal"<<endl;
					}
					newS.printGrid(newS.b);**/

					////////
					GameStructure newS = s;
					newS.move(newS.b,i,j,it->first,it->second);
					nextStates.push_back(newS);
					////////
					
				}
			}
		}
		return nextStates;
	}

	public : vector <GameStructure> getNextStates2(GameStructure &s,int &idNum ,map<int , GameStructure>&nodes,map<int , int>&childToParent){

		vector <GameStructure> nextStates; 
		nextStates.reserve(4);
		int inc=0;

		GameStructure newSUp = s.deepCopy(s) ;
		newSUp.parent = &s;
		

		GameStructure newSDown = s.deepCopy(s);
		newSDown.parent = &s;
		
		
		GameStructure newSRight = s.deepCopy(s);
		newSRight.parent = &s;
		
		
		GameStructure newSLeft = s.deepCopy(s);
		newSLeft.parent  = &s;
		

		

		map<pair<int,int>,list<pair<int,int>>> possiblePositions = checkMoves(b);
		for(int i=0;i<sizeX;i++){
			for(int j=0;j<sizeY;j++){
				for (std::list<pair<int,int>>::iterator it = possiblePositions[make_pair(i,j)].begin(); it != possiblePositions[make_pair(i,j)].end(); ++it){
				
					if(i>it->first){
						newSUp.move(newSUp.b,i,j,it->first,it->second);
					}
					if(i<it->first){
						newSDown.move(newSDown.b,i,j,it->first,it->second);
					}
					if(j<it->second){
						newSRight.move(newSRight.b,i,j,it->first,it->second);
					}
					if(j>it->second){
						newSLeft.move(newSLeft.b,i,j,it->first,it->second);
					}	
										
				}
			} 
		}


		if((newSUp==s)==false){
			newSUp.id = ++idNum;
			nodes[idNum]=newSUp;
			childToParent[idNum]=s.id;
			nextStates.push_back(newSUp);
			
			
		} 
		if((newSDown==s)==false){  
			newSDown.id = ++idNum;
			nodes[idNum]=newSDown;
			childToParent[idNum]=s.id;
			nextStates.push_back(newSDown);
		}
		if((newSRight==s)==false){
			newSRight.id = ++idNum;
			nodes[idNum]=newSRight;
			childToParent[idNum]=s.id;
			nextStates.push_back(newSRight);
		}
		if((newSLeft==s)==false){
			newSLeft.id = ++idNum;
			nodes[idNum]=newSLeft;
			childToParent[idNum]=s.id;
			nextStates.push_back(newSLeft);
		}
		
	

		return nextStates;
	}


	
	/**User Part**/  
 
	public : bool checkUp(Board b,int i,int j){
	if(i-1>=0 && b.cells[i-1][j].type!="wall"  && b.boxes[i][j]!=0 && b.boxes[i-1][j]==0){
		return true;
	}
	return false;
}
		   
	public : bool checkDown(Board b,int i,int j){
	if(i+1<=sizeX && b.cells[i+1][j].type!="wall" && b.boxes[i][j]!=0 && b.boxes[i+1][j]==0){
		return true;
	}
	return false;
}
		   
	public : bool checkRight(Board b,int i,int j){
	if(j+1<=sizeY && b.cells[i][j+1].type!="wall"  && b.boxes[i][j]!=0 && b.boxes[i][j+1]==0){
		//cout<< b.cells[i][j].type<<endl;
		return true;
	}
	return false;
}
		   
	public : bool checkLeft(Board b,int i,int j){
	if(j-1>=0 && b.cells[i][j-1].type!="wall" && b.boxes[i][j]!=0 && b.boxes[i][j-1]==0){
		return true;
	}
	return false;
}
		   
	public : bool checkForOptimality(Board b){
	for(int i=0;i<sizeX;i++){
		for(int j=0;j<sizeY;j++){
			if(b.numbers[i][j]!=b.boxes[i][j]){
				return false;
			}
		}
	}
	return true;
}
		   
	public : bool userMove(char letter){
	bool visited[sizeX][sizeY];
	for(int i = 0; i < sizeX; i++){ 
		for(int j = 0; j < sizeY; j++){   
			visited[i][j] = false; 
		}
	}

	if(letter=='w'){
		
		for(int i=0;i<sizeX;i++){
			for(int j=0;j<sizeY;j++){
				if(visited[i][j]!=true){ 
					if(checkUp(b,i,j)){
						move(b,i,j,i-1,j);
						visited[i+1][j]=true;
					}
				}
			}
		}
		return checkForOptimality(b);
	}else if(letter=='s'){
		
		for(int i=0;i<sizeX;i++){
			for(int j=0;j<sizeY;j++){
				if(visited[i][j]!=true){ 
					if(checkDown(b,i,j)){
						move(b,i,j,i+1,j);
						visited[i+1][j]=true;
						
					}
				}
			}
		}
		return checkForOptimality(b);
	}else if(letter=='d'){
		for(int i=0;i<sizeX;i++){
			for(int j=0;j<sizeY;j++){
				if(visited[i][j]!=true){
					if(checkRight(b,i,j)){
						move(b,i,j,i,j+1);
						visited[i][j+1]=true;
					}
				}
			}
		}
		return checkForOptimality(b);
	}else{
		for(int i=0;i<sizeX;i++){
			for(int j=0;j<sizeY;j++){
				if(visited[i][j]!=true){
					if(checkLeft(b,i,j)){
						move(b,i,j,i,j-1);
						visited[i][j+1]=true;
					}
				}
			}
		}	
	}
	return checkForOptimality(b);
}
	
};
#endif STRUCTURE_HEADER