/*
 * BIT_CALC.h
 *
 *  Created on: Aug 30, 2019
 *      Author: William
 */

#ifndef BIT_CALC_H_
#define BIT_CALC_H_

# define SET_BIT(var,bitNo) (var |= (1<<bitNo))
# define CLR_BIT(var,bitNo) (var &= (~(1<<bitNo)))
# define TOG_BIT(var,bitNo) (var ^= (1<<bitNo))
# define GET_BIT(var,bitNo) ((var & (1<<bitNo))>>bitNo)


#endif /* BIT_CALC_H_ */
