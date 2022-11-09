#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "mvector/vector2.h"
#include "lin/pqr.h"

int main(void)
{
    // use for temporary vectors
    Vector2 *tmp;

    // 2 De Basis

    // 2.1 De Basisobjecten ----

    // positions of objects A and B
    Vector2 *a, *b;

    // Calculate from object A towards B
    Vector2 *d;

    printf("2.1: De Basis\n");
    a = newVec2(-6, 3);
    b = newVec2(5, 1);

    printf("Vector a voor GameObject A: ");
    printVec2(a);
    printf("Vector b voor GameObject B: ");
    printVec2(b);

    // opdracht 1 ---
    d = newVec2(b->x, b->y);
    vec2SubVector(d, a);
    printf("\n1. Bereken de verschilvector d = b - a\n");
    printf("\tVector d wijzend van A naar B: ");
    printVec2(d);
    // --------------

    // opdracht 2 ---
    printf("\n2. Bereken de lengte van de verschilvector ||d||\n");
    printf("\tLengte van deze vector: %f\n", vec2Magnitude(d));
    // -------------- 
    
    // opdracht 3 ---
    printf("\n3. Bereken de genormeerde eenheidsvector van d^\n");
    tmp = vec2Normalized(d);
    printf("\tgenormeerde vector hiervan: ");
    printVec2(tmp);
    free(tmp);
    // --------------

    // -------------------------

    free(a);
    free(b);
    free(d);
    // 2.2 De enemy ------------
    printf("\n\nOpdrachten van 2.2 zijn incompleet:\n");
    printf("In de uitleg wordt nooit de waarde van de velocity\nvector gegeven, waardoor we er geen richting mee kunnen bereken.\n");

    // -------------------------



    return EXIT_SUCCESS;
}