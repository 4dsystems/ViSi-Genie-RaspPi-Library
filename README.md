![image](http://www.4dsystems.com.au/imagenes/header.png)

ViSi-Genie-RaspPi-Library
====================

4D Systems Raspberry Pi Library for Visi-Genie

Library for the Raspberry Pi to allow easy communication between 4D Intelligent Display modules running ViSi-Genie programmed from Workshop 4, and the Raspberry Pi.

This library is also required for the Raspberry Pi demo programs.


## Installation of Genie Pi Library on the Raspberry Pi
=======================================================

  make

  sudo make install

## To Uninstall Genie Pi Library
=================================

  sudo make uninstall
  

## To Install wiringPi library (Required for some applications/demos)
=====================================================================
  Connect your raspberry Pi up to the Internet and download WiringPi library from github:
  
  
  cd
  
  git clone git://git.drogon.net/wiringPi
  
  cd wiringPi
  
  ./build
  
  
  This will then download and install the wiringPi library
