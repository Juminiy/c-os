#include <math.h>
#include <stdlib.h>
struct point {
    int x,y;
    point(int _x,int _y) {
        x = _x , y = _y ;
    }
    bool nlnr(point p) {
        if (x == p.x) {
            return y < p.y ;
        }
        return x < p.x ;
    } 
    bool nlmr(point p) {
        if (x == p.x) {
            return y > p.y ;
        }
        return x < p.x ;
    }
    bool mlnr(point p) {
        if (x == p.x) {
            return y < p.y ;
        }
        return x > p.x ;
    }
    bool mlmr(point p) {
        if (x == p.x) {
            return y > p.y ;
        }
        return x > p.x ;
    }
} ;

double caltriggle(point a,point b ,point c) {
    
}
double largestTriangleArea(int** points, int pointsSize, int* pointsColSize){
    point *pts = (point*) malloc(sizeof(point)*pointsSize) ; 
    for(int i=0;i<pointsSize;i++) {
        pts[i] = point(points[i][0],points[i][1]);
    }
    // ..sort 
    point nlnr = pts[0] ;
    // ..sort
    point nlmr = pts[0] ;
    // ..sort
    point mlnr = pts[0] ;
    // ..sort
    point mlmr = pts[0] ; 

}