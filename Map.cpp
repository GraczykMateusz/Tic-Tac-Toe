#include <iostream>
#include <memory>
#include <vector>

#include "Map.h"
#include "systemClear.h"

using std::cout;
using std::endl;

Map::Map() {
	setMapNumbers();
}

void Map::setMapNumbers() {
	int value;

	for(int i = 0; i < 9; ++i) {
		value = i;
		vecMap2D[i][4] = std::to_string(value);
	}
}
void Map::drawMap() {
	systemClear();
        cout << "Tic-Tac-Toe" << endl << endl;

	//Horizontal lines
	for(int i = 0; i < 9; ++i) {
		if( i == 3 || i == 6) {
			for(int z = 0; z < 11; ++z) {
				cout << '-';
			}
			cout << endl;
		}
		//Area (0,1,2)
		if(i == 0 || i == 1 || i == 2) {	
			for(int a = 0; a < 3; ++a) {
				if(i == 0) {	
					for(int k = 0; k < 3; ++k) {
						cout << vecMap2D[a][k];
					}
				}
				if(i == 1) {
                        	        for(int k = 3; k < 6; ++k) {
                        	                cout << vecMap2D[a][k];
                        	        }
				}
				if(i == 2) {
                                	for(int k = 6; k < 9; ++k) {
                                        	cout << vecMap2D[a][k];
                                	}
				}
				if(a != 2)
					cout << '|';
			}
			cout << endl;
		}
                //Area (3,4,5)
                if(i == 3 || i == 4 || i == 5) {
                        for(int a = 3; a < 6; ++a) {
                                if(i == 3) {
                                        for(int k = 0; k < 3; ++k) {
                                                cout << vecMap2D[a][k];
                                        }
                                }
                                if(i == 4) {
                                        for(int k = 3; k < 6; ++k) {
                                	        cout << vecMap2D[a][k];
                                        }
                                }                           
                                if(i == 5) {
                                        for(int k = 6; k < 9; ++k) {
                                                cout<<vecMap2D[a][k];
                                        }
                                }
                                if(a != 5)
                                	cout << '|';
                        }
                        cout << endl;
                }
                //Area (6,7,8)
                if(i == 6 || i == 7 || i == 8) {
                        for(int a = 6; a < 9; ++a) {
                                if(i == 6) {
                                        for(int k = 0; k < 3; ++k) {
                                                cout << vecMap2D[a][k];
                                        }
                                }
                                if(i == 7) {
                                        for(int k = 3; k < 6; ++k) {
                                        	cout << vecMap2D[a][k];
                                        }
                                }
                                if(i == 8) {
                                        for(int k = 6; k < 9; ++k) {
                                                cout<<vecMap2D[a][k];
                                        }
                                }
                                if(a != 8)
                                        cout << '|';
                        }
                        cout << endl;
                }
	}		
}
