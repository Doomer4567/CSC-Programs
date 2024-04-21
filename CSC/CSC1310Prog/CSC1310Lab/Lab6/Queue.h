#ifndef Queue_H
#define Queue_H
#include <iostream>

class Queued{
    private:
        struct ListNode{
            std::string Rider;
            struct ListNode *next;
        };

        ListNode *head;
        ListNode *tail;


    public:
        Queued(){
            head = NULL;
            tail = NULL;
        }
        ~Queued(){
            ListNode* delNode = head;
            while(head != NULL){
                std::cout << "Oh shoot, I am sorry, our park is closed so "  << head->Rider << " will not get to ride today." << std::endl;
                head = head->next;
                delete delNode;
                delNode = head;
            }
        }

        void enqueue(std::string Name){
            ListNode* newNode = new ListNode;
            newNode->Rider = Name;
            if(!head){
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }

            tail->next = NULL;
        }

        void dequeue(){
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }

        bool isEmpty(){
            if(!head)
                return true;
             else 
                return false;
        }

        std::string getRider(){
            return head->Rider;
        }


};




#endif