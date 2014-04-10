![image](http://www.4dsystems.com.au/imagenes/header.png)

ViSi-Genie-RaspPi-Library
====================

4D Systems Raspberry Pi Library for Visi-Genie

Library for the Raspberry Pi to allow easy communication between 4D Intelligent Display modules running ViSi-Genie programmed from Workshop 4, and the Raspberry Pi.

This library is also required for the Raspberry Pi demo programs.

This is C library with a Pythn bindings that uses the compiled shared library.


## Installation of Genie Pi Library on the Raspberry Pi
=======================================================

  It is necessary to install swig prior to attempt the installtion as it is the tool used to generate the python binding.

  sudo apt-get install swig
  
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

* Please see here for more detail if you need to install git also (https://projects.drogon.net/raspberry-pi/wiringpi/download-and-install/)
  

## Disable Linux from using the Pi Serial Port so the GeniePi library can instead
=================================================================================
* From terminal, launch leafpad (or your chosen editor) with root:

  sudo leafpad

* Nagivate to /boot/cmdline.txt and remove the following text (LEAVE everything else intact)

  kgdboc=ttyAMA0,115200 console=tty1  
  
* Save the file, overwriting the existing one.
  
* Navigate and edit /etc/inittab
  
* Comment out the bottom line by putting a '#' symbol at the start of it, where the bottom line is:
  
  T0:23:respawn:/sbin/getty -L ttyAMA0 115200 vt100
  
* Save the file, overwriting the existing one
  
* Reboot your Raspberry Pi
