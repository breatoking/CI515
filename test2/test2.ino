asm volatile(
  "one: \n"
  "ldi r18, 0b10000000 ; \n"
  "out 5, r18 ; \n"
  "ret ; \n"
);
asm volatile(
  "two: \n"
  "ldi r18, 0b11000000 ; \n"
  "out 5, r18 ; \n"
  "ret ; \n"
);
asm volatile(
  "three: \n"
  "ldi r18, 0b11100000 ; \n"
  "out 5, r18 ; \n"
  "ret ; \n"
);
asm volatile(
  "four: \n"
  "ldi r18, 0b11110000 ; \n"
  "out 5, r18 ; \n"
  "ret ; \n"
);
asm volatile(
  "five: \n"
  "ldi r18, 0b11111000 ; \n"
  "out 5, r18 ; \n"
  "ret ; \n"
);
asm volatile(
  "six: \n"
  "ldi r18, 0b111111000 ; \n"
  "out 5, r18 ; \n"
  "ret ; \n"
);
asm volatile(
  "seven: \n"
  "ldi r18, 0b11111100 ; \n"
  "out 5, r18 ; \n"
  "ret ; \n"
);
asm volatile(
  "eight: \n"
  "ldi r18, 0b11111110 ; \n"
  "out 5, r18 ; \n"
  "ret ; \n"
);

int passFlag = 0;

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void setup() {
Serial.begin(9600);
Serial.println("Do you want a descending or ascending array?");
}

void loop() {
if  (passFlag == 0) {  
  if (Serial.available()){
    char userInput = Serial.read(); 
  if (userInput == 'A'){
    ascending();
  }
  else if (userInput == 'D'){
    descending();
  }
  else{
    Serial.println("Idiot");
  }
  }
else if (passFlag == 1) {
  exit(0);
}
}
}


void ascending(){

#define ARRAY_SIZE 50

  srand(time(NULL));

  int numbers[ARRAY_SIZE];

  for (int a = 0; a < ARRAY_SIZE; a++) {
    numbers[a] = rand() % 255 + 1;
  }

  // Sort the array in ascending order using bubble sort
  for (int a = 0; a < ARRAY_SIZE - 1; a++) {
    for (int b = 0; b < ARRAY_SIZE - a - 1; b++) {
      if (numbers[b] > numbers[b + 1]) {
        // Swap the elements if they are in the wrong order
        int temp = numbers[b];
        numbers[b] = numbers[b + 1];
        numbers[b + 1] = temp;
      }
    }
  }

  // Print the array
  for (int a = 0; a < ARRAY_SIZE; a++) {

    numbers[a++];

    if(a = numbers[6]){
      asm volatile(
        "call one ; \n"
      );
    }
    else{
     continue;
    }
     if(a = numbers[13]){
      asm volatile(
        "call two ; \n"
      );

    }
    else{
      continue;
    }
     if(a = numbers[22]){
      asm volatile(
        "call three ; \n"
      );
    }
    else{
      continue;
    }
    if(a = numbers[27]){
     asm volatile(
        "call four ; \n"
      );
    }
    else{
      continue;
    }
    if(a = numbers[34]){
      asm volatile(
        "call five ; \n"
      );
    }
    else{
      continue;
    }
      if(a = numbers[41]){
      asm volatile(
        "call six ; \n"
      );
    }
    else{
      continue;
    }
    if(a = numbers[45]){
      asm volatile(
        "call seven ; \n"
      );
    }
    else{
      continue;
    }
    if(a = numbers[49]){
      asm volatile(
        "call eight ; \n"
      );
       passFlag ++;
    }
    else{
       continue;
    }
  }
}
void descending() {
  #define ARRAY_SIZE 50
   // Seed the random number generator
  srand(time(NULL));

  int numbers[ARRAY_SIZE];

  // Generate 50 random numbers from 1 to 255
  for (int a = 0; a < ARRAY_SIZE; a++) {
    numbers[a] = rand() % 255 + 1;
  }

  // Sort the array in descending order using bubble sort
  for (int a = 0; a < ARRAY_SIZE - 1; a++) {
    for (int b = 0; b < ARRAY_SIZE - a - 1; b++) {
      if (numbers[b] < numbers[b+ 1]) {
        // Swap the elements if they are in the wrong order
        int temp = numbers[b];
        numbers[b] = numbers[b + 1];
        numbers[b + 1] = temp;
      }
    }
  }

  for (int a = 0; a < ARRAY_SIZE; a++) {

    numbers[a++];

    if(a = numbers[1]){
      asm volatile(
        "call eight ; \n"
      );

    }
    else{
     continue;
    }
     if(a = numbers[5]){
      asm volatile(
        "call seven ; \n"
      );

    }
    else{
      continue;
    }
     if(a = numbers[16]){
      asm volatile(
        "call six ; \n"
      );

    }
    else{
      continue;
    }
    if(a = numbers[25]){
      asm volatile(
        "call five ; \n"
      );

    }
    else{
      continue;
    }
    if(a = numbers[31]){
      asm volatile(
        "call four ; \n"
      );

    }
    else{
      continue;
    }
      if(a = numbers[42]){
      asm volatile(
        "call three ; \n"
      );

    }
    else{
      continue;
    }
    if(a= numbers[45]){
      asm volatile(
        "call two ; \n"
      );

    }
    else{
      continue;
    }
    if(a = numbers[49]){
      asm volatile(
        "call one ; \n"
      );
      passFlag ++;
    }
    else{
       continue;
    }
 }
  printf("\n");
}
