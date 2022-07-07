//***********************************************
//
//            AUTOMATED CHESSBOARD
//
//***********************************************


//___________________________________________________________________________________________________
// Declaring required constants and Pin numbers
//---------------------------------------------------------------------------------------------------
const int stepsBetweenSquares = 150;
const int stepPinX = 5; 
const int dirPinX = 4; 
const int stepPinY = 2;
const int dirPinY = 3;
const int limitSwitchX = 8;
const int limitSwitchY = 12;
const int magnetPinPos = 9;
const int magnetPinNeg = 11;
int x1 = 0; int x2 = 1;
int y1 = 0; int y2 = 1;
int xsteps;
int ysteps;
int x = 0;
int y = 0;

void setup() {
  Serial.begin(9600);
  pinMode(stepPinX,OUTPUT); 
  pinMode(dirPinX,OUTPUT);
  pinMode(stepPinY,OUTPUT); 
  pinMode(dirPinY,OUTPUT);
  pinMode(limitSwitchX, INPUT);
  pinMode(limitSwitchY, INPUT);
  pinMode(magnetPinPos, OUTPUT);
  pinMode(magnetPinNeg, OUTPUT);
}


void loop() {
//___________________________________________________________________________________________________
// Recieve position adress of piece to be moved from Serial monitor (Letter, Number)
//---------------------------------------------------------------------------------------------------
  Serial.print("Piece to be moved letter adress:  ");
  while (!Serial.available());
    x1 = readSerialLetter();
      
  Serial.print("Piece to be moved number adress:  ");
  while (!Serial.available());
    y1 = readSerialNumber();      


//______________________________________________________________________________________________
// Move to Position of piece to be moved
//-----------------------------------------------------------------------------------------------
  xsteps = stepsBetweenSquares*(x1-x2);
  ysteps = stepsBetweenSquares*(y1-y2);
  
  movePieceDiagonal(xsteps, ysteps);
 

//_______________________________________________________________________________________________
// Recieve position adress of piece new location from Serial Monitor (Letter, Number)
//-----------------------------------------------------------------------------------------------
  Serial.print("New location letter adress:  ");
  while (!Serial.available());
    x2 = readSerialLetter();

  Serial.print("New location number adress:  ");
  while (!Serial.available());
    y2 = readSerialNumber();
  Serial.println();

  
//________________________________________________________________________________________________
// Turn on magnet
//------------------------------------------------------------------------------------------------
  digitalWrite(magnetPinPos, HIGH);
  digitalWrite(magnetPinNeg, LOW);

  
//________________________________________________________________________________________________
// Move piece to new location
//-------------------------------------------------------------------------------------------------
  xsteps = stepsBetweenSquares*(x2-x1);
  ysteps = stepsBetweenSquares*(y2-y1);
  
  digitalWrite(dirPinX, HIGH); digitalWrite(dirPinY, LOW);
  offsetPiece();
  delay(50);
  movePiece(xsteps, dirPinX, stepPinX);
  movePiece(-ysteps, dirPinY, stepPinY);
  delay(50);
  digitalWrite(dirPinX, LOW); digitalWrite(dirPinY, HIGH);
  offsetPiece();

//___________________________________________________________________________________________________
// Turn off Magnets
//---------------------------------------------------------------------------------------------------
  digitalWrite(magnetPinPos, LOW);
  digitalWrite(magnetPinNeg, LOW);
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////
// FUNCTIONS ////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////

int readSerialLetter(){
  int i;
  while(i < 1 || i > 8){
    i = Serial.read(); 
    i = i - 64;
    }
  Serial.println(i);
  Serial.parseInt();
  return i;
  }

//////////////////////////////////////////////////////////////////////////////////////////////////////

int readSerialNumber(){
  int i;
  while (i < 1 || i > 9){
    i = Serial.parseInt();
    }
  Serial.println(i);
  Serial.parseInt();
  return i;
  }

////////////////////////////////////////////////////////////////////////////////////////////////////////

void zeroDiagonal(){
  digitalWrite(dirPinX, LOW);
  digitalWrite(dirPinY, HIGH);
  while (digitalRead(limitSwitchX) == HIGH && digitalRead(limitSwitchY) == HIGH){
    moveDiagonal(1.5);
  }
  while (digitalRead(limitSwitchX) == HIGH){
    moveLinear(stepPinX, 1.5);
  }
  while (digitalRead(limitSwitchY) == HIGH){
    moveLinear(stepPinY, 1.5);
  }
  while (digitalRead(limitSwitchX) == LOW){         //Backoff switch
    digitalWrite(dirPinX, HIGH);
    moveLinear(stepPinX, 1);
  }
  while (digitalRead(limitSwitchY) == LOW){         //Backoff switch
    digitalWrite(dirPinY, LOW);
    moveLinear(stepPinY, 1);
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////

void movePiece(int steps, int dirPin, int stepPin){
  if (steps > 0){
    digitalWrite(dirPin,HIGH);
  }
  else{
    steps = abs(steps);
    digitalWrite(dirPin, LOW);
  }
  for(int i = 0; i < steps; i++) {
    moveLinear(stepPin, 2.5);
  }
  }

////////////////////////////////////////////////////////////////////////////////////////////////////////

void movePieceDiagonal(int xsteps, int ysteps){
  if (ysteps > 0){
    digitalWrite(dirPinY, LOW);
  }
  else{
    ysteps = abs(ysteps);
    digitalWrite(dirPinY, HIGH);
  }
  if (xsteps > 0){
    digitalWrite(dirPinX, HIGH);
  } 
  else{
    xsteps = abs(xsteps);
    digitalWrite(dirPinX, LOW);
  }
  x = 0; y = 0; 
  while (x < xsteps && y < ysteps){
    moveDiagonal(1.5);
    x++; y++;
  }
  for(x; x < xsteps; x++){
    moveLinear(stepPinX, 1.5);
  }
  for(y; y < ysteps; y++){
    moveLinear(stepPinY, 1.5);
  }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////

void offsetPiece(){
  for (int i=0; i < stepsBetweenSquares/1.5; i++){
    moveDiagonal(3);
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////

void moveDiagonal(int delayTime){
    digitalWrite(stepPinX, HIGH);
    digitalWrite(stepPinY, HIGH);
    delay(delayTime);
    digitalWrite(stepPinX, LOW);
    digitalWrite(stepPinY, LOW);
    delay(delayTime);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void moveLinear(int stepPin, int delayTime){
  digitalWrite(stepPin, HIGH);
  delay(delayTime);
  digitalWrite(stepPin, LOW);
  delay(delayTime);
}
