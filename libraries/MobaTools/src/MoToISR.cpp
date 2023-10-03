/*
  MobaTools.h - a library for model railroaders
  Author: fpm, fpm@mnet-mail.de
  Copyright (c) 2019 All right reserved.

  ISR for stepper and softleds
*/

#include <MobaTools.h>

// Debug-defines
#include <MoToDbg.h>

#ifdef debugPrint
     const char *rsC[] = { "INACTIVE", "STOPPED", "RAMPSTART", "RAMPACCEL", "CRUISING", "STARTDECEL", "RAMPDECEL", "SPEEDDECEL" };    
#endif
void stepperISR(uint8_t cyclesLastIRQ) __attribute__ ((weak));
void softledISR(uint8_t cyclesLastIRQ) __attribute__ ((weak));

uint8_t nextCycle;
static uint8_t cyclesLastIRQ = 1;  // cycles since last IRQ

// ---------- OCRxB Compare Interrupt used for stepper motor and Softleds ----------------
#ifdef __AVR_MEGA__
ISR ( TIMERx_COMPB_vect) {
    uint16_t tmp;
#elif defined __STM32F1__
void ISR_Stepper(void) {
#endif
  // Timer1 Compare B, used for stepper motor, starts every CYCLETIME us
    // 26-09-15 An Interrupt is only created at timeslices, where data is to output
    SET_TP1;
    nextCycle = TIMERPERIODE  / CYCLETIME ;// min ist one cycle per Timeroverflow
    if ( stepperISR ) stepperISR(cyclesLastIRQ);
    //============  End of steppermotor ======================================
   if ( softledISR ) softledISR(cyclesLastIRQ);
    // ======================= end of softleds =====================================
    cyclesLastIRQ = nextCycle;
    // set compareregister to next interrupt time;
    // compute next IRQ-Time in us, not in tics, so we don't need long
    #ifdef __AVR_MEGA__
    //noInterrupts(); // when manipulating 16bit Timerregisters IRQ must be disabled
    if ( nextCycle == 1 )  {
        // this is timecritical: Was the ISR running longer then CYCELTIME?
        // compute length of current IRQ ( which startet at OCRxB )
        // we assume a max. runtime of 1000 Tics ( = 500�s , what nevver should happen )
        tmp = GET_COUNT - OCRxB ;
        if ( tmp > 1000 ) tmp += TIMER_OVL_TICS; // there was a timer overflow
        if ( tmp > (CYCLETICS-10) ) {
            // runtime was too long, next IRQ mus be started immediatly
            SET_TP3;
            tmp = GET_COUNT+10; 
        } else {
            tmp = OCRxB + CYCLETICS;
        }
        OCRxB = ( tmp > TIMER_OVL_TICS ) ? tmp -= TIMER_OVL_TICS : tmp ;
    } else {
        // time till next IRQ is more then one cycletime
        // compute next IRQ-Time in us, not in tics, so we don't need long
        tmp = ( OCRxB / TICS_PER_MICROSECOND + nextCycle * CYCLETIME );
        if ( tmp > TIMERPERIODE ) tmp = tmp - TIMERPERIODE;
        OCRxB = tmp * TICS_PER_MICROSECOND;
    }
    #elif defined __STM32F1__
    long tmpL = ( timer_get_compare(MT_TIMER, STEP_CHN) + nextCycle * CYCLETICS );
    if ( tmpL > TIMER_OVL_TICS ) tmpL = tmpL - TIMER_OVL_TICS;
    timer_set_compare( MT_TIMER, STEP_CHN, tmpL ) ;
    #endif
    CLR_TP1; // Oszimessung Dauer der ISR-Routine
}
