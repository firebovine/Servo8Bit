// Servo8Bit cowhat controller
// firebovine!
// based on example by Ilya Brutman

#include "Servo8Bit.h"
#include <stdlib.h>

void delay(uint16_t milliseconds);  //forward declaration to the delay function
Servo8Bit setupServo(uint8_t controlPin, uint8_t powerPin);
void loopityLoop(Servo8Bit rightEar, Servo8Bit leftEar);

int main()
{
  srandom(42); // seed the answer to the generator
  Servo8Bit rightEar = setupServo(0, 2);
  Servo8Bit leftEar = setupServo(1, 3);
  loopityLoop(rightEar, leftEar);
}

Servo8Bit setupServo(uint8_t controlPin, uint8_t powerPin)
{
  Servo8Bit myServo;
  myServo.attach(controlPin, powerPin, 600, 2200);
  myServo.write(170);
  delay(250);
  myServo.powerOff();
  return myServo;
}
  

void loopityLoop(Servo8Bit rightEar, Servo8Bit leftEar)
{
  while ( 1==1 )
  {
    Servo8Bit myServos[2];
    myServos[0] =  rightEar;
    myServos[1] =  leftEar;
    int myEar = ( random() % 2 );
    int myRandom = ( random() % 10 ) * 1000;
    delay(myRandom); // delay between 0 and 10 seconds
    myServos[myEar].powerOn();
    myServos[myEar].write(80);   //rotate to the 45 degree position
    delay(500);
    myServos[myEar].write(170);   //rotate to the 45 degree position
    delay(500);
    myServos[myEar].powerOff();
  }
}

void delayMicroseconds(uint16_t us)
{
#if F_CPU >= 16000000L
    // for the 16 MHz clock on most Arduino boards

    // for a one-microsecond delay, simply return.  the overhead
    // of the function call yields a delay of approximately 1 1/8 us.
    if (--us == 0)
        return;

    // the following loop takes a quarter of a microsecond (4 cycles)
    // per iteration, so execute it four times for each microsecond of
    // delay requested.
    us <<= 2;

    // account for the time taken in the preceeding commands.
    us -= 2;
#else
    // for the 8 MHz internal clock on the ATmega168

    // for a one- or two-microsecond delay, simply return.  the overhead of
    // the function calls takes more than two microseconds.  can't just
    // subtract two, since us is unsigned; we'd overflow.
    if (--us == 0)
        return;
    if (--us == 0)
        return;

    // the following loop takes half of a microsecond (4 cycles)
    // per iteration, so execute it twice for each microsecond of
    // delay requested.
    us <<= 1;

    // partially compensate for the time taken by the preceeding commands.
    // we can't subtract any more than this or we'd overflow w/ small delays.
    us--;
#endif

    // busy wait
    __asm__ __volatile__ (
        "1: sbiw %0,1" "\n\t" // 2 cycles
        "brne 1b" : "=w" (us) : "0" (us) // 2 cycles
    );
}//end delayMicroseconds

void delay(uint16_t milliseconds)
{
    for(uint16_t i = 0; i < milliseconds; i++)
    {
        delayMicroseconds(1000);
    }
}//end delay
