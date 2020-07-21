/*
 * geniePi.h:
 *	Library to utilise the 4D Systems Genie interface to displays
 *	that have been created using the Visi-Genie creator platform.
 *	Primarily aimed at the Raspberry Pi, however this may be used
 *	on most Linux platforms with a serial connection (USB on
 *	on-board) to the 4D Systems Intelligent displays.
 *
 *	Written by Gordon Henderson, December 2012, <projects@drogon.net>
 *  Updated/Maintained by 4D Systems Pty Ltd, www.4dsystems.com.au
 *	Copyright (c) 2020 4D Systems PTY Ltd, Sydney, Australia
 ***********************************************************************
 * This file is part of geniePi:
 *    geniePi is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU Lesser General Public License as
 *    published by the Free Software Foundation, either version 3 of the
 *    License, or (at your option) any later version.
 *
 *    geniePi is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU Lesser General Public License for more details.
 *
 *    You should have received a copy of the GNU Lesser General Public
 *    License along with geniePi.
 *    If not, see <http://www.gnu.org/licenses/>.
 ***********************************************************************
 */

#undef	GENIE_DEBUG

// Genie commands & replys:

#define	GENIE_ACK		0x06
#define	GENIE_NAK		0x15

#define	GENIE_READ_OBJ				       0
#define	GENIE_WRITE_OBJ				       1
#define	GENIE_WRITE_STR				       2
#define	GENIE_WRITE_STRU			       3
#define	GENIE_WRITE_CONTRAST		     4
#define	GENIE_REPORT_OBJ			       5
#define	GENIE_REPORT_EVENT			     7
#define GENIE_MAGIC_BYTES			       8
#define GENIE_DOUBLE_BYTES 			     9
#define GENIE_REPORT_MAGIC_BYTES  	10
#define GENIE_REPORT_DOUBLE_BYTES	  11


// Objects
//	the manual says:
//		Note: Object IDs may change with future releases; it is not
//		advisable to code their values as constants.

#define	GENIE_OBJ_DIPSW		 		   0
#define	GENIE_OBJ_KNOB		 		   1
#define	GENIE_OBJ_ROCKERSW	 		 2
#define	GENIE_OBJ_ROTARYSW	 		 3		
#define	GENIE_OBJ_SLIDER	 		   4
#define	GENIE_OBJ_TRACKBAR			 5
#define	GENIE_OBJ_WINBUTTON	 		 6
#define	GENIE_OBJ_ANGULAR_METER	 7
#define	GENIE_OBJ_COOL_GAUGE		 8
#define	GENIE_OBJ_CUSTOM_DIGITS	 9
#define	GENIE_OBJ_FORM				  10
#define	GENIE_OBJ_GAUGE				  11
#define	GENIE_OBJ_IMAGE				  12
#define	GENIE_OBJ_KEYBOARD			13
#define	GENIE_OBJ_LED				    14
#define	GENIE_OBJ_LED_DIGITS		15
#define	GENIE_OBJ_METER				  16
#define	GENIE_OBJ_STRINGS			  17
#define	GENIE_OBJ_THERMOMETER		18
#define	GENIE_OBJ_USER_LED			19
#define	GENIE_OBJ_VIDEO				  20
#define	GENIE_OBJ_STATIC_TEXT		21
#define	GENIE_OBJ_SOUND				  22
#define	GENIE_OBJ_TIMER				  23
#define	GENIE_OBJ_SPECTRUM			24
#define	GENIE_OBJ_SCOPE				  25
#define	GENIE_OBJ_TANK				  26
#define	GENIE_OBJ_USERIMAGES		27
#define	GENIE_OBJ_PINOUTPUT			28
#define	GENIE_OBJ_PININPUT			29
#define	GENIE_OBJ_4DBUTTON			30
#define	GENIE_OBJ_ANIBUTTON			31
#define	GENIE_OBJ_COLORPICKER		32
#define	GENIE_OBJ_USERBUTTON		33
// reserved for magic functions 34
#define GENIE_OBJ_SMARTGAUGE            35
#define GENIE_OBJ_SMARTSLIDER           36
#define GENIE_OBJ_SMARTKNOB             37
// Not advisable to use the below 3, use the above 3 instead.
#define GENIE_OBJ_ISMARTGAUGE           35 // Retained for backwards compatibility, however Users should use SMARTGAUGE instead of ISMARTGAUGE
#define GENIE_OBJ_ISMARTSLIDER          36 // Retained for backwards compatibility, however Users should use SMARTSLIDER instead of ISMARTSLIDER
#define GENIE_OBJ_ISMARTKNOB            37 // Retained for backwards compatibility, however Users should use SMARTKNOB instead of ISMARTKNOB
// Comment end																																	  			  
#define GENIE_OBJ_ILED_DIGITS_H         38
#define GENIE_OBJ_IANGULAR_METER        39
#define GENIE_OBJ_IGAUGE                40
#define GENIE_OBJ_ILABEL                41
#define GENIE_OBJ_IUSER_GAUGE           42
#define GENIE_OBJ_IMEDIA_GAUGE          43
#define GENIE_OBJ_IMEDIA_THERMOMETER    44
#define GENIE_OBJ_ILED                  45
#define GENIE_OBJ_IMEDIA_LED            46
#define GENIE_OBJ_ILED_DIGITS_L         47
#define GENIE_OBJ_ILED_DIGITS           47
#define GENIE_OBJ_INEEDLE               48
#define GENIE_OBJ_IRULER                49
#define GENIE_OBJ_ILED_DIGIT            50
#define GENIE_OBJ_IBUTTOND              51
#define GENIE_OBJ_IBUTTONE              52
#define GENIE_OBJ_IMEDIA_BUTTON         53
#define GENIE_OBJ_ITOGGLE_INPUT         54
#define GENIE_OBJ_IDIAL                 55
#define GENIE_OBJ_IMEDIA_ROTARY         56
#define GENIE_OBJ_IROTARY_INPUT         57
#define GENIE_OBJ_ISWITCH               58
#define GENIE_OBJ_ISWITCHB              59
#define GENIE_OBJ_ISLIDERE              60
#define GENIE_OBJ_IMEDIA_SLIDER         61
#define GENIE_OBJ_ISLIDERH              62
#define GENIE_OBJ_ISLIDERG              63
#define GENIE_OBJ_ISLIDERF              64
#define GENIE_OBJ_ISLIDERD              65
#define GENIE_OBJ_ISLIDERC              66
#define GENIE_OBJ_ILINEAR_INPUT         67

