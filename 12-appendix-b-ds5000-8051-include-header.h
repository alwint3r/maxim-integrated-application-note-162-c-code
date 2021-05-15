/*-----------------------------------------------------------------------------
DS5000.H
Header file for Dallas Semiconductor DS5000.
Copyright (c) 1995-1996 Keil Software, Inc. All rights reserved.
-----------------------------------------------------------------------------*/
#ifndef DS5000_HEADER_FILE
#define DS5000_HEADER_FILE 1
/*------------------------------------------------
DS5000 Byte Registers
------------------------------------------------*/
sfr P0 = 0x80;
sfr SP = 0x81;
sfr DPL = 0x82;
sfr DPH = 0x83;
sfr PCON = 0x87;
sfr TCON = 0x88;
sfr TMOD = 0x89;
sfr TL0 = 0x8A;
sfr TL1 = 0x8B;
sfr TH0 = 0x8C;
sfr TH1 = 0x8D;
sfr P1 = 0x90;
sfr SCON = 0x98;
sfr SBUF = 0x99;
sfr P2 = 0xA0;
sfr IE = 0xA8;
sfr P3 = 0xB0;
sfr IP = 0xB8;
sfr MCON = 0xC6;
sfr TA = 0xC7;
sfr PSW = 0xD0;
sfr ACC = 0xE0;
sfr B = 0xF0;
/*------------------------------------------------
DS5000 P0 Bit Registers
------------------------------------------------*/
//sbit P0_0 = 0x80; // Set Output Here
sbit DQ = 0x80; // Set Output Here
sbit P0_1 = 0x81;
sbit P0_2 = 0x82;
sbit P0_3 = 0x83;
sbit P0_4 = 0x84;
sbit P0_5 = 0x85;
sbit P0_6 = 0x86;
sbit P0_7 = 0x87;

/*------------------------------------------------
DS5000 PCON Bit Values
------------------------------------------------*/
#define IDL_ 0x01
#define STOP_ 0x02
#define EWT_ 0x04
#define EPFW_ 0x08
#define WTR_ 0x10
#define PFW_ 0x20
#define POR_ 0x40
#define SMOD_ 0x80
/*------------------------------------------------
DS5000 TCON Bit Registers
------------------------------------------------*/
sbit IT0 = 0x88;
sbit IE0 = 0x89;
sbit IT1 = 0x8A;
sbit IE1 = 0x8B;
sbit TR0 = 0x8C;
sbit TF0 = 0x8D;
sbit TR1 = 0x8E;
sbit TF1 = 0x8F;
/*------------------------------------------------
DS5000 TMOD Bit Values
------------------------------------------------*/
#define T0_M0_ 0x01
#define T0_M1_ 0x02
#define T0_CT_ 0x04
#define T0_GATE_ 0x08
#define T1_M0_ 0x10
#define T1_M1_ 0x20
#define T1_CT_ 0x40
#define T1_GATE_ 0x80
#define T1_MASK_ 0xF0
#define T0_MASK_ 0x0F
/*------------------------------------------------
DS5000 P1 Bit Registers
------------------------------------------------*/
sbit P1_0 = 0x90;
sbit P1_1 = 0x91;
sbit P1_2 = 0x92;
sbit P1_3 = 0x93;
sbit P1_4 = 0x94;
sbit P1_5 = 0x95;
sbit P1_6 = 0x96;
sbit P1_7 = 0x97;

/*------------------------------------------------
DS5000 SCON Bit Registers
------------------------------------------------*/
sbit RI = 0x98;
sbit TI = 0x99;
sbit RB8 = 0x9A;
sbit TB8 = 0x9B;
sbit REN = 0x9C;
sbit SM2 = 0x9D;
sbit SM1 = 0x9E;
sbit SM0 = 0x9F;
/*------------------------------------------------
DS5000 P2 Bit Registers
------------------------------------------------*/
sbit P2_0 = 0xA0;
sbit P2_1 = 0xA1;
sbit P2_2 = 0xA2;
sbit P2_3 = 0xA3;
sbit P2_4 = 0xA4;
sbit P2_5 = 0xA5;
sbit P2_6 = 0xA6;
sbit P2_7 = 0xA7;
/*------------------------------------------------
DS5000 IE Bit Registers
------------------------------------------------*/
sbit EX0 = 0xA8;
sbit ET0 = 0xA9;
sbit EX1 = 0xAA;
sbit ET1 = 0xAB;
sbit ES = 0xAC;
sbit EA = 0xAF;
/*------------------------------------------------
DS5000 P3 Bit Registers (Mnemonics & Ports)
------------------------------------------------*/
sbit RD = 0xB7;
sbit WR = 0xB6;
sbit T1 = 0xB5;
sbit T0 = 0xB4;
sbit INT1 = 0xB3;
sbit INT0 = 0xB2;
sbit TXD = 0xB1;
sbit RXD = 0xB0;
sbit P3_0 = 0xB0;
sbit P3_1 = 0xB1;
sbit P3_2 = 0xB2;
sbit P3_3 = 0xB3;
sbit P3_4 = 0xB4;
sbit P3_5 = 0xB5;
sbit P3_6 = 0xB6;
sbit P3_7 = 0xB7;

/*------------------------------------------------
DS5000 IP Bit Registers
------------------------------------------------*/
sbit PX0 = 0xB8;
sbit PT0 = 0xB9;
sbit PX1 = 0xBA;
sbit PT1 = 0xBB;
sbit PS = 0xBC;
sbit RWT = 0xBF;
/*------------------------------------------------
DS5000 MCON Bit Values
------------------------------------------------*/
#define SL_ 0x01
#define PAA_ 0x02
#define ECE2_ 0x04
#define RA32_8_0x08
#define PA0_ 0x10
#define PA1_ 0x20
#define PA2_ 0x40
#define PA3_ 0x80
/*------------------------------------------------
DS5000 PSW Bit Registers
------------------------------------------------*/
sbit P = 0xD0;
sbit OV = 0xD2;
sbit RS0 = 0xD3;
sbit RS1 = 0xD4;
sbit F0 = 0xD5;
sbit AC = 0xD6;
sbit CY = 0xD7;
/*------------------------------------------------
Interrupt Vectors:
Interrupt Address = (Number * 8) + 3
------------------------------------------------*/
#define IE0_VECTOR 0 /* 0x03 */
#define TF0_VECTOR 1 /* 0x0B */
#define IE1_VECTOR 2 /* 0x13 */
#define TF1_VECTOR 3 /* 0x1B */
#define SIO_VECTOR 4 /* 0x23 */
#define PFW_VECTOR 5 /* 0x2B */
/*------------------------------------------------
------------------------------------------------*/
#endif
