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
#include <stack>
#include <vector>

using std::cout; using std::endl; using std::ifstream;
using std::exception; using std::queue; using std::stack;
using std::vector;

short int temp[2];
short int ** startCoordinates;
short int ** targetCoordinates;
short int ** neighbours;
short int size;
short int colors;

struct node {
    char color;
    short int i;
    short int j;
    
public:
    void set(int i, int j) {
        this->i = i; this->j = j;
    }
};

bool isGoal();
bool isSemiGoal(node **, short int);
void BfsSuccessor(node **&, queue<node>&, short int , short int * , short int);
void print(node **);

// ********************************************************************** This will get all the neighbours ********************************************************************************
void get_neighbour (node ** matrix, short int coordinate[2], short int size)
{
    //up, down, left, right
    for (auto i = 0; i < colors; i++) {
        for (auto j = 0; j < 2; j++) {
            neighbours[i][j] = -1;
        }
    }
//    up side neighbour
    if ((coordinate[0] - 1 < size) && (coordinate[0] - 1 >= 0)) {
        if (matrix[coordinate[0] - 1][coordinate[1]].color == '0') {
            neighbours[0][0] = coordinate[0] - 1;
            neighbours[0][1] = coordinate[1];
        }
    }
//    down side neighbour
    if ((coordinate[0] + 1 < size) && (coordinate[0] + 1 >= 0)) {
        if (matrix[coordinate[0] + 1][coordinate[1]].color == '0') {
            neighbours[1][0] = coordinate[0] + 1;
            neighbours[1][1] = coordinate[1];
        }
    }
    
//    left side neighbour
    if ((coordinate[1] - 1 < size) && (coordinate[1] - 1 >= 0)) {
        if (matrix[coordinate[0]][coordinate[1] - 1].color == '0') {
            neighbours[2][0] = coordinate[0];
            neighbours[2][1] = coordinate[1] - 1;
        }
    }
    
//    right side neighbour
    if ((coordinate[1] + 1 < size) && (coordinate[1] + 1 >= 0)) {
        if (matrix[coordinate[0]][coordinate[1] + 1].color == '0') {
            neighbours[3][0] = coordinate[0];
            neighbours[3][1] = coordinate[1] + 1;
        }
    }
}

vector<node> sendNeighbour (node ** &matrix, short int * coordinate) {
    get_neighbour(matrix, coordinate, size - 1);
    vector<node> shit;
    for (int i = 0; i < colors; i++)
        if (neighbours[i][0] != -1)
            shit.insert(shit.begin(), matrix[neighbours[i][0]][neighbours[i][1]]);
    return shit;
}

