/*
 * STD_TYPES.h
 *
 *  Created on: Sep 20, 2018
 *      Author: MuhammadElzeiny
 */
#ifndef _STD_Types_H
#define _STD_Types_H

#define ENABLE 					1
#define DISABLE					0

typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;

typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;

typedef float f32;
typedef double f64;

typedef enum
{
	OK,
	NOT_OK
}ret_status_t;
typedef enum
{
	false =0,
	true
}boolean_t;
typedef void(*p2func_t)(void);
#endif 
