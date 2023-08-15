/*
 * Data Direction registers.h
 *
 * Created: 8/14/2023 6:15:30 PM
 * Author : Kirollos
 */

#ifndef DATA_DIRECTION_REGISTER_H  
#define DATA_DIRECTION_REGISTER_H  

//	OUTPUTS
#define  PORTD0_OUT  OUTPUT_MODULE(DDRD,0) //set data that write on 7 segment as output "Pin0"
#define  PORTD1_OUT  OUTPUT_MODULE(DDRD,1) //set data that write on 7 segment as output "Pin1"
#define  PORTD2_OUT  OUTPUT_MODULE(DDRD,2) //set data that write on 7 segment as output "Pin2"
#define  PORTD3_OUT  OUTPUT_MODULE(DDRD,3) //set data that write on 7 segment as output "Pin3"
#define  PORTD4_OUT  OUTPUT_MODULE(DDRD,4) //set data that write on 7 segment as output "Pin4"
#define  PORTD5_OUT  OUTPUT_MODULE(DDRD,5) //set data that write on 7 segment as output "Pin5"
#define  PORTD6_OUT  OUTPUT_MODULE(DDRD,6) //set data that write on 7 segment as output "Pin6"
#define  PORTD7_OUT  OUTPUT_MODULE(DDRD,7) //set data that write on 7 segment as output "Pin7"


#define  PORTA0_OUT  OUTPUT_MODULE(DDRA,0) //set Enable of first 7 segment as output
#define  PORTA7_OUT OUTPUT_MODULE(DDRA,7)//set Enable of second 7 segment as output
#define  PORTB5_OUT OUTPUT_MODULE(DDRB,5) //set cooling fan as output
#define  PORTB6_OUT OUTPUT_MODULE(DDRB,6) //set Heater as output
#define  PORTB4_OUT OUTPUT_MODULE(DDRB,4) //set Heater LED as output

//INPUTS
#define  PORTB3_IN INPUT_MODULE(DDRB,3) //set increment temperature button to be input
#define  PORTB2_IN INPUT_MODULE(DDRB,2) //set decrement temperature button to be input
#define  PORTB1_IN INPUT_MODULE(DDRB,1) //set OFF/ON button to be input*/
#endif

