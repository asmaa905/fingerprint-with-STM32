/*
 * fingerPrint_interface.h
 *
 *  Created on: Apr 21, 2021
 *      Author: asmaa
 */

#ifndef FINGERPRINT_INTERFACE_H_
#define FINGERPRINT_INTERFACE_H_

u8 read_finger_1() ;
u8 read_finger_2();
void make_template();
void store(unsigned char charBuf ,unsigned int ID);
u8 check_finger();
void empty();

void VfyPwd();
void OpenLED();
//u32 GetRandomCode();

#endif /* FINGERPRINT_INTERFACE_H_ */
