/*
*************************************
*  Queue                            *
*   v.1.1                           *
*************************************
*/

#ifndef QUEUE_H
#define QUEUE_H

template <class dataType> class Queue  {
protected:
    // Container class for the queue data structuture.
//    template <class dadoTipo>
    class queueItem  {
    public:
        dataType data;    // data stored on queue
        queueItem* next;  // next item on queue
    };

	// defines a shortcut to access a node from the same type as
    // a standard on queue.
    typedef queueItem item;

// ========================================
// Data member from queue
// ========================================
protected:

    item* first;    // pointer to the queue first.
    item* last;     // last queue item.

// ========================================
// Queue Public interface:
// ========================================
public:

// ----------------------------------------------------------------
//  Name:           Queue::Queue
//  Description:    Constructor, creates an empty queue.
//  Arguments:      None.
//  Return Value:   None.
// ----------------------------------------------------------------
    Queue()  {
	first = 0;
	last = 0;
    }

// ----------------------------------------------------------------
//  Name:           Queue::~Queue
//  Description:    Destructor, deletes each item from queue.
//  Arguments:      None
//  Return Value:   None.
// ----------------------------------------------------------------
    ~Queue()  {
        clean();
    }

// ----------------------------------------------------------------
//  Name:           Queue::isEmpty
//  Description:    determines if the queue is empty or not.
//  Arguments:      None
//  Return Value:   True if queue is empty, Falso, otherwise.
// ----------------------------------------------------------------
    bool isEmpty()  {
        if( first == 0 )
            return true;
        return false;
    }

// ----------------------------------------------------------------
//  Name:           Fila::put
//  Description:    puts another item at the end of queue.
//  Arguments:      data: data to be inserted on queue.
//  Return Value:   None.
// ----------------------------------------------------------------
    void put( dataType& data )  {
		item* temp = new item;
		temp->data = data;
		if( isEmpty() )  {
	        	first = temp;
			last = temp;
		}
		else {
			last->next = temp;
			temp->next = 0;
			last = temp;
		}
    }

// ----------------------------------------------------------------
//  Name:           Queue::remove
//  Description:    Removes the first item or do nothing in case 
//                  the top is invalid. 
//  Arguments:      None.
//  Return Value:   None.
// ----------------------------------------------------------------
    void remove()  {
	item* temp = new item;
        if( first != 0 )   {
		temp = first;
		first = first->next;
        }
	delete temp;
    }

// ----------------------------------------------------------------
//  Name:           Queue::clean
//  Description:    Empties the queue completely.
//  Arguments:      None.
//  Return Value:   None.
// ----------------------------------------------------------------
    void clean()  {
        item* temp = first;
        while( temp != 0 ) {
            first = temp->next;
            delete temp;
            temp = first;
        }
        first = 0;
    }

// ----------------------------------------------------------------
//  Name:           Queue::accessFirst
//  Description:    Gets an item on the top of the queue. 
//  Arguments:      None.
//  Return Value:   the first item on the queue.
// ----------------------------------------------------------------
    dataType& accessFirst()   {
        return first->data;
    }

};

#endif

