int x=0; bool en=false;
int sinus[]={0,8,16,23,31,39,47,55,63,71,78,86,93,101,108,115,122,129,
136,143,149,156,162,168,174,180,185,191,196,201,206,210,215,219,223,
227,230,234,237,239,242,244,246,248,250,251,252,253,254,254,255,254,
254,253,252,251,250,248,246,244,242,239,237,234,230,227,223,219,215,
210,206,201,196,191,185,180,174,168,162,156,149,143,136,129,122,115,
108,101,93,86,78,71,63,55,47,39,31,23,16,8,0};
void setup(){
TCCR1A = 0b10100010;
TCCR1B = 0b00011001;
TIMSK1 = 0b00000001;
ICR1   = 1600;
TCCR0A=0; TCCR0B=0; //disable millis, delay and mciroseconds function 
sei();
//pinMode(12,OUTPUT); pinMode(11,OUTPUT);     // MEGA2560
pinMode(9,OUTPUT); pinMode(10,OUTPUT);   //UNO, PRO Mini or NANO

}

void loop(){ //do nothing 
}
ISR(TIMER1_OVF_vect){
ICR1   = 1600;
if(++x>99){x=0; en=!en;}
if(en==true){
OCR1A=map(sinus[x],0,255,0,ICR1); OCR1B=0;}
else{OCR1A=0; OCR1B=map(sinus[x],0,255,0,ICR1);}
}

