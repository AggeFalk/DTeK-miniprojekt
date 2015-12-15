#include <stdint.h>   
#include <pic32mx.h>  
#include "mipslab.h" 
//Kodskelet, ej syntaktiskt korrekt.
int background[128];

<<<<<<< HEAD
/*private helper method to fill list*/
void fillist(){
	int list[] = {1,4,5,6,3,2,0,2,4,5,0,3,0,1,4,3,6,1,3,5};
}


int main(){
	//SETUP
	/* Set up peripheral bus clock */
        /* OSCCONbits.PBDIV = 1; */
        OSCCONCLR = 0x100000; /* clear PBDIV bit 1 */
	OSCCONSET = 0x080000; /* set PBDIV bit 0 */
	
	/* Set up output pins */
	AD1PCFG = 0xFFFF;
	ODCE = 0x0;
	TRISECLR = 0xFF;
	PORTE = 0x0;
	
	/* Output pins for display signals */
	PORTF = 0xFFFF;
	PORTG = (1 << 9);
	ODCF = 0x0;
	ODCG = 0x0;
	TRISFCLR = 0x70;
	TRISGCLR = 0x200;
	
	/* Set up input pins */
	TRISDSET = (1 << 8);
	TRISFSET = (1 << 1);
	
	/* Set up SPI as master */
	SPI2CON = 0;
	SPI2BRG = 4;
	/* SPI2STAT bit SPIROV = 0; */
	SPI2STATCLR = 0x40;
	/* SPI2CON bit CKP = 1; */
        SPI2CONSET = 0x40;
	/* SPI2CON bit MSTEN = 1; */
	SPI2CONSET = 0x20;
	/* SPI2CON bit ON = 1; */
	SPI2CONSET = 0x8000;

	display_init();
	timer_init();
	fillist();
	//END SETUP
	
       



void main(){
     while(1){     
	    int input = getbtns();
            switch (input){
                case 1:
                    putDown();
                    break;
                case 2:
                    moveRight();
                    break;
                case 4:
                    rotate();
                    break;
                case 8:
                    moveLeft();
                    break;
           
            }
        }

	return 0;
    }
}