//************************************************************************************ BFS SUCCESSOR ***************************************************************************************
void BfsSuccessor(node ** &matrix, queue<node> &bfsQueue ,short int size, short int * StartCoordinate, short int SemiGoal[2]) {
    get_neighbour(matrix, StartCoordinate, size - 1);
    temp[0] = 0;
    
//    initializing neighbours locations
    for (int i = 0; i < colors; i++) {
        if (neighbours[i][0] != -1)
            temp[0]++;
    }
    if (temp[0] == 1) {
        if (neighbours[0][0] != -1) {
            matrix[neighbours[0][0]][neighbours[0][1]].set(neighbours[0][0], neighbours[0][1]);
            bfsQueue.push(matrix[neighbours[0][0]][neighbours[0][1]]);

        }
        else if (neighbours[1][0] != -1) {
            matrix[neighbours[1][0]][neighbours[1][1]].set(neighbours[1][0], neighbours[1][1]);
            bfsQueue.push(matrix[neighbours[1][0]][neighbours[1][1]]);

        }
        else if (neighbours[2][0] != -1) {
            matrix[neighbours[2][0]][neighbours[2][1]].set(neighbours[2][0], neighbours[2][1]);
            bfsQueue.push(matrix[neighbours[2][0]][neighbours[2][1]]);
        }
        else if (neighbours[3][0] != -1) {
            matrix[neighbours[3][0]][neighbours[3][1]].set(neighbours[3][0], neighbours[3][1]);
            bfsQueue.push(matrix[neighbours[3][0]][neighbours[3][1]]);
        }
    }
    
    else if(temp[0] == 2) {
        if (neighbours[0][0] != -1) {
            matrix[neighbours[0][0]][neighbours[0][1]].set(neighbours[0][0], neighbours[0][1]);
                bfsQueue.push(matrix[neighbours[0][0]][neighbours[0][1]]);
        }
        else if (neighbours[1][0] != -1) {
            matrix[neighbours[1][0]][neighbours[1][1]].set(neighbours[1][0], neighbours[1][1]);
                 bfsQueue.push(matrix[neighbours[1][0]][neighbours[1][1]]);
             }
             else if (neighbours[2][0] != -1) {
                 matrix[neighbours[2][0]][neighbours[2][1]].set(neighbours[2][0], neighbours[2][1]);
                 bfsQueue.push(matrix[neighbours[2][0]][neighbours[2][1]]);
             }
             else if (neighbours[3][0] != -1) {
                 matrix[neighbours[3][0]][neighbours[3][1]].set(neighbours[3][0], neighbours[3][1]);
                 bfsQueue.push(matrix[neighbours[3][0]][neighbours[3][1]]);
             }
             }
             
             else if(temp[0] == 3) {
             if (neighbours[0][0] != -1) {
                 matrix[neighbours[0][0]][neighbours[0][1]].set(neighbours[0][0], neighbours[0][1]);
                 bfsQueue.push(matrix[neighbours[0][0]][neighbours[0][1]]);
             }
             else if (neighbours[1][0] != -1) {
                 matrix[neighbours[1][0]][neighbours[1][1]].set(neighbours[1][0], neighbours[1][1]);
                 bfsQueue.push(matrix[neighbours[1][0]][neighbours[1][1]]);
             }
             else if (neighbours[2][0] != -1) {
                 matrix[neighbours[2][0]][neighbours[2][1]].set(neighbours[2][0], neighbours[2][1]);
                 bfsQueue.push(matrix[neighbours[2][0]][neighbours[2][1]]);
             }
             else if (neighbours[3][0] != -1) {
                 matrix[neighbours[3][0]][neighbours[3][1]].set(neighbours[3][0], neighbours[3][1]);
                 bfsQueue.push(matrix[neighbours[3][0]][neighbours[3][1]]);
             }
             }
             
             else if(temp[0] == 4) {
                 matrix[neighbours[0][0]][neighbours[0][1]].set(neighbours[0][0], neighbours[0][1]);
                 bfsQueue.push(matrix[neighbours[0][0]][neighbours[0][1]]);
                 
                 matrix[neighbours[1][0]][neighbours[1][1]].set(neighbours[1][0], neighbours[1][1]);
                 bfsQueue.push(matrix[neighbours[1][0]][neighbours[1][1]]);
                 
                 matrix[neighbours[2][0]][neighbours[2][1]].set(neighbours[2][0], neighbours[2][1]);
                 bfsQueue.push(matrix[neighbours[2][0]][neighbours[2][1]]);
                 
                 matrix[neighbours[3][0]][neighbours[3][1]].set(neighbours[3][0], neighbours[3][1]);
                 bfsQueue.push(matrix[neighbours[3][0]][neighbours[3][1]]);
             
             }
             
             
     }

