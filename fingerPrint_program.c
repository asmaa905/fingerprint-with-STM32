/*
 * fingerPrint_program.c
 *
 *  Created on: Apr 21, 2021
 *      Author: asmaa
 */
#include"MACROS.h"
#include"TYPES.h"
#include"USART_INTERFACE.h"
#include"GPIO_INTERFACE.h"
#include"RCC_INTERFACE.h"
#include"DELAY_INTERFACE.h"
#include <string.h>
#include<stdbool.h>
u8 read_finger_1()          //for char_buffer1
{
      int i=0;
      unsigned char  k=1,ch=1;
     	   /* To genetrate finger  GetRandomCode */
     	      /*       MUSART1_VidSendCharSync(0xef);//header =0xEF01

     	             MUSART1_VidSendCharSync(0x01);// header =0xEF01

     	             MUSART1_VidSendCharSync(0xff);//address 0xffffffff

     	             MUSART1_VidSendCharSync(0xff);//address 0xff

     	             MUSART1_VidSendCharSync(0xff);//address 0xff

     	             MUSART1_VidSendCharSync(0xff);//address 0xff

     	             MUSART1_VidSendCharSync(0x01);//ID

     	             MUSART1_VidSendCharSync(0x00);

     	             MUSART1_VidSendCharSync(0x03);//length

     	             MUSART1_VidSendCharSync(0x14);

     	             MUSART1_VidSendCharSync(0x00);

     	             MUSART1_VidSendCharSync(0x18);

     	             	      for(i=0;i<10;i++)

     	             	      {

     	             	            k=MUSART1_u8RecCharSynch();
     	             	           // itoa(k,(unsigned char*)sstring,16);
     	             	        // systick_lcd_print_data(k);

     	             	            if(i==9)

     	             	            {

     	             	                  ch=k;
     	             	                  int j;

     	             	                  for(j=0;j<4;j++)
     	             	                  {
     	             		                  k=MUSART1_u8RecCharSynch();
     	             		              	 // itoa(ID[j],(unsigned char*)string,10);

     	             		              	//systick_lcd_print_data(k);
     	             	                  }

     	             	                 // k=MUSART1_u8RecCharSynch();

     	             	                  if(ch==0x00||ch==0x21)
     	             	                  {
     	             	                	MGPIO_VidSetPinValue( GPIOA , 0 , 1);
     	             	                  }
 	             		                  k=MUSART1_u8RecCharSynch();
 	             		                  k=MUSART1_u8RecCharSynch();

     	             	            }
     	             	      }*/
     	         		//_delay_ms(500);//1000
/* To collect finger image GenImg */
     MUSART1_VidSendCharSync(0xef);/* header =0xEF01*/
     MUSART1_VidSendCharSync(0x01);/* header =0xEF01*/;
     MUSART1_VidSendCharSync(0xff);/*address 0xffffffff*/
     MUSART1_VidSendCharSync(0xff);/*address 0xff*/
     MUSART1_VidSendCharSync(0xff);/*address 0xff*/
     MUSART1_VidSendCharSync(0xff);/*address 0xff*/
     MUSART1_VidSendCharSync(0x01);/*ID*/
     MUSART1_VidSendCharSync(0x00);
     MUSART1_VidSendCharSync(0x03);//length
     MUSART1_VidSendCharSync(0x01);
     MUSART1_VidSendCharSync(0x00);
     MUSART1_VidSendCharSync(0x05);
      for(i=0;i<10;i++)//0-9
      {
            k=MUSART1_u8RecCharSynch();//0-9 //10
            if(i==9)//10
            {
                  ch=k;
                  k=MUSART1_u8RecCharSynch();//10
                  k=MUSART1_u8RecCharSynch();
                  if(ch==0x00||ch==0x21)
                  {
	                	MGPIO_VidSetPinValue( GPIOA , 2 , 1);
 	         			//_delay_ms(500);//1000
               /*generate character file from image char file img2tz #1*/
                       MUSART1_VidSendCharSync(0xef);
                       MUSART1_VidSendCharSync(0x01);
                       MUSART1_VidSendCharSync(0xff);
                       MUSART1_VidSendCharSync(0xff);
                       MUSART1_VidSendCharSync(0xff);
                       MUSART1_VidSendCharSync(0xff);
                       MUSART1_VidSendCharSync(0x01);//id
                       MUSART1_VidSendCharSync(0x00);
                       MUSART1_VidSendCharSync(0x04);//length
                       MUSART1_VidSendCharSync(0x02);
                       MUSART1_VidSendCharSync(0x01);
                       MUSART1_VidSendCharSync(0x00);
                       MUSART1_VidSendCharSync(0x08);
                        i=0;
                        for(i=0;i<10;i++)
                        {
                              k=MUSART1_u8RecCharSynch();
                              if(i==9)
                              {
                                    ch=k;
                                    k=MUSART1_u8RecCharSynch();
                                    k=MUSART1_u8RecCharSynch();
                                    if(ch==0x00||ch==0x21)
                                    {

 	             	                	MGPIO_VidSetPinValue( GPIOA , 5 , 1);
 	                            		//_delay_ms(500);//1000
 	                            		return 1;
                                    }
                              }
                        }
                  }
            }
      }
      return 0;
}
u8 read_finger_2()          //for char_buffer2
{
      int i=0;
      char k=1,ch=1;

/***** To collect finger image GenImg *****/

     MUSART1_VidSendCharSync(0xef);
     MUSART1_VidSendCharSync(0x01);
     MUSART1_VidSendCharSync(0xff);
     MUSART1_VidSendCharSync(0xff);
     MUSART1_VidSendCharSync(0xff);
     MUSART1_VidSendCharSync(0xff);
     MUSART1_VidSendCharSync(0x01);
     MUSART1_VidSendCharSync(0x00);
     MUSART1_VidSendCharSync(0x03);
     MUSART1_VidSendCharSync(0x01);
     MUSART1_VidSendCharSync(0x00);
     MUSART1_VidSendCharSync(0x05);
      for(i=0;i<10;i++)
      {
            k=MUSART1_u8RecCharSynch();
            if(i==9)
            {
                  ch=k;
                  k=MUSART1_u8RecCharSynch();
                  k=MUSART1_u8RecCharSynch();
                  if(ch==0x000||ch==0x21)
                  {
	                	MGPIO_VidSetPinValue( GPIOA , 6 , 1);

                        k=1;
 	         		//	_delay_ms(500);//1000

/*To generate character file from image Img2Tz char file #2*/
                       MUSART1_VidSendCharSync(239);
                       MUSART1_VidSendCharSync(1);
                       MUSART1_VidSendCharSync(255);
                       MUSART1_VidSendCharSync(255);
                       MUSART1_VidSendCharSync(255);
                       MUSART1_VidSendCharSync(255);
                       MUSART1_VidSendCharSync(1);//id
                       MUSART1_VidSendCharSync(0);
                       MUSART1_VidSendCharSync(4);//lenght
                       MUSART1_VidSendCharSync(2);
                       MUSART1_VidSendCharSync(2);
                       MUSART1_VidSendCharSync(0);
                       MUSART1_VidSendCharSync(9);
                        i=0;
                        for(i=0;i<10;i++)
                        {
                              k=MUSART1_u8RecCharSynch();
                              if(i==9)
                              {
                                    ch=k;
                                    k=MUSART1_u8RecCharSynch();
                                    k=MUSART1_u8RecCharSynch();
                                    if(ch==0x00||ch==0x21)
 	             	                	{
                                    	MGPIO_VidSetPinValue( GPIOA , 7 , 1);
             	         			//_delay_ms(500);//1000
             	         			return 1;
 	             	                	}
                                    else if(ch==0x01||ch==0x21)//error when receiving package;
 	             	                	MGPIO_VidSetPinValue( GPIOA , 8 , 1);
                                    else if(ch==0x06)//fail to generate character file due to the over-disorderly fingerprint image;
 	             	                	MGPIO_VidSetPinValue( GPIOA , 0 , 1);
                                    else if(ch==0x07)//fail to generate character file due to lackness of character point or over-smallness of fingerprint image;
 	             	                	MGPIO_VidSetPinValue( GPIOA , 1 , 1);
                                    else if(ch==0x15)//fail to generate the image for the lackness of valid primary image;
                                    {
 	             	                	MGPIO_VidSetPinValue( GPIOA , 4 , 1);
             	         			//_delay_ms(500);//1000
                                    }


                              }

                        }

                  }

            }

      }
		return 0;

}
/* To generate template RegModel */
void make_template()
{
	 //systick_lcd_clear_screen();
	// systick_lcd_print_string((unsigned char *)"make template ");
      int i=0;
      char k=1,ch=1;
	//  _delay_ms(1000);

     MUSART1_VidSendCharSync(0xEF);
     MUSART1_VidSendCharSync(0x01);
     MUSART1_VidSendCharSync(0xFF);
     MUSART1_VidSendCharSync(0xFF);
     MUSART1_VidSendCharSync(0xFF);
     MUSART1_VidSendCharSync(0xFF);
     MUSART1_VidSendCharSync(0x01);//ID
     MUSART1_VidSendCharSync(0x00);
     MUSART1_VidSendCharSync(0x03);//length
     MUSART1_VidSendCharSync(0x05);//instruct code
     MUSART1_VidSendCharSync(0x00);
     MUSART1_VidSendCharSync(0x09);//sum = ID + length + instruct code=1+3+5

      for(i=0;i<10;i++)
      {
            k=MUSART1_u8RecCharSynch();
           // systick_lcd_clear_screen();
            //  systick_lcd_print_data((unsigned char *)k);
            if(i==9)
            {
                  ch=k;
                  k=MUSART1_u8RecCharSynch();
                  k=MUSART1_u8RecCharSynch();


                  if(ch==0x00||ch==0x21)
                  {

	                	MGPIO_VidSetPinValue( GPIOA , 0 , 1);
	                	 // _delay_ms(500);

                  }
                  else if (ch==0x01)//error when receiving package;
                  {

	                	MGPIO_VidSetPinValue( GPIOA , 7, 1);
	                	//_delay_ms(500);

                  }
                  else if (ch==0x0a)//That’s, the character files don’t belong to one finger.
                  {

	                	MGPIO_VidSetPinValue( GPIOA , 7, 1);
	                	//_delay_ms(500);
                  }
            }
      }
}

