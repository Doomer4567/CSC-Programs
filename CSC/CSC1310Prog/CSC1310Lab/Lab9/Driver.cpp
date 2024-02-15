/*
    Date: 11/12/2023
    Author: Ethan Byker
    Purpose:Adjancency list practice and showcase
*/

#include "GraphList.h"
#include <iostream>
#include <fstream>

int main(){
    int Vertices, Vertice2;
    std::fstream fs;
    fs.open("graph.txt");
    if(!(fs.is_open())){
        std::cout << "Error Processing Text File: Please Contact The Author" << std::endl;
        return 0;
    }
    
    fs >> Vertices;
    std::cout << "There are " << Vertices << " vertices in the graph. " << std::endl;
    GraphList GL(Vertices);
    while(!fs.eof()){
        fs >> Vertices;
        fs >> Vertice2;
        std::cout << "Adding an edge from " << Vertices << " to " << Vertice2 << "." << std::endl;
        GL.addEdge(Vertices,Vertice2);
    }

    GL.printGraph();

    fs.close();
    return 0;
}