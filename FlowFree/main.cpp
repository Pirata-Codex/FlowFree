//
//  main.cpp
//  FlowFree
//
//  Created by Pirate on 11/3/17.
//  Copyright © 2017 Pirate. All rights reserved.
//
#include <iostream>
#include <fstream>
#include <queue>

short int temp[2];

using std::cout; using std::endl; using std::ifstream;
using std::exception;

struct node {
    
    char color;

};

//bool is_valid_i(node ** matrix, short int i, short int size) {
//    if ((j+1 > 0) && (j+1 < size) && (i+1 > 0) && (i+1 < size))
//}
//
//bool is_valid_j(node ** matrix, short int j) {
//    if ((j+1 > 0) && (j+1 < size) && (i+1 > 0) && (i+1 < size))
//}

void get_neighbour (bool * &neighbours, node ** matrix, short int coordinate[2], short int size)
{
    //up, down, left, right
    neighbours = new bool[4];
    cout<< endl;
    // 0,4
//    short int up = coordinate[0] - 1;
//    short int down = coordinate[0] + 1;
//    short int left = coordinate[1] - 1;
//    short int right = coordinate[1] + 1;

    
    if ((coordinate[0] - 1 < size) && (coordinate[0] - 1 >= 0)) {
        if (matrix[coordinate[0] - 1][coordinate[1]].color == '0') {
            neighbours[0] = true;
        }
    }
    
    if ((coordinate[0] + 1 < size) && (coordinate[0] + 1 >= 0)) {
        if (matrix[coordinate[0] + 1][coordinate[1]].color == '0') {
            neighbours[1] = true;
        }
    }
    
    if ((coordinate[1] - 1 < size) && (coordinate[1] - 1 >= 0)) {
        if (matrix[coordinate[0]][coordinate[1] - 1].color == '0') {
            neighbours[2] = true;
        }
    }
    
    if ((coordinate[1] + 1 < size) && (coordinate[1] + 1 >= 0)) {
        if (matrix[coordinate[0]][coordinate[1] + 1].color == '0') {
            neighbours[3] = true;
        }
    }
    
//    cout << "in neghi";
//    cout << endl;
//    for (int i = 0; i < 4; i++) {
//
//        cout << neighbours[i] << " ,";
//    }
}

void init_successor() {
    ifstream input("input.txt");
    short int semi_goal[2];
    short int start_state[2];
    
    input >> semi_goal[0]; input >> semi_goal[0]; input >> semi_goal[0]; //going to the first line of start_state
    input >> start_state[0]; input >> start_state[1];                    //start state coordinate
    input >> semi_goal[0]; input >> semi_goal[1];                        //semi goal coordinate
    
    input >> semi_goal[0];
    
}

/*void successor(node ** &matrix, short int size, short int StartCoordinate[2], short int SemiGoal[2]) {
    for (short int i = 0; i < size; i++)
        for (short int j = 0; j < size; j++) {
            if ((j+1 > 0) && (j+1 < size) && (i+1 > 0) && (i+1 < size)) {
                if ()
            }
        }
}*/

//int size = 0;
int main() {
    ifstream input("input.txt");
    
    //we should delete these temp vars
    short int colors;
    
    node ** array;
    
    input >> temp[0]; //row size
    short int size = temp[0];
    array = new node*[temp[0]];

//    int size1 = 0;
    
    input >> temp[0]; //column size
    for (int i = 0; i < temp[0]; i++) {
        array[i] = new node [temp[0]];
    }
    for (auto i = 0; i < size; i++)
        for (auto j =0; j < size; j++) {
            array[i][j].color = '0';
    
        }

    input >> colors;
    colors = -colors;
    while (!input.eof()) {
        try {
            input >> temp[0]; input >> temp[1]; //i,j
            array[temp[0]-1][temp[1]-1].color = (char) (colors + 77);
            cout << temp[0] << " ," << temp[1] << " has the color " << array[temp[0]-1][temp[1]-1].color << endl;
            
            input >> temp[0]; input >> temp[1];
            array[temp[0]-1][temp[1]-1].color = (char) (colors + 77);
            cout << temp[0] << " ," << temp[1] << " has the color " << array[temp[0]-1][temp[1]-1].color << endl;
            
            colors++;
            
            cout<<endl;
        } catch (exception e) {
            cout<< e.what();
        }
        
    }
    input.close();
    bool * neighbour;
    temp[0] = 2; temp[1] = 1;
    get_neighbour(neighbour, array, temp, 4);
    for (int i = 0; i < 4; i++) {
//        cout << endl;
//        cout << neighbour[i] << endl;
        if (neighbour[i] == true)
        {
            switch (i) {
                case 0:
                    cout << "up is free\n";
                    break;

                case 1:
                    cout << "down is free\n";
                    break;

                case 2:
                    cout << "left is free\n";
                    break;

                case 3:
                    cout << "right is free\n";
                    break;

                default:
                    break;
            }
        }
    }
    for (auto i = 0; i < size; i++) {
        for (auto j =0; j < size; j++) {
            cout << array[i][j].color << " ";
        }
        cout << endl;
    }
    /*for (auto i = 0; i < size; i++)
        for (auto j =0; j < size; j++) {
            size1 += sizeof(array[i][j]);
            if (array[i][j].color != '0')
                cout << array[i][j].color << " ," << " in " << "[" << i << "," << j << "]" <<endl;

        }*/
    cout<<endl<<sizeof(node);

    return 0;
}
