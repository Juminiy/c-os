#include <math.h>
#include <stdlib.h>

// fail error ! 
// 凹包
typedef struct point {
    int x ; 
    int y ; 
} point ;
int nlnr (const void * vpa, const void * vpb) { 
    point *pa = (point *) vpa ; 
    point *pb = (point *) vpb ; 
    if (pa->x == pb->x) { 
        return pa->y < pb->y ; 
    } 
    return pa->x < pb ->x ;
}
int nlmr (const void * vpa, const void * vpb) { 
    point *pa = (point *) vpa ;
    point *pb = (point *) vpb ; 
    if (pa->x == pb->x) {
        return pa->y > pb->y ; 
    }
    return pa->x < pb->x ;
}
int mlnr (const void * vpa, const void * vpb) { 
    point *pa = (point *) vpa ;
    point *pb = (point *) vpb ; 
    if (pa->x == pb->x) {
        return pa->y < pb->y ; 
    }
    return pa->x > pb ->x ;
}
int mlmr (const void * vpa, const void * vpb) { 
    point *pa = (point *) vpa ; 
    point *pb = (point *) vpb ; 
    if (pa->x == pb->x) { 
        return pa->y > pb->y ; 
    }
    return pa->x > pb ->x ;
}

double pp_len(point a,point b) { 
    return 1.0*sqrt( 1.0 * (a.x-b.x) * (a.x-b.x) + 1.0 * (a.y-b.y) * (a.y-b.y) ) ; 
}
double cal_triangle_s(point a,point b ,point c) { 
    double la = pp_len(a,b) , lb = pp_len(a,c) , lc = pp_len(b,c) ; 
    double p = 0.5 * (la+lb+lc) ; 
    return sqrt( p * (p-la) * (p-lb) * (p-lc) ) ;  
}

double max_v2(double v1, double v2) {
    return v1 > v2 ? v1 : v2 ;
}
double max_v4(double v1,double v2,double v3,double v4) { 
    double v12 = max_v2(v1,v2),v34 = max_v2(v3,v4) ; 
    return v12 > v34 ? v12 : v34 ; 
}
double largestTriangleArea(int** points, int pointsSize, int* pointsColSize){
    point *pts = (point*) malloc(sizeof(point)*pointsSize) ; 
    for(int i=0;i<pointsSize;i++) {
        pts[i].x = points[i][0] ;
        pts[i].y = points[i][1] ;  
    }

    qsort((void*)pts,pointsSize,sizeof(point),nlnr);
    point nlnrp = pts[0] ;
    qsort((void*)pts,pointsSize,sizeof(point),nlmr);
    point nlmrp = pts[0] ;
    qsort((void*)pts,pointsSize,sizeof(point),mlnr);
    point mlnrp = pts[0] ;
    qsort((void*)pts,pointsSize,sizeof(point),mlmr);
    point mlmrp = pts[0] ; 

    double v1 = cal_triangle_s(nlnrp,nlmrp,mlnrp) , v2 = cal_triangle_s(nlnrp,nlmrp,mlmrp) ; 
    double v3 = cal_triangle_s(nlnrp,mlnrp,mlnrp) , v4 = cal_triangle_s(nlmrp,mlnrp,mlmrp) ; 

    double res = max_v4(v1,v2,v3,v4) ; 

    return res ; 
}