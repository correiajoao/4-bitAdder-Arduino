/*
Developers: João Correia, João Constantino. 
4-bitsAdder - Code from Arduino
*/

const int bit1 = 9;
const int bit2 = 10;
const int bit3 = 11;
const int bit4 = 12;

const int _bit1 = 8;
const int _bit2 = 7; 
const int _bit3 = 6;
const int _bit4 = 5;

//Logic gate and
int _and(int bitOne, int bitTwo){
  return bitOne & bitTwo;
}

//Logic gate or
int _or(int bitOne, int bitTwo){
  return bitOne | bitTwo;
}
  
//Logic gate exclusive or 
int _xor(int bitOne, int bitTwo){
  return bitOne ^ bitTwo;
} 


void setup() {
   digitalWrite(bit1, HIGH);
   pinMode(bit1, INPUT);
   digitalWrite(bit2, HIGH);
   pinMode(bit2, INPUT);
   digitalWrite(bit3, HIGH);
   pinMode(bit3, INPUT);
   digitalWrite(bit4, HIGH);
   pinMode(bit4, INPUT);

   digitalWrite(_bit1, HIGH);
   pinMode(_bit1, INPUT);
   digitalWrite(_bit2, HIGH);
   pinMode(_bit2, INPUT);
   digitalWrite(_bit3, HIGH);
   pinMode(_bit3, INPUT);
   digitalWrite(_bit4, HIGH);
   pinMode(_bit4, INPUT);
   
   pinMode(A0, OUTPUT);
   pinMode(A1, OUTPUT);
   pinMode(A2, OUTPUT);
   pinMode(A3, OUTPUT);
   pinMode(A4, OUTPUT); 
}


void loop() {
  int firstNumber[3];
  int secondNumber[3];

  //Setting bits values
  firstNumber[0] = digitalRead(bit1);   
  firstNumber[1] = digitalRead(bit2);
  firstNumber[2] = digitalRead(bit3);
  firstNumber[3] = digitalRead(bit4);
 
  //Setting bits values
  secondNumber[0] = digitalRead(_bit1);
  secondNumber[1] = digitalRead(_bit2);
  secondNumber[2] = digitalRead(_bit3);
  secondNumber[3] = digitalRead(_bit4);
  
  /*  The sum is like the example
  *
  *    firstNumber[0]   firstNumber[1]   firstNumber[2]   firstNumber[3]
  *  + secondNumber[0]  secondNumber[1]  secondNumber[2]  secondNumber[3]
  *   -------------------------------------------------------------------
  *    res[0]           res[1]         res[2]           res[3]
  */
  
  int carryIn = 0;  
  int carryOut = 0;

  int res[3];

  // This part simulates what is described in the electric scheme
 
  res[3] = _xor(carryIn, _xor(firstNumber[3],secondNumber[3]));
  carryOut = _or(_and(firstNumber[3],secondNumber[3]),_and(carryIn,_xor(firstNumber[3],secondNumber[3])));
  carryIn = carryOut;
  
  res[2] = _xor(carryIn, _xor(firstNumber[2],secondNumber[2]));
  carryOut = _or(_and(firstNumber[2],secondNumber[2]),_and(carryIn,_xor(firstNumber[2],secondNumber[2])));
  carryIn = carryOut; 
  
  res[1] = _xor(carryIn, _xor(firstNumber[1],secondNumber[1]));
  carryOut = _or(_and(firstNumber[1],secondNumber[1]),_and(carryIn,_xor(firstNumber[1],secondNumber[1])));
  carryIn = carryOut; 
  
  res[0] = _xor(carryIn, _xor(firstNumber[0],secondNumber[0]));
  carryOut = _or(_and(firstNumber[0],secondNumber[0]),_and(carryIn,_xor(firstNumber[0],secondNumber[0])));
  carryIn = carryOut; 
  
  if(carryIn == 1){
      digitalWrite(A0,HIGH);  
  }else{
      digitalWrite(A0,LOW);
  } 

  //Printing the result 
  if(res[0] == 1){
     digitalWrite(A1, HIGH);
  }else{
     digitalWrite(A1, LOW);
  } 

  if(res[1] == 1){
     digitalWrite(A2, HIGH);
  }else{
     digitalWrite(A2, LOW);
  }
  
  if(res[2] == 1){
     digitalWrite(A3, HIGH);
  }else{
     digitalWrite(A3, LOW);
  }
  
  if(res[3] == 1){
     digitalWrite(A4, HIGH);
  }else{
     digitalWrite(A4, LOW);
  }
  delay(200);
 
}
