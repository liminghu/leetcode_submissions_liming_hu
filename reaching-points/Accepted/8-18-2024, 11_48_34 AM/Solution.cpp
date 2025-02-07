// https://leetcode.com/problems/reaching-points

/*Given four integers sx, sy, tx, and ty, return true if it is possible to convert the point 
(sx, sy) to the point (tx, ty) through some operations, or false otherwise.

The allowed operation on some point (x, y) is to convert it to either (x, x + y) or (x + y, y).
*/
class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) { //1 <= sx, sy, tx, ty <= 109
        bool res = false;

        /*we work backwards to find the answer, trying to transform the target point to the starting point via applying the parent 
        operation (x, y) -> (x-y, y) or (x, y-x) [depending on which one doesn't have negative coordinates.]
        We can speed up this transformation by bundling together parent operations.*/
        
        while(tx>=sx && ty >= sy) {
            if(tx == ty)
                break; //nothing can be done.
            if(tx > ty) {
                if(ty > sy ) tx = tx % ty;
                else return (tx-sx) % ty == 0;
            } else { //tx < ty
                if(tx > sx ) ty = ty % tx;
                else return (ty-sy) % tx == 0;                
            }
        }

        return (tx == sx && ty == sy);        
    }
};