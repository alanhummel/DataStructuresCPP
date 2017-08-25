/*
*************************************
*  Double Linked List               *
*   v.1.2                           *
*************************************
*/

#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H



template <class dataType> class DoubleLinkedList  {

// ========================================
// Internal classes for the list:
// ========================================
protected:

    // Container class of a simple node.
//    template <class dadoTipo>
    class nodeList  {
    public:
        dataType data;        // data stored in node
        nodeList* before;   // the before node of the list
        nodeList* next;       // the next node in the list
    };

    // defines a shortcut to access a node of the same type
    // as a standard type.
    typedef nodeList node;

// ========================================
// Data members of the list:
// ========================================
protected:

    node* head;    // points to the first node of the list.
    node* tail;    // points to the las node of the list.
    node* current; // internal iteractor the contains the current node.
      
// ========================================
// List public interface:
// ========================================
public:

// ----------------------------------------------------------------
//  Name:           DoubleLinkedList::DoubleLinkedList
//  Description:    Constructor, creates an empty linked list.
//  Arguments:      None
//  Return Value:   None.
// ----------------------------------------------------------------
    DoubleLinkedList()  {
        head = 0;
        tail = 0;
        current = 0;
    }


// ----------------------------------------------------------------
//  Name:           DoubleLinkedList::~DoubleLinkedList
//  Description:    Destructor, deletes each nodeList.
//  Arguments:      None
//  Return Value:   None.
// ----------------------------------------------------------------
    ~DoubleLinkedList()  {
        clean();
    }


// ----------------------------------------------------------------
//  Name:           DoubleLinkedList::isEmpty
//  Description:    determines wheter the list is empty or not.
//  Arguments:      None
//  Return Value:   True if it is empty, False, otherwise.
// ----------------------------------------------------------------
    bool isEmpty()  {
        if( head == 0 )
            return true;
        return false;
    }


// ----------------------------------------------------------------
//  Name:           DoubleLinkedList::isValid
//  Description:    Determines if the current iteractor is valid
//  Arguments:      None
//  Return Value:   True if it is a valid iteractor, False, otherwise
// ----------------------------------------------------------------
    bool isValid()  {
        if( current != 0 )
            return true;
        return false;
    }


// ----------------------------------------------------------------
//  Name:           DoubleLinkedList::moveToHead
//  Description:    Moves the iteractor to the beginning of the list.
//  Arguments:      None.
//  Return Value:   None.
// ----------------------------------------------------------------
    void moveToHead()  {
        current = head;
    }

    
// ----------------------------------------------------------------
//  Name:           DoubleLinkedList::moveToTail
//  Description:    Moves the iteractor to the end of the list.
//  Arguments:      None.
//  Return Value:   None.
// ----------------------------------------------------------------
    void moveToTail()  {
        current = tail;   
    }


// ----------------------------------------------------------------
//  Name:           DoubleLinkedList::moveForward
//  Description:    Moves the iteractor to the next list node, or
//                  invalids the current iteractor if current=tail.
//  Arguments:      None.
//  Return Value:   None.
// ----------------------------------------------------------------
    void moveForward()  {
        if( current != 0 )
            current = current->next;
    }

    
// ----------------------------------------------------------------
//  Name:           DoubleLinkedList::moveBackward
//  Description:    Moves the iteractor to the node before the current, or
//                invalids the iteracdor if it is already on beginning.
//  Arguments:      None.
//  Return Value:   None.
// ----------------------------------------------------------------
    void moveBackward()  {
        if( current != 0 )
            current = current->before;
    }


// ----------------------------------------------------------------
//  Name:           DoubleLinkedList::addToTail
//  Description:    adds an item at the end of list.
//  Arguments:      data: data to be added on the list
//  Return Value:   None.
// ----------------------------------------------------------------
    void addAtTail( dataType& data )  {
        node* temp = new node;
        temp->data = data;
        temp->next = 0;
        temp->before = tail;
        if( tail != 0 )
            tail->next = temp;

        tail = temp;
    
        if( head == 0 )
            head = temp;
    }

    

// ----------------------------------------------------------------
//  Name:           DoubleLinkedList::remove
//  Description:    Removes an data item from current node, or doesn't
//                  if current is invalid. Current is always invalidated
//                  after this method has been called.
//  Arguments:      None.
//  Return Value:   None.
// ----------------------------------------------------------------
    void remove()  {
        if( current != 0 )  {
            if( current == head )
                head = current->next;
            if( current == tail )
                tail = current->before;
            if( current->before != 0 )
                current->before->next = current->next;
            if( current->next != 0 )
                current->next->before = current->before;
            delete current;
            current = 0;
        }
    }


// ----------------------------------------------------------------
//  Name:           DoubleLinkedList::clean
//  Description:    Deletes each nodeList from the list.
//  Arguments:      None.
//  Return Value:   None.
// ----------------------------------------------------------------
    void clean()  {
        node* temp = head;
        while( temp != 0 )   {
            current = temp->next;
            delete temp;
            temp = current;
        }
        head = 0;
        tail = 0;
        current = 0;
    }


// ----------------------------------------------------------------
//  Name:           ListaDupLigada::getItem
//  Description:    gets the dataType from the current node. It's
//               recommended a isValid() check before its execution
//  Arguments:      None.
//  Return Value:   dataType item of the current node.
// ----------------------------------------------------------------
    dataType& getItem()   {
        return current->data;
    }


}; // End of class

#endif

