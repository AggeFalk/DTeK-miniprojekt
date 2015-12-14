//Kodskelet, ej syntaktiskt korrekt.
int background[128];
Block currentBlock;
Block nextBlock;

void main(){
    while(true){
        //@tickFlag flaggar typ varje sekund
        while(tickFlag){
            moveDown()
        }
        //@inputFlag flaggas när användaren trycker på något
        while(inputFlag){
            switch input{
                case 1:
                    moveLeft();
                    break;
                case 2:
                    moveRight();
                    break;
                case 4:
                    rotate();
                    break;
                case 8:
                    putDown();
                    break;
            }
        }
    }
}