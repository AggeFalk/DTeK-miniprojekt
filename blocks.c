unsigned char[4][4][2] simpleStick = {{{2,31},{3,31},{4,31},{5,31}},
                                        {{3,31},{3,30},{3,29},{3,28}},
                                        {{2,31},{3,31},{4,31},{5,31}},
                                        {{3,31},{3,30},{3,29},{3,28}}
                                        };

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

unsigned char[8][32] picture;
unsigned char[4][2] currentBlock;


unsigned char[8][32] addBlock(unsigned char[8][32] picture,unsigned char[4][2] block){
    int i;
    for(i=0;i<4;i++){
        picture[block[i][0]][block[i][1]] += 1;
    }
    return picture;
}

unsigned char collision(unsigned char[8][32] picture){
    int i;
    int j;
    for(i=0;i<8;i++){
        for(j=0;j<32;j++){
            if(picture[i][j]>=2)
                return 1;
        }
    }
    return 0;
}

unsigned char[8][32] moveDown(){
    int i;
    unsigned char[4][2] tempBlock = currentBlock;
    for(i=0;i<4;i++){
        if(currentBlock[i][1] == 0){
            return addBlock(background,tempBlock);
        }
        else{
            currentBlock[i][1]--;
        }
    }
    unsigned char[8][32] newPicture = addBlock(background,currentBlock);
    if(collision(newPicture)){
        for(i=0;i<4;i++){
            currentBlock[i][1]++;
        }
        return addBlock(background,currentBlock);
    }
    else{
        return newPicture;
    }
}

void moveLeft(){
    int i;
    unsigned char[4][2] tempBlock = currentBlock;
    for(i=0;i<4;i++){
        if(currentBlock[i][0] == 0){
            return addBlock(background,tempBlock);
        }
        else{
            currentBlock[i][0]--;
        }
    }
    unsigned char[8][32] newPicture = addBlock(background,currentBlock);
    if(collision(newPicture)){
        for(i=0;i<4;i++){
            currentBlock[i][0]++;
        }
        return addBlock(background,currentBlock);
    }
    else{
        return newPicture;
    }
}

void moveRight(){
    int i;
    unsigned char[4][2] tempBlock = currentBlock;
    for(i=0;i<4;i++){
        if(currentBlock[i][0] == 7){
            return addBlock(background,tempBlock);
        }
        else{
            currentBlock[i][0]++;
        }
    }
    unsigned char[8][32] newPicture = addBlock(background,currentBlock);
    if(collision(newPicture)){
        for(i=0;i<4;i++){
            currentBlock[i][0]--;
        }
        return addBlock(background,currentBlock);
    }
    else{
        return newPicture;
    }
}

void putDown(){
    unsigned char[4][2] tempBlock = currentBlock;
    while(tempBlock[0][0]==currentBlock[0][0]){
        moveDown();
        tempBlock[0][0]--;
    }
    return moveDown();
}

void rotate(){
    int i;
    unsigned char maxH = 0;
    unsigned char minH = 255;
    unsigned char maxW = 0;
    unsigned char minW = 255;
    unsigned char[4][2] tempBlock = currentBlock;
    for(i=0;i<4;i++){
        if(currentBlock[i][0] > maxW){
            maxW = currentBlock[i][j];
        }
        if(currentBlock[i][0] < minW){
            minW = currentBlock[i][j];
        }
        if(currentBlock[i][1] > maxH){
            maxH = currentBlock[i][j];
        }
        if(currentBlock[i][1] < minH){
            minH = currentBlock[i][j];
        }
    }
    if(maxW-minW>maxH-minH){
        unsigned char[maxW-minW][maxW-minW] square;
    }
    else{
        unsigned char[maxH-minH][maxH-minH] square;
    }
}
