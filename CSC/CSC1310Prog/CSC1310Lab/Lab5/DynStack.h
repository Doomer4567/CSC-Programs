#ifndef DynStack_H
#define DynStack_H
#include <iostream>
#include "InvItem.h"
using namespace std;

template <class T>
class InvItmStack{
    private:
        struct Node{
            T Data;
            Node* Next;
        };
        Node* Top;
        
        
    public:
        InvItmStack(){ 
            Top = NULL; 
        }
           
        ~InvItmStack(){
            Node* DelNode;
            while(Top != NULL){
                DelNode = Top;
                Top = Top->Next;
                delete DelNode;
            }
        }
        void push(InvItem NewData){
            Node* NewNode = NULL;
            NewNode = new Node;
            NewNode->Data = NewData;

            if(isEmpty()){
                Top = NewNode;
                NewNode->Next = NULL;
            } else {
                NewNode->Next = Top;
                Top = NewNode;
            }
            
        }

        void pop(T& DelData){
            Node* DelNode = NULL;
            
            DelData = Top->Data;
            DelNode = Top->Next;
            delete Top;
            Top = DelNode;
        }

        bool isEmpty(){
            bool stance;

            if(Top == NULL)
                stance = true;
            else
                stance = false;

            return stance;
        }
};



#endif