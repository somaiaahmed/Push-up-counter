
//HC-SR04
#define echoPin  12
#define trigPin  10
#define resetPin 4


float duration; //micro second
float d_cm;
long numDisplay=100;
boolean trigUp = false;
boolean trigDown = false;
float counterPushUp=0;

void setup() {

// initialize serial communication:
  Serial.begin(9600);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  //
  
  
}

void loop() {
  
 
  //reset 
  
  if(d_cm>=2282&&d_cm<=2288){
    trigUp=false;
    trigDown=false;
    counterPushUp=0;
  }
  
  // generate pusle trigger
  digitalWrite(trigPin,LOW);
  delayMicroseconds(500);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin,LOW);
  // receive, convert time (us) to cm
  duration = pulseIn(echoPin,HIGH);
  d_cm = duration * 0.034/2.;
  
  //trigger body 
  if (d_cm>15 && d_cm<=30){
    trigUp = true;
  } else if (d_cm < 10){
    trigDown = true;
  } else if(d_cm >30) {
  }
  //counter
  if (trigUp==true && trigDown==true){
    counterPushUp=counterPushUp+0.5;
    trigUp=false;
    trigDown=false;
  }
  //print
 Serial.print(d_cm);
 Serial.print(" --- ");
 Serial.println(int(counterPushUp));
 
 
}