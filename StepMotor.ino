#define in_A_1 2
#define in_A_2 3
#define in_B_1 4
#define in_B_2 5

int currentStep = 0;
 
void setup()
{
    pinMode(in_A_1, OUTPUT);
    pinMode(in_A_2, OUTPUT);
    pinMode(in_B_1, OUTPUT);
    pinMode(in_B_2, OUTPUT);
}
unsigned int time_delay = 200;

void step1(){
    //A+,B+
    digitalWrite(in_A_1, 1);
    digitalWrite(in_A_2, 0);
    digitalWrite(in_B_1, 1);
    digitalWrite(in_B_2, 0);
    delay(time_delay);
}

void step2(){
    //A+,B-
    digitalWrite(in_A_1, 1);
    digitalWrite(in_A_2, 0);
    digitalWrite(in_B_1, 0);
    digitalWrite(in_B_2, 1);
    delay(time_delay);
}

void step3(){
    //A-,B-
    digitalWrite(in_A_1, 0);
    digitalWrite(in_A_2, 1);
    digitalWrite(in_B_1, 0);
    digitalWrite(in_B_2, 1);
    delay(time_delay);
}

void step4(){
    //A-,B+
    digitalWrite(in_A_1, 0);
    digitalWrite(in_A_2, 1);
    digitalWrite(in_B_1, 1);
    digitalWrite(in_B_2, 0);
    delay(time_delay);
}

void tickClock(){
  currentStep++;
  if( currentStep >= 4 ){
    currentStep = 0;
  }
  int cycle = currentStep % 4;
  if( cycle == 0 ){
    step1();
  } else if( cycle == 1 ){
    step2();
  } else if( cycle == 2 ){
    step3();
  } else if( cycle == 3 ){
    step4();
  }
}

void counter_tickClock(){
  currentStep--;
  if( currentStep < 0 ){
    currentStep = 3;
  }
  int cycle = currentStep % 4;
  if( cycle == 0 ){
    step1();
  } else if( cycle == 1 ){
    step2();
  } else if( cycle == 2 ){
    step3();
  } else if( cycle == 3 ){
    step4();
  }
}

void clockwise(long st){
  long i = 0;
  while( i < st ){
    //step1
    step1();
    //step2
    step2();
    //step3
    step3();
    //step4
    step4();
    i++;
  }
}

void counter_clockwise(long st){
  long i = 0;
  while( i < st ){
    //step1
    step1();
    //step4
    step4();
    //step3
    step3();
    //step2
    step2();
    i++;
  }
}
void loop()
{
    //clockwise(18);//counter_clockwise(18);
   // tickClock();
    counter_tickClock();
}