//************************************************************************************ DFS SUCCESSOR **************************************************************************************
void DfsSuccessor(node ** &matrix, stack<node> &dfsStack, short int size, short int * StartCoordinate, short int SemiGoal[2]) {
    get_neighbour(matrix, StartCoordinate, size - 1);
    temp[0] = 0;
    for (int i = 0; i < colors; i++) {
        if (neighbours[i][0] != -1)
            temp[0]++;
    }
    if (temp[0] == 1) {
        if (neighbours[0][0] != -1) {
            matrix[neighbours[0][0]][neighbours[0][1]].set(neighbours[0][0], neighbours[0][1]);
            dfsStack.push(matrix[neighbours[0][0]][neighbours[0][1]]);

        }
        else if (neighbours[1][0] != -1) {
            matrix[neighbours[1][0]][neighbours[1][1]].set(neighbours[1][0], neighbours[1][1]);
            dfsStack.push(matrix[neighbours[1][0]][neighbours[1][1]]);

        }
        else if (neighbours[2][0] != -1) {
            matrix[neighbours[2][0]][neighbours[2][1]].set(neighbours[2][0], neighbours[2][1]);
            dfsStack.push(matrix[neighbours[2][0]][neighbours[2][1]]);

        }
        else if (neighbours[3][0] != -1) {
            matrix[neighbours[3][0]][neighbours[3][1]].set(neighbours[3][0], neighbours[3][1]);
            dfsStack.push(matrix[neighbours[3][0]][neighbours[3][1]]);

        }
    }

    else if(temp[0] == 2) {
        if (neighbours[0][0] != -1) {
            matrix[neighbours[0][0]][neighbours[0][1]].set(neighbours[0][0], neighbours[0][1]);
            dfsStack.push(matrix[neighbours[0][0]][neighbours[0][1]]);
        }
        else if (neighbours[1][0] != -1) {
            matrix[neighbours[1][0]][neighbours[1][1]].set(neighbours[1][0], neighbours[1][1]);
            dfsStack.push(matrix[neighbours[1][0]][neighbours[1][1]]);
        }
        else if (neighbours[2][0] != -1) {
            matrix[neighbours[2][0]][neighbours[2][1]].set(neighbours[2][0], neighbours[2][1]);
            dfsStack.push(matrix[neighbours[2][0]][neighbours[2][1]]);
        }
        else if (neighbours[3][0] != -1) {
            matrix[neighbours[3][0]][neighbours[3][1]].set(neighbours[3][0], neighbours[3][1]);
            dfsStack.push(matrix[neighbours[3][0]][neighbours[3][1]]);
        }
    }

    else if(temp[0] == 3) {
        if (neighbours[0][0] != -1) {
            matrix[neighbours[0][0]][neighbours[0][1]].set(neighbours[0][0], neighbours[0][1]);
            dfsStack.push(matrix[neighbours[0][0]][neighbours[0][1]]);
        }
        else if (neighbours[1][0] != -1) {
            matrix[neighbours[1][0]][neighbours[1][1]].set(neighbours[1][0], neighbours[1][1]);
            dfsStack.push(matrix[neighbours[1][0]][neighbours[1][1]]);
        }
        else if (neighbours[2][0] != -1) {
            matrix[neighbours[2][0]][neighbours[2][1]].set(neighbours[2][0], neighbours[2][1]);
            dfsStack.push(matrix[neighbours[2][0]][neighbours[2][1]]);
        }
        else if (neighbours[3][0] != -1) {
            matrix[neighbours[3][0]][neighbours[3][1]].set(neighbours[3][0], neighbours[3][1]);
            dfsStack.push(matrix[neighbours[3][0]][neighbours[3][1]]);
        }
    }

    else if(temp[0] == 4) {
        matrix[neighbours[0][0]][neighbours[0][1]].set(neighbours[0][0], neighbours[0][1]);
        dfsStack.push(matrix[neighbours[0][0]][neighbours[0][1]]);
        
        matrix[neighbours[1][0]][neighbours[1][1]].set(neighbours[1][0], neighbours[1][1]);
        dfsStack.push(matrix[neighbours[1][0]][neighbours[1][1]]);
        
        matrix[neighbours[2][0]][neighbours[2][1]].set(neighbours[2][0], neighbours[2][1]);
        dfsStack.push(matrix[neighbours[2][0]][neighbours[2][1]]);
        
        matrix[neighbours[3][0]][neighbours[3][1]].set(neighbours[3][0], neighbours[3][1]);
        dfsStack.push(matrix[neighbours[3][0]][neighbours[3][1]]);

    }
    
    
}


