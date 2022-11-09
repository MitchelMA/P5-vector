#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "vector2.h"

Vector2 *newVec2(float x, float y)
{
    Vector2 *v = malloc(sizeof(Vector2));
    v->x = x;
    v->y = y;
    return v;
}

Vector2 *newVec2Angle(float angle)
{
    float x = cos(angle);
    float y = sin(angle);
    return newVec2(x, y);
}

float vec2Magnitude(const Vector2 *v)
{
    return sqrt(pow(v->x, 2) + pow(v->y, 2));
}

void vec2SetMagnitude(Vector2 *v, float magnitude)
{
    float m = vec2Magnitude(v);
    if (m == 0)
        return;

    v->x = (v->x / m) * magnitude;
    v->y = (v->y / m) * magnitude;
}

void vec2Normalize(Vector2 *v)
{
    float m = vec2Magnitude(v);
    v->x /= m;
    v->y /= m;
}

Vector2 *vec2Normalized(const Vector2 *v)
{
    Vector2 *tmp = newVec2(v->x, v->y);
    vec2Normalize(tmp);
    return tmp;
}

void vec2Limit(Vector2 *v, float max)
{
    float m = vec2Magnitude(v);
    if (m == 0 || m < max)
        return;

    vec2Normalize(v);
    vec2SetMagnitude(v, max);
}

void vec2AddVector(Vector2 *a, const Vector2 *b)
{
    a->x += b->x;
    a->y += b->y;
}
void vec2AddNum(Vector2 *v, float n)
{
    v->x += n;
    v->y += n;
}

void vec2SubVector(Vector2 *a, const Vector2 *b)
{
    a->x -= b->x;
    a->y -= b->y;
}
void vec2SubNum(Vector2 *v, float n)
{
    v->x -= n;
    v->y -= n;
}

void vec2MultVector(Vector2 *a, const Vector2 *b)
{
    a->x *= b->x;
    a->y *= b->y;
}
void vec2MultNum(Vector2 *v, float n)
{
    v->x *= n;
    v->y *= n;
}

void vec2DivVector(Vector2 *a, const Vector2 *b)
{
    a->x /= b->x;
    a->y /= b->y;
}
void vec2DivNum(Vector2 *v, float n)
{
    v->x /= n;
    v->y /= n;
}

float vec2Dot(const Vector2 *a, const Vector2 *b)
{
    return a->x * b->x + a->y * b->y;
}

Vector2 *vec2Lerp(const Vector2 *a, const Vector2 *b, float t)
{
    Vector2 *tmp1 = newVec2(a->x, a->y);
    Vector2 *tmp2 = newVec2(b->x, b->y);

    vec2SubVector(tmp2, tmp1);
    vec2MultNum(tmp2, t);
    vec2AddVector(tmp1, tmp2);
    free(tmp2);

    return tmp1;
}

float vec2Angle(const Vector2 *a, const Vector2 *b)
{
    float dot = vec2Dot(a, b);
    float mag = vec2Magnitude(a) * vec2Magnitude(b);
    return acos(dot / mag);
}

Vector2 *vec2RotatedBy(const Vector2 *v, float radians)
{
    // this method uses the following matrix-transform:
    // | COS θ  -SIN θ | | Vx |
    // | SIN θ   COS θ | | Vy |
    // where θ is the given angle in radians and V the vector the method was called on

    // calculate the dot-product of (COS θ, -SIN θ) * (Vx, Vy)
    float newX = cos(radians) * v->x + -sin(radians) * v->y;

    // calculate the dot-product of (SIN θ, COS θ) * (Vx, Vy)
    float newY = sin(radians) * v->x + cos(radians) * v->y;

    return newVec2(newX, newY);
}

float vec2Heading(const Vector2 *v)
{
    return atan2(v->y, v->x);
}

void printVec2(const Vector2 *v)
{
    if (v == NULL)
    {
        printf("\n");
        return;
    }
    printf("[%0.2f; %0.2f]\n", v->x, v->y);
}
