![image](http://www.4dsystems.com.au/downloads/4DLogo.png)

ViSi-Genie-RaspPi-Library
=========================

4D Systems Raspberry Pi Library for Visi-Genie

Library for the Raspberry Pi to allow easy communication between 4D Intelligent Display modules running ViSi-Genie programmed from Workshop 4, and the Raspberry Pi.

This library is also required for the Raspberry Pi demo programs.

## Genie Pi version 1.3 
-----
*	Added the following function:

	genieWriteShortToIntLedDigits   (int index, int16_t data)
	genieWriteLongToIntLedDigits    (int index, int32_t data)
	genieWriteFloatToIntLedDigits   (int index, float data)
	
*	Added numerous new objects to support Internal/Inherent Widgets in Workshop4	

## Genie Pi version 1.2 
-----
*	Added the following function:

	genieWriteStrHex	(int index, long n)
	genieWriteStrDec	(int index, long n)
	genieWriteStrOct	(int index, long n)
	genieWriteStrBin	(int index, long n)
	genieWriteStrBase	(int index, long n, int base)
	genieWriteStrFloat	(int index, float n, int precision)
	
## Genie Pi version 1.1 
-----
*	Added the following function:	
	genieWriteMagicBytes	(int magic_index, unsigned int *byteArray) 
	genieWriteDoubleBytes	(int magic_index, unsigned int *doubleByteArray)
	
* 	Added additional Struct : 
		genieMagicReplyStruct :	cmd, index, length, data[100]	

## Dependencies
-----
This section discusses the package requirements of the library

### WiringPi

* Connect your Raspberry Pi up to the Internet and install wiringPi:
	```  
	sudo apt install wiringpi
	```

* Please see here for more details (https://projects.drogon.net/raspberry-pi/wiringpi/download-and-install/)


## Installation
-----
This section discusses install and uninstall procedure for Genie Pi

### Install Genie Pi Library
```
make
sudo make install
```

### Uninstall Genie Pi Library
```
sudo make uninstall
```  

## Setup Raspberry Pi Serial UART hardware
-----

* In a default install of Raspbian, the primary UART is assigned to the Linux console. Using the serial port for other purposes requires this default behavour to be changed. On startup, systemd checks the Linux Kernal command line for any console entries, and will use the console defined therein. To stop this behavour, the serial console setting needs to be removed from the command line.

* This can be done by using the raspi-config utility, or manually.
	```
	sudo raspi-config
	```

* Select **Interfacing options**, then option **Serial**

* Select **No** to disable Console via Serial

* Select **Yes** to enable Serial hardware

* Exit Raspberry Pi Configuration

* To manually change the settings, edit the kernel command line with:
	```
	sudo nano /boot/cmdline.txt
	```

* Find the console entry the refers to the serial0 device, and remove it, including the baud rate setting. It will look something like: ```console=serial0,115200```

* Make sure the rest of the line remains the same, as errors in this configuration can stop the Raspberry Pi from booting.

* Reboot the Raspberry Pi for the change to take effect.

## Questions/Issues?

Please sign up for our Forum and ask a question there, or submit a Tech Support Ticket from our website.
http://forum.4dsystems.com.au or http://www.4dsystems.com.au/support