//************************************************************************************ MAIN *******************************************************************************************
int main() {
    ifstream input("input.txt");
    
    //we should delete these temp vars
    
    node ** array = nullptr;
    if (input)
    {
        
        input >> temp[0]; //row size
        short int size = temp[0];
        array = new node*[temp[0]];
        
        input >> temp[0]; //column size
        for (int i = 0; i < temp[0]; i++) {
            array[i] = new node [temp[0]];
        }
        for (auto i = 0; i < size; i++)
            for (auto j =0; j < size; j++) {
                array[i][j].color = '0';
        
            }

        input >> colors;
        startCoordinates = new short int *[colors];
        targetCoordinates = new short int *[colors];
        neighbours = new short int *[colors];
        for (int i = 0; i < colors; i++) {
            startCoordinates[i] = new short int[2];
            targetCoordinates[i] = new short int[2];
            neighbours[i] = new short int[2];
        }
        short int colorss = 0;
        while (!input.eof()) {
            try {
                input >> temp[0]; input >> temp[1]; //i,j
                startCoordinates[colors][0] = temp[0]; startCoordinates[colors][1] = temp[1];
                array[temp[0]-1][temp[1]-1].color = (char) (colorss + 65);
                cout << temp[0] << " ," << temp[1] << " has the color " << array[temp[0]-1][temp[1]-1].color << endl;
                
                input >> temp[0]; input >> temp[1];
                targetCoordinates[colors][0] = temp[0]; targetCoordinates[colors][1] = temp[1];
                array[temp[0]-1][temp[1]-1].color = (char) (colorss + 65);
                cout << temp[0] << " ," << temp[1] << " has the color " << array[temp[0]-1][temp[1]-1].color << endl;
                
                colorss++;
                
                cout<<endl;
            } catch (exception e) {
                cout<< e.what();
            }
            
        }
        input.close();
    } if (!input) {
        cout << "no input were found";
        return 0;
    }
    
    temp[0] = 2; temp[1] = 2;
    get_neighbour(array, temp, size - 1); //this will get the neighbours of an specific index
    for (int i = 0; i < 4; i++) {
        if (neighbours[i][0] != -1)
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
    
}

vector<node**> matrixes;

bool BFS(node ** matrix, short int * Start, short int * Target, short int whichColor)
{
    if (isGoal())
    {
        print(matrix);
        return true;
    }
    queue<node> bfsQueue;
    node temp;
    // Mark all the vertices as not visited
    BfsSuccessor(matrix, bfsQueue, size, Start, Target);
    // Queue is empty and the road is blocked.
    if (bfsQueue.empty()) {
        if (!isSemiGoal())
            return false;
        
        else {
            whichColor++;
            BFS(matrix, startCoordinates[whichColor], targetCoordinates[whichColor], whichColor);
        }
    }
    // 'i' will be used to get all adjacent
    // vertices of a vertex
    
    while(!bfsQueue.empty())
    {
        temp = bfsQueue.front();
        node ** newMatrix = matrix;
        newMatrix[temp.i][temp.j].color = temp.color;
        Start[0] = temp.i; Start[1] = temp.j;
        bfsQueue.pop();

        BFS(newMatrix, Start, Target, whichColor);
    }
    return false;
}

//************************************************************************************ IS GOALs *******************************************************************************************

bool isGoal(node ** matrix) {
    for (auto i = 0; i < size; i++) {
        for (auto j =0; j < size; j++) {
            if (matrix[i][j].color == '0')
                return false;
            }
    }
    node ** input;
    for (auto i = 0; i < colors; i++) {
        if (!isSemiGoal(input, colors)) {
            return false;
        }
    }
    return true;
}

bool isSemiGoal(node ** matrix, short int color) {
    bool flag = false;
    while (!flag) {
        
    }
}
//************************************************************************************ PRINT *******************************************************************************************

void print(node ** matrix) {
    for (auto i = 0; i < size; i++) {
        for (auto j =0; j < size; j++) {
            cout << matrix[i][j].color << " ";
        }
        cout << endl;
    }
}





