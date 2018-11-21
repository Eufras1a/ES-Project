//******************************************************************************
//
//                  keypad with LCD 16X2 Demo
//
//******************************************************************************
// Microcontroller: LPC2148
// Compiler:        Keil
// Target Hardware: ARM7 Universal Development Board
// Company:         ADVANCE TECH (I) PVT. LTD
// Author  : 		Prateek Gupta
//******************************************************************************
//                 Hardware Settings for ARM7 Development Board
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  Microcontroller:LPC2148
//  Ext.Oscillator:	12 MHz
//
//	PINOUT:	LCD   -   LPC2148 
//					----------------- 
//					DB0   -   	P1.16 
//					DB1   -   	P1.17 
//					DB2   -   	P1.18
//					DB3   -   	P1.19 
//					DB4   -   	P1.20 
//					DB5   -   	P1.21 
//					DB6   -   	P1.22
//					DB7   -   	P1.23 
//					RS    -   	P1.24 
//					E     -   	P1.25 
//					R/W   -   	GND
//***************************************************************************

//**************************INCLUDES********************************************
#include <LPC214x.h>
//////////////////////////USER SETTINGS//////////////////////////////////
#define DATA_PORT_SET       IOSET0
#define DATA_PORT_CLR       IOCLR0
#define DATA_DIR            IODIR0
#define D7					23
#define D6					22
#define D5					21
#define D4					20
#define D3					19
#define D2					18
#define D1					17
#define D0					16
//Set data port pins
#define DATA_PORT    				(unsigned long)((1<<D7)|(1<<D6)|(1<<D5)|(1<<D4))|((1<<D3)|(1<<D2)|(1<<D1)|(1<<D0))

#define CTRL_PORT_SET       IOSET1
#define CTRL_PORT_CLR       IOCLR1
#define CTRL_DIR            IODIR1
#define CTRL_RS             24
#define CTRL_EN             25

#define KEYPAD_DIR          IODIR1
#define KEYPAD_SET	        IOSET1
#define KEYPAD_CLR  	      IOCLR1
#define KEYPAD_PIN          IOPIN1
#define R1 23
#define R2	22
#define R3	21
#define R4	20
#define C1	19
#define C2	18
#define C3	17
#define C4	16
#define KEYPAD_PORT_COL    				(unsigned long)((1<<C1)|(1<<C2)|(1<<C3)|(1<<C4))
#define KEYPAD_PORT_ROW    				(unsigned long)((1<<R1)|(1<<R2)|(1<<R3)|(1<<R4))
////////////////////////End of USER SETTINGS////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
#include"delay.h"
#include"lcd.h"
#include"keypad.h"

	
//code that was originally present here is below 

//int main(void)
//{
//	unsigned char key;
//	KEYPAD_DIR |=   (KEYPAD_PORT_ROW);
//	KEYPAD_DIR &= ~ (KEYPAD_PORT_COL);
//	init_lcd();	  				//lcd init.
//	cmd_lcd(0x80);			//Set curser position 
//	string_lcd("Press key ");	//Display string
//	while(1)
//	{
//      cmd_lcd(0xc0);
//			key = keyscan();			//Scan keypad
//			data_lcd(key);				//Display pressed key on lcd
//	}

//}


// code by eufrasia 
//calculator only involving add and sub

int main(void)
{int key;

	while(1)
	{
		
cmd_lcd(0x01);
cmd_lcd(0x80);			
string_lcd("Do you want to..");
delay_ms(2000);

cmd_lcd(0x01);
cmd_lcd(0x80);			
string_lcd("add(1) or Sub (0) ?");

key=keyscan();

switch(key)
{
	case '1':
	{	int Op1,Op2,Result;

	  cmd_lcd(0x01); // clear lcd
	  cmd_lcd(0x80);			//set cursor to ~~who knows where~~ ? 
    string_lcd("Enter Operand 1");
    Op1=keyscan();

	  cmd_lcd(0x01);
	  cmd_lcd(0x80);			
    string_lcd("Ener Operand 2");
    Op2=keyscan();

    Result=Op1+Op2;

	  cmd_lcd(0x01);
	  cmd_lcd(0x80);			
    string_lcd("Result=");
    data_lcd(Result);
		delay_ms(2000);

   }
	break;

	case '2':
	{int Op1,Op2,Result;

	  cmd_lcd(0x01);
	  cmd_lcd(0x80);			
    string_lcd("Enter Operand 1");
    Op1=keyscan();

	  cmd_lcd(0x01);
	  cmd_lcd(0x80);			
    string_lcd("Ener Operand 2");
    Op2=keyscan();

    Result=Op1-Op2;

	  cmd_lcd(0x01);
	  cmd_lcd(0x80);			
    string_lcd("Result=");
    data_lcd(Result);
	  delay_ms(2000);
}
	break;

	default:
	{ cmd_lcd(0x01);
	  cmd_lcd(0x80);			
    string_lcd("Invalid Input");
	  delay_ms(2000);
	}
	break;
}

	}
}
