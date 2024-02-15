#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <string.h>
using namespace std;


class List{
    public:
    struct ListNode
    {
        string data;
        ListNode* Next;
    };
    ListNode* Head;
    ListNode* Tail;
    List(){
        Head = NULL;
        Tail = NULL;
    }

    ~List(){
        ListNode *curNode;  
	    ListNode *sucNode;  

	
	    curNode = Head;

	
        while (curNode != NULL)
        {
        
            sucNode = curNode->Next;
            
            
            delete curNode;

        
        curNode = sucNode;
        }
    } 

    void appendNode(string Input){
        ListNode *temp = new ListNode;
        temp->data = Input;
        temp->Next = nullptr; 

        if(Head == NULL){
            Head = temp;
            Tail = temp;
        } else {
            Tail->Next = temp;
            Tail = temp;
        }
    }

    //Need to account for alphabet
    void insertNode(string Input){
        ListNode* NewNode = new ListNode;
        ListNode* curNode;
        NewNode->data=Input;
        NewNode->Next=NULL;
        
            if (Head == NULL) { // List empty
                Head = NewNode;
                Tail = NewNode;
            }
            else { // Insert after tail
                curNode = Head;
                if (Input[0] == curNode->data[0]){
                    NewNode->Next = Head; 
                    Head = NewNode;
                }
                int num;
                while (curNode != Tail && curNode->data[num] != Input[0])
                {
                    num++;
                    if(Input == curNode->data)
                        break;
                    curNode = curNode->Next;
                }
                if(curNode->Next == NULL)
                    Tail = NewNode;

                NewNode->Next = curNode->Next;
                curNode->Next = NewNode;                
            }
    }

    void deleteNode(string Input){
        
        ListNode* curNode = NULL;
        ListNode* sucNode = NULL;
        if(!Head)
            return;

        if (Head->data == Input){
            curNode = Head->Next;
            delete Head;
            Head = curNode;
        } else {
            curNode = Head;

            while(curNode != NULL && curNode->data != Input){
                sucNode = curNode;
                curNode = curNode->Next;
            }
        }
        if(curNode)
        {
            if(curNode == Tail)
                Tail = sucNode;
            sucNode->Next = curNode->Next;
            delete curNode;
        }
    }
    
    void displayList(){
        ListNode* curNode;
        curNode = Head;
        if(Head != NULL){
            while(curNode != NULL){
                cout << curNode->data << endl;

                curNode = curNode->Next;
            }
        }
    }
};
#endif