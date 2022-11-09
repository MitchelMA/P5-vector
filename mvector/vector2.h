#ifndef VECTOR2_GUARD_H
#define VECTOR2_GUARD_H

/**
 * @brief Structure for a 2D point in space defined as a vector
 *
 */
typedef struct Vector2
{
    float x, y;
} Vector2;

/**
 * @brief Creates a new instance of a Vector2 struct
 *
 * @param x The x-component of the 2D vector
 * @param y The y-component of the 2D vector
 * @return A new instance of a Vector2 struct
 */
Vector2 *newVec2(float x, float y);

/**
 * @brief Creates a new instance of a Vector2 struct,
 * but by angle
 *
 * @param angle The angle of the 2D vector
 * @return A new instance of a Vector2 struct
 */
Vector2 *newVec2Angle(float angle);

/**
 * @brief Calculates the magnitude of a Vector2
 *
 * @param v The instance of a Vector2 struct
 * @return The magnitude of the Vector2
 */
float vec2Magnitude(const Vector2 *v);

/**
 * @brief Sets the magnitude of a Vector2
 * while maintaining the proportions of the x and y components
 *
 * @param v The instance of a Vector2 struct
 * @param magnitude The new magnitude of the instance passed
 */
void vec2SetMagnitude(Vector2 *v, float magnitude);

/**
 * @brief Normalizes the Vector2
 *
 * @param v The instance that gets normalized
 */
void vec2Normalize(Vector2 *v);

/**
 * @brief Returns the unit-vector
 *
 * @param v The instance of which you want the unit-vector
 * @return The unit-vector of the passed Vector2 `v`
 */
Vector2 *vec2Normalized(const Vector2 *v);

/**
 * @brief Limits the magnitude of the passed instance
 *
 * @param v The instance whose magnitude gets limited
 * @param max The max value of the magnitude
 */
void vec2Limit(Vector2 *v, float max);

/**
 * @brief Adds Vector2 `b` to Vector2 `a`
 *
 * @param a The base vector
 * @param b The vector that gets added to the base vector
 */
void vec2AddVector(Vector2 *a, const Vector2 *b);

/**
 * @brief Adds a value `n` to the x and y components of Vector2 `v`
 *
 * @param v The base vector
 * @param n The value that gets added to the base vector
 */
void vec2AddNum(Vector2 *v, float n);

/**
 * @brief Subtracts Vector2 `b` from Vector2 `a`
 *
 * @param a The base vector
 * @param b The vector that gets subtracted from the base vector
 */
void vec2SubVector(Vector2 *a, const Vector2 *b);

/**
 * @brief Subtracts a value `n` from the x and y components of Vector2 `v`
 *
 * @param v The base vector
 * @param n The value that gets subtracted from the base vector
 */
void vec2SubNum(Vector2 *v, float n);

/**
 * @brief Multiplies vector `a` by vector `b`. By mathematical rules, this would be incorrect,
 * So this method should be used to multiply the x and y components of vector `v` independently.
 *
 * @param a The base vector
 * @param b The vector that the base vector gets multiplied by
 */
void vec2MultVector(Vector2 *a, const Vector2 *b);

/**
 * @brief Multiplies a vector `v` by a value `n`
 *
 * @param v The base vector
 * @param n The value that the base vector gets multiplied by
 */
void vec2MultNum(Vector2 *v, float n);

/**
 * @brief Devides vector `a` by vector `b`. By mathematical rules, this would be incorrect,
 * So this method should be used to devide the x and y components of vector `v` independently.
 *
 * @param a The base vector
 * @param b The vector that the base vector gets devided by
 */
void vec2DivVector(Vector2 *a, const Vector2 *b);

/**
 * @brief Devies vector `v` by a value `n`
 *
 * @param v The base vector
 * @param n The value that the base vector gets devided by
 */
void vec2DivNum(Vector2 *v, float n);

/**
 * @brief Calculates the dot-product of two vectors
 *
 * @param a
 * @param b
 * @return the dot-product of vector `a` and vector `b`
 */
float vec2Dot(const Vector2 *a, const Vector2 *b);

/**
 * @brief Linearly interpolates from vector `a` towards vector `b` at a time instance `t`
 *
 * @param a
 * @param b
 * @param t
 * @return The point between vector `a` and vector `b` at the time instance `t`
 */
Vector2 *vec2Lerp(const Vector2 *a, const Vector2 *b, float t);

/**
 * @brief Calculates the angle between two vectors
 *
 * @param a
 * @param b
 * @return The angle between the two vectors
 */
float vec2Angle(const Vector2 *a, const Vector2 *b);

/**
 * @brief Returns a new instance of Vector2 rotated by angle `radians` from the base vector `v`
 *
 * @param v
 * @param radians
 * @return A new instance of Vector2 rotated by a given angle `radians` from the base vector `v`
 */
Vector2 *vec2RotatedBy(const Vector2 *v, float radians);

/**
 * @brief Calculates the direction a vector is heading towards in radians
 *
 * @param v
 * @return The direction towards which the vector is heading
 */
float vec2Heading(const Vector2 *v);

void printVec2(const Vector2 *v);

#endif