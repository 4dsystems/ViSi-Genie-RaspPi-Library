![image](http://www.4dsystems.com.au/downloads/4DLogo.png)

ViSi-Genie-RaspPi-Library
====================

4D Systems Raspberry Pi Library for Visi-Genie

Library for the Raspberry Pi to allow easy communication between 4D Intelligent Display modules running ViSi-Genie programmed from Workshop 4, and the Raspberry Pi.

This library is also required for the Raspberry Pi demo programs.

## Genie Pi version 1.3 
=======================================================
*	Added the following function:

	genieWriteShortToIntLedDigits   (int index, int16_t data)
	genieWriteLongToIntLedDigits    (int index, int32_t data)
	genieWriteFloatToIntLedDigits   (int index, float data)
	
*	Added numerous new objects to support Internal/Inherent Widgets in Workshop4	

## Genie Pi version 1.2 
=======================================================
*	Added the following function:

	genieWriteStrHex	(int index, long n)
	genieWriteStrDec	(int index, long n)
	genieWriteStrOct	(int index, long n)
	genieWriteStrBin	(int index, long n)
	genieWriteStrBase	(int index, long n, int base)
	genieWriteStrFloat	(int index, float n, int precision)
	
## Genie Pi version 1.1 
=======================================================
*	Added the following function:	
	genieWriteMagicBytes	(int magic_index, unsigned int *byteArray) 
	genieWriteDoubleBytes	(int magic_index, unsigned int *doubleByteArray)
	
* 	Added additional Struct : 
		genieMagicReplyStruct :	cmd, index, length, data[100]	

		
		

## Installation of Genie Pi Library on the Raspberry Pi
=======================================================

  make

  sudo make install

## To Uninstall Genie Pi Library
=================================

  sudo make uninstall
  

## To Install wiringPi library (Required for some applications/demos)
=====================================================================
* Connect your raspberry Pi up to the Internet and download WiringPi library from github:
  
  
  cd
  
  git clone git://git.drogon.net/wiringPi
  
  cd wiringPi
  
  ./build
  
  
* This will then download and install the wiringPi library, assuming you have git installed on your Raspberry Pi already.

* If you encounter an error such as: error while loading shared libraries: libgeniePi.so: cannot open shared object file: No such file or directory
do the following:

  sudo ldconfig -v

This should solve the problem

* Please see here for more detail if you need to install git also (https://projects.drogon.net/raspberry-pi/wiringpi/download-and-install/)
  

## Disable Linux from using the Pi Serial Port so the GeniePi library can instead
=================================================================================
* In a default install of Raspbian, the primary UART (serial0) is assigned to the Linux console. Using the serial port for other purposes requires this default behavour to be changed. On startup, systemd checks the Linux Kernal command line for any console entries, and will use the console defined therein. To stop this behavour, the serial console setting needs to be removed from the command line.
* This can be done by using the raspi-config utility, or manually.

  sudo raspi-config

* Select option 5, interfacing options, then option P6, Serial, and then select No. Exit Raspi-config.

* To manually change the settings, edit the kernel command line with:

  sudo nano /boot/cmdline.txt

* Find the console entry the refers to the serial0 device, and remove it, including the baud rate setting. It will look something like:

  console=serial0,115200

* Make sure the rest of the line remains the same, as errors in this configuration can stop the Raspberry Pi from booting.

* Reboot the Raspberry Pi for the change to take effect.


## Questions/Issues?

Please sign up for our Forum and ask a question there, or submit a Tech Support Ticket from our website.
http://forum.4dsystems.com.au or http://www.4dsystems.com.au/support
