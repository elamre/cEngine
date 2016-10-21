/*
 * fixedpoint.h
 *
 *  Created on: Mar 8, 2016
 *      Author: elmar
 */

#ifndef UTIL_MATH_FIXEDPOINT_H_
#define UTIL_MATH_FIXEDPOINT_H_

typedef int32_t q21_10_t;

#define __Q_MUL(A, B, TYPE, TMP_TYPE, FBITS) \
	((TYPE)((((TMP_TYPE)(A)) * ((TMP_TYPE)(B))) >> FBITS ))

#define __Q_DIV(A, B, TYPE, TMP_TYPE, FBITS) \
	((TYPE)(((TMP_TYPE)(A) << FBITS) / (B)))

/**
 * q7.8 multiply, resulting in q23.7
 */
#define mul_q7_8(A, B)		__Q_MUL(A, B, q23_8_t, q23_8_t, 8)

/**
 * q7.8 divide,
 */
#define  div_q7_8(A, B)		__Q_DIV(A, B, q7_8_t, q23_8_t, 8)

inline int32_t q21_10_t_frac(q21_10_t var) {
	return var & 0x3FF;
}

inline int32_t q21_10_t_int(q21_10_t var) {
	return var >> 10;
}

#endif /* UTIL_MATH_FIXEDPOINT_H_ */
