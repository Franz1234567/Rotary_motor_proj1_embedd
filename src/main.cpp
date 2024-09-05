// PART 1 MAIN

// #include <util/delay.h>
// #include <avr/io.h>

// int main(){
//   const uint8_t LED_PIN = (1 << 5); //  associate LED to pin 5
//   DDRB |= LED_PIN;
//   PORTB |= LED_PIN;

//   while(1){
//     _delay_ms(500); // blinks LED at 2Hz
//     PORTB ^= LED_PIN;
//   }
//   return 0;
// }

// ---------------------------------------------------------

// PART 2 MAIN

// #include <util/delay.h>
// #include <digital_out.h>

// int main()
// {
//   Digital_out led(5); 
  
//   led.init();

//   while (1){
//     _delay_ms(200);
//     led.toggle();
//   }

//   return 0;
// }

// ---------------------------------------------------------

// PART 3 MAIN

// #include <util/delay.h>
// #include <digital_out.h>
// #include <digital_in.h>

// int main()
// {
//   Digital_in button(4); // we  connect the button to pin 4
//   Digital_out led(5); // we connect the LED to pin 5 

//   button.init();
//   led.init();

//   while (1){
//     _delay_ms(1000);
//     if (button.is_lo()){ // Check if button is pressed
//       led.set_lo(); // It is pressed, so we turn the LED  off
//   }
//     else{
//       led.toggle(); //  it's not  pressed, we make  the LED blink
//     }
//   }
//   return 0;
// }


// Project 1 MAIN

// #include <util/delay.h>
// #include <digital_out.h>
// #include <digital_in.h>
// #include <encoder.h>
// #include <Arduino.h>

// int waiting_time_us = 140;

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
//       // Serial.println(encA.count);
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
//           led.toggle();
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
//           led.toggle();
//         }
//       }
//     }
//     last_state_A = curr_state_A;
//     last_state_B = curr_state_B;
//   }
// }

