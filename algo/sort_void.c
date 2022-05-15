// generic 

// int array cmp function example 

void _swp_int(void *a, void *b) {
    void *tmp = a ;
    *a = b ; 
    *b = tmp ; 
}

int _cmp_int(int a , int b ) { 
    return a < b ;
}


// quick sort realize 
// the algo is assigned in luogu 

void _q_sort(void *arr , int l ,int r ,int cmp ) { 
    if (l >= r) return ; 
    void *pivot = arr[ (r-l) / 2 + l ] ; 
    int j = r , i = l ; 
    while (i <= j) { 
        while(cmp(pivot,arr[j])) { j -- ; } 
        while(cmp(arr[i],pivot)) { i ++ ; } 
        if (i <= j) {
            _swp_int(arr+i,arr+j) ; 
            i ++ , j -- ; 
        }
    } 
    if (i <= r) { _q_sort(arr,i,r,cmp) ; }
    if (l <= j) { _q_sort(arr,l,j,cmp) ; }
}
void _qsort(void *arr, int n,int cmp) { 
    _q_sort( arr , 0 , n-1 , cmp ) ; 
} 


