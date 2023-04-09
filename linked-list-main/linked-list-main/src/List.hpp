#ifndef LIST_H_
#define LIST_H_

#include <iostream>

#include <sstream>

#include <string>
//98% 2% ->
namespace ECE275Lib { 
    namespace containers {
         template < typename Y >
            class Node {
            public:
                Y data; 
                Node < Y > * next = nullptr;
                Node < Y > * get_next() {
                    return next = nullptr;
                }
            };
        template < typename T >
        class List {
        public:
        
            T at(unsigned int g) {
                //int index = 0;
                Node<T> * temp = head;
                for (unsigned int i =0; i < g; i++){
                    temp = temp->get_next();
                }
                return temp->data;
            }
            List() {
                head = nullptr;
            }
            List (unsigned int j){
                head = new Node<T> ();
                Node<T> * temp = head;
                for (unsigned int i = 1; i < j ; i++){
                    temp->next = new Node<T> ();
                    temp = temp->get_next();
                }
            }
            Node<T>* returnode (unsigned int i) {
                Node<T> *temp = head;
                for (unsigned int g = 0; g < i; g++) {
                    temp = temp->get_next();
                }
                return temp;
            }
            void insert(unsigned int i, T d) {
              //  Node<T>* current = returnode(i);
                Node<T>* before = returnode(i-1);
                Node<T>* new_Node = new Node<T> ();
                new_Node->data = d;
                new_Node->next = before->next;
                before->next = new_Node;
            }
            void push_back(T dat) {
                Node < T > * temp = head;
                Node < T >* neww = new Node < T > ();
                neww->data = dat;
                if (head == nullptr) {
                    head = neww;
                }
                else {
                    while (temp->get_next() != nullptr)
                        temp = temp->get_next();
                    temp -> next = neww;
                }

            }
            Node<T>* back (){
               Node<T> * temp = head;
                while (temp->get_next() != NULL)
                    temp = temp->get_next();
                return temp;
            }

            Node<T>* front (){
            return nullptr;
            }
            void assign(unsigned int h,T d) {
                Node<T>* temp = head;
                for (unsigned int i = 0; i < h; i++){
                    temp = temp->get_next();
                }
                temp->data = d;
            }
            void insert(unsigned int i, List<T>& other){
                Node<T>* ref = returnode(i-1);
                Node<T> * last = returnode(i);
                Node<T> * add = other.head;
                ref->next = add;
                while(add->get_next() != nullptr)
                    add = add->get_next();
                add->next = last;
            }

            void remove(unsigned int s) {
                Node<T> * temp1 = returnode(s-1);
                Node<T> * temp2 = returnode(s);
                temp1->next = temp2->get_next();
               // temp2->next = nullptr;
                free(temp2);
            }
            void remove(unsigned int s, unsigned int e){
                Node<T> * before = returnode(s-1);
                Node<T> * last = returnode(e-1);
                before->next = last->next;
            }

            unsigned int size() {
                unsigned int length = 0;
                Node<T>* current = head;
            while (current != NULL) 
            { 
            length++; 
            current = current->next; 
            } 
                return length;
            }

        private:
            Node<T> * head;
        };
    }
}

#endif
