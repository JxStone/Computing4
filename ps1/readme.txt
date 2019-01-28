**********************************************************************
* ps1-readme
* Sierpinski Triangle Assignment
* Author: Jingxian Shi
* Date: 02/01/2018
**********************************************************************/

* Sierpinski Triangle
In the Sierpinski class stores three vertex coordinates using sf::Vector2f. The constructor that takestwo parameters is being called in main and initiate the first level sierpinski triange.
The draw function is derived from sf::Drawable. The other constructor that takes 4 parameters is being called in the draw function. I implemented in a way such that it will call sierpinski object recursively inside the draw function with decreasing the recursion depth. Each new sierpinski object created will store its vertex coordinates and thus able to draw the upside-down triangle in the middle.


