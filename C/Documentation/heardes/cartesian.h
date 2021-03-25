/**
* This library has made to work with points in a bidimensional cartesian plane.
* 
* Funções:
*    eclidians_distace(Point a, Point b)
* autor: @namelew
*   created_at: 22/03/2021
*   last_modified: 22/03/2021
*/


/**
 * Basic structere of a point in a bidimensional cartesian plane. When, x is the 
 * coordinate on the axis x and y is the coordinate on the axis y
 * 
 */

typedef struct{
    int x;
    int y;
}Point;

/**
 * This method calculates the eclidians distance between to points A and B
 * input: two ints points
 * 
 * output: double eclidians distance
 */
double euclidians_distance(Point a, Point b);