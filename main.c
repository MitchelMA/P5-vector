#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "mvector/vector2.h"
#include "lin/pqr.h"

#define RAD2DEG 57.29577951308232286
#define DEG2RAD 0.01745329251994329547

int main(void)
{
    printf("RAD2DEG: %f\n", RAD2DEG);
    printf("DEG2RAD: %f\n", DEG2RAD);
    // use for temporary vectors
    Vector2 *tmp;

    // positions of objects A and B
    Vector2 *a, *b;

    // Calculate from object A towards B
    Vector2 *d;

    // vector f
    Vector2 *f;

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
    printf("\n3. Bereken de genormeerde eenheidsvector van d^\n");
    tmp = vec2Normalized(d);
    printf("\tgenormeerde vector hiervan: ");
    printVec2(tmp);
    free(tmp);
    // --------------

    // -------------------------

    // 2.2 De enemy ------------
    Vector2 *dir_vec;
    float vel;

    printf("\n\n2.2: De enemy\n");

    // opdracht 1 ---
    printf("\n1. Wat is de waarde van ve>?\n");
    dir_vec = vec2Normalized(d);
    vel = 1;
    vec2MultNum(dir_vec, vel);
    printf("\tve>: ");
    printVec2(dir_vec);
    // --------------   

    // opdracht 2 ---
    printf("\n2. Wat is de waarde van ||ve>||?\n");
    printf("\t||ve>||: %f\n", vec2Magnitude(dir_vec));
    // --------------

    // opdracht 3 ---
    printf("\n3. Hoe lang duurt de beweging van enemy van A naar B?\n");
    float len = vec2Magnitude(d);
    printf("\tervanuitgaande dat de snelheid 1ms en de afstand: %f, duurt het %fm/s\n", len, len);
    // --------------

    // opdracht 4 ---
    printf("\n4. Verander de waarde van ve = 2. Wat is nu de waarde van ||ve>||?\n");
    vec2Normalize(dir_vec);
    vel = 2;
    vec2MultNum(dir_vec, vel);
    printf("\t%f\n", vec2Magnitude(dir_vec));
    // --------------

    // opdracht 5 ---
    printf("\n5. Hoe lang duur nu de beweging van enemy van A naar B?\n");
    printf("\tDe lengte gedeelt door de velocity (in m/s): %fm/s\n", vec2Magnitude(d)/vel);
    
    // --------------


    free(dir_vec);
    // -------------------------

    // 3 Het afleggen an de weg van A naar B


    // 3.1: Punt op weg --------
    printf("\n\n3.1 Punt op de weg\n");
    // reusing vector a and b

    // linear formula l(x)
    Pqr *l;

    // opdracht 1 ---
    printf("\n1. Beschouw het speelveld als een plat vlak, waarbij de enemy door de punten A(-6, 3) en B(5, 1)\ngaat. Wat is de lineaire vergelijking van l(x) die door de punten A en B gaat?\n");

    l = newPqrPoints(a, b);
    printf("\tl(x): ");
    printPqr(l);
    // --------------

    // opdracht 2 ---
    printf("\n2. onderzoek of de enemy daadwerkelijk langs dit punt [-0.5, 2] komt\n");
    f = newVec2(-0.5, 2);
    float y = pqrGetY(l, f->x); 
    char *kwamlangs = fabs(f->y - y) < 0.00001 ? "true" : "false";
    printf("\tkwam daadwerkelijk langs dit punt: %s\n ", kwamlangs);
    // --------------

    // opdracht 3 ---
    printf("\nHoe snel na het verlaten van A is enemy bij punt F bij een snelheid van ve = 2?\n");
    tmp = newVec2(f->x, f->y);
    vec2SubVector(tmp, a);
    len = vec2Magnitude(tmp);
    free(tmp);
    printf("\tde afstand van A naar f is %f, met een snelheid van 2 duurt dat %fm/s\n", len, len/2);
    // --------------

    free(l);
    // -------------------------

    // 4 De toren

    // 4.1 Het plaatsen van de toren ---
    Vector2 *t;
    Vector2 *tf; // van f naar t
    Vector2 *ft; // van t naar f

    printf("\n\n4.1 Het plaatsen van de toren\n");

    // opdracht 1 ---
    printf("\n1. Wat is de waarde van de differencevector naar T van F: tf>?\n");
    t = newVec2(-3, -3);
    tf = newVec2(t->x, t->y);
    vec2SubVector(tf, f);
    printf("\ttf>: ");
    printVec2(tf);
    // --------------

    // opdracht 2 ---
    printf("\n2. Wat is de afstand naar T van F?\n");
    printf("\t||tf||: %f\n", vec2Magnitude(tf));
    // --------------

    // opdracht 3 ---
    printf("\n3. Om toren T te laten richten op punt F moeten wij weten welke hoek deze maakt t.o.v. de wereld.\n"
    "Daarvoor gebruiken wij de tegenovergestelde differencevector naar F van T ft = -tf wat is de\n"
    "hoek van ft t.o.v. de wereld (0*)?\n");
    ft = newVec2(tf->x, tf->y);
    vec2MultNum(ft, -1);
    tmp = newVec2Angle(0);
    printf("\tdat is %f graden\n", vec2Angle(ft, tmp) * RAD2DEG);
    free(tmp);
    // --------------

    free(t);
    free(tf);
    free(ft);
    // ---------------------------------


    return EXIT_SUCCESS;
}