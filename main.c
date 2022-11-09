#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "mvector/vector2.h"

int main(void)
{
    // positions of objects A and B
    Vector2 *a, *b;

    a = newVec2(-6, 3);
    b = newVec2(5, 1);

    printf("Vector a voor GameObject A: ");
    printVec2(a);
    printf("\nVector b voor GameObject B: ");
    printVec2(b);



    free(a);
    free(b);
    return EXIT_SUCCESS;
}