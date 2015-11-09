/* ------------------------------------------------------------ */
/*** OledDspInit
**
** Parameters:
** none
**
** Return Value:
** none
**
** Errors:
** none
**
** Description:
** Initialize the OLED display controller and turn the display on.
*/
void
OledDspInit()
 {
 /* We're going to be sending commands, so clear the Data/Cmd bit
 */
 PORTClearBits(prtDataCmd, bitDataCmd);
 /* Start by turning VDD on and wait a while for the power to come up.
 */
 PORTClearBits(prtVddCtrl, bitVddCtrl);
 DelayMs(1);
 /* Display off command
 */
 Spi2PutByte(0xAE);
 /* Bring Reset low and then high
 */
 PORTClearBits(prtReset, bitReset);
 DelayMs(1);
 PORTSetBits(prtReset, bitReset);
 /* Send the Set Charge Pump and Set Pre-Charge Period commands
 */
 Spi2PutByte(0x8D);
 Spi2PutByte(0x14);
 Spi2PutByte(0xD9);
 Spi2PutByte(0xF1);
 /* Turn on VCC and wait 100ms
 */
 PORTClearBits(prtVbatCtrl, bitVbatCtrl);
 DelayMs(100);
 /* Send the commands to invert the display. This puts the display origin
 ** in the upper left corner.
 */ 
 Spi2PutByte(0xA1); //remap columns
 Spi2PutByte(0xC8); //remap the rows
 /* Send the commands to select sequential COM configuration. This makes the
 ** display memory non-interleaved.
 */
 Spi2PutByte(0xDA); //set COM configuration command
 Spi2PutByte(0x20); //sequential COM, left/right remap enabled
 /* Send Display On command
 */
 Spi2PutByte(0xAF);
}

/* -------------------------------------------------------------------------------------*/
/* -------------------------------------------------------------------------------------*/
/*** OledHostInit
**
** Parameters:
** none
**
** Return Value:
** none
**
** Errors:
** none
**
** Description:
** Perform PIC32 device initialization to prepare for use
** of the OLED display.
** This example is hard coded for the chipKIT Uno32 and
** SPI2.
*/
void
OledHostInit()
 {
 unsigned int tcfg;
 /* Initialize SPI port 2.
 */
 SPI2CON = 0;
 SPI2BRG = 15; //8Mhz, with 80Mhz PB clock
 SPI2STATbits.SPIROV = 0;
 SPI2CONbits.CKP = 1;
 SPI2CONbits.MSTEN = 1;
 SPI2CONbits.ON = 1;
 /* Make pins RF4, RF5, and RF6 be outputs.
 */
 PORTSetBits(IOPORT_F, bitVddCtrl|bitVbatCtrl|bitDataCmd);
 PORTSetPinsDigitalOut(prtDataCmd, bitDataCmd); //Data/Command# select
 PORTSetPinsDigitalOut(prtVddCtrl, bitVddCtrl); //VDD power control (1=off)
 PORTSetPinsDigitalOut(prtVbatCtrl, bitVbatCtrl); //VBAT power control (1=off)
 /* Make the RG9 pin be an output. On the Basic I/O Shield, this pin
 ** is tied to reset.
 */
 PORTSetBits(prtReset, bitReset);
 PORTSetPinsDigitalOut(prtReset, bitReset);
} 
