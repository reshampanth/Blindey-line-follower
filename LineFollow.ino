// Left Motor Controls
# define Lp  7    // ip B
# define Ln  4    // ip A
# define El  5
// Right Motor Controls
# define Rp  8    // ip A
# define Rn  12   // ip B
# define Er  6

# define Rs   A1
# define Ms   A2
# define Ls   A3
//# define Ers  A4 //avoid using 2 ??
//# define Els  A0
//# define Er1  A0
//# define El1  A4
int b=850;
int i=0;
void setup()
{  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode (Lp, OUTPUT);
  pinMode (Ln, OUTPUT);
  pinMode (El, OUTPUT);
  pinMode (Rp, OUTPUT);
  pinMode (Rn, OUTPUT);
  pinMode (Er, OUTPUT);
  
  digitalWrite (El,HIGH);
  digitalWrite (Er,HIGH);
  
  pinMode (Rs, INPUT);    // A1
  pinMode (Ms, INPUT);    // A2
  pinMode (Ls, INPUT);    // A3
 // pinMode (Ers,INPUT);  //A0  
 // pinMode (Els,INPUT);  //A4 
}
void MotorControl(int driveL, int driveR)
{
switch (driveL) {      
    case 0:                  // lft STOP
      digitalWrite (Ln,LOW);
      digitalWrite (Lp,LOW);
      break;      
    case 1:                  // lft FORWARD
      digitalWrite (Ln,HIGH);
      digitalWrite (Lp,LOW);
      break;      
    case 2:                  // lft REVERSE
      digitalWrite (Ln,LOW);
      digitalWrite (Lp,HIGH);
      break;      
    default:break;
  }

switch (driveR) {      
    case 0:                  // rgt STOP
      digitalWrite (Rn,LOW);
      digitalWrite (Rp,LOW);
      break;      
    case 1:                  // rgt FORWARD
      digitalWrite (Rn,HIGH);
      digitalWrite (Rp,LOW);
      break;      
    case 2:                  // rgt REVERSE
      digitalWrite (Rn,LOW);
      digitalWrite (Rp,HIGH);
      break;    
    default:break;
  }
}  

void loop(){
  if ((analogRead(Ls)<b) && (analogRead(Ms)<b) && (analogRead(Rs)<b))      
     {  MotorControl(1,1); Serial.println("forward");   }
  else if ((analogRead(Ls)>b) && (analogRead(Ms)<b) && (analogRead(Rs)<b))
     {  MotorControl(1,0); Serial.println("right"); }
  else if ((analogRead(Ls)>b) && (analogRead(Ms)>b) && (analogRead(Rs)<b))   
     {  MotorControl(1,2); Serial.println("right sharp"); }
  else if ((analogRead(Ls)<b) && (analogRead(Ms)<b) && (analogRead(Rs)>b))
     {  MotorControl(0,1); Serial.println("left"); }
  else if ((analogRead(Ls)<b) && (analogRead(Ms)>b) && (analogRead(Rs)>b))  
     {  MotorControl(2,1); Serial.println("left sharp");}
   else if ((analogRead(Ls)>b) && (analogRead(Ms)>b) && (analogRead(Rs)>b))
     {MotorControl(0,0);Serial.println("Stop");}
}

