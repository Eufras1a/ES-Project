unsigned char keyscan(void)
{	
	delay_ms(50);
	while(1)
	{
			KEYPAD_CLR = (1<<R1);
			KEYPAD_SET = (1<<R2)|(1<<R3)|(1<<R4);
			delay_ms(10);
			if((KEYPAD_PIN&(1<<C1))==0){delay_ms(20);while((KEYPAD_PIN&(1<<C1))==0); return '3';}
			if((KEYPAD_PIN&(1<<C2))==0){delay_ms(20);while((KEYPAD_PIN&(1<<C2))==0); return '7';}
			if((KEYPAD_PIN&(1<<C3))==0){delay_ms(20);while((KEYPAD_PIN&(1<<C3))==0); return 'B';}
			if((KEYPAD_PIN&(1<<C4))==0){delay_ms(20);while((KEYPAD_PIN&(1<<C4))==0); return 'F';}

			KEYPAD_CLR = (1<<R2);
			KEYPAD_SET = (1<<R1)|(1<<R3)|(1<<R4);
			delay_ms(10);
			if((KEYPAD_PIN&(1<<C1))==0){delay_ms(20);while((KEYPAD_PIN&(1<<C1))==0); return '2';}
			if((KEYPAD_PIN&(1<<C2))==0){delay_ms(20);while((KEYPAD_PIN&(1<<C2))==0); return '6';}
			if((KEYPAD_PIN&(1<<C3))==0){delay_ms(20);while((KEYPAD_PIN&(1<<C3))==0); return 'A';}
			if((KEYPAD_PIN&(1<<C4))==0){delay_ms(20);while((KEYPAD_PIN&(1<<C4))==0); return 'E';}
		 
			KEYPAD_CLR = (1<<R3); 
			KEYPAD_SET = (1<<R1)|(1<<R2)|(1<<R4);
			delay_ms(10);
			if((KEYPAD_PIN&(1<<C1))==0){delay_ms(20);while((KEYPAD_PIN&(1<<C1))==0); return '1';}
			if((KEYPAD_PIN&(1<<C2))==0){delay_ms(20);while((KEYPAD_PIN&(1<<C2))==0); return '5';}
			if((KEYPAD_PIN&(1<<C3))==0){delay_ms(20);while((KEYPAD_PIN&(1<<C3))==0); return '9';}
			if((KEYPAD_PIN&(1<<C4))==0){delay_ms(20);while((KEYPAD_PIN&(1<<C4))==0); return 'D';}

			KEYPAD_CLR = (1<<R4);
			KEYPAD_SET = (1<<R1)|(1<<R2)|(1<<R3);
			delay_ms(10);
			if((KEYPAD_PIN&(1<<C1))==0){delay_ms(20);while((KEYPAD_PIN&(1<<C1))==0); return '0';}
			if((KEYPAD_PIN&(1<<C2))==0){delay_ms(20);while((KEYPAD_PIN&(1<<C2))==0); return '4';}
			if((KEYPAD_PIN&(1<<C3))==0){delay_ms(20);while((KEYPAD_PIN&(1<<C3))==0); return '8';}
			if((KEYPAD_PIN&(1<<C4))==0){delay_ms(20);while((KEYPAD_PIN&(1<<C4))==0); return 'C';}	 
	}

}