u8 check_finger()
{
int i=0;
u8 k=1,ch=1;

u8 matchScore1=0;
u8 matchScore2=0;

u8 pageNo1=0;
u8 pageNo2=0;

//char* sstring='1';
MUSART1_VidSendCharSync(0xef);
MUSART1_VidSendCharSync(0x01);
MUSART1_VidSendCharSync(0xff);//1
MUSART1_VidSendCharSync(0xff);//2
MUSART1_VidSendCharSync(0xff);//3
MUSART1_VidSendCharSync(0xff);//4
MUSART1_VidSendCharSync(0x01);//ID
MUSART1_VidSendCharSync(0x00);//length
MUSART1_VidSendCharSync(0x08);
MUSART1_VidSendCharSync(0x04);
MUSART1_VidSendCharSync(0x01);
MUSART1_VidSendCharSync(0x00);
MUSART1_VidSendCharSync(0x00);
MUSART1_VidSendCharSync(0x00);
MUSART1_VidSendCharSync(0xA3);//page no
MUSART1_VidSendCharSync(0x00);
MUSART1_VidSendCharSync(0xb7);
for(i=0;i<10;i++)
{
  k=MUSART1_u8RecCharSynch();
  if(i==9)
  {
     ch=k;
     pageNo1=MUSART1_u8RecCharSynch();
     pageNo2=MUSART1_u8RecCharSynch();
    /* if(pageNo2==0)
     {
     	MGPIO_VidSetPinValue( GPIOA , 0, 1);
      //  _delay_ms(500);

     }
     else if(pageNo2==1)
     {
     	MGPIO_VidSetPinValue( GPIOA , 1, 1);
      //  _delay_ms(500);

     }
     else if(pageNo2==2)
     {
     	MGPIO_VidSetPinValue( GPIOA , 2, 1);
       // _delay_ms(500);

     }
     else if(pageNo2==3)
     {
     	MGPIO_VidSetPinValue( GPIOA , 3, 1);
        //_delay_ms(500);

     }
     else if(pageNo2==4)
      {
     	MGPIO_VidSetPinValue( GPIOA , 4, 1);
       // _delay_ms(500);

      }
     else if(pageNo2==5)
     {
        MGPIO_VidSetPinValue( GPIOA , 5, 1);
        //_delay_ms(500);

     }
     */
     matchScore1=MUSART1_u8RecCharSynch();
      matchScore2=MUSART1_u8RecCharSynch();
      k=MUSART1_u8RecCharSynch();
      k=MUSART1_u8RecCharSynch();
      if(ch==0x21||ch==0x00)////page no
      {

    	 MGPIO_VidSetPinValue( GPIOA , 4, 1);
        // _delay_ms(500);
         return 1;

        // LCD_vidWriteString(pageNo1);
       // LCD_vidWriteString(pageNo2);
        // LCD_vidWriteString(matchScore1);
       //   LCD_vidWriteString(matchScore2);

      }
      else
      {
     	 MGPIO_VidSetPinValue( GPIOA , 4, 0);
         // _delay_ms(500);
      }

  }

}
return 0;
}
void store(unsigned char charBuf ,unsigned int ID)
{
      unsigned char  i=0,sum=14+ID;
      unsigned char k=1,ch=1;
     MUSART1_VidSendCharSync(239);
     MUSART1_VidSendCharSync(1);
     MUSART1_VidSendCharSync(255);
     MUSART1_VidSendCharSync(255);
     MUSART1_VidSendCharSync(255);
     MUSART1_VidSendCharSync(255);
     MUSART1_VidSendCharSync(1);
     MUSART1_VidSendCharSync(0);
     MUSART1_VidSendCharSync(6);
     MUSART1_VidSendCharSync(6);
     MUSART1_VidSendCharSync(charBuf);
     MUSART1_VidSendCharSync((unsigned char )(ID>>8));
     MUSART1_VidSendCharSync((unsigned char )ID);
     MUSART1_VidSendCharSync(0);//C
     MUSART1_VidSendCharSync(sum);//C
     for(i=0;i<10;i++)
            {
                  k=MUSART1_u8RecCharSynch();
                  if(i==9)
                  {
                        ch=k;
                        k=MUSART1_u8RecCharSynch();
                        k=MUSART1_u8RecCharSynch();
                        if(ch==0x00||ch==0x21)
    	                	MGPIO_VidSetPinValue( GPIOA , 6, 1);
 	         			//_delay_ms(500);//1000

                  }
            }
}
void empty()
{
      int i=0;
      unsigned char k=1,ch=1;
     MUSART1_VidSendCharSync(0xef);
     MUSART1_VidSendCharSync(0x01);
     MUSART1_VidSendCharSync(0xff);
     MUSART1_VidSendCharSync(0xff);
     MUSART1_VidSendCharSync(0xff);
     MUSART1_VidSendCharSync(0xff);
     MUSART1_VidSendCharSync(0x01);
     MUSART1_VidSendCharSync(0x00);
     MUSART1_VidSendCharSync(0x03);
     MUSART1_VidSendCharSync(0x0d);
     MUSART1_VidSendCharSync(0x00);
     MUSART1_VidSendCharSync(0x11);
     for(i=0;i<10;i++)
        {
          k=MUSART1_u8RecCharSynch();
          if(i==9)
           {
             ch=k;
             k=MUSART1_u8RecCharSynch();
             k=MUSART1_u8RecCharSynch();
             if(ch==0x00||ch==0x21)
             	MGPIO_VidSetPinValue( GPIOA , 6, 1);
             else
             	MGPIO_VidSetPinValue( GPIOA , 8, 1);

           }
        }
}
void VfyPwd()
{
	unsigned char k=1,ch=1;
   MUSART1_VidSendCharSync(0xEF);//header
   MUSART1_VidSendCharSync(0x01);
   MUSART1_VidSendCharSync(0xff);//adress 0xffffffff
   MUSART1_VidSendCharSync(0xff);
   MUSART1_VidSendCharSync(0xff);
   MUSART1_VidSendCharSync(0xff);
   MUSART1_VidSendCharSync(0x01);//cmd verify 0x01
   MUSART1_VidSendCharSync(0x00);//length 0x07
   MUSART1_VidSendCharSync(0x07);//length
   MUSART1_VidSendCharSync(0x13);//instruction code 0x13
   MUSART1_VidSendCharSync(0x00);//data password 0x00000000
   MUSART1_VidSendCharSync(0x00);
   MUSART1_VidSendCharSync(0x00);
   MUSART1_VidSendCharSync(0x00);
   MUSART1_VidSendCharSync(0x1b);// check sum
   int i;
    for(i=0;i<10;i++)
     {
        k=MUSART1_u8RecCharSynch();
         if(i==9)
           {
             ch=k;

             k=MUSART1_u8RecCharSynch();
             k=MUSART1_u8RecCharSynch();
             if(ch==0x21)
             {
               	MGPIO_VidSetPinValue( GPIOA , 7 , 1);

             }
             else  if(ch==0x01)
             {
               	MGPIO_VidSetPinValue( GPIOA , 8 , 1);

             }
             else  if(ch==0x13)
             {   MGPIO_VidSetPinValue( GPIOA , 6, 1);

             }
           }
     }
}
/*void portControl()
{
	char k=1,ch=1;
	MUSART1_VidSendCharSync(239);//ef
     MUSART1_VidSendCharSync(1);//1
     MUSART1_VidSendCharSync(255);//ffffffff
	 MUSART1_VidSendCharSync(255);
	 MUSART1_VidSendCharSync(255);
     MUSART1_VidSendCharSync(255);
     MUSART1_VidSendCharSync(1);//1 =>id
     MUSART1_VidSendCharSync(0);// length 0004
     MUSART1_VidSendCharSync(4);//04
     MUSART1_VidSendCharSync(23);//instr 0x17
     MUSART1_VidSendCharSync(1);//0x00
     MUSART1_VidSendCharSync(0);//sum
	 MUSART1_VidSendCharSync(29);
     int i;
	 for(i=0;i<10;i++)
	 {
		 k=MUSART1_u8RecCharSynch();//0
           if(i==9)
           {
              ch=k;
              k=MUSART1_u8RecCharSynch();
              k=MUSART1_u8RecCharSynch();
            if(ch==0x00||ch==0x21)
            {
		      PORTC^=(1<<0);
		      systick_lcd_clear_screen();
			   systick_lcd_print_string((unsigned char*)"port open");
            }
			 else  if(ch==0x01)//error when receiving package
			 {
				 PORTC^=(1<<6);
			      systick_lcd_clear_screen();
			       systick_lcd_print_string((unsigned char*)"Error");
			 }
			  else  if(ch==0x1d)//fail to operate the communication port
			  {
				  PORTC^=(1<<7);
			       systick_lcd_clear_screen();
			         systick_lcd_print_string((unsigned char*)"fail");
			  }

           }

	 }
}
void CloseLED()
{
	char k=1,ch=1;
	MUSART1_VidSendCharSync(0xef);//ef
	MUSART1_VidSendCharSync(0x01);//1
    MUSART1_VidSendCharSync(0xff);//ffffffff
	MUSART1_VidSendCharSync(0xff);
    MUSART1_VidSendCharSync(0xff);
    MUSART1_VidSendCharSync(0xff);
	MUSART1_VidSendCharSync(0x01);//1 =>id
    MUSART1_VidSendCharSync(0x00);// length 0003
    MUSART1_VidSendCharSync(0x03);//03
    MUSART1_VidSendCharSync(0x51);//instr 0x01
    MUSART1_VidSendCharSync(0x00);//sum
    MUSART1_VidSendCharSync(0x55);
      int i;
	  for(i=0;i<10;i++)
		{
		 k=MUSART1_u8RecCharSynch();//0
		if(i==9)
		 {
	      ch=k;
			k=MUSART1_u8RecCharSynch();
			 k=MUSART1_u8RecCharSynch();
			 if(ch==0x00||ch==0x21)     //finger collection success;
			{
				 PORTC^=(1<<1 );
				 _delay_ms(1000);

			}
			else  //error when receiving package
			 PORTC^=(1<<7);
			 _delay_ms(1000);

		 }
		}
}
*/
void OpenLED()
{
    char k=1,ch=1;
	MUSART1_VidSendCharSync(0xef);//ef
    MUSART1_VidSendCharSync(0x01);//1
    MUSART1_VidSendCharSync(0xff);//ffffffff
	MUSART1_VidSendCharSync(0xff);
    MUSART1_VidSendCharSync(0xff);
	MUSART1_VidSendCharSync(0xff);
	MUSART1_VidSendCharSync(0x01);//1 =>id
    MUSART1_VidSendCharSync(0x00);// length 0003
	MUSART1_VidSendCharSync(0x03);//03
    MUSART1_VidSendCharSync(0x01);//instr 0x01
    MUSART1_VidSendCharSync(0x00);//sum
    MUSART1_VidSendCharSync(0x06);
			         int i;
				     for(i=0;i<10;i++)
				      {
				       k=MUSART1_u8RecCharSynch();//0
				       if(i==9)
				        {
	                     ch=k;
				         k=MUSART1_u8RecCharSynch();
				         k=MUSART1_u8RecCharSynch();
				         if(ch==0x00||ch==0x21)     //finger collection success;
				         {
       	                	MGPIO_VidSetPinValue( GPIOA , 0 , 1);

				         }
				         else  //error when receiving package
				            {
       	                	MGPIO_VidSetPinValue( GPIOA , 1 , 1);

				            }

				        }
				      }
}
