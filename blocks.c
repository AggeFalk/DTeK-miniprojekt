//Smart hantering av blocks
struct Block{
    int placement = 95;
    int pixels[4][4];
} stick, square, podium, Lzig, Rzig, Ll, Rl;

stick.pixels = {{0,63,252,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
square.pixels = {{0,7,192,0},{0,7,192,0},{0,0,0,0},{0,0,0,0}};
podium.pixels = {{0,7,0,0},{0,63,224,0},{0,0,0,0},{0,0,0,0}};