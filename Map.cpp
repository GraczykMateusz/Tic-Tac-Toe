#include <iostream>

using std::cout;
using std::endl;

void Map::setMapNumbers() {
	for(int i=0; i<9; i++) {
		array[i][5] = i;
	}
}

void Map::testMap() {
	for(int i=0; i<9; i++) {
        	for(int z=0; z<9; z++)
			array[i][z] = i;
        }

}

void Map::showMap() {
	systemClear();
        cout<<"Tic-Tac-Toe"<<endl<<endl;
	//Horizontal lines
	for(int i = 0; i < 11; i++) {
		if(i != 3 && i != 7) {          
			//Vertical lines
                        for(int j = 0; j < 11; j++) {
                                if(j != 3 && j != 7) {              
				       	if(i == 0 || i == 4 || i == 8)
						cout<<"1";
                			if(i == 1 || i == 5 || i == 9)
                       				cout<<"2";
                      			if(i == 2 || i == 6 || i == 10)
                                		cout<<"3";				
				}
				else
                                        cout<<"|";
                        }
                cout<<endl;
                }
                else {
                        for(int k = 0; k < 11; k++) {
                                 cout<<"-";
                        }
                cout<<endl;
                }
        }	
}
