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

using std::cout; using std::endl; using std::ifstream;
using std::exception; using std::queue; using std::stack;

short int temp[2];
short int ** start_states;
short int ** semi_goals;
short int neighbours[4][2];
short int size = 0;
short int colors;


struct node {
    char color;
};

queue<node> bfsQueue;
stack<node> dfsStack;

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
void BfsSuccessor(node ** &matrix, short int size, short int * StartCoordinate, short int SemiGoal[2]) {
    get_neighbour(matrix, StartCoordinate, size - 1);
    if (temp[0] == 1) {
        if (matrix[StartCoordinate[0]][StartCoordinate[1]].neighbours[0]) {
            matrix[StartCoordinate[0] - 1][StartCoordinate[1]].color = matrix[StartCoordinate[0]][StartCoordinate[1]].color;
        }
        else if (matrix[StartCoordinate[0]][StartCoordinate[1]].neighbours[1]) {
            matrix[StartCoordinate[0] + 1][StartCoordinate[1]].color = matrix[StartCoordinate[0]][StartCoordinate[1]].color;
        }
        else if (matrix[StartCoordinate[0]][StartCoordinate[1]].neighbours[2]) {
            matrix[StartCoordinate[0]][StartCoordinate[1] - 1].color = matrix[StartCoordinate[0]][StartCoordinate[1]].color;
        }
        else if (matrix[StartCoordinate[0]][StartCoordinate[1]].neighbours[3]) {
            matrix[StartCoordinate[0]][StartCoordinate[1] + 1].color = matrix[StartCoordinate[0]][StartCoordinate[1]].color;
        }
    }
    
    else if(temp[0] == 2) {
        if (matrix[StartCoordinate[0]][StartCoordinate[1]].neighbours[0]) {
            bfsQueue.push(matrix[StartCoordinate[0] - 1][StartCoordinate[1]]);
        }
        else if (matrix[StartCoordinate[0]][StartCoordinate[1]].neighbours[1]) {
            bfsQueue.push(matrix[StartCoordinate[0] + 1][StartCoordinate[1]]);
        }
        else if (matrix[StartCoordinate[0]][StartCoordinate[1]].neighbours[2]) {
            bfsQueue.push(matrix[StartCoordinate[0]][StartCoordinate[1] - 1]);
        }
        else if (matrix[StartCoordinate[0]][StartCoordinate[1]].neighbours[3]) {
            bfsQueue.push(matrix[StartCoordinate[0]][StartCoordinate[1] + 1]);
        }
    }
    
    else if(temp[0] == 3) {
        if (matrix[StartCoordinate[0]][StartCoordinate[1]].neighbours[0]) {
            bfsQueue.push(matrix[StartCoordinate[0] - 1][StartCoordinate[1]]);
        }
        else if (matrix[StartCoordinate[0]][StartCoordinate[1]].neighbours[1]) {
            matrix[StartCoordinate[0] + 1][StartCoordinate[1]].color = matrix[StartCoordinate[0]][StartCoordinate[1]].color;
            bfsQueue.push(matrix[StartCoordinate[0] + 1][StartCoordinate[1]]);
        }
        else if (matrix[StartCoordinate[0]][StartCoordinate[1]].neighbours[2]) {
            bfsQueue.push(matrix[StartCoordinate[0]][StartCoordinate[1] - 1]);
        }
        else if (matrix[StartCoordinate[0]][StartCoordinate[1]].neighbours[3]) {
            bfsQueue.push(matrix[StartCoordinate[0]][StartCoordinate[1] + 1]);
        }
    }
    
    else if(temp[0] == 4) {
        bfsQueue.push(matrix[StartCoordinate[0] - 1][StartCoordinate[1]]);
        bfsQueue.push(matrix[StartCoordinate[0] + 1][StartCoordinate[1]]);
        bfsQueue.push(matrix[StartCoordinate[0]][StartCoordinate[1] - 1]);
        bfsQueue.push(matrix[StartCoordinate[0]][StartCoordinate[1] + 1]);

    }
    
    
}

//************************************************************************************ DFS SUCCESSOR **************************************************************************************
void DfsSuccessor(node ** &matrix, short int size, short int * StartCoordinate, short int SemiGoal[2]) {
    get_neighbour(matrix, StartCoordinate, size - 1);
    temp[0] = 0;
    for (int i = 0; i < 4; i++) {
        if (neighbours[i][0] != -1)
            temp[0]++;
    }
    if (temp[0] == 1) {
        if (neighbours[0][0] != -1) {
            matrix[neighbours[0][0]][neighbours[0][1]].color = matrix[StartCoordinate[0]][StartCoordinate[1]].color;
        }
        else if (neighbours[1][0] != -1) {
            matrix[neighbours[1][0]][neighbours[1][1]].color = matrix[StartCoordinate[0]][StartCoordinate[1]].color;
        }
        else if (neighbours[2][0] != -1) {
            matrix[neighbours[2][0]][neighbours[2][1]].color = matrix[StartCoordinate[0]][StartCoordinate[1]].color;
        }
        else if (neighbours[3][0] != -1) {
            matrix[neighbours[3][0]][neighbours[3][1]].color = matrix[StartCoordinate[0]][StartCoordinate[1]].color;
        }
    }

    else if(temp[0] == 2) {
        if (neighbours[0][0] != -1) {
            dfsStack.push(matrix[neighbours[0][0]][neighbours[0][1]]);
        }
        else if (neighbours[1][0] != -1) {
            dfsStack.push(matrix[matrix[neighbours[0][0]][neighbours[0][1]]);
        }
        else if (neighbours[2][0] != -1) {
            dfsStack.push(matrix[neighbours[0][0]][neighbours[0][1]]);
        }
        else if (neighbours[3][0] != -1) {
            dfsStack.push(matrix[neighbours[0][0]][neighbours[0][1]]);
        }
    }

    else if(temp[0] == 3) {
        if (neighbours[0][0] != -1) {
            dfsStack.push(matrix[neighbours[0][0]][neighbours[0][1]]);
        }
        else if (neighbours[1][0] != -1) {
            matrix[StartCoordinate[0] + 1][StartCoordinate[1]].color = matrix[StartCoordinate[0]][StartCoordinate[1]].color;
            dfsStack.push(matrix[neighbours[0][0]][neighbours[0][1]]);
        }
        else if (neighbours[2][0] != -1) {
            dfsStack.push(matrix[neighbours[0][0]][neighbours[0][1]]);
        }
        else if (neighbours[3][0] != -1) {
            dfsStack.push(matrix[neighbours[0][0]][neighbours[0][1]]);
        }
    }

    else if(temp[0] == 4) {
        dfsStack.push(matrix[StartCoordinate[0] - 1][StartCoordinate[1]]);
        dfsStack.push(matrix[StartCoordinate[0] + 1][StartCoordinate[1]]);
        dfsStack.push(matrix[StartCoordinate[0]][StartCoordinate[1] - 1]);
        dfsStack.push(matrix[StartCoordinate[0]][StartCoordinate[1] + 1]);

    }
    
    
}


//************************************************************************************ MAIN *******************************************************************************************
int main() {
    ifstream input("input.txt");
    
    //we should delete these temp vars
    
    node ** array;
    
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
    start_states = new short int *[colors];
    semi_goals = new short int *[colors];
    for (int i = 0; i < colors; i++) {
        start_states[i] = new short int[2];
        semi_goals[i] = new short int[2];
    }
    colors = 0;
    while (!input.eof()) {
        try {
            input >> temp[0]; input >> temp[1]; //i,j
            start_states[colors][0] = temp[0]; start_states[colors][1] = temp[1];
            array[temp[0]-1][temp[1]-1].color = (char) (colors + 65);
            cout << temp[0] << " ," << temp[1] << " has the color " << array[temp[0]-1][temp[1]-1].color << endl;
            
            input >> temp[0]; input >> temp[1];
            semi_goals[colors][0] = temp[0]; semi_goals[colors][1] = temp[1];
            array[temp[0]-1][temp[1]-1].color = (char) (colors + 65);
            cout << temp[0] << " ," << temp[1] << " has the color " << array[temp[0]-1][temp[1]-1].color << endl;
            
            colors++;
            
            cout<<endl;
        } catch (exception e) {
            cout<< e.what();
        }
        
    }
    input.close();
    temp[0] = 2; temp[1] = 2;
    get_neighbour(array, temp, size - 1); //this will get the neighbours of an specific index
    for (int i = 0; i < 4; i++) {
        if (array[4][1].neighbours[i] == true)
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
    int size1=0;
    for (auto i = 0; i < size; i++) {
        for (auto j =0; j < size; j++) {
            size1 += sizeof(array[i][j]);
//            cout << array[i][j].color << " ";
        }
        
    }
    cout << "The Size" <<size1;
    return 0;
}

//************************************************************************************ IS GOALs *******************************************************************************************
bool isSemiGoal (node ** matrix, short int start[2], short int target[2]) {
    char check = matrix[start[0]][start[1]].color;
    short int counter;
    while (start != target) {
        counter = get_neighbour(matrix[start[0]][start[1]].neighbours, matrix, start, size - 1);
        if (counter == 0)
            return false;
        
        if (counter == 1) {
            if (matrix[start[0]][start[1]].neighbours[0]) {
                if (matrix[start[0] - 1][start[1]].color != check)
                    return false;
            }
            else if (matrix[start[0]][start[1]].neighbours[1]) {
                if (matrix[start[0] + 1][start[1]].color != check)
                    return false;
            }
            else if (matrix[start[0]][start[1]].neighbours[2]) {
                if (matrix[start[0]][start[1] - 1].color != check)
                    return false;
                
            }
            else if (matrix[start[0]][start[1]].neighbours[3]) {
                if (matrix[start[0]][start[1] + 1].color != check)
                    return false;
                
            }
        }
    }
    return true;
}

//bool isGoal(node ** matrix) {
//    for (auto i = 0; i < size; i++)
//        for (auto j =0; j < size; j++)
//            if (matrix[i][j].color == '0')
//                return false;
//    for (auto i =0; i< colors; i++)
//    {
//        if (!isSemiGoal(matrix, start_states[i], semi_goals[i]))
//    }
//}


/*void BFS(int s)
{
    queue<node**> bfsQueue;
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
    
    // Create a queue for BFS
    // Mark the current node as visited and enqueue it
    visited[s] = true;
    bfsQueue.push_back(s);
    
    // 'i' will be used to get all adjacent
    // vertices of a vertex
    list<int>::iterator i;
    
    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        cout << s << " ";
        queue.pop_front();
        
        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}*/

