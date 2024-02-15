#ifndef GraphList_H
#define GraphList_H

#include <iostream>

class GraphList{
    private:
    struct ListNode
    {
        int value;
        ListNode* Next;
    };
    
    ListNode** HeadArray;
    int numVertices;
    int numEdges;

    public:
    GraphList(int numV){
        numVertices = numV;
        HeadArray = new ListNode*[numVertices];
        for(int i = 0; i < numVertices; i++){
            HeadArray[i] = new ListNode;
            HeadArray[i]->value = i;
            HeadArray[i]->Next = NULL;
        }
        numEdges = 0;    
    }

    ~GraphList(){
        for(int i = numVertices-1;i > 0;i--){
            ListNode* prev = NULL;
            ListNode* TS = HeadArray[i];
            while(TS->Next != NULL){
                TS = TS->Next;
                if(TS->Next == NULL){
                    TS = NULL;
                    TS = HeadArray[i]; 
                }
            }
        }
        delete [] HeadArray;
    }
    void addEdge(int Vert1, int Vert2){
        ListNode* newNode = new ListNode;
        newNode->value = Vert2;
        newNode->Next = NULL;
        ListNode* TS = HeadArray[Vert1];
        while(TS->Next != NULL)
            TS = TS->Next;
        TS->Next = newNode;
        TS = TS->Next;
        TS->Next = NULL;
        numEdges++;
    }
    void printGraph(){
        std::cout << std::endl;
        std::cout << "Adjacency List..." << std::endl;
        ListNode* TS = new ListNode;
        for(int i = 0; i < numVertices; i++){
            TS = HeadArray[i];
            while(TS){
                std::cout << TS->value << "--->";
                TS = TS->Next;
            }
            std::cout << "NULL" << std::endl;
        }
    }

};


#endif