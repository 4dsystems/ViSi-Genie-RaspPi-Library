#!/usr/bin/env python

from setuptools import setup, find_packages

setup(name='geniePi',
      version='1.0',
      description='Python bindings for the ViSi-Genie-RaspPi-Library, a C library for interfacing 4D Systems displays with a Raspberry Pi',
      author='David Michel',
      author_email='dmichel76@googlemail.com',
      url='https://github.com/dmichel76/ViSi-Genie-RaspPi-Library',
      py_modules=['geniePi'],
      data_files=[('.',['_geniePi.so'])],
     )
