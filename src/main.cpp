#include "Structure.h"   
#include "Logic.h"


int main()             
{              
	GameStructure s ; 
	                             
	GameLogic l ;                   
	        
	 int level,type=' ';       
	 cout<<"Choose A Level"<<endl;           
	 cin >> level;            
	 switch(level){           
	 	case 1: {      
			s.initLevel1();   
			break;  
		 } 
		case 2: {
			s.initLevel2();          
			break;  
		 }   
		case 3: {  
			s.initLevel3();    
			break; 
		 }    
		case 4: {  
			s.initLevel4();
			break;        
		 }                
		case 5: { 
			s.initLevel5();   
			break;                   
		 }   
		case 6: {    
			s.initLevel6();    
			break;           
		 }                 
		          
	 }       
      s.printGrid(s.b);         	           
	                 
	 cout << "Press 1 to play the game" << endl;
	 cout << "Press 2 to solve via DFS" << endl;    
	 cout << "Press 3 to solve via BFS" << endl;      
	 cout << "Press 4 to solve via UCS" << endl; 
	           
	 cin >> type;  
	                 
	 switch(type){     
		case 1:{           
			l.userPlay(s);    
			break;     
		}           
	   case 2:{                   
			l.DFS(s);                 
			break;         

		}       
	  case 3:{
			l.BFS(s);          
			break;      
		}
			     
	case 4:{  
			l.UCS(s);   
			break;   
		}              
	 }
	  
   return 0;   
}  