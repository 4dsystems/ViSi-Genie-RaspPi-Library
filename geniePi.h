/*
 * geniePi.h:
 *	Library to utilise the 4D Systems Genie interface to displays
 *	that have been created using the Visi-Genie creator platform.
 *	Primarily aimed at the Raspberry Pi, however this may be used
 *	on most Linux platforms with a serial connection (USB on
 *	on-board) to the 4D Systems Intelligent displays.
 *
 *	Gordon Henderson, December 2012, <projects@drogon.net>
 *	Copyright (c) 2012 4D Systems PTY Ltd, Sydney, Australia
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

#define	GENIE_READ_OBJ		0
#define	GENIE_WRITE_OBJ		1
#define	GENIE_WRITE_STR		2
#define	GENIE_WRITE_STRU	3
#define	GENIE_WRITE_CONTRAST	4
#define	GENIE_REPORT_OBJ	5
#define	GENIE_REPORT_EVENT	7

// Objects
//	the manual says:
//		Note: Object IDs may change with future releases; it is not
//		advisable to code their values as constants.

#define	GENIE_OBJ_DIPSW		 0
#define	GENIE_OBJ_KNOB		 1
#define	GENIE_OBJ_ROCKERSW	 2
#define	GENIE_OBJ_ROTARYSW	 3
#define	GENIE_OBJ_SLIDER	 4
#define	GENIE_OBJ_TRACKBAR	 5
#define	GENIE_OBJ_WINBUTTON	 6
#define	GENIE_OBJ_ANGULAR_METER	 7
#define	GENIE_OBJ_COOL_GAUGE	 8
#define	GENIE_OBJ_CUSTOM_DIGITS	 9
#define	GENIE_OBJ_FORM		10
#define	GENIE_OBJ_GAUGE		11
#define	GENIE_OBJ_IMAGE		12
#define	GENIE_OBJ_KEYBOARD	13
#define	GENIE_OBJ_LED		14
#define	GENIE_OBJ_LED_DIGITS	15
#define	GENIE_OBJ_METER		16
#define	GENIE_OBJ_STRINGS	17
#define	GENIE_OBJ_THERMOMETER	18
#define	GENIE_OBJ_USER_LED	19
#define	GENIE_OBJ_VIDEO		20
#define	GENIE_OBJ_STATIC_TEXT	21
#define	GENIE_OBJ_SOUND		22
#define	GENIE_OBJ_TIMER		23

// Structure to store replys returned from a display

struct genieReplyStruct
{
  int cmd ;
  int object ;
  int index ;
  unsigned int data ;
} ;

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

extern int  genieReplyAvail    (void) ;
extern void genieGetReply      (struct genieReplyStruct *reply) ;

extern int  genieReadObj       (int object, int index) ;
extern int  genieWriteObj      (int object, int index, unsigned int data) ;
extern int  genieWriteContrast (int value) ;
extern int  genieWriteStr      (int index, char *string) ;

extern int  genieSetup         (char *device, int baud) ;
extern void genieClose         (void) ;

#ifdef __cplusplus
}
#endif
