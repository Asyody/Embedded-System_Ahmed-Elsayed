
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_registers.h"
#include "DIO_private.h"
#include "DIO_config.h"


void DIO_void_SetPinDirection (uint8 copy_uint8_port, uint8 copy_uint8_pin, uint8 copy_uint8_direction)
{
	if (copy_uint8_pin <= DIO_UINT8_PIN7)
	{
		if(copy_uint8_direction == DIO_UINT8_PIN_INPUT)
		{
			switch (copy_uint8_port)
			{
				case DIO_UINT8_PORTA: CLR_BIT(DDRA, copy_uint8_pin); break;
				case DIO_UINT8_PORTB: CLR_BIT(DDRB, copy_uint8_pin); break;
				case DIO_UINT8_PORTC: CLR_BIT(DDRC, copy_uint8_pin); break;
				case DIO_UINT8_PORTD: CLR_BIT(DDRD, copy_uint8_pin); break;
			}
		}
		else if (copy_uint8_direction == DIO_UINT8_PIN_OUTPUT)
		{
			switch (copy_uint8_port)
			{
				case DIO_UINT8_PORTA: SET_BIT(DDRA, copy_uint8_pin); break;
				case DIO_UINT8_PORTB: SET_BIT(DDRB, copy_uint8_pin); break;
				case DIO_UINT8_PORTC: SET_BIT(DDRC, copy_uint8_pin); break;
				case DIO_UINT8_PORTD: SET_BIT(DDRD, copy_uint8_pin); break;
			}
		}

	}


}

void DIO_void_SetPinValue (uint8 copy_uint8_port, uint8 copy_uint8_pin, uint8 copy_uint8_value)
{
	if (copy_uint8_pin <= DIO_UINT8_PIN7)
	{
		if(copy_uint8_value == DIO_UINT8_LOW)
		{
			switch (copy_uint8_port)
			{
				case DIO_UINT8_PORTA: CLR_BIT(PORTA, copy_uint8_pin); break;
				case DIO_UINT8_PORTB: CLR_BIT(PORTB, copy_uint8_pin); break;
				case DIO_UINT8_PORTC: CLR_BIT(PORTC, copy_uint8_pin); break;
				case DIO_UINT8_PORTD: CLR_BIT(PORTD, copy_uint8_pin); break;
			}
		}
		else if (copy_uint8_value == DIO_UINT8_HIGH)
		{
			switch (copy_uint8_port)
			{
				case DIO_UINT8_PORTA: SET_BIT(PORTA, copy_uint8_pin); break;
				case DIO_UINT8_PORTB: SET_BIT(PORTB, copy_uint8_pin); break;
				case DIO_UINT8_PORTC: SET_BIT(PORTC, copy_uint8_pin); break;
				case DIO_UINT8_PORTD: SET_BIT(PORTD, copy_uint8_pin); break;
			}
		}

	}

}

void DIO_void_SetPortDirection(uint8 copy_uint8_port, uint8 copy_uint8_direction)
{
	switch (copy_uint8_port)
	{
		case DIO_UINT8_PORTA: DDRA = copy_uint8_direction; break;
		case DIO_UINT8_PORTB: DDRB = copy_uint8_direction; break;
		case DIO_UINT8_PORTC: DDRC = copy_uint8_direction; break;
		case DIO_UINT8_PORTD: DDRD = copy_uint8_direction; break;
	}

}

void DIO_void_SetPortValue (uint8 copy_uint8_port,uint8 copy_uint8_value)
{
	switch (copy_uint8_port)
	{
		case DIO_UINT8_PORTA: PORTA = copy_uint8_value; break;
		case DIO_UINT8_PORTB: PORTB = copy_uint8_value; break;
		case DIO_UINT8_PORTC: PORTC = copy_uint8_value; break;
		case DIO_UINT8_PORTD: PORTD = copy_uint8_value; break;
	}
}

uint8 DIO_uint8_GetPinValue(uint8 copy_uint8_port, uint8 copy_uint8_pin)
{
	switch (copy_uint8_port)
	{
		case DIO_UINT8_PORTA:
		    if (GET_BIT(PORTA, copy_uint8_pin) == DIO_UINT8_HIGH)
            {
                return DIO_UINT8_HIGH;
            }
            else
            {
                return DIO_UINT8_LOW;
            }
            break;
		case DIO_UINT8_PORTB:
		    if (GET_BIT(PORTB, copy_uint8_pin) == DIO_UINT8_HIGH)
            {
                return DIO_UINT8_HIGH;
            }
            else
            {
                return DIO_UINT8_LOW;
            }
            break;
        case DIO_UINT8_PORTC:
		    if (GET_BIT(PORTC, copy_uint8_pin) == DIO_UINT8_HIGH)
            {
                return DIO_UINT8_HIGH;
            }
            else
            {
                return DIO_UINT8_LOW;
            }
            break;
        case DIO_UINT8_PORTD:
		    if (GET_BIT(PORTD, copy_uint8_pin) == DIO_UINT8_HIGH)
            {
                return DIO_UINT8_HIGH;
            }
            else
            {
                return DIO_UINT8_LOW;
            }
            break;
	}
}

void DIO_void_EnablePullupResistance (uint8 copy_uint8_port, uint8 copy_uint8_pin)
{
	switch (copy_uint8_port)
	{
		case DIO_UINT8_PORTA: 
			{
				DDRA = CLR_BIT(DDRA, copy_uint8_pin);
				PORTA = SET_BIT(PORTA, copy_uint8_pin);
				break;
			}
		case DIO_UINT8_PORTB: 
			{
				DDRB = CLR_BIT(DDRB, copy_uint8_pin);
				PORTB = SET_BIT(PORTB, copy_uint8_pin);
				break;
			}
		case DIO_UINT8_PORTC: 
			{
				DDRC = CLR_BIT(DDRC, copy_uint8_pin);
				PORTC = SET_BIT(PORTC, copy_uint8_pin);
				break;
			}
		case DIO_UINT8_PORTD: 
			{
				DDRD = CLR_BIT(DDRD, copy_uint8_pin);
				PORTD = SET_BIT(PORTD, copy_uint8_pin);
				break;
			}
	}
}

void DIO_void_EnablePulldownResistance (uint8 copy_uint8_port, uint8 copy_uint8_pin)
{
	switch (copy_uint8_port)
	{
		case DIO_UINT8_PORTA: 
			{
				DDRA = CLR_BIT(DDRA, copy_uint8_pin);
				PORTA = CLR_BIT(PORTA, copy_uint8_pin);
				break;
			}
		case DIO_UINT8_PORTB: 
			{
				DDRB = CLR_BIT(DDRB, copy_uint8_pin);
				PORTB = CLR_BIT(PORTB, copy_uint8_pin);
				break;
			}
		case DIO_UINT8_PORTC: 
			{
				DDRC = CLR_BIT(DDRC, copy_uint8_pin);
				PORTC = CLR_BIT(PORTC, copy_uint8_pin);
				break;
			}
		case DIO_UINT8_PORTD: 
			{
				DDRD = CLR_BIT(DDRD, copy_uint8_pin);
				PORTD = CLR_BIT(PORTD, copy_uint8_pin);
				break;
			}
	}
}

