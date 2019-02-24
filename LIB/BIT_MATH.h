/*
 * BIT_MATH.h
 *
 *  Created on: Sep 20, 2018
 *      Author: MuhammadElzeiny
 */
#ifndef _BIT_MATH_H
#define _BIT_MATH_H

#define SET_BIT(reg,bitno)					reg|=(1<<bitno)
#define CLR_BIT(reg,bitno)					reg&=(~(1<<bitno))
#define TOGGLE_BIT(reg,bitno)				reg^=(1<<(bitno))
#define GET_BIT(reg,bitno)					(reg&(1<<bitno) )>>bitno
#define ASSIGN_BIT(reg,bitno,value)			do{ CLR_BIT(reg,bitno); reg|=((value)<<bitno); }while(0)

/*TODO: implement macro function SHIFT_RIGHT(reg,shiftno) */

/*TODO: implement macro function SHIFT_LEFT(reg,shiftno) */

/*TODO: implement macro function CIR_SHIFT_RIGHT(reg,shiftno) */

/*TODO: implement macro function CIR_SHIFT_LEFT(reg,shiftno) */


#define BIT_CONC(B7,B6,B5,B4,B3,B2,B1,B0)	CONC_HELP(B7,B6,B5,B4,B3,B2,B1,B0)
#define CONC_HELP(B7,B6,B5,B4,B3,B2,B1,B0)	0b##B7##B6##B5##B4##B3##B2##B1##B0


#endif
