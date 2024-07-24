//Nombre: Meneses López Arisai Ricardo
unsigned char cuenta,a,b,c1;
unsigned char Secuencia1[]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};
unsigned char Secuencia2[]={0x01,0x03,0x07,0x0F,0x1F,0x3F,0x7F,0xFF};
void main()
{
              TRISC=0x00;
              TRISB=0x00;
              TRISA=0x00;
              while(1)
              {
              PORTC=0; PORTA=0; PORTB=0; PORTD=0; a=0;b=0;c1=0;
              for(cuenta=0;cuenta!=20;cuenta++)
              {
                   if(cuenta<8)
                   {
                    PORTB=Secuencia1[b];
                    delay_ms(200);         //Retraso 1/10 segundo
                    b++;
                   }
                   else if(cuenta<16)
                   {
                    PORTB=0;
                    PORTA=Secuencia1[a];
                    delay_ms(200);         //Retraso 1/10 segundo
                    a++;
                   }
                   else
                   {
                    PORTA=0;
                    PORTC=Secuencia1[c1];
                    delay_ms(200);         //Retraso 1/10 segundo
                    c1++;
                   }
              }
              PORTC=0; a=0;b=0;c1=0;
              for(cuenta=0;cuenta!=20;cuenta++)
              {
                   if(cuenta<8)
                   {
                    PORTB=Secuencia2[b];
                    delay_ms(100);         //Retraso 1/10 segundo
                    b++;
                   }
                   else if(cuenta<16)
                   {
                    PORTA=Secuencia2[a];
                    delay_ms(100);         //Retraso 1/10 segundo
                    a++;
                   }
                   else
                   {
                    PORTC=Secuencia2[c1];
                    delay_ms(100);         //Retraso 1/10 segundo
                    c1++;
                   }
              }
              a=7;b=7;c1=3;
              for(cuenta=0;cuenta!=20;cuenta++)
              {
                   if(cuenta<3)
                   {
                    c1--;
                    PORTC=Secuencia2[c1];
                    delay_ms(100);         //Retraso 1/10 segundo
                   }
                   else if(cuenta<11)
                   {
                    PORTC=0;
                    PORTA=Secuencia2[a];
                    a--;
                    delay_ms(100);         //Retraso 1/10 segundo
                   }
                   else
                   {
                    PORTA=0;
                    PORTB=Secuencia2[b];
                    b--;
                    delay_ms(100);         //Retraso 1/10 segundo
                   }
              }
              }
}