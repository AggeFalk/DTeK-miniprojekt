SimpleBlock struct{
    unsigned char[4][2] pixels;
} simpleStick, simpleSquare, simplePodium, Lzig, Rzig, Ll, Rl;

simpleStick.pixels = {{2,31},{3,31},{4,31},{5,31}}

unsigned char[8][32] background = {
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};

unsigned char[8][32] addBlock(unsigned char[8][32] background,SimpleBlock block){
    int i;
    for(i=0;i<4;i++){
        background[block.pixels[i][0]][block.pixels[i][1]] += 1;
    }
    return background;
}

unsigned char collision(unsigned char[8][32] picture){
    int i;
    int j;
    for(i=0;i<8;i++){
        for(j=0;j<32;j++){
            if(picture[i][j]>=3)
                return 1;
        }
    }
    return 0;
}

unsigned char[8][32] moveDown(){
    int i;
    SimpleBlock tempBlock = currentBlock;
    for(i=0;i<4;i++){
        if(currentBlock.pixels[i][1] == 0){
            return addBlock(background,tempBlock);
        }
        else{
            currentBlock.pixels[i][1]--;
        }
    }
    unsigned char[8][32] newPicture = addBlock(background,currentBlock);
    if(collision(newPicture)){
        for(i=0;i<4;i++){
            currentBlock.pixels[i][1]++;
        }
        return addBlock(background,currentBlock);
    }
    else{
        return newPicture;
    }
}

void moveLeft(){
    int i;
    for(i=0;i<4;i++){
        if
        currentBlock[i][0]--;
    }
    return addBlock(background,currentBlock);
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
