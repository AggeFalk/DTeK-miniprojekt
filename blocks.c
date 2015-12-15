#include <stdio.h>
#include <string.h>

unsigned char simpleStick[4][4][2] = {{{2,31},{3,31},{4,31},{5,31}},
                                        {{3,31},{3,30},{3,29},{3,28}},
                                        {{2,31},{3,31},{4,31},{5,31}},
                                        {{3,31},{3,30},{3,29},{3,28}}
                                        };
unsigned char simpleBox[4][4][2] = {{{3,31},{3,30},{4,31},{4,30}},
                                        {{3,31},{3,30},{4,31},{4,30}},
                                        {{3,31},{3,30},{4,31},{4,30}},
                                        {{3,31},{3,30},{4,31},{4,30}}
                                        };
unsigned char simplePodium[4][4][2] = {{{2,30},{3,30},{3,31},{4,30}},
                                        {{3,31},{3,30},{3,29},{4,30}},
                                        {{2,30},{3,30},{4,30},{3,29}},
                                        {{2,30},{3,31},{3,30},{3,29}}
                                        };
unsigned char simpleLZig[4][4][2] = {{{2,30},{3,30},{3,31},{4,31}},
                                        {{2,31},{2,30},{3,30},{3,29}},
                                        {{2,30},{3,30},{3,31},{4,31}},
                                        {{2,31},{2,30},{3,30},{3,29}}
                                        };
unsigned char simpleRZig[4][4][2] = {{{2,31},{3,31},{3,30},{4,30}},
                                        {{2,30},{2,29},{3,31},{3,30}},
                                        {{2,31},{3,31},{3,30},{4,30}},
                                        {{2,30},{2,29},{3,31},{3,30}}
                                        };
unsigned char simpleLfoot[4][4][2] = {{{2,29},{3,31},{3,30},{3,29}},
                                        {{2,31},{2,30},{3,30},{4,30}},
                                        {{2,29},{2,30},{2,31},{3,31}},
                                        {{2,31},{3,31},{4,31},{4,30}}
                                        };
unsigned char simpleRfoot[4][4][2] = {{{2,31},{2,30},{2,29},{3,29}},
                                        {{2,31},{2,30},{3,31},{4,31}},
                                        {{2,31},{3,31},{3,30},{3,29}},
                                        {{2,30},{3,30},{4,30},{4,31}}
                                        };

unsigned char background[8][32] = {
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};
unsigned char matrix[8][32] = {
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};

unsigned char picture[8][32];
unsigned char currentBlock[4][4][2];
unsigned char orientation = 0;

void newBlock(){
    memcpy(background, matrix, 8*32);
    memcpy(currentBlock, simpleBox, 4*4*2);//random block istället för simpleBox
    orientation = 0;
}

void addBlock(){
    unsigned char tempBackground[8][32];
    memcpy(tempBackground, background, 8*32);
    int i;
    for(i=0;i<4;i++){
        tempBackground[currentBlock[orientation][i][0]][currentBlock[orientation][i][1]] += 1;
    }
    memcpy(matrix, tempBackground, 8*32);
}

unsigned char collision(){
    int i;
    int j;
    for(i=0;i<8;i++){
        for(j=0;j<32;j++){
            if(matrix[i][j]>=2)
                return 1;
        }
    }
    return 0;
}

void moveDown(){
    int i;
    unsigned char tempBlock[4][4][2];
    memcpy(tempBlock, currentBlock, 4*4*2);
    for(i=0;i<4;i++){
        if(currentBlock[orientation][i][1] == 0){
            memcpy(currentBlock, tempBlock, 4*4*2);
            newBlock();
            addBlock();
            return;
        }
        else{
            int o;
            for(o=0;o<4;o++){
                currentBlock[o][i][1]--;
            }
        }
    }
    addBlock();
    if(collision()){
        for(i=0;i<4;i++){
            int o;
            for(o=0;o<4;o++){
                currentBlock[o][i][1]++;
            }
        }
        addBlock();
        newBlock();
        return;
    }
}

void moveLeft(){
    int i;
    unsigned char tempBlock[4][4][2];
    memcpy(tempBlock, currentBlock, 4*4*2);
    for(i=0;i<4;i++){
        if(currentBlock[orientation][i][0] == 0){
            memcpy(currentBlock, tempBlock, 4*4*2);
            addBlock();
            return;
        }
        else{
            int o;
            for(o=0;o<4;o++){
                currentBlock[o][i][1]--;
            }
        }
    }
    addBlock();
    if(collision()){
        for(i=0;i<4;i++){
            int o;
            for(o=0;o<4;o++){
                currentBlock[o][i][1]++;
            }
        }
        addBlock();
        newBlock();
        return;
    }
}

void moveRight(){
    int i;
    unsigned char tempBlock[4][4][2];
    memcpy(tempBlock, currentBlock, 4*4*2);
    for(i=0;i<4;i++){
        if(currentBlock[orientation][i][0] == 7){
            memcpy(currentBlock, tempBlock, 4*4*2);
            addBlock();
            return;
        }
        else{
            int o;
            for(o=0;o<4;o++){
                currentBlock[o][i][1]++;
            }
        }
    }
    addBlock();
    if(collision()){
        for(i=0;i<4;i++){
            int o;
            for(o=0;o<4;o++){
                currentBlock[o][i][1]--;
            }
        }
        addBlock();
        newBlock();
        return;
    }
}

void putDown(){
    unsigned char tempBlock[4][4][2];
    memcpy(tempBlock, currentBlock, 4*4*2);
    while(tempBlock[orientation][0][0]==currentBlock[orientation][0][0]){
        moveDown();
        tempBlock[orientation][0][0]--;
    }
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
    addBlock();
    if(collision()){
        if(orientation == 0){
            orientation = 3;
        }
        else{
            orientation--;
        }
    }
    addBlock();
}

int main(){
    memcpy(currentBlock, simpleStick, 4*4*2);
    return 0;
}
