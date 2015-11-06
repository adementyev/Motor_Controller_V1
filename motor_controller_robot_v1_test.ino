//#include <DRV8835_DRIVER.h>


/*

 * 
 * The connections are: 
 * IN2/EN - BIN2/BENABLE - M2PWM 
 * IN1/PH - BIN1/BPHASE  - M2DIR
 * IN2/EN - AIN2/AENABLE - M1PWM
 * IN1/PH - AIN1/APHASE  - M1DIR
 */

const int LED_BLUE = 4;
const int LED_RED = A1; 
const int MODE = 5; 
const int M1_DIR = 6;   
const int M1_PWM = 7;
const int M2_DIR = 8;
const int M2_PWM = 9;

int counter = 0 ;

int speedPercent = 100;  //Speed percentage of the maximum


//DRV8835_DRIVER motors;

void setup()
{
  pinMode(LED_RED, OUTPUT);     
  pinMode(LED_BLUE,OUTPUT);
  pinMode(MODE,OUTPUT);
  pinMode(M1_DIR,OUTPUT);
  pinMode(M1_PWM,OUTPUT);
  pinMode(M2_DIR,OUTPUT);
  pinMode(M2_PWM,OUTPUT);
  
  digitalWrite(LED_BLUE, LOW); 
  digitalWrite(LED_RED, HIGH);
  digitalWrite(MODE,HIGH);
  // uncomment one or both of the following lines if your motors' directions need to be flipped
  //motors.flipM1(true);
  //motors.flipM2(true);
  for(int i =0; i<20; i++) { 
        digitalWrite(LED_RED, !digitalRead(LED_RED)); 
        digitalWrite(LED_BLUE, !digitalRead(LED_BLUE));
        delay(100);
  }
}

void loop()
{
  //Here the motor speed is determined by delays between
  //setting PWM high and low. 
  //For example 50us high and 500 low will give 9% PWM so motors 
  //will be pretty slow, only at 9% of maximum speed. 
  digitalWrite(M1_PWM, HIGH);
  digitalWrite(M2_PWM, HIGH); 
  delayMicroseconds(50); 
  digitalWrite(M1_PWM, LOW);
  digitalWrite(M2_PWM,LOW); 
  delayMicroseconds(500);
  
  //M1_DIR and M2_DIR will change the direction of the motors. 
  counter++ ;
  if (counter>5000) { 
    counter=0; 
    digitalWrite(M1_DIR, !digitalRead(M1_DIR)); 
    digitalWrite(M2_DIR, !digitalRead(M2_DIR));
    digitalWrite(LED_RED, !digitalRead(LED_RED)); 
    digitalWrite(LED_BLUE, !digitalRead(LED_BLUE));
  }
  //delay(1000);
  
  /*
  digitalWrite(LED_BLUE, HIGH); 
  motors.setM1Speed(50);
  delay(1000); 
  motors.setM1Speed(0);
  delay(1000);
  motors.setM1Speed(-50);
  delay(1000);
  digitalWrite(LED_BLUE, LOW);
  
  
  digitalWrite(LED_RED, HIGH); 
  motors.setM2Speed(50);
  delay(1000); 
  motors.setM2Speed(0);
  delay(1000);
  motors.setM2Speed(-50);
  delay(1000);
  digitalWrite(LED_RED, LOW);
  */
  
}
