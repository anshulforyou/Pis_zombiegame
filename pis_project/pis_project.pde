/*
Program to create a game and gets its motion values serially from 3rd PORT 
Programed by B.Aswinth Raj
Dated on : 21-08-2016
*/



import processing.serial.*;

Serial port;

int data;
int movby;
float x=300;
float y=00;
float spdy=6;
float spdx=0;
float posxr,posxl,posyr,posyl,ballpos;
int score = 0;
float speed=0;
float flag=0;
float ballsize=20;
float temp;

void setup()
{
  size(600,600,P2D);
  smooth();
  port = new Serial(this,Serial.list()[4],9600);
  println(Serial.list());
}




void draw()
{
   if (port.available()>0 && port.available()<30)
  {
    data=port.read();
    movby = int(map(float(data), 255,0,30,570));
    println(movby);
  }


 if (flag==0)
 strtscrn();
 if (flag==1)
 game();
 if (flag==3)
 lastscrn();

 

  fill(18,250,8);
textSize(12);
text("Created by asWINth raj", 245, 590);

textSize(22);
text("Score:",10,20);
text(score, 80, 20);
fill(0, 102, 153);
}


void strtscrn()
{score=0;
  cursor();
background(255); //Color of the backgroud
  fill(18,250,8);
textSize(52);
text("WELCOME", 200,300);
fill(18,250,80);
textSize(32);
text("Select your Level", 200,330);
fill(180,250,8);
textSize(22);
text("1   2    3   4", 250,370);
//println(mouseX, mouseY);
if (mouseY > 340 && mouseY < 380)  
{
  cursor(HAND);
if(mousePressed==true && flag==0)
{
  
 if (mouseX >240 && mouseX <270)
 {
 speed=1;
 }
 if (mouseX >280 && mouseX <300)
 {
 speed=2;
 }
 if (mouseX >320 && mouseX <350)
 {
 speed=3;
 }
 if (mouseX >350 && mouseX <380)
 {
 speed=4;
 }
  flag=1;
}

}

}


void game()
{
  noCursor();
   background(0); //Color of the backgroud
 y=y+spdy; //speed and positon of ball in Y axis
 x=x+spdx; //speed and positon of ball in X axis 

rectMode(CENTER);  
  fill(16,22,162);
rect(movby,530,60,10); //The plate

posxr=movby+40;
posxl=movby-40;
posyr=530+15;
posyl=530-10;

if (( (posyl < y) && (y < posyr) ) && ( (posxl < x) && (x < posxr) ))  //Plate and ball meeting
{
  spdy=-(speed*3);
  

if (x<movby) //Pad left deflection
{
  ballpos=movby-x;
 spdx=-(ballpos/5);
// println(ballpos);
}

if (x>movby)  //Pad right deflection
{
 ballpos=x-movby;
spdx=+(ballpos/5);
//println(ballpos);
}

}
  
if (x<=0 ) // Left margin deflection
spdx=(speed*3);


if (y<=0 ) // Top margin deflection
{
  spdy=(speed*3);
  score=score+1;
}

if (x>=600) // Right margin deflection
spdx=-(speed*3);

if (y>=600) 
{
  background(250,0,0);
x=300;
y=0;
flag=3;
speed=1;
}

  fill(88,250,68);
  ellipse(x,y,ballsize,20); //The ball


if(score>=15 && score<=20)
  {
  ellipse(random(600),random(600),20,20);
  ellipse(random(600),random(600),20,20);
  ellipse(random(600),y,20,20);
  ellipse(x,random(600),20,20);///The ball
  }

temp=x;


}


void lastscrn()
{
  background(250,0,0);
  textSize(32);
text("GAME OVER", 200,300);
fill(18,250,80);
textSize(22);
text("Your Score:", 200,330);
text(score, 320,330);
fill(180,250,8);

text("Click to try again..", 200,370);
if(mousePressed == true)
 flag =0;
}
