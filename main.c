/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/


#include "TYPES.h"
#include "MACROS.h"
#include "TYPES.h"
#include "RCC_INTERFACE.h"
#include "GPIO_INTERFACE.h"
#include "USART_INTERFACE.h"
#include "fingerPrint_interface.h"
#include "DELAY_INTERFACE.h"
#include "STRING_COMPARE.h"

#define FALSE  0
#define TRUE   1

int main(void)
{
u8 read1_sucess=0;
u8 template_sucess=0;
u8 read2_sucess=0;
	u8 * LOC_ptrName ;

	MRCC_VidInit();
	MRCC_VidEnablePeripheralClock ( APB2_BUS , GPIOA_RCC                   ) ;
	MRCC_VidEnablePeripheralClock ( APB2_BUS , USART1_RCC                  ) ;

	MGPIO_VidSetPinDirection      ( GPIOA , PIN9  , OUTPUT_SPEED_2MHZ_AFPP ) ;
	MGPIO_VidSetPinDirection      ( GPIOA , PIN10 , INPUT_FLOATING         ) ;

	MGPIO_VidSetPinDirection      ( GPIOB , PIN0 , INPUT_PULLUP_PULLDOWN         ) ;
	MGPIO_VidSetPinDirection      ( GPIOB , PIN1 , INPUT_PULLUP_PULLDOWN         ) ;
	MGPIO_VidSetPinDirection      ( GPIOB , PIN2 , INPUT_PULLUP_PULLDOWN         ) ;
	MGPIO_VidSetPinValue( GPIOB , 0 , 1);
	MGPIO_VidSetPinValue( GPIOB, 1, 1);
	MGPIO_VidSetPinValue( GPIOB , 2 , 1);

	MGPIO_VidSetPortDirection     ( GPIOA , LOW  , OUTPUT_SPEED_2MHZ_PP    ) ;

	MUSART_VidInit();
	//_delay_ms(1000);
    u8 enroll=0,search=1,empty=2;
	while(1){
		//_delay_ms(1000);
		u8 button = GET_BIT(GPIOB,enroll);
	    u8 button1= GET_BIT(GPIOB,search);
	    u8 button2= GET_BIT(GPIOB,empty);

		if(button==0)
		{
        read1_sucess=read_finger_1();

		if(read1_sucess)
		{

			 _delay_ms(1000);
	         read2_sucess=read_finger_2();
             if(read2_sucess)
             {
		    make_template();



		    	_delay_ms(1000);
 		        store(1,5);
		        _delay_ms(1000);
             }
		}
		}

	 if(button1==0)
	{

		read1_sucess=read_finger_1();

				if(read1_sucess)
				{

					 _delay_ms(500);
			         read2_sucess=read_finger_2();
		             if(read2_sucess)
		             {
				    make_template();
				    _delay_ms(500);
				    if( check_finger()==1)
				    {
					    //_delay_ms(500);

				    	MGPIO_VidSetPinValue( GPIOA , 0 , 1);
				    		    _delay_ms(500);
/*
				    MGPIO_VidSetPinValue( GPIOA , 1, 1);
				    		     _delay_ms(500);
				    MGPIO_VidSetPinValue( GPIOA , 2 , 1);
					 _delay_ms(500);
					MGPIO_VidSetPinValue( GPIOA , 3 , 1);
	    		     _delay_ms(500);
	    		     */

			    	MGPIO_VidSetPinValue( GPIOA , 0 , 0);
			    		     _delay_ms(500);
/*
			    MGPIO_VidSetPinValue( GPIOA , 1, 0);
			    		     _delay_ms(500);
			    MGPIO_VidSetPinValue( GPIOA , 2 , 0);
				 _delay_ms(500);
				MGPIO_VidSetPinValue( GPIOA , 3 , 0);
				*/
				    }
		             }
				 }
	}
	/*else if(button2==0)
	{
		 empty();
	}
	*/
//	}


		  //OpenLED();


	}
	return 0;
}

