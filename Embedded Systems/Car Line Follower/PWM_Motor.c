unsigned short current_duty, old_duty, current_duty1, old_duty1;
void InitMain();
void InitMain() {
  ANSEL  = 0;                         // Configure AN pins as digital
  ANSELH = 0; 
  C1ON_bit = 0;                       // Disable comparators
  C2ON_bit = 0;    
  PORTA = 255;
  TRISA = 255;                        // configure PORTA pins as input
  PORTB = 0x00;                          // set PORTB to 0
  PORTD = 0xFF;                          // designate PORTB pins as output
  PORTC = 0;                          // set PORTC to 0
  TRISC = 0;                          // designate PORTC pins as output
  PWM1_Init(5000);                    // Initialize PWM1 module at 5KHz
  PWM2_Init(5000);
  
 }                 // Initialize PWM2 module at 5KHz}
 



void main() { 
 InitMain();
  //ANSEL  = 0;                         // Configure AN pins as digital
  //ANSELH = 0;  //C1ON_bit = 0;                       // Disable comparators
  //C2ON_bit = 0;
 // PWM1_Init(5000);                    // Initialize PWM1 module at 5KHz
 // PWM2_Init(5000);
  current_duty  = 16;                 // initial value for current_duty
  current_duty1 = 16;                 // initial value for current_duty1
  PWM1_Start();                       // start PWM1
  PWM2_Start();                       // start PWM2
  PWM1_Set_Duty(current_duty);        // Set current duty for PWM1
  PWM2_Set_Duty(current_duty1);       // Set current duty for PWM2

  while (1) {                         // endless loop

     PWM1_Set_Duty(current_duty);
     PWM2_Set_Duty(current_duty1);

     if(current_duty>=255&&current_duty1>=255)
     {   current_duty=16;  current_duty1=16; }
     else{  current_duty++; current_duty1++; }
     delay_ms(40);
     
     if(PORTD.RD3==1)
     {
      PORTB.RB0 = 1;
      PORTB.RB1 = 0;
     }
     else if(PORTD.RD2==1)
     {
      PORTB.RB0 = 0;
      PORTB.RB1 = 1;
     }
     
    }
    
    
    
    }                    // slow down change pace a little  }}