#include <REGX52.H>

#define STROBE P0_6
#define ACK P0_7
#define BUTTON P3_2

void delay_ms(unsigned int ms)
{
    unsigned int i, j;
    for (i = 0; i < ms; i++)
        for (j = 0; j < 123; j++);
}

void display(unsigned char value)
{
    P1 = value;
}

void main()
{
    unsigned char dana = 8;
    
    P2 = 0xFF;      
    display(0xFF);  

    P1 = 0xFF;      

    STROBE = 1;     
    ACK = 1;        

    delay_ms(2000); 

    while (1)
    {
        if (BUTTON == 0) 
        {
            delay_ms(20); 
            if (BUTTON == 0)
            {
                P2 = dana;         
                P1 = 0x10 | dana;  

                delay_ms(2000);     

                STROBE = 0;        
                P1 = 0x00 | dana;  

                delay_ms(2000);    

                STROBE = 1;        
                P1 = 0x10 | dana;  

                while (ACK == 1);

                while (ACK == 0);

                delay_ms(2000);    
                P2 = 0xFF;
                P1 = 0xFF;
            }
        }
    }
}