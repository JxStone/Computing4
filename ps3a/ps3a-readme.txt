/**********************************************************************
*  N-Body Simulation ps3a-readme.txt template
**********************************************************************/

Name: Jingxian Shi
OS: Mac
Text editor:
Hours to complete assignment: 3

/**********************************************************************
*  Briefly discuss the assignment itself and what you accomplished.
**********************************************************************/
I make the universe radius scale to the window size, and draw the planets in the window at its coordinate. The extraction operator is overloaded to extract input informations from a file.

/**********************************************************************
*  Discuss one or more key algorithms, data structures, or
*  OO designs that were central to the assignment.
**********************************************************************/
I used vector of pointers to Body object to store the coordinates of a planet. When drawing the planets, each element in the vector is being called through a for loop.


/**********************************************************************
*  Briefly explain the workings of the features you implemented.
*  Include code excerpts.
**********************************************************************/
Since the universe radius is not written to fit the window, I had to get the diameter first and then get the ratio between the window size and the universe diameter. And then Since the origin of the universe is in the middle of the window which is different from the SFML window, I transformed universe coordinate extracted from the file to SFML coordinate and scaled them to fit in the SFML window.



/**********************************************************************
*  List whatever help (if any) you received from the instructor,
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
