#ifndef STACK_H
#define STACK_H
#include <string>

class Stack {

    private:

        struct Node{
            char data;
            Node* next;
        };
        Node* top;

    public:

        Stack();
        virtual void push(char data);
        virtual void pop();
        virtual bool isEmpty();
        virtual bool isBalanced();

};

#endif