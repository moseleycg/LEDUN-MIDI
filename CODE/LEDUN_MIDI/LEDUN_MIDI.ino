///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////MOSELEY MIRANDA GOES/////////
/////////////////////////////////////////////16-12-2018  TO 17-12-2018/////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
int val = 0; 
int lastVal = 0;
int val1 = 0; 
int lastVal1 = 0;
int val2 = 0;
int lastVal2 = 0;

///////// PIN 0 ////////////
int b1 = LOW;
int b1A = LOW;  

void setup(){
     pinMode(3, INPUT);
     Serial.begin(9600); 

}
void loop()
{///////// PIN 01 ////////////
b1 = digitalRead(4);
 
 if (b1 == HIGH && b1A == LOW) {
 Serial.write(144); // 1001 0000 = Note On Kanal 1
 Serial.write(36); //Note C1
 Serial.write(0);//Note on
 b1A = b1;
 }
 if (b1 == LOW && b1A == HIGH) {
 Serial.write(144); // 1001 0000 = Note On Kanal 1
 Serial.write(36); //Note C1
 Serial.write(127); //Note off
 b1A = b1;
 }

    val = analogRead(0)/8;   // Divide by 8 to get range of 0-127 for midi
   if (val != lastVal) // If the value does not = the last value the following command is made. This is because the pot has been turned. Otherwise the pot remains the same and no midi message is output.
   {
   MIDImessage(176,1,val);}         // 176 = CC command (channel 1 control change), 1 = Which Control, val = value read from Potentionmeter 1 NOTE THIS SAYS VAL not VA1 (lowercase of course)
   lastVal = val; 
   
   
       val1 = analogRead(1)/8;   // Divide by 8 to get range of 0-127 for midi
   if (val1 != lastVal1) // If the value does not = the last value the following command is made. This is because the pot has been turned. Otherwise the pot remains the same and no midi message is output.
   {
   MIDImessage(176,2,val);}         // 176 = CC command (channel 1 control change), 1 = Which Control, val = value read from Potentionmeter 1 NOTE THIS SAYS VAL not VA1 (lowercase of course)
   lastVal1 = val1; 
   
   
       val2 = analogRead(3)/8;   // Divide by 8 to get range of 0-127 for midi
   if (val != lastVal) // If the value does not = the last value the following command is made. This is because the pot has been turned. Otherwise the pot remains the same and no midi message is output.
   {
   MIDImessage(176,3,val2);}         // 176 = CC command (channel 1 control change), 1 = Which Control, val = value read from Potentionmeter 1 NOTE THIS SAYS VAL not VA1 (lowercase of course)
   lastVal2 = val2; 
   
   
   delay(1);
}

//////////////////////////////////FIM//////////////////////////////////////////
void MIDImessage(byte command, byte data1, byte data2) //pass values out through standard Midi Command
{
   Serial.write(command);
   Serial.write(data1);
   Serial.write(data2);
}

