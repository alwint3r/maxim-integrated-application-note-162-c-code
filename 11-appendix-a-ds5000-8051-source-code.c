// 1wiretalk.c -- Functions for the Dallas Semiconductor DS18x20/DS1822
// Two-Wire Temperature Sensor
// Designed for 8051 microcontrollers
// This code was developed using the DS5000/DS2251T
// Please note that 128K RAM size is required to run this program.
/*----------------------------------------------------------------------*/
//#pragma CODE SMALL OPTIMIZE(3)
/* command line directives */
#include <absacc.h>   /* absolute addressing modes */
#include <ctype.h>    /* character types */
#include <math.h>     /* standard math */
#include <stdio.h>    /* standard I/O */
#include <string.h>   /* string functions */
#include <ds50001w.h> /* DS5000 series 8052 registers */
/*----------------------------------------------------------------------*/
/* Configuration parameters */
/*----------------------------------------------------------------------*/
#define XtalFreq (11059490)      /* main crystal frequency */
#define CntrFreq (XtalFreq / 12) /* main counter frequency */
#define BaudRate (9600)          /* baud rate */
#define CntrTime (8)             /* number of cycles for counter */
#define Ft (32768.0)             /* target crystal frequency */
/*----------------------------------------------------------------------*/
/*--------------------------------------------------------------------* /
/////////////////////////BEGIN MAIN PROGRAM//////////////////////////////
main()
{/
*----------------------------------------------------------------------*/
/* Local variables */
/*----------------------------------------------------------------------*/
unsigned char Select_Type; /* Function variable */
/*----------------------------------------------------------------------*/
/* Start of program execution */
/*----------------------------------------------------------------------*/
/* Inhibit the watchdog timer and set up memory */
/*----------------------------------------------------------------------*/
TA = 0xAA; /* timed access */
TA = 0x55;
PCON = 0x00; /* inhibit watchdog timer */
*----------------------------------------------------------------------* /
    /* Set up the serial port */
    /*----------------------------------------------------------------------*/
    SCON = 0x50; /* SCON: mode 1, 8-bit UART, enable rcvr */
TMOD = 0x21;     /* TMOD: timer 1, mode 2, 8-bit reload */
/* TMOD: timer 0, mode 1, 16-bit */
PCON |= 0x80; /* SMOD = 1 Double Baud Rate for TH1 load */
TH0 = TL0 = 0;
TH1 = TL0 = (unsigned int)(256 - ((XtalFreq / BaudRate) / 192));
TR0 = 1; /* TR0: timer 0 run */
TR1 = 1; /* TR1: timer 1 run */
TI = 1;  /* TI: set TI to send first char of UART */
/*----------------------------------------------------------------------*/
/* Display DS1820 One-Wire Device banner */
/*----------------------------------------------------------------------*/
printf("\n");
printf(" Dallas Semiconductor - Systems Extension\n");
printf(" Source for DS1820 Temperature Reading and\n");
printf(" Search ROM code.\n");
printf(" Updated Code August, 2001 \n");
printf(" [C Program for DS500x or 8051 Compatible Microcontroller]");
printf("\n\n");
printf("\n********************************************************************\n");
printf(" Select Menu Option\n");
printf(" 1. One-Wire Reset\n");
printf(" 2. Read ROM Code of Single Device On Net\n");
printf(" 3. Perform Search ROM\n");
printf(" 4. Read Scratch PAD\n");
printf(" 5. Read Temperature\n");
printf(" 6. Find All Devices\n");
printf("\n\n");
printf(" Note: This program represents an example only.\n");
printf(" No warranties or technical support is provided with this program.\n");
/*----------------------------------------------------------------------*/
do
{
    /*----------------------------------------------------------------------*/
    /* Enable CE2 */
    /*----------------------------------------------------------------------*/
    EA = 0;    /* Inhibit interrupts */
    TA = 0xAA; /* timed access */
    TA = 0x55;
    MCON = MCON |= 0x04; /* Enable topside CE 0xCC */
    /*----------------------------------------------------------------------*/
    /* Disable CE2 */
    /*----------------------------------------------------------------------*/
    TA = 0xAA; /* timed access */
    TA = 0x55;
    MCON = 0xC8;             /* Disable topside CE */
    EA = 1;                  /* Enable interrupts */
    Select_Type = getchar(); /* get variable to start */
    switch (Select_Type)
    {
    case '1':
        printf("\n 1. Sent 1-Wire Reset\n");
        ow_reset();
        break;
    case '2':
        printf(" 2. Read ROM Code of Single Device On Net\n");
        ow_reset();
        Read_ROMCode();
    case '3':
        printf("\n 3. Performing Search ROM\n");
        ow_reset();
        First();
        printf("\nROM CODE =%02X%02X%02X%02X\n",
               FoundROM[5][7], FoundROM[5][6], FoundROM[5][5], FoundROM[5][4],
               FoundROM[5][3], FoundROM[5][2], FoundROM[5][1], FoundROM[5][0]);
        break;
    case '4':
        printf("\n 4. Read Scratch PAD\n");
        ow_reset();
        write_byte(0xCC); // Skip ROM
        Read_ScratchPad();
        break;
    case '5':
        printf("\n 5. Read Temperature\n");
        Read_Temperature(); //initiates a temperature reading
        break;
    case '6':
        printf("\n 6. Find All Devices\n");
        ow_reset();
        FindDevices();
        break;
    default:
        printf("\n Typo: Select Another Menu Option\n");
        break;
    };       /* end switch*/
} while (1); /* Loop forever */
             /*----------------------------------------------------------------------*/
             /* End of program */
             /*----------------------------------------------------------------------*/