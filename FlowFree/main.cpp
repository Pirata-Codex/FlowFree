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

node ** answer;

bool isGoal(node **);
bool isSemiGoal(node **, short int * ,short int);
void BfsSuccessor(node **&, queue<node>&, short int , short int * , short int);
void print(node **);
vector<node> sendNeighbour(node **, short int *, short int);
bool BFS(node **, short int *, short int *, short int);
bool DFS(node **, short int *, short int *, short int);


// ********************************************************************** This will get all the neighbours ********************************************************************************
void get_neighbour (node ** matrix, short int coordinate[2], short int size, short int color)
{
    //up, down, left, right
    for (auto i = 0; i < colors; i++) {
        for (auto j = 0; j < 2; j++) {
            neighbours[i][j] = -1;
        }
    }
    
//    up side neighbour
    if ((coordinate[0] - 1 < size) && (coordinate[0] - 1 >= 0)) {
        if ((matrix[coordinate[0] - 1][coordinate[1]].color == '0') || (matrix[coordinate[0] - 1][coordinate[1]].color == matrix[targetCoordinates[color][0]][targetCoordinates[color][1]].color)) {
            neighbours[0][0] = coordinate[0] - 1;
            neighbours[0][1] = coordinate[1];
        }
    }
//    down side neighbour
    if ((coordinate[0] + 1 < size) && (coordinate[0] + 1 >= 0)) {
        if ((matrix[coordinate[0] + 1][coordinate[1]].color == '0') || (matrix[coordinate[0] + 1][coordinate[1]].color == matrix[targetCoordinates[color][0]][targetCoordinates[color][1]].color)) {
            neighbours[1][0] = coordinate[0] + 1;
            neighbours[1][1] = coordinate[1];
        }
    }
    
//    left side neighbour
    if ((coordinate[1] - 1 < size) && (coordinate[1] - 1 >= 0)) {
        if ((matrix[coordinate[0]][coordinate[1] - 1].color == '0') || (matrix[coordinate[0]][coordinate[1] - 1].color == matrix[targetCoordinates[color][0]][targetCoordinates[color][1]].color)) {
            neighbours[2][0] = coordinate[0];
            neighbours[2][1] = coordinate[1] - 1;
        }
    }
    
//    right side neighbour
    if ((coordinate[1] + 1 < size) && (coordinate[1] + 1 >= 0)) {
        if ((matrix[coordinate[0]][coordinate[1] + 1].color == '0') || (matrix[coordinate[0]][coordinate[1] + 1].color == matrix[targetCoordinates[color][0]][targetCoordinates[color][1]].color)) {
            neighbours[3][0] = coordinate[0];
            neighbours[3][1] = coordinate[1] + 1;
        }
    }
}

//************************************************************************************ BFS SUCCESSOR ***************************************************************************************
void BfsSuccessor(node ** &matrix, queue<node> &bfsQueue ,short int size, short int color, short int * StartCoordinate, short int SemiGoal[2]) {
    get_neighbour(matrix, StartCoordinate, size - 1, color);
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
void DfsSuccessor(node ** &matrix, stack<node> &dfsStack, short int size, short int color, short int * StartCoordinate, short int SemiGoal[2]) {
    get_neighbour(matrix, StartCoordinate, size - 1, color);
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
                startCoordinates[colorss][0] = temp[0]; startCoordinates[colorss][1] = temp[1];
                array[temp[0]-1][temp[1]-1].color = (char) (colorss + 65);
                cout << temp[0] << " ," << temp[1] << " has the color " << array[temp[0]-1][temp[1]-1].color << endl;
                
                input >> temp[0]; input >> temp[1];
                targetCoordinates[colorss][0] = temp[0]; targetCoordinates[colorss][1] = temp[1];
                array[temp[0]-1][temp[1]-1].color = (char) (colorss + 65);
                cout << temp[0] << " ," << temp[1] << " has the color " << array[temp[0]-1][temp[1]-1].color << endl;
                
                colorss++;
                
                cout<<endl;

            } catch (exception e) {
                cout<< e.what();
            }
            
        }
        input.close();
        BFS(array, startCoordinates[0], targetCoordinates[0], 0);

    } if (!input) {
        cout << "no input were found";
        return 0;
    }
//    temp[0] = 2; temp[1] = 2;
//    //get_neighbour(array, temp, size - 1); //this will get the neighbours of an specific index
//    for (int i = 0; i < 4; i++) {
//        if (neighbours[i][0] != -1)
//        {
//            switch (i) {
//                case 0:
//                    cout << "up is free\n";
//                    break;
//
//                case 1:
//                    cout << "down is free\n";
//                    break;
//
//                case 2:
//                    cout << "left is free\n";
//                    break;
//
//                case 3:
//                    cout << "right is free\n";
//                    break;
//
//                default:
//                    break;
//            }
//        }
//    }
    return 0;
}
//************************************************************************************ ALGORITHMS *******************************************************************************************

vector<node**> matrixes;

bool BFS(node ** matrix, short int * Start, short int * Target, short int whichColor)
{
    // Check whether it's goal or not
    if (isGoal(matrix))
    {
        print(matrix);
        *(answer) = *(matrix);
        return true;
    }
    
    // new queue for each state
    queue<node> bfsQueue;
    node temp;
    // Successor will be called
    BfsSuccessor(matrix, bfsQueue, size, whichColor, Start, Target);
    
    // Queue is empty and the road is blocked.
    if (bfsQueue.empty()) {
//        if the queue is empty and it's blocked by something else
        if (!isSemiGoal(matrix, startCoordinates[whichColor], whichColor))
            return false;
        
        else {
//            else next color to connect
            whichColor++;
            BFS(matrix, startCoordinates[whichColor], targetCoordinates[whichColor], whichColor);
        }
    }
    
    while(!bfsQueue.empty())
    {
        temp = bfsQueue.front();
        node ** newMatrix = matrix;
        newMatrix[temp.i][temp.j].color = temp.color;
        Start[0] = temp.i; Start[1] = temp.j;
        bfsQueue.pop();

        print(matrix);
        BFS(newMatrix, Start, Target, whichColor);
    }
    return false;
}

bool DFS(node ** matrix, short int * Start, short int * Target, short int whichColor)
{
    // Check whether it's goal or not
    if (isGoal(matrix))
    {
        print(matrix);
        *(answer) = *(matrix);
        return true;
    }
    
    // new queue for each state
    stack<node> dfsStack;
    node temp;
    // Successor will be called
    DfsSuccessor(matrix, dfsStack, size, whichColor, Start, Target);
    
    // Queue is empty and the road is blocked.
    if (dfsStack.empty()) {
        //        if the queue is empty and it's blocked by something else
        if (!isSemiGoal(matrix, startCoordinates[whichColor], whichColor))
            return false;
        
        else {
            //            else next color to connect
            whichColor++;
            DFS(matrix, startCoordinates[whichColor], targetCoordinates[whichColor], whichColor);
        }
    }
    
    while(!dfsStack.empty())
    {
        temp = dfsStack.top();
        node ** newMatrix = matrix;
        newMatrix[temp.i][temp.j].color = temp.color;
        Start[0] = temp.i; Start[1] = temp.j;
        dfsStack.pop();
        
        print(matrix);
        DFS(newMatrix, Start, Target, whichColor);
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
    for (auto i = 0; i < colors; i++) {
        if (!isSemiGoal(matrix, startCoordinates[colors] ,colors)) {
            return false;
        }
    }
    return true;
}

bool isSemiGoal(node ** matrix, short int * start ,short int color) {
    if ((start[0] == targetCoordinates[color][0]) && (start[1] == targetCoordinates[color][1]))
        return true;
    vector<node> path;
    path = sendNeighbour(matrix, start, color);
    for (auto i = 0; i < path.size(); i++) {
        if (path[i].color == matrix[start[0]][start[1]].color)
        {
            short int next[2];
            isSemiGoal(matrix, next, color);
            break;
        }
        
    }
    
    path.clear();
    return false;
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
//************************************************************************************ FIND PATH *******************************************************************************************
vector<node> sendNeighbour (node ** matrix, short int * coordinate, short int color) {
    get_neighbour(matrix, coordinate, size - 1, color);
    vector<node> shit;
    for (int i = 0; i < colors; i++)
        if (neighbours[i][0] != -1)
            shit.insert(shit.begin(), matrix[neighbours[i][0]][neighbours[i][1]]);
    return shit;
}




