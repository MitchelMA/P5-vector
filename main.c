#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "mvector/vector2.h"
#include "lin/pqr.h"

int main(void)
{
    // positions of objects A and B
    Vector2 *a, *b;

    // Calculate from object A towards B
    Vector2 *d;

    // linear formula l(x)
    Pqr *l;

    a = newVec2(-6, 3);
    b = newVec2(5, 1);

    printf("Vector a voor GameObject A: ");
    printVec2(a);
    printf("Vector b voor GameObject B: ");
    printVec2(b);

    // calculating the vector with a as tail and b as head
    d = newVec2(b->x, b->y);
    vec2SubVector(d, a);
    printf("\nVector d wijzend van A naar B: ");
    printVec2(d);

    // calculate linear formula through A and B
    l = newPqrPoints(a, b);
    printf("lineaire formule door A en B: ");
    printPqr(l);


    free(a);
    free(b);
    free(d);
    free(l);
    return EXIT_SUCCESS;
}