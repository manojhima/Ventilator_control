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

// port oscillator related

UWORD16 XSSCPORT;

//ports definition
UWORD16 P2;
UWORD16 DP2;
UWORD16 ODP2;
//UWORD16 P3;
UWORD16 DP3;
UWORD16 ODP3;
UWORD16 P4;
UWORD16 DP4;
UWORD16 ODP4;
UWORD16 P5;
UWORD16 DP5;
UWORD16 ODP5;
UWORD16 P6;
UWORD16 DP6;
UWORD16 ODP6;
UWORD16 P7;
UWORD16 DP7;
UWORD16 ODP7;
UWORD16 P8;
UWORD16 DP8;
UWORD16 ODP8;


// adc related

UWORD16 PECC0;
UWORD16 DSTP0;
UWORD16 ADST;
UWORD16 ADEIE;
UWORD16 ADEIR;
UWORD16 ADDAT=0;
UWORD16 ADDAT2=0;

// interrupt ihibit
UWORD16 S0TBIE;

//com buffer
UWORD16 S0RBUF;

// capture compare 0
UWORD16 CC0;
// timer 1 interrupt enable
UWORD16 T1IE;
UWORD16 T1;
UWORD16 T1IR;
UWORD16 CC0IR;
//UWORD16

UWORD16 PWMCON1;
UWORD16 PWMCON0;
UWORD16 PP3;
UWORD16 CCM7;
UWORD16 CC28;

UWORD16 PW3;
//UWORD16
//UWORD16

// for timer t1
UWORD16 T1R;

// for timer t2
UWORD16 T2;
UWORD16 T2IE;
UWORD16 T2R;
UWORD16 T2CON;
UWORD16 T2IC;
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

// timer t3 related
UWORD16 T3IR;
UWORD16 T3;
UWORD16 T3CON;

// watch dog
UWORD16 WDTCON;


// timer t4 related registers
UWORD16 T4CON;
UWORD16 T4R;
UWORD16 T4IE;
UWORD16 T4;
UWORD16 T4IC;

// timer t4 related registers
UWORD16 T5CON;
UWORD16 T5R;
UWORD16 T5IE;
UWORD16 T5;
UWORD16 T5IC;

// timer t6
UWORD16 T6CON;
UWORD16 T6IC;

// timer 7&8 timers
UWORD16 T7;
UWORD16 T7R;
UWORD16 T7REL;
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

// capture compare 10 related
UWORD16 CC10IE;
UWORD16 CC10IR;
//interrupt related
UWORD16 XP1IE;
UWORD16 XP1IR;
UWORD16 XIR1CLR;

UWORD16 DSTP7;
UWORD16 PECC6;
UWORD16 PECC7;
UWORD16 XIR1SET;

UWORD16 XP1IC;
UWORD16 XP2IC;
UWORD16 XIR2CLR;
UWORD16 XIR3CLR;
UWORD16 XSSCCONCLR;
UWORD16 XS1RBUF;
UWORD16 XIR0SEL;
UWORD16 SSCBSY;

UWORD16 XSSCCONSET;
UWORD16 XSSCBR;
UWORD16 XP1IE;
UWORD16 XP3IC;
UWORD16 XIR3SET;
UWORD16 CCM2;
UWORD16 CC10IC;

UWORD16 SRCP7;
UWORD16 SRCP6;
UWORD16 DSTP6;
UWORD16 XIR2SET;
UWORD16 XP2IR;
UWORD16 XP2IE;
UWORD16 XSSCRB;
UWORD16 XSSCTB;


#endif /* mono inclusion */
