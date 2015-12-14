#include "Adafruit-GFX-Library-master/Adafruit_GFX.h"
#include "Adafruit_SSD1306-master/Adafruit_SSD1306.h"

 Uncomment this block to use hardware SPI
#define OLED_DC     6
#define OLED_CS     7
#define OLED_RESET  8
Adafruit_SSD1306 display(OLED_DC, OLED_RESET, OLED_CS);

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2

#define LOGO16_GLCD_HEIGHT 16 
#define LOGO16_GLCD_WIDTH  16 
static const unsigned char PROGMEM logo16_glcd_bmp[] =
{ B00000000, B11000000,
  B00000001, B11000000,
  B00000001, B11000000,
  B00000011, B11100000,
  B11110011, B11100000,
  B11111110, B11111000,
  B01111110, B11111111,
  B00110011, B10011111,
  B00011111, B11111100,
  B00001101, B01110000,
  B00011011, B10100000,
  B00111111, B11100000,
  B00111111, B11110000,
  B01111100, B11110000,
  B01110000, B01110000,
  B00000000, B00110000 };
/*
int[] template;
int[] currentBlock;
int[] nextBlock;

generateBlock()
{
    //return random block;
}

init()
{
    currentBlock = generateBlock();
    nextBlock = generateBlock();
    //return picture + currentBlock + nextBlock;
}

addBlocks()

/**
 * Taget från display_image från mipslabfunc.c
 **//*
draw(int x, const uint8_t *data)
{
    int i, j;
	
	for(i = 0; i < 4; i++) {
		DISPLAY_CHANGE_TO_COMMAND_MODE;

		spi_send_recv(0x22);
		spi_send_recv(i);
		
		spi_send_recv(x & 0xF);
		spi_send_recv(0x10 | ((x >> 4) & 0xF));
		
		DISPLAY_CHANGE_TO_DATA_MODE;
		
		for(j = 0; j < 32; j++)
			spi_send_recv(~data[i*32 + j]);
	}
}
*/
main()
{
    /*
    int picture[] = init();
    draw(picture);
    while(1)
    {
        while(tickFlag)
        {
            draw(moveDown());
        }
        while(inputFlag)
        {
            switch input
            {
                case 1:
                    draw(moveLeft());
                    break;
                case 2:
                    draw(moveRight());
                    break;
                case 4:
                    draw(rotate());
                    break;
                case 8:
                    draw(putDown());
                    break;
                default:
                    break;
            }
        }
        while(collisionFlag)
        {
            
        }
    }
    * */
    Serial.begin(9600);
  
    // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
    display.begin(SSD1306_SWITCHCAPVCC);
    // init done
  
    // Show image buffer on the display hardware.
    // Since the buffer is intialized with an Adafruit splashscreen
    // internally, this will display the splashscreen.
    display.display();
    delay(2000);

    // Clear the buffer.
    display.clearDisplay();
}
