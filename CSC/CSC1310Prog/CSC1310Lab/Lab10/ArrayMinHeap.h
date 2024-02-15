#ifndef ARRAYMINHEAP_H
#define ARRAYMINHEAP_H
#include "Creature.h"

#include <iostream>
#include <string>
#include <cmath>



class ArrayMinHeap {
    private:
        
        Creature* HeapArray;
        int capacity;
        int heap_size;
        
        void swap(int I1, int I2){
            Creature Temp = HeapArray[I1];
            HeapArray[I1] = HeapArray[I2];
            HeapArray[I2] = Temp;
        }
        int parent(int index){ return (index-1) / 2; }
        int left(int index){ return (2*index) + 1; }
        int right(int index){ return (2*index) + 2; }
    public:
        ArrayMinHeap(int size){
            HeapArray = new Creature[size];
            heap_size = size;
            capacity = 0;
        }

        ~ArrayMinHeap(){ delete [] HeapArray; }

        void minHeapify(int index){
            int L = left(index);
            int R = right(index);

            int small = index;

            if(capacity > L && HeapArray[L].getName() > HeapArray[small].getName()){
                small = L; //sets small to the left child index
            }
            if (capacity > R && HeapArray[R].getName() > HeapArray[small].getName()){
                small = R; //sets small to the right child index
            }

            if(small == index){
                swap(index, small);
                minHeapify(index);
            }
        }

        Creature peek(){return HeapArray[0];} 

        bool remove(){ 
            if(isEmpty())
                return false;
            HeapArray[0] = HeapArray[heap_size - 1];
            minHeapify(0);
            capacity--;
            return true;
        }
        void insert(Creature newCreature){
            if(heap_size == capacity){
                resizeArray();
            }
            HeapArray[capacity] = newCreature;
            capacity++;
        }

        void resizeArray(){
            heap_size *= 2;
            Creature* newHeap = new Creature[heap_size];
            for(int i = 0; i < capacity; i++)
                newHeap[i] = HeapArray[i];

            delete [] HeapArray;
            HeapArray = newHeap;
            
        }

        bool isEmpty(){ 
            if(capacity == 0) 
                return true; 
            else 
             return false;
            }

        int getNumberOfNodes(){return heap_size;}

        int getHeight(){ return ceil(log2(heap_size + 1));}

        void Display(){ 
            if(isEmpty())
                cout << "isEmpty" << endl;
            for(int i = 0; i < capacity; i++) 
                cout << HeapArray[i].getName() << endl;
            }

        void saveToFile(){
            for(int i = 0; i < capacity; i++)
                HeapArray[i].printCreatureToFile("output.txt");
        }
        

};


#endif