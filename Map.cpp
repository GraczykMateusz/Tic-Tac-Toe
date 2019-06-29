#include <iostream>

using std::cout;
using std::endl;

void Map::setMapNumbers() {
	for(int i = 0; i < 9; i++) {
		for(int j = 0; j < 9; j++) {
			array[i][j] = '1';
		}
		array[i][5] = i;
	}
}

void Map::showMap() {
	systemClear();
        cout << "Tic-Tac-Toe" << endl << endl;
	//
	for(int i=0; i<9; i++) {
		if( i == 3 || i == 6) {
			for(int z=0; z<11; z++) {
				cout<<'-';
			}
			cout << endl;
		}
		for(int j=0; j<3; j++) {
			for(int k=0; k<3; k++) {
				cout<<array[j][k];
			}
			if(j != 2)
				cout << '|';
		}
		cout << endl;
	}
	
		
}