// Structure to store replys returned from a display

struct genieReplyStruct
{
  int cmd ;
  int object ;
  int index ;
  unsigned int data ;
} ;

// Structure to store replys returned from a display

struct genieMagicReplyStruct
{
  int cmd ;
  int index ;
  int length ;
  unsigned int data[100] ;
} ;

union FloatLongFrame {
    float floatValue;
    int32_t longValue;
    uint32_t ulongValue;
    int16_t wordValue[2];
};

// Globals (for debugging, mostly)

#ifdef	GENIE_DEBUG
extern int genieChecksumErrors  ;
extern int genieTimeouts ;
extern int genieAck ;
extern int genieNak ;
#endif



// Functions

#ifdef __cplusplus
extern "C" {
#endif

extern int  genieReplyAvail    		(void) ;

extern void genieGetReply      		(struct genieReplyStruct *reply) ;

extern int  genieReadObj       		(int object, int index) ;
extern int  genieWriteObj      		(int object, int index, unsigned int data) ;
extern int  genieWriteShortToIntLedDigits   (int index, int16_t data);
extern int  genieWriteLongToIntLedDigits    (int index, int32_t data);
extern int  genieWriteFloatToIntLedDigits   (int index, float data);
extern int  genieWriteContrast 		(int value) ;
extern int  genieWriteStr      		(int index, char *string) ;

extern int  genieWriteStrHex 		(int index, long n);
extern int  genieWriteStrDec 		(int index, long n);
extern int  genieWriteStrOct 		(int index, long n);
extern int  genieWriteStrBin 		(int index, long n);
extern int  genieWriteStrBase 		(int index, long n, int base);
extern int  genieWriteStrFloat 		(int index, float n, int precision);

extern int  genieWriteMagicBytes	(int magic_index, unsigned int *byteArray) ;
extern int  genieWriteDoubleBytes	(int magic_index, unsigned int *doubleByteArray) ;

extern int  genieSetup         (char *device, int baud) ;
extern void genieClose         (void) ;

#ifdef __cplusplus
}
#endif
