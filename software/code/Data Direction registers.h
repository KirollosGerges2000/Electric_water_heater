
#ifndef Data_Direction_registers
#define  DATA_DIRECTION_REGISTERS_H  Data_Direction_registers()
void Data_Direction_registers(void);
#endif

void Data_Direction_registers(void)
{
	/*OUTPUTS*/
	DDRD=0xFF;
	OUTPUT_MODULE(DDRB,0); //set Enable of first 7 segment as output
	OUTPUT_MODULE(DDRA,7); //set Enable of second 7 segment as output
	OUTPUT_MODULE(DDRB,5); //set cooling fan as output
	OUTPUT_MODULE(DDRB,6); //set Heater as output
	OUTPUT_MODULE(DDRB,4); //set Heater LED as output
	
/* INPUTS*/
	INPUT_MODULE(DDRB,3); //set increment temperature button to be input
	INPUT_MODULE(DDRB,2); //set decrement temperature button to be input
	INPUT_MODULE(DDRB,1); //set OFF/ON button to be input
}