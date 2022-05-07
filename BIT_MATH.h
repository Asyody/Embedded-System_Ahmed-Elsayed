
#ifndef BTI_MATH_H
#define BIT_MATH_H



#define 	SET_BIT(VAR, BITNO)  	(VAR) |= (1 << (BITNO))
#define 	CLR_BIT(VAR, BITNO)		(VAR) &= ~(1<< (BITNO))
#define 	TOG_BIT(VAR, BITNO)		(VAR) ^= (1 << (BITNO))
#define 	GET_BIT(VAR, BITNO)		(((VAR) >> (BITNO)) & 0X01)



#endif
