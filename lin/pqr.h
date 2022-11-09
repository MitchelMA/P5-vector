// make sure the header file doesn't get included multiple times
#ifndef PQR_GUARD_H
#define PQR_GUARD_H

#include "../mvector/vector2.h"

// structure
/**
 * @brief Pqr structure used to for formula's in the `px + qy = r` form
 *
 */
typedef struct Pqr
{
    float p, q, r;
} Pqr;

// methods
/**
 * @brief Constructor for a formula in the form `px + qy = r`
 *
 * @param p The p component of the formula
 * @param q The q component of the formula
 * @param r The r component of the formula
 * @return An instance of a PQRStruct
 */
Pqr *newPqr(float p, float q, float r);

/**
 * @brief Constructor for a formula in the form `px + qy = r`.
 * This constructor creates a formula using two points through which the formula should pass
 *
 * @param point1
 * @param point2
 * @return An instance of a PQRStruct
 */
Pqr *newPqrPoints(const Vector2 *point1, const Vector2 *point2);

/**
 * @brief Constructor for a formula in the form `px + qy = r`.
 * This constructor creates a `px + qy = r` formula from a `y = px + r` formula
 *
 * @param p
 * @param r
 * @return An instance of a PQRStruct
 */
Pqr *newPqrPR(float p, float r);

/**
 * @brief Constructor for a formula in the form `px + qy = r`.
 * This constructor creates a `px + qy = r` formula from a slope and a given point A
 *
 * @param slope
 * @param pointA
 * @return An instance of a PQRStruct
 */
Pqr *newPqrSlope(float slope, const Vector2 *ref);

/**
 * @brief Method to copy a PQRStruct
 *
 * @param copy the PQRStruct that gets copied
 * @return The copy of the passed PQRStruct
 */
Pqr *pqrCopy(const Pqr *copy);

/**
 * @brief Method to get the x-value at a given y-value
 *
 * @param form The formula you want to get the x-valu of
 * @param y The y value you want to get the corresponding x-value of
 * @return The corresponding x-value at the given y-value
 */
float pqrGetX(const Pqr *form, float y);
/**
 * @brief Method to get the y-value at a given x-value
 *
 * @param form The formula you want to get the y-value of
 * @param x The x value you want to get the corresponding y-value of
 * @return The corresponding y-value at the given x-value
 */
float pqrGetY(const Pqr *form, float x);

/**
 * @brief Method to get the coordinates at which a formula intersects with the x-axis.
 * This method could possibly return `NULL`. This happens when the formula doesn't intersect with the x-axis
 *
 * @param form The formula you want to get the x-intersection of
 * @return The coordinates at which the formula intersects with the x-axis
 */
Vector2 *pqrRoot(const Pqr *form);
/**
 * @brief Method to get the coordinates at which a formula intersects with the y-axis.
 * This method could possibly return `NULL`. This happens when the formula doesn't intersect with the y-axis
 *
 * @param form The formula you want to get the y-intersection of
 * @return The coordinates at which the formula intersects with the y-axis
 */
Vector2 *pqrYIcept(const Pqr *form);

/**
 * @brief Method to get a perpendicular formula of a given formula
 *
 * @param form Formula you want to get the perpendicular formula of
 * @return The perpendicular formula
 */
Pqr *pqrPerpendicular(const Pqr *form);

/**
 * @brief Method to get the slope of a formula
 *
 * @param form The formula whose slope will get returned
 * @return The slope of the formula
 */
float pqrSlope(const Pqr *form);

/**
 * @brief Method to get the angle of the slope of the formula
 *
 * @param form The formula of which the angle of the slope gets calculated
 * @return The angle of the formula in radians
 */
float pqrAngle(const Pqr *form);

/**
 * @brief Method to get the slope of a given angle
 *
 * @param angle Given angle in radians
 * @return The slope of the given angle
 */
float pqrSlopeFromAngle(float angle);

/**
 * @brief Method to get the angle of a given slope
 *
 * @param slope The slope of the formula
 * @return The angle in radians of the given slope
 */
float pqrAngleFromSlope(float slope);

/**
 * @brief Method to get the coordinates of an intersection between two formula's
 *
 * @param form1 The first formula
 * @param form2 The second formula
 * @param tolerance Difference between the slopes at which the method will test to see if they are equal
 * @return The coordinates of the point at which the two formula's intersect
 */
Vector2 *pqrIntersect(const Pqr *form1, const Pqr *form2, double tolerance);

/**
 * @brief Prints a formula to the standard output
 *
 * @param form The formula that gets printed
 */
void printPqr(const Pqr *form);

#endif