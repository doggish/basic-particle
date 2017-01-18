//T1A11-Range-Finder-Name.ino

// EXAMPLE
//using Ultrasonic Range Finder from Robotshop
//http://www.robotshop.com/ca/en/hc-sr04-ultrasonic-range-finder.html
//(c)2016 Nick (to some degree)

unsigned long duration;
unsigned long duration1;

void setup()
{


    pinMode(D0, OUTPUT);   // LED on D7
    pinMode(D1, OUTPUT);   // Other LED connected from D1 through resistor to ground
    pinMode(D2, OUTPUT);
    pinMode(D3, OUTPUT);
    
                           // ultrasonic range finder Robotshop RB-lte-54
                           
                           // GND pin goes to ground
    pinMode(D7, INPUT);    // echo
    pinMode(D5, OUTPUT);   // Trig
                           // VCC pin goes to VIN on the photon
                                      

 pinMode(D6, INPUT);    // echo
    pinMode(D4, OUTPUT);   // Trig
                           // VCC pin goes to VIN on the photon
                                      
}
void loop(){
            digitalWrite(D5, HIGH);         // activate trigger

        digitalWrite(D5, LOW);          // de-activate trigger

        duration = pulseIn(D7, HIGH); // how long until a reply?
        
        digitalWrite(D4, HIGH);         // activate trigger

        digitalWrite(D4, LOW);          // de-activate trigger
                                     
        duration1 = pulseIn(D6, HIGH);
                                        // a blocking call so may wait a few seconds
                                        
        if (duration + duration1 > 2000    ){        // raw data from 200 to 16000                                         
                                        // where  2000 raw = ~35cm,  4000 raw = ~80cm 1                                  
        myStepStop(10);
            
        } else {
        myStepClockwise(10);
        
        }
        
        digitalWrite(D4, HIGH);         // activate trigger

        digitalWrite(D4, LOW);          // de-activate trigger
                                     
        duration1 = pulseIn(D6, HIGH);   // how long until a reply?
        
        digitalWrite(D5, HIGH);         // activate trigger

        digitalWrite(D5, LOW);          // de-activate trigger

        duration = pulseIn(D7, HIGH); // how long until a reply?
                                        // a blocking call so may wait a few seconds
        if (duration1 < 2000 + duration > 2000   ){        // raw data from 200 to 16000                                         
                                        // where  2000 raw = ~35cm,  4000 raw = ~80cm 1                                  
        myStepClockwise(10);
            
        } else {
            
        myStepCounterClockwise(10);
        }
}

    
    void myStepClockwise(int myDelay){
    
    digitalWrite(D0,1);   //power D0
    digitalWrite(D1,0);
    digitalWrite(D2,0);
    digitalWrite(D3,0);
    delay(myDelay);
      
    digitalWrite(D0,0);
    digitalWrite(D1,0);
    digitalWrite(D2,1);  //power D2
    digitalWrite(D3,0);
    delay(myDelay);
    
    digitalWrite(D0,1);
    digitalWrite(D1,1);   //power D1
    digitalWrite(D2,0);
    digitalWrite(D3,0);
    delay(myDelay);


    digitalWrite(D0,0);
    digitalWrite(D1,0);
    digitalWrite(D2,1);
    digitalWrite(D3,1);  //power D3
    delay(myDelay);
    
}  

     void myStepCounterClockwise(int myDelay){

    digitalWrite(D0,0);
    digitalWrite(D1,0);
    digitalWrite(D2,1);
    digitalWrite(D3,1);  //power D3
    delay(myDelay);
    
     
    digitalWrite(D0,1);
    digitalWrite(D1,1);   //power D1
    digitalWrite(D2,0);
    digitalWrite(D3,0);
    delay(myDelay);

      
    digitalWrite(D0,0);
    digitalWrite(D1,0);
    digitalWrite(D2,1);  //power D2
    digitalWrite(D3,0);
    delay(myDelay);
    
    digitalWrite(D0,1);   //power D0
    digitalWrite(D1,0);
    digitalWrite(D2,0);
    digitalWrite(D3,0);
    delay(myDelay);


}  


     void myStepStop(int myDelay){

    digitalWrite(D0,0);
    digitalWrite(D1,0);
    digitalWrite(D2,0);
    digitalWrite(D3,0);  //power D3
    delay(myDelay);
    
     
    digitalWrite(D0,0);
    digitalWrite(D1,0);   //power D1
    digitalWrite(D2,0);
    digitalWrite(D3,0);
    delay(myDelay);

      
    digitalWrite(D0,0);
    digitalWrite(D1,0);
    digitalWrite(D2,0);  //power D2
    digitalWrite(D3,0);
    delay(myDelay);
    
    digitalWrite(D0,0);   //power D0
    digitalWrite(D1,0);
    digitalWrite(D2,0);
    digitalWrite(D3,0);
    delay(myDelay);

}
