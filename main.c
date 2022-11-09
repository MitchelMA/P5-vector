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

    // use for temporary vectors
    Vector2 *tmp;

    // linear formula l(x)
    Pqr *l;

    // 2 De Basis

    // 2.1 De Basisobjecten ----
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
    printf("\n3. Bereken de genormeerde eenheidsvector van d\n");
    tmp = vec2Normalized(d);
    printf("\tgenormeerde vector hiervan: ");
    printVec2(tmp);
    free(tmp);
    // --------------

    // -------------------------

    // 2.2 De enemy ------------

    // -------------------------


    // calculate linear formula through A and B
    l = newPqrPoints(a, b);
    printf("\nlineaire formule door A en B: ");
    printPqr(l);


    free(a);
    free(b);
    free(d);
    free(l);
    return EXIT_SUCCESS;
}