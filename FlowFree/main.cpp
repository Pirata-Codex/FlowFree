//
//  main.cpp
//  FlowFree
//
//  Created by Pirate on 11/3/17.
//  Copyright © 2017 Pirate. All rights reserved.
//

struct node {
    
    char color;
    node * parent;
    node * next;

};

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


int size = 0;
int main() {
    ifstream input("input.txt");
    
    short int temp, temp2; //we should delete these temp vars
    short int colors;
    
    node ** array;
    
    input >> temp;
    short int size = temp;
    array = new node*[temp];

    int size1 = 0;
    
    input >> temp;
    for (int i = 0; i < temp; i++) {
        array[i] = new node [temp];
    }
    for (auto i = 0; i < size; i++)
        for (auto j =0; j < size; j++) {
            array[i][j].color = '0';
    
        }

    input >> colors;
    colors = -colors;
    while (colors != 0) {
        try {
            input >> temp; input >> temp2;
            array[temp-1][temp2-1].color = (char) (colors + 77);
            cout << temp << " ," << temp2 << " has the color " << array[temp-1][temp2-1].color << endl;
            
            input >> temp; input >> temp2;
            array[temp-1][temp2-1].color = (char) (colors + 77);
            cout << temp << " ," << temp2 << " has the color " << array[temp-1][temp2-1].color << endl;
            
            colors++;
            
            cout<<endl;
        } catch (exception e) {
            cout<< e.what();
        }
        
    }
    
    for (auto i = 0; i < size; i++)
        for (auto j =0; j < size; j++) {
            size1 += sizeof(array[i][j]);
            if (array[i][j].color != '0')
                cout << array[i][j].color << " ," << " in " << "[" << i << "," << j << "]" <<endl;

        }
    cout<<endl<<sizeof(array[0][4].parent);
//    cout<<endl<<sizeof();

    return 0;
}
