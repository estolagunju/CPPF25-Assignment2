#include "bmp.hpp"
#include <iostream>
#include <time.h>
void draw_rectangle(BMP &bmp,int x, int y, int l, int h, color c, color b ){
    for(int i=0;i<=l;i++){
        for(int ii=0;ii<=h;ii++){
        bmp.set_pixel(i+x, y+ii, c.r,c.g,c.b);
        bmp.set_pixel(i+x, y+h-ii, c.r, c.g,c.b);
        bmp.set_pixel(i+x, y+ii, b.r, b.g, b.b); bmp.set_pixel(i+x, y+h-ii, b.r,b.g, b.b); // go through the shape, length and height
    }
    /*for(int j=0;j<=h;j++){
        for(int ii=0;ii<=b;ii++){
            bmp.pixel(x+ii, y+j, c.r,c.g,c.b);
            bmp.set_pixel(x+l-ii, y+j,c.r, c.g,c.b);
        } // set the border of shape
    }*/
}

int main() {
    
    BMP bmp(500, 500); 
     srand(static_cast<unsigned int>(time(0)));
    color c(0,255,0);color b(23,19,60);
    for(int i=0;i<5;i++){
        uint8_t x=rand()%500;
        uint8_t y=rand()%500;
        uint8_t l=rand()%500;
        uint8_t h=rand()%500;
        
        draw_rectangle(bmp,x,y,l,h,c,b);//,rand()%10

    }
    
     draw_rectangle(bmp,1,1,500,500,color{255,255,0}, color{0,0,0}); //500,10,

    bmp.write("rect.bmp"); // Save the image to a file

    return 0;
}