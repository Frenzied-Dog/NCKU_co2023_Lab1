#ifndef __USER__
#define __USER__

#include "common.h"

/*
 * Implement "ecall" environment call instruction in RV32I
 * Define in src/include/call_to_aisemu.S
 */
extern volatile void call_to_aisemu(int arg0, int arg1);

/* for calculations */
extern int32_t mul(int32_t, int32_t);     // multiply operation, ignore overflow
extern int32_t divide(int32_t, int32_t);  // divide operation
extern int32_t mod(int32_t, int32_t);     // modulo operation

/* for printing to terminal */
extern void putc(const char);   // put char
extern void puts(const char*);  // put string
extern void putint(int32_t);    // put integer

/* use to exit aisemu */
extern void exit(void);

#endif
