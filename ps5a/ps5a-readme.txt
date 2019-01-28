/**********************************************************************
*  readme.txt template
*  Guitar Hero: RingBuffer implementation with unit tests and exceptions
**********************************************************************/

Name: Jingxian Shi



Hours to complete assignment: 2

/**********************************************************************
*  Briefly discuss the assignment itself and what you accomplished.
**********************************************************************/
Implemented a ringbuffer that can be given a max capacity

/**********************************************************************
*  Discuss one or more key algorithms, data structures, or
*  OO designs that were central to the assignment.
**********************************************************************/
The size of the buffer is fixed and it acts as a circular array



/**********************************************************************
*  Briefly explain the workings of the features you implemented.
*  Include code excerpts.
**********************************************************************/
Used vector to build the buffer
enqueue() function adds an item at the end. if the buffer is full enqueue() will throw an exception
dequeue() removes the item at the front and returns that item. it pushes the front to the next position and throws exception if the buffer is empty where nothing can be removed
peek() returns the front item without removing it. throw exception if the buffer is empty


/**********************************************************************
*  Did you complete the whole assignment?
*  Successfully or not?
*  Indicate which parts you think are working, and describe
*    how you know that they're working.
**********************************************************************/
All working. All functions and all exceptions passed unit tests



/**********************************************************************
*  Does your RingBuffer implementation pass the unit tests?
*  Indicate yes or no, and explain how you know that it does or does not.
**********************************************************************/
Yes. No errors were detected



/**********************************************************************
*  List whatever help (if any) you received from lab TAs,
*  classmates, or anyone else.
**********************************************************************/
N/A


/**********************************************************************
*  Describe any serious problems you encountered.
**********************************************************************/
N/A


/**********************************************************************
*  List any other comments here.
**********************************************************************/
N/A
