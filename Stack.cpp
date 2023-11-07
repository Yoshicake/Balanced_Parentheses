#include "Stack.h"
#include "Exceptions.h"
#include <string>
#include <iostream>

using namespace std;

// Creates a Stack class.
//
Stack::Stack(){

    top = nullptr;

}

// Puts a character at the top of the stack.
//
void Stack::push(char data){

    Node *newNode = new Node;

    newNode->data = data;

    if (top == nullptr) {

        top = newNode;

        newNode->next = nullptr;

    } else {

        newNode->next = top;

        top = newNode;

    }

}

// Removes from the top of the stack. Throws an EmptyStackException if the stack is empty.
//
void Stack::pop(){


    Node *nodeToPop;

    
    if (top == nullptr) {

        throw EmptyStackException();

    } else {

        nodeToPop = top;

        top = top->next;

        delete nodeToPop;

    }

}

// Checks if the stack is empty.
//
bool Stack::isEmpty(){

    if (top == nullptr) {
        return true;
    }
    
    return false;

}

// Scans through the stack and checks if brackets are balanced.
// Creates a stack that only holds brackets. Brackets are added if
// the stack is empty or if the current bracket found does not 
// pair with the top of the temp stack. Removes if a balanced pair
// is found. At the end of searching, if the temp stack is empty,
// returns true. Otherwise, returns false.
//
bool Stack::isBalanced(){
    Stack temp;
    Node* current = top;
    while (current != nullptr) {
        if (((current->data) == '(') || ((current->data) == ')') || 
            ((current->data) == '[') || ((current->data) == ']') || 
            ((current->data) == '{') || ((current->data) == '}')) {

            if (temp.isEmpty()) {

                temp.push(current->data); 

            } else if ((((temp.top)->data) == '(' && ((current->data) == ')')) ||
                       (((temp.top)->data) == '{' && ((current->data) == '}')) ||
                       (((temp.top)->data) == '[' && ((current->data) == ']'))) {

                        temp.pop();

            } else {

                temp.push(current->data);

            }

            current = current->next;

        // If a character is not a bracket, it is ignored.
        //
        } else {

            current = current->next;   

        }
    }

    if (temp.isEmpty()) {
        return true;
    }

    return false;

}