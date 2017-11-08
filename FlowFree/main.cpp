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
short int neighbours[4][2];
short int size;
short int colors;

struct node {
    char color;
    short int i;
    short int j;
    
public:
    void set(int i, int j) {
        temp.i = i; temp.j = j;
    }
};

bool isGoal();
bool isSemiGoal();
void BfsSuccessor(node **&, queue<node>&, short int , short int * , short int);

// ********************************************************************** This will get all the neighbours ********************************************************************************
void get_neighbour (node ** matrix, short int coordinate[2], short int size)
{
    //up, down, left, right
    for (auto i = 0; i < 4; i++) {
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

//************************************************************************************ BFS SUCCESSOR ***************************************************************************************
void BfsSuccessor(node ** &matrix, queue<node> &bfsQueue ,short int size, short int * StartCoordinate, short int SemiGoal[2]) {
    get_neighbour(matrix, StartCoordinate, size - 1);
    temp[0] = 0;
    
//    initializing neighbours locations
    for (int i = 0; i < 4; i++) {
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
    for (int i = 0; i < 4; i++) {
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
    
    node ** array;
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
        for (int i = 0; i < colors; i++) {
            startCoordinates[i] = new short int[2];
            targetCoordinates[i] = new short int[2];
        }
        colors = 0;
        while (!input.eof()) {
            try {
                input >> temp[0]; input >> temp[1]; //i,j
                startCoordinates[colors][0] = temp[0]; startCoordinates[colors][1] = temp[1];
                array[temp[0]-1][temp[1]-1].color = (char) (colors + 65);
                cout << temp[0] << " ," << temp[1] << " has the color " << array[temp[0]-1][temp[1]-1].color << endl;
                
                input >> temp[0]; input >> temp[1];
                targetCoordinates[colors][0] = temp[0]; targetCoordinates[colors][1] = temp[1];
                array[temp[0]-1][temp[1]-1].color = (char) (colors + 65);
                cout << temp[0] << " ," << temp[1] << " has the color " << array[temp[0]-1][temp[1]-1].color << endl;
                
                colors++;
                
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

bool BFS(node ** matrix, queue<node> Queue, short int * Start, short int * Target)
{
    if (isGoal())
        return true;
    queue<node> bfsQueue;
    node temp;
    // Mark all the vertices as not visited
    BfsSuccessor(matrix, bfsQueue, size, Start, Target);
    // Create a queue for BFS
    // Mark the current node as visited and enqueue it
    
    // 'i' will be used to get all adjacent
    // vertices of a vertex
    
    while(!bfsQueue.empty())
    {
        // Dequeue a vertex from queue and print it
        temp = bfsQueue.front();
        cout << temp.color << " ";
        bfsQueue.pop();
        
        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                bfsQueue.push_back(*i);
            }
        }
    }
}

//************************************************************************************ IS GOALs *******************************************************************************************

bool isGoal(node ** matrix) {
    for (auto i = 0; i < size; i++) {
        for (auto j =0; j < size; j++) {
            if (matrix[i][j] == '0')
                return false
                }
    }
    
    for (auto i = 0; i < size; i++) {
        if (isSemiGoal(node ** input, startCoordinates, targetCoordinates))
            }
}






