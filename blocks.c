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
unsigned char[4][4][2] currentBlock;
unsigned char orientation = 0;


unsigned char[8][32] addBlock(unsigned char[8][32] picture,unsigned char[4][4][2] block){
    int i;
    for(i=0;i<4;i++){
        picture[block[orientation][i][0]][block[orientation][i][1]] += 1;
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
    unsigned char[4][4][2] tempBlock = currentBlock;
    for(i=0;i<4;i++){
        if(currentBlock[orientation][i][1] == 0){
            return addBlock(background,tempBlock);
        }
        else{
            int o;
            for(o=0;o<4;o++){
                currentBlock[o][i][1]--;
            }
        }
    }
    unsigned char[8][32] newPicture = addBlock(background,currentBlock);
    if(collision(newPicture)){
        for(i=0;i<4;i++){
            int o;
            for(o=0;o<4;o++){
                currentBlock[o][i][1]++;
            }
        }
        return addBlock(background,currentBlock);
    }
    else{
        return newPicture;
    }
}

void moveLeft(){
    int i;
    unsigned char[4][4][2] tempBlock = currentBlock;
    for(i=0;i<4;i++){
        if(currentBlock[orientation][i][0] == 0){
            return addBlock(background,tempBlock);
        }
        else{
            int o;
            for(o=0;o<4;o++){
                currentBlock[o][i][0]--;
            }
        }
    }
    unsigned char[8][32] newPicture = addBlock(background,currentBlock);
    if(collision(newPicture)){
        for(i=0;i<4;i++){
            int o;
            for(o=0;o<4;o++){
                currentBlock[o][i][0]++;
            }
        }
        return addBlock(background,currentBlock);
    }
    else{
        return newPicture;
    }
}

void moveRight(){
    int i;
    unsigned char[4][4][2] tempBlock = currentBlock;
    for(i=0;i<4;i++){
        if(currentBlock[orientation][i][0] == 7){
            return addBlock(background,tempBlock);
        }
        else{
            int o;
            for(o=0;o<4;o++){
                currentBlock[o][i][0]++;
            }
        }
    }
    unsigned char[8][32] newPicture = addBlock(background,currentBlock);
    if(collision(newPicture)){
        for(i=0;i<4;i++){
            int o;
            for(o=0;o<4;o++){
                currentBlock[o][i][0]--;
            }
        }
        return addBlock(background,currentBlock);
    }
    else{
        return newPicture;
    }
}

void putDown(){
    unsigned char[4][4][2] tempBlock = currentBlock;
    while(tempBlock[orientation][0][0]==currentBlock[orientation][0][0]){
        moveDown();
        tempBlock[orientation][0][0]--;
    }
    return moveDown();
}

void rotate(){
    if(orientation == 3){
        orientation = 0;
    }
    else{
        orientation++;
    }
    int i;
    int o;
    for(i=0;i<4;i++){
        while(currentBlock[orientation][i][0]<0){
            for(o=0;o<4;o++){
                currentBlock[o][i][0]++;
            }
        }
        while(currentBlock[orientation][i][0]>7){
            for(o=0;o<4;o++){
                currentBlock[o][i][0]--;
            }
        }
        while(currentBlock[orientation][i][1]<0){
            for(o=0;o<4;o++){
                currentBlock[o][i][1]++;
            }
        }
        while(currentBlock[orientation][i][1]>32){
            for(o=0;o<4;o++){
                currentBlock[o][i][1]--;
            }
        }
    }
    if(collision(addBlock(background,currentBlock))){
        if(orientation == 0){
            orientation = 3;
        }
        else{
            orientation--;
        }
    }
    return addBlock(background,currentBlock);
}
