//Smart hantering av blocks
Block struct{
    int* placement = 91;
    int[64] pixels;
} stick, square, podium, Lzig, Rzig, Ll, Rl;

SimpleBlock struct{
    int indent = 2;
    int[4][4] pixels;
} simpleStick, simpleSquare, simplePodium, Lzig, Rzig, Ll, Rl;

simpleStick.pixels =    {{1,0,0,0},
                         {1,0,0,0},
                         {1,0,0,0},
                         {1,0,0,0}};

//index<index+4 är helt fel!
Block generateBlock(SimpleBlock sb){
    Block block;
    int index = 0;
    int empty = sb.indent;
    while(empty>=2){
        for(;index<index+16;index++){
            block.pixels[index] = 0;
        }
        empty -= 2;
    }
    if(empty%2!=0){//==1,-1,-3 etc.
        for(int j=(empty*-1;j<4;j++){
            if(sb.pixels[0][j]==1){
                for(;index<index+4;index++){
                    block.pixels[index] = 240;
                }
            }
            else if(sb.pixels[0][j]==0){
                for(;index<index+4;index++){
                    block.pixels[index] = 0;
                }
            }
        }
        for(int j=(empty*-1;j<4;j++){
            if(sb.pixels[1][j]==1&&sb.pixels[2][j]==1){
                for(;index<index+4;index++){
                    block.pixels[index] = 255;
                }
            }
            else if(sb.pixels[1][j]==0&&sb.pixels[2][j]==1){
                for(;index<index+4;index++){
                    block.pixels[index] = 240;
                }
            }
            else if(sb.pixels[1][j]==1&&sb.pixels[2][j]==0){
                    for(;index<index+4;index++){
                        block.pixels[index] = 15;
                    }
                }
            else{
                for(;index<index+4;index++){
                    block.pixels[index] = 0;
                }
            }
        }
        for(int j=(empty*-1;j<4;j++){
            if(sb.pixels[3][j]==1){
                for(;index<index+4;index++){
                    block.pixels[index] = 15;
                }
            }
            else if(sb.pixels[3][j]==0){
                for(;index<index+4;index++){
                    block.pixels[index] = 0;
                }
            }
        }
        for(int j=(empty*-1);j>0;j--){
            for(;index<index+4;index++){
                block.pixels[index] = 0;
            }
        }
    }
    else{//empty == 0
        for(int i=0;i<4;i+=2){
            for(int j=(empty*-1);j<4;j++){
                if(sb.pixels[i][j]==1&&sb.pixels[i+1][j]==1){
                    for(;index<index+4;index++){
                        block.pixels[index] = 255;
                    }
                }
                else if(sb.pixels[i][j]==0&&sb.pixels[i+1][j]==1){
                    for(;index<index+4;index++){
                        block.pixels[index] = 240;
                    }
                }
                else if(sb.pixels[i][j]==1&&sb.pixels[i+1][j]==0){
                    for(;index<index+4;index++){
                        block.pixels[index] = 15;
                    }
                }
                else{
                    for(;index<index+4;index++){
                        block.pixels[index] = 0;
                    }
                }
            }
            for(int j=(empty*-1);j>0;j--){
                for(;index<index+4;index++){
                    block.pixels[index] = 0;
                }
            }
        }
    }
}

/**
 * 2
 * [1000
 *  1000
 *  1000
 *  1000]
 */
stick.pixels = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                255,255,255,255,0,0,0,0,0,0,0,0,0,0,0,0,
                255,255,255,255,0,0,0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                };
/**
 * [0000
 *  0000
 *  0110
 *  0110]
 */
square.pixels = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},
                    {240,240,0,0},{240,240,0,0},{240,240,0,0},{240,240,0,0},
                    {15,15,0,0},{15,15,0,0},{15,15,0,0},{15,15,0,0},
                    {0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}
                };
/**
 * [0000
 *  0000
 *  0100
 *  1110]
 */
podium.pixels = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},
                    {255,240,0,0},{255,240,0,0},{255,240,0,0},{255,240,0,0},
                    {15,0,0,0},{15,0,0,0},{15,0,0,0},{15,0,0,0},
                    {0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}
                };
/**
 * [0000
 *  0000
 *  0110
 *  1100]
 */
Lzig.pixels = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},
                    {255,240,0,0},{255,240,0,0},{255,240,0,0},{255,240,0,0},
                    {0,15,0,0},{0,15,0,0},{0,15,0,0},{0,15,0,0},
                    {0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}
                };
/**
 * [0000
 *  0000
 *  0110
 *  0011]
 */
Rzig.pixels = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},
                    {0,240,0,0},{0,240,0,0},{0,240,0,0},{0,240,0,0},
                    {255,15,0,0},{255,15,0,0},{255,15,0,0},{255,15,0,0},
                    {0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}
                };
/**
 * [0000
 *  0010
 *  0010
 *  0110]
 */
Ll.pixels = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},
                {240,0,0,0},{240,0,0,0},{240,0,0,0},{240,0,0,0},
                {15,15,15,0},{15,15,15,0},{15,15,15,0},{15,15,15,0},
                {0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}
            };
/**
 * [0000
 *  0100
 *  0100
 *  0110]
 */
Rl.pixels = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},
                {240,240,240,0},{240,240,240,0},{240,240,240,0},{240,240,240,0},
                {15,0,0,0},{15,0,0,0},{15,0,0,0},{15,0,0,0},
                {0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}
            };

void moveDown(){
    currentBlock.placement -= 1;
    if(collision()){
        currentBlock.placement += 1;
    }
    draw();
}

void moveLeft(){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(currentBlock.pixels[i][j]&b11110000){
                if(i==0){
                    return;
                }
                else{
                    currentBlock.pixels[i-1][j]|=(currentBlock.pixels[i][j]>>4);
                }
            }
            currentBlock.pixels[i][j]<<=4;
        }
    }
}

void moveRight(){
    for(int i=3;i>=0;i--){
        for(int j=3;j>=0;j--){
            if(currentBlock.pixels[i][j]&b00001111){
                if(i==3){
                    return;
                }
                else{
                    currentBlock.pixels[i+1][j]|=(currentBlock.pixels[i][j]<<4);
                }
            }
            currentBlock.pixels[i][j]>>=4;
        }
    }
}

void putDown(){
    int check = currentBlock.placement;
    while(check == currentBlock.placement){
        moveDown();
        check--;
    }
}

void rotate(){
    
}
