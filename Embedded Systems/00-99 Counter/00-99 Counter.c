unsigned char U2=0; //Variable para las unidades
unsigned char D2=0; // Variable para las decenas
unsigned char TABLA[]={0x77,0x41,0x3B,0x6B,0x4D,0x6E,0x7E,0x43,0x7F,0x6F};


void conteo_down();                        //Cuenta descendente
void conteo_up();                          //Cuenta ascendente                         //Cuenta ascendente x3
void multiplexado(unsigned char veces);    //Multiplexado


void main()
{
  TRISC=0x00;     //Configurando el puerto "C" como salida
  TRISD=~0x03;    //Configurando bit 0 y 1 del puerto "D" como salida
  OPTION_REG = OPTION_REG & 0x7F,  //Activar "Weak pull-up"
  ANSELH=0x00;    //Configurando entradas digitales en PORTB
  PORTB=0x3F;     //Activando pull-ups

  while(1)
  {
      if(PORTB.RB0==1)  //DECENAS
      {
           if(PORTB.RB2==1)  //PLUS D2
           {     if(D2==9){}else{D2++;}    }
           else if(PORTB.RB3==1)  //MINUS D2
           {     if(D2==0){}else{D2--;}   }
      }
      else if(PORTB.RB1==1)  //UNIDADES
      {
           if(PORTB.RB2==1)  //PLUS U2
           {     if(U2==9){}else{U2++;}     }
           else if(PORTB.RB3==1)  //MINUS U2
           {     if(U2==0){}else{U2--;}     }
      }
     else if(PORTB&0x10)      //Estado del puerto Stop/RUN,  0=Stop, 1=RUN
     {
          conteo_up();
     }
     else       //Estado del botón Stop/RUN,  0=Stop, 1=RUN
     {
          conteo_down();
     }

     multiplexado(25);   //Multiplexado (1/5 segundo) y paro
  }
}



void conteo_up()
{
    U2++;
    if(U2==10)        //Unidades
    {
        U2=0;
        D2++;
        if(D2==10)     //Decenas
        {
          U2=0;   D2=0;
        }
    }
}

void conteo_down()
{
    if(U2==0)        //Unidades
    {
        U2=10;
        if(D2==0)     //Decenas
        {
          D2=10;    U2=10;
        }
        D2--;
    }
     U2--;
}



void multiplexado(unsigned char veces)
{
    PORTD.RD0=0;      //Cátodos deshabilitados
    PORTD.RD1=0;

    while(veces)
    {
       PORTC=TABLA[U2];     //Decodificación
       PORTD.RD1=1;               //Activación del cátodo de las unidades
       delay_ms(5);               //Retardo 5 milisegundos
       PORTD.RD1=0;

       PORTC=TABLA[D2];      //Decodificación
       PORTD.RD0=1;               //Activación del Cátodo de las decenas
       delay_ms(5);               //Retado 5 milisegundos
       PORTD.RD0=0;

       veces--;
    }
}