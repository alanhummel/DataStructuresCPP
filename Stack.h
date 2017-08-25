/*
*************************************
*  Stack                            *
*   v.1.3                           *
*  Alan Hummel - alanh@terra.com.br *
*************************************
*/

#ifndef STACK_H
#define STACK_H

template <class dataType> class Stack  {
protected:
    // Container class for the stack data structure.
//    template <class dadoTipo>
    class stackItem  {
    public:
        dataType data;   // data stored on stack
        stackItem* next; // the next node on stack
    };

    // defines a shortcut to stack item
    typedef stackItem item;

// ========================================
// Data Member of queue data structure:
// ========================================
protected:

    item* top; // pointer to stack top.

// ========================================
// Public Interface of Stack class:
// ========================================
public:

// ----------------------------------------------------------------
//  Name:           Stack::Stack
//  Description:    Constructor, creates an empty stack.
//  Arguments:      None.
//  Return Value:   None.
// ----------------------------------------------------------------
    Stack() {
	top = 0;
    }

// ----------------------------------------------------------------
//  Name:           Stack::~Stack
//  Description:    Destrutor, deletes each item of the stack.
//  Arguments:      None.
//  Return Value:   None.
// ----------------------------------------------------------------
    ~Stack()  {
        clean();
    }

// ----------------------------------------------------------------
//  Name:           Stack::isEmpty
//  Description:    determines if the stack is empty or not.
//  Arguments:      None
//  Return Value:   True if the stack is empty, False, otherwise.
// ----------------------------------------------------------------
    bool isEmpty()  {
        if( top == 0 )
            return true;
        return false;
    }

// ----------------------------------------------------------------
//  Name:           Stack::put
//  Description:    stacks another item on the top.
//  Arguments:      data: data to be stacked.
//  Return Value:   None.
// ----------------------------------------------------------------
    void put( dataType& data )  {
        item* temp = new item;
        temp->data = data;
        temp->next = top;
        top = temp;
    }

// ----------------------------------------------------------------
//  Name:           Stack::remove
//  Description:    Removes a data item from the stack top or
//                  do nothing case the stack is empty. 
//  Arguments:      None.
//  Return Value:   None.
// ----------------------------------------------------------------
    void remove()  {
        item* temp = top;
        if( temp != 0 ) {
            top = temp->next;
            delete temp;
        }
    }

// ----------------------------------------------------------------
//  Name:           Stack::clean
//  Description:    Empties the stack completely.
//  Arguments:      None.
//  Return Value:   None.
// ----------------------------------------------------------------
    void clean()  {
        item* temp = top;
        while( temp != 0 )  {
            top = temp->next;
            delete temp;
            temp = top;
        }
        top = 0;
    }

// ----------------------------------------------------------------
//  Name:           Stack::accessTop
//  Description:    Reads the item on the stack top.
//  Arguments:      None.
//  Return Value:   data item on the top.
// ----------------------------------------------------------------
    dataType& accessTop()   {
        return top->data;
    }

};

#endif

