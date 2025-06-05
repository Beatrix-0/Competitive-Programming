// Recursive : 
int power ( int x , int y ){
    if( y == 0 ) return 1 ;
    if( y % 2 == 0 ){
        return power((x*x) , y/2);
    }
    else {
        return (x * power((x * x), (y - 1) / 2));
    }
}

// Iterative : 
int power(int x, int y) {
    int result = 1;
    while (y > 0) {
        if (y % 2) {
            result *= x;
        }
        x *= x;
        y /= 2;
    }
    return result;
}