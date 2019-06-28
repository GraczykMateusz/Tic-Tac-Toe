#include <iostream>
#include "systemClear.cpp"

using std::cout;
using std::endl;

void showStartMenu() {
	systemClear();
	cout<<"Tic-Tac-Toe"<<endl<<endl;
	//Lines
	for(int z = 0; z < 11; z++) {
		if(z != 3 && z != 7 && z != 11) {
			for(int i = 0; i < 5; i++) {
				if(i % 2 == 0)
					cout<<"   ";
				else
					cout<<"#";
			}
		cout<<endl;
		}
		else {
			for(int j = 0; j < 11; j++) {
               			 cout<<"#";
 			}
		cout<<endl; 	 
		}
	}    	
}
