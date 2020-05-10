#ifndef IO_STUBS_H	/* mono inclusion */
#define IO_STUBS_H
#include "../GENERAL/typedef.h"
#define P2_0 0
#define P2_1 0
#define P2_2 0
#define P2_3 0
#define P2_4 0
#define P2_5 0
#define P2_6 0
#define P2_7 0
#define P2_8 1
#define P2_9 1
#define P2_10 1
#define P2_11 0
#define P2_12 0
#define P2_13 0
#define P2_14 1
#define P2_15 0

// for port 3

#define P3_0 0
#define P3_1 0
#define P3_2 0
#define P3_3 0
#define P3_4 0
#define P3_5 0
#define P3_6 0
#define P3_7 0
#define P3_8 0
#define P3_9 0
#define P3_10 0
#define P3_11 0
#define P3_12 0
#define P3_13 0
#define P3_14 0
#define P3_15 0


// for port 6
#define P6_0 0
#define P6_1 0
#define P6_2 0
#define P6_3 0
#define P6_4 0
#define P6_5 0
#define P6_6 0
#define P6_7 0

// for port 7
#define P7_0 0
#define P7_1 0
#define P7_2 0
#define P7_3 0
#define P7_4 0
#define P7_5 0
#define P7_6 0
#define P7_7 0
#define P7_8 0
#define P7_9 0
#define P7_10 0
#define P7_11 0
#define P7_12 0
#define P7_13 0
#define P7_14 0
#define P7_15 0

// for port 8

#define P8_0 0
#define P8_1 0
#define P8_2 0
#define P8_3 0
#define P8_4 0
#define P8_5 0
#define P8_6 0
#define P8_7 0

// for timer t1
UWORD16 T1R;

// for timer t2
int T2;
int T2IE;
int T2R;
int T2CON;
int T2IC;
UWORD16 T2IR;

// for port p3
UWORD16 P3;

//for SEC_NmiTrap.c
UWORD16 SSCTB;
UWORD16 SSCRB;
void _nop_(){};

void _srvwdt_(){};
UWORD16 PUST_ERROR;

// interrupt enable related in main
UWORD16 IEN;

// timer t4 related registers
UWORD16 T4CON;
UWORD16 T4R;
UWORD16 T4IE;
UWORD16 T4;
UWORD16 T4IC;

// timer t6
UWORD16 T6CON;
UWORD16 T6IC;

// timer 7&8 timers

UWORD16 T78CON;
UWORD16 T8REL;
UWORD16 T8R;

// timer 0&1

UWORD16 T01CON;
UWORD16 T1IC;
UWORD16 T1REL;

// capture compare registers

UWORD16 CCM0;
UWORD16 CC0IC;
UWORD16 CC0IE;
UWORD16 CAPREL;
//configuring port 8 to XS1PORT

UWORD16 XS1PORT;
UWORD16 XP0IC;

// spi related

UWORD16 SSCCON;
UWORD16 SSCTIC;
UWORD16 SSCRIC;
/*%CConfiguration of the bus speed SPI 1.8Mhz */
UWORD16 SSCBR;

//scon related

UWORD16 S0CON;
UWORD16 S0TBIR;
UWORD16 S0TBUF;
UWORD16 S0BG;
UWORD16 S0TBIC;
UWORD16 S0RIC;


#endif /* mono inclusion */
