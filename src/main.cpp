// PART 1 and 2 MAIN

// #include <util/delay.h>
// #include <digital_out.h>
// #include <digital_in.h>
// #include <encoder.h>
// #include <Arduino.h>

// int waiting_time_us = 280; // 280 for only one encoder, 140 us for both of them

// int main(){
//   Serial.begin(9600);
//   Encoder encA(1);
//   Encoder encB(2);

//   Digital_out led(5);
//   led.init();

//   bool last_state_A = encA.is_low();
//   bool last_state_B = encB.is_low();
//   bool curr_state_A;
//   bool curr_state_B;

//   while(1){
//     while((last_state_A == encA.is_low()) && (last_state_B == encB.is_low())){

//     }
//     // _delay_us(waiting_time_us);
//     // if(encA.count % 100 == 0){
//       Serial.println(encA.count);
//     // }

//     if(last_state_A == last_state_B){
//       curr_state_A = encA.is_low();
//       if(curr_state_A != last_state_A){
//         encA.count++;
//         led.toggle();
//       }
//       else{ 
//         curr_state_B  = encB.is_low();
//         if(curr_state_B != last_state_B){
//           encA.count--;
//         //   led.toggle();
//         }
//       }
//     }
//     else{
//       curr_state_A = encA.is_low();
//       if(curr_state_A != last_state_A){
//         encA.count--;
//         led.toggle();
//       }
//       else{ 
//         curr_state_B  = encB.is_low();
//         if(curr_state_B != last_state_B){
//           encA.count++;
//         //   led.toggle();
//         }
//       }
//     }
//     last_state_A = curr_state_A;
//     last_state_B = curr_state_B;
//   }
// }

// PART 3 MAIN

#include <timer_msec.h>
#include <encoder.h>
#include <digital_out.h>
#include <avr/interrupt.h>

Encoder encA(1);
Encoder encB(2);

Digital_out led(5);

int waiting_time_us = 280;
bool last_state_A = encA.is_low();
bool last_state_B = encB.is_low();
bool curr_state_A;
bool curr_state_B;

Timer_msec timer;

int  main(){
    led.init();
    timer.init(waiting_time_us);
    sei();
    
    while(1){

    }
}

ISR(TIMER1_COMPA_vect)
{
    if(last_state_A == last_state_B){
      curr_state_A = encA.is_low();
      if(curr_state_A != last_state_A){
        encA.count++;
        led.toggle();
      }
      else{ 
        curr_state_B  = encB.is_low();
        if(curr_state_B != last_state_B){
          encA.count--;
          led.toggle();
        }
      }
    }
    else{
      curr_state_A = encA.is_low();
      if(curr_state_A != last_state_A){
        encA.count--;
        led.toggle();
      }
      else{ 
        curr_state_B  = encB.is_low();
        if(curr_state_B != last_state_B){
          encA.count++;
          led.toggle();
        }
      }
    }
    last_state_A = curr_state_A;
    last_state_B = curr_state_B;
  }

