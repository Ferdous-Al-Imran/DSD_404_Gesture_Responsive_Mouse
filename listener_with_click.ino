#define maximumRangex  200 // Maximum range needed
#define maximumRangey  200 // Maximum range needed
#define minimumRange  0 // Minimum range needed
float duration, distance; // Duration used to calculate distance
float px,py;
bool sx,sxx;
bool sy,syy;
char pme;
void setup() {
Serial.begin (9600);
px=maximumRangex;
py=maximumRangey;
pme = 'n';

}

void loop() {
  float mClick = checkDistance(36,37);
  if(mClick >= 8 && mClick <15){
    
    if(pme =='n')
      Serial.println("s");
     pme = 's';
     
    
  }else if(mClick < 8 ){
    
    if(pme == 'n')
      Serial.println("d");
     pme = 'd';
    
  }else{
    pme = 'n';
  }
  float my =maximumRangey;
  for(int i = 0 ;i  < 4 ; i++){
    delay(3);
    my = min(my,checkDistance((11+i)*2,(11+i)*2+1));
    
  }

  float mx =maximumRangex;
  for(int i = 0 ;i  < 3 ; i++){
    delay(3);
    mx = min(mx,checkDistance((15+i)*2,(15+i)*2+1));
    
  }

float moveX = 0;
float moveY = 0;
  
if((abs(mx-px) > 1) && px < 38 && mx < 38 ){
  moveX = mx - px;
  
}
if((abs(my-py) > 1) && py < 28 && my <28){
  moveY = py - my;
}

bool stx = moveX<0?false:true;
bool sty = moveY < 0 ? false : true;

//Serial.println(mClick);
if((moveX || moveY) && ((stx == sx) ||(stx == sxx)) &&  ((sty == sy) ||(sty == syy))){

Serial.print((moveX*20));
Serial.print(" ");
Serial.println((moveY*20));
}
px = mx; py = my;
sxx = sx;
sx = stx;
syy = sy;
sy = sty;
}


float checkDistance(int echoPin,int trigPin){
/* The following trigPin/echoPin cycle is used to determine the
 distance of the nearest object by bouncing soundwaves off of it. */ 
  pinMode(echoPin, INPUT);
   pinMode(trigPin, OUTPUT);
 digitalWrite(trigPin, LOW); 
 delay(1); 

 digitalWrite(trigPin, HIGH);
 delay(2); 
 
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 
 //Calculate the distance (in cm) based on the speed of sound.
 distance = duration/58.2;


 /* Send the distance to the computer using Serial protocol, and
 turn LED OFF to indicate successful reading. */
 
 return distance;
  
 

  
}
