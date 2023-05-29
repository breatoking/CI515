extern "C"
{
  void start();
  void led(byte);
  void stop(byte);
}

String yes = "";
//----------------------------------------------------
void setup()
{
  Serial.begin(9600);
  start();
}
//----------------------------------------------------
void loop()
{
  Serial.println("Do you want to corss the road? Y/N");

  led(1);

  if(Serial.available() > 0){

    yes = Serial.read();
    Serial.print("HELLO!");
    stop(1);
    yes = "";
  }
}
