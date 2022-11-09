#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "pqr.h"

Pqr *newPqr(float p, float q, float r)
{
    Pqr *pqr = malloc(sizeof(Pqr));
    pqr->p = p;
    pqr->q = q;
    pqr->r = r;
    return pqr;
}

Pqr *newPqrPoints(const Vector2 *point1, const Vector2 *point2)
{
    float deltaY = point2->y - point1->y;
    float deltaX = point2->x - point1->x;
    float rc = deltaY / deltaX;
    Pqr *pqr = malloc(sizeof(Pqr));

    if (isnan(rc))
    {
        rc = 0;
    }

    if (isfinite(rc))
    {
        float r = point1->y - rc * point1->x;
        pqr->p = -rc;
        pqr->q = 1;
        pqr->r = r;
        return pqr;
    }

    pqr->p = 1;
    pqr->q = 0;
    pqr->r = point1->x;

    return pqr;
}

Pqr *newPqrPR(float p, float r)
{
    if (isinf(p))
    {
        return newPqr(1, 0, r);
    }
    return newPqr(-p, 1, r);
}

Pqr *newPqrSlope(float slope, const Vector2 *ref)
{
    float b = ref->y - ref->x * slope;
    if (isinf(slope))
    {
        return newPqr(1, 0, ref->x);
    }
    return newPqr(-slope, 1, b);
}

Pqr *pqrCopy(const Pqr *copy)
{
    return newPqr(copy->p, copy->q, copy->r);
}

float pqrGetX(const Pqr *form, float y)
{
    if (form->p != 0)
    {
        return (form->r - form->q * y) / form->p;
    }

    return INFINITY;
}

float pqrGetY(const Pqr *form, float x)
{
    if (form->q != 0)
    {
        return (form->r - form->p * x) / form->q;
    }

    return INFINITY;
}

Vector2 *pqrRoot(const Pqr *form)
{
    if (isinf(pqrGetX(form, 0)))
    {
        if (form->r == 0)
        {
            return newVec2(INFINITY, 0);
        }
        return NULL;
    }

    return newVec2(pqrGetX(form, 0), 0);
}

Vector2 *pqrYIcept(const Pqr *form)
{
    if (isinf(pqrGetY(form, 0)))
    {
        if (form->r == 0)
        {
            return newVec2(0, INFINITY);
        }
        return NULL;
    }

    return newVec2(0, pqrGetY(form, 0));
}

Pqr *pqrPerpendicular(const Pqr *form)
{
    return newPqr(form->q, -form->p, form->r);
}

float pqrSlope(const Pqr *form)
{
    if (form->q == 0)
    {
        return INFINITY;
    }

    return (-form->p / form->q);
}

float pqrAngle(const Pqr *form)
{
    return pqrAngleFromSlope(pqrSlope(form));
}

float pqrSlopeFromAngle(float angle)
{
    if (fabs(fabs(angle) - M_PI_2) < 0.00001f)
    {
        return INFINITY;
    }
    return tanf(angle);
}

float pqrAngleFromSlope(float slope)
{
    return atan2f(slope, 1);
}

Vector2 *pqrIntersect(const Pqr *form1, const Pqr *form2, double tolerance)
{
    // test to see if the lines even intersect at all
    float slopeDiff = fabs(pqrSlope(form1) - pqrSlope(form2));
    // obviously when both are infinity, subtraction should lead to 0, no matter what
    if (isinf(pqrSlope(form1)) + isinf(pqrSlope(form2)) == 2)
    {
        slopeDiff = 0;
    }
    if (slopeDiff <= tolerance)
    {
        if (fabs(form1->r / form1->p - form2->r / form2->p) <= tolerance)
        {
            return newVec2(INFINITY, INFINITY);
        }

        return NULL;
    }

    // get p, q and ar values
    // also get the a, b and c values
    // this way it is easier to work with

    float p = form1->p;
    float q = form1->q;
    float r = form1->r;

    float a = form2->p;
    float b = form2->q;
    float c = form2->r;

    // declare the x and y
    float x, y;

    // px + qy = r
    // ax + 0y = c
    // ----------- sub
    if (a != 0 && q != 0 && b == 0)
    {
        x = c / a;
        y = r / q - (p * c) / (q * a);
        return newVec2(x, y);
    }

    // px + qy = r
    // 0x + by = c
    // ----------- sub
    if (b != 0 && p != 0 && a == 0)
    {
        y = c / b;
        x = r / p - (q * c) / (p * b);
        return newVec2(x, y);
    }

    // 0x + qy = r
    // ax + by = c
    // ----------- sub
    // or:
    // px + 0y = r
    // ax + by = c
    // ----------- sub
    // in this case switching would be better, since it would automatically
    // go to one of the cases above
    if ((q != 0 && a != 0 && p == 0) || (p != 0 && b != 0 && q == 0))
    {
        return pqrIntersect(form2, form1, tolerance);
    }

    // in the scenario that p, q, a and b all are not equal to 0

    float xFactor = q / b;
    x = (r - xFactor * c) / (p - xFactor * a);

    float yFactor = p / a;
    y = (r - yFactor * c) / (q - yFactor * b);

    return newVec2(x, y);
}

void printPqr(const Pqr *form)
{
    printf("%0.2fx + %0.2fy = %0.2f\n", form->p, form->q, form->r);
}