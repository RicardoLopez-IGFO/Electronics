unsigned char cuenta;
void interrupt();

void main() 
{
    OPTION_REG.T0CS=0;     //CONTADOR INTERNO (MODO TIMER)
    OPTION_REG.T0SE=1;     //FLANCO DE BAJADA
    OPTION_REG.PSA=1;      //ASIGNACIÓN DEL PRE-ESCALADOR PARA EL WDT -
                           //- POR LO TANTO EL PRE-ESCALADOR NO FUNCIONA PARA EL TMR0
    OPTION_REG.PS2=1;      //DEBIDO A LO ANTERIOR PRE-ESCALA 1:1
    OPTION_REG.PS1=1;
    OPTION_REG.PS0=1;
    
    INTCON.GIE=1;
    INTCON.T0IE=1;
    TMR0=0x00;
    
    TRISC.RC0=0;
    PORTC.RC0=0;
    
    while(1)
    {
        PORTC=TMR0IF;     //interrupt();
    }
}

void interrupt()
{
     if(INTCON.TMR0IF)
     {
       cuenta++;
       if(cuenta==7)
       {
        cuenta=0;
        PORTC.RC0=~PORTC.RC0;
        INTCON.TMR0IF=0;          //LIMPIAR BANDERA DE INTERRUPCION DEL TMR0
       }
       INTCON.TMR0IF=0;           //LIMPIAR BANDERA DE INTERRUPCIÓN DEL TMR0
     }
     else if(INTCON.RBIF)
     {
         INTCON.RBIF=0;
     }
}