/**********************************************************************
*  readme.txt template
*  Kronos PS7a startup
**********************************************************************/

Name: Jingxian Shi


Hours to complete assignment (optional): 4


/**********************************************************************
*  Did you complete the whole assignment?
*  Successfully or not?
*  Indicate which parts you think are working, and describe
*    how you know that they're working.
**********************************************************************/
Worked


/**********************************************************************
*  Copy here all regex's you created for parsing the file,
*  and explain individually what each ones does.
**********************************************************************/
"(\\d{4}\\-(\\d{2})\\-(\\d{2}) "
"(\\d{2}):(\\d{2}):(\\d{2})): "
"\\(log.c.166\\) server started\\s*";
matches 4 digits followed by a dash and 2 digits with a dash and 2 digits with a dash which forms the date. and then it finds 3 groups of 2 digits followed by a ":", then it finds "(log.c.166) server started"

"(\\d{4}\\-(\\d{2})\\-(\\d{2}) "
"(\\d{2}):(\\d{2}):(\\d{2}))\\.(\\d{3})"
".*oejs\\.AbstractConnector:Started\\s+"
"SelectChannelConnector@0.0.0.0:9080\\s*";
matches the date and time and "oejs.AbstractConnector:Started SelectChannelConnector"


/**********************************************************************
*  Describe your overall approach for solving the problem.
*  100-200 words.
**********************************************************************/
use regular expression to find the lines where the device started and completed and output to a file


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

