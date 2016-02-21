Version History
---------------
0.7 - forked to work with 16.5mhz clock and such
0.6 	-Added ability to easily select if this driver should use timer0 or
	  timer1.
	-Timer1 is now the default timer used. Used to be timer0.
	-Made the timer init happen later to allow this driver to work when
	  used with an attiny arduino library.
	-Fixed bug where a 512 microsecond pulse would not be generated.
	
0.5 	-Initial public release




Short Guide On How To Compile
------------------------------
1) Make sure you have WinAvr installed (http://winavr.sourceforge.net/)
2) open a CMD window and navigate to the Servo8Bit folder
3) type in "make" in the CMD window and the code will be compiled
3a) or make TARGET=programname
4) type  "make upload" to upload with micronucleus
4a) make upload  TARGET=programname
5) Remember to clean: make clean
5) make clean TARGET=programname

Note: Makefile assumes you have micronucleus installed  on your %PATH%
