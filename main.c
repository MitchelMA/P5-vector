#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "mvector/vector2.h"

int main(void)
{
    // positions of objects A and B
    Vector2 *a, *b;

    // Calculate from object A towards B
    Vector2 *d;

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



    free(a);
    free(b);
    free(d);
    return EXIT_SUCCESS;
}