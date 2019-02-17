#include <MPCx58AP.h>
#include <string.h>

unsigned char temp_char=0;

void InitilizeSerial(void);
void TIMER_INIT(void);
void SERIAL_TRANSMIT(unsigned char tx_char);
void SERIAL_STRING_TX(unsigned char *tx_String);
void SERIAL_STRING_TX_LN(unsigned char *tx_String);

void main(void){

	TIMER_INIT();
	InitilizeSerial();
	P0_0 = 0;
	P2 = 0x00;
	SERIAL_STRING_TX_LN("Jai Sri Ram");
	while(1);	
}

void InitilizeSerial(void){
	SCON=0x50;
	PCON |= 0x80;
	TMOD &= 0xCF;
	TMOD |=0x20; 
	TH1 = 0xFA;   // setting buadrate to 9600 bps
	TL1 = 0x00;
	TR1=1;
	REN = 1;
	IE |= 0x90;
	
} // SERIAL_INIT ends here

void TIMER_INIT(void){
	TMOD=0x00;
	IE=0x00;
	TR0=0;
	TF0=0;
	TMOD|=0x01;
	IE|=0x82;
	TH0=0xF8;   // setting 1ms timer
	TL0=0xCD;
	TR0=1;
} // TIMER_INIT ends here

void SERIAL_STRING_TX_LN(unsigned char *tx_String){   // For sending a String
	unsigned int i,stringSize;
	
	stringSize = strlen(tx_String); // Calculate the String length
	for(i=0;i<stringSize;i++){
		temp_char = tx_String[i];  
		SERIAL_TRANSMIT(temp_char);  // Send each character to the SERIAL_TRANSMIT function
	}
	SERIAL_TRANSMIT('\r');
	SERIAL_TRANSMIT('\n');
}

void SERIAL_STRING_TX(unsigned char *tx_String){   // For sending a String
	unsigned int i,stringSize;
	
	stringSize = strlen(tx_String); // Calculate the String length
	for(i=0;i<stringSize;i++){
		temp_char = tx_String[i];  
		SERIAL_TRANSMIT(temp_char);  // Send each character to the SERIAL_TRANSMIT function
	}
}

void SERIAL_TRANSMIT(unsigned char tx_char){  // For sending each character
	SBUF=tx_char;  //Store the incoming character in SUBF
	while(TI==0);  // Wait until Tx bit is High
	TI=0;   // Make it 0 once it's high
}
