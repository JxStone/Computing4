/**********************************************************************
*  readme template
*  DNA Sequence Alignment
**********************************************************************/

Name: Jingxian Shi
Login: Mac OS


Hours to complete assignment (optional): 2



/**********************************************************************
*  Explain what you did to find the alignment itself.
**********************************************************************/
Used the Needleman-Wunsch algorithm(NxM matrix). The matrix is filled with min of 3(bottom to top, right to left, and diagonal) formula to have the distance in the top left. The formula is used while traversing the matrix to get the upper left cell [0][0] which gives the optimal distance of the two given strings.


/**********************************************************************
* Does your code work correctly with the endgaps7.txt test file?
*
* This example should require you to insert a gap at the beginning
* of the Y string and the end of the X string.
**********************************************************************/
Input:
atattat
tattata

Expected output:
Edit distance = 4
a - 2
t t 0
a a 0
t t 0
t t 0
a a 0
t t 0
- a 2

What happened:
worked correctly



/**********************************************************************
*  How much main memory does your computer have? Typical answers
*  are 2 GB to 16 GB.
**********************************************************************/
8GB


/**********************************************************************
*  Were you able to run Valgrind's massif tool to verify that your
*  implementation uses the expected amount of memory?
*
*  Answer yes, no, I didn't try, I tried and failed, or I used a
*  different tool.
*
*  If yes, paste in the ms_print top chart of memory use over time,
*  and also indicate which file your code was solving.
*
*  Explain if necessary.
/**********************************************************************
I didn't try. Couldn't install valgrind on mac OS high sierra. I just used Xcode to check memory leaks


/**********************************************************************
*  For each data file, fill in the edit distance computed by your
*  program and the amount of time it takes to compute it.
*
*  If you get segmentation fault when allocating memory for the last
*  two test cases (N=20000 and N=28284), note this, and skip filling
*  out the last rows of the table.
**********************************************************************/

data file           distance       time (seconds)     memory (MB)
------------------------------------------------------------------
ecoli2500.txt       118             0.253268
ecoli5000.txt       160             1.03645
ecoli7000.txt       194             1.999
ecoli10000.txt      223             3.99
ecoli20000.txt      3135            17.44
ecoli28284.txt

/*************************************************************************
*  Here are sample outputs from a run on a different machine for
*  comparison.
************************************************************************/

data file           distance       time (seconds)
-------------------------------------------------
ecoli2500.txt          118             0.171
ecoli5000.txt          160             0.529
ecoli7000.txt          194             0.990
ecoli10000.txt         223             1.972
ecoli20000.txt         3135            7.730




/**********************************************************************
*  List whatever help (if any) you received from the course TAs,
*  instructor, classmates, or anyone else.
**********************************************************************/
N/A


/**********************************************************************
*  Describe any serious problems you encountered.
**********************************************************************/
N/A


/**********************************************************************
*  List any other comments here.
**********************************************************************/

