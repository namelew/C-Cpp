/**
 * Implemantain of cartsian.h
 * autor: @namelew
 *      created_at: 22/03/2021
 *      last_modified: 22/03/2021
 */

#include <math.h>
#include "cartesian.h"

double euclidians_distance(Point a, Point b){
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}