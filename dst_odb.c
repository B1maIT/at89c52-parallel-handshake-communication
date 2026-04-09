#include <REGX52.H>

#define STROBE P0_4
#define ACK P0_5

void delay_ms(unsigned int ms)
{
    unsigned int i, j;
    for (i = 0; i < ms; i++)
        for (j = 0; j < 123; j++);
}

void main()
{
    unsigned char odebrana;
    P1 = 0xFF; 
    ACK = 1;   
    delay_ms(2000); 

    while (1)
    {
        if (STROBE == 0)
        {
            P1 = 0xBF; 
            delay_ms(2000); 

            odebrana = P2;

            P1 = 0xA0 | (odebrana & 0x0F); 
            ACK = 0; 
            delay_ms(2000);
            ACK = 1;
            P1 = 0xFF;
        }
    }
}
	
