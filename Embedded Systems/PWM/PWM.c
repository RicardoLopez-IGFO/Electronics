//Prototipado
void PWM_CFG();                           //CONFIGURACIÓN DE LOS REGISTROS DEL PWM
void Ancho_Pulso(int ancho_useg);         //ANCHO DE PULSO
void Periodo(int t_useg);                 //PERIODO DE LA SEÑAL

void main()
{

    int i;
    PWM_CFG();
    Periodo(256);

    while(1)
    {
        for(i=0;i<=1000;i=i+100)
          {   Ancho_Pulso(i);  delay_ms(500);    }
    }
}


void PWM_CFG()
{
     CCP1CON.P1M1=0;            //PWM SINGLE OUTPUT, P1A MODULADA, P1B, P1C Y P1D COMO I/O
     CCP1CON.P1M0=0;
     CCP1CON.CCP1M3=1;          //MODO PWM P1A, P1C, P1B, P1D ACTIVAD EN ALTO.
     CCP1CON.CCP1M2=1;          //PRE-ESCALA DEL TIMER2 1:1

     PIR1.TMR2IF=0;             //LIMPIEZA DE LA BANDERA DE INTERRUPCIÓN DEL TRM2
     T2CON.TMR2ON=1;            //ACTIVACIÓN DEL TMR2
     TRISC.RC2=0;               //ACTIVACIÓN DE LA SALIDA DE LA TERMINAL
}

void Ancho_Pulso(int ancho)   //Ancho de Pulso
{
     //De 0 A 1023 PARTES EQUIVALENTES DE 0 A 100%
     //LA FRECUENCIA EN EL OSCILADOR ES DE 4 MHZ
     //SE CONSIDERA LA PRE-ESCALA DE TMR2 1:1

     CCP1CON|=((ancho&0x0003)<<4);
     CCPR1L=ancho>>2;
}

void Periodo(int t_useg)   //PERIODO DE LA SEÑAL
{
     //DE 1 A 256 MICROSEGUNDOS
     //LA FRECUENCIA EN EL OSCILADOR ES DE 4 MHZ
     //SE CONSIDERA LA PRE-ESCALA DEL TMR2 1:1
     PR2=(t_useg-1);
}