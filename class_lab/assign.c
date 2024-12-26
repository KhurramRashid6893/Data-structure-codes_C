#include <stdio.h>

int main(){

    int a, b, c  = 1, d = 2,e = 50 ,f = 23, g = 20;

    b = 54;
    a = b;

    c+= a;
    d-= a;

    e*= a;
    f/= a;

    g %= a;

    printf("b = %d\n", b);

    printf("\na = %d", a);

    printf("\nc += a is %d", c);
    printf("\nd -=a  is %d", d);

    printf("\ne *= a is %d", e);
    printf("\nf /= a is %d", f);
    printf("\ng %%= a %d", g);
}
