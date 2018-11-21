

void cmd_lcd(unsigned char byte)
{
	  CTRL_PORT_CLR |= ((unsigned long)(1)<<CTRL_RS);		   								// Selects Register Select for cmd	  
	  DATA_PORT_CLR |= DATA_PORT;		//Clear Data Port
      DATA_PORT_SET |= ((unsigned long)byte <<D0);					//Send byte to Data port   
	  CTRL_PORT_SET |= ((unsigned long)(1)<<CTRL_EN);
	  delay_us(100);
	  CTRL_PORT_CLR |= ((unsigned long)(1)<<CTRL_EN);
	  delay_us(100);                 
}

void data_lcd(unsigned char byte)
{
	  CTRL_PORT_SET |= ((unsigned long)(1)<<CTRL_RS);      								// Selects Register Select for data       
	  DATA_PORT_CLR |= DATA_PORT;		//Clear Data Port
      DATA_PORT_SET |= ((unsigned long)byte <<D0);					//Send byte to Data port   
	  CTRL_PORT_SET |= ((unsigned long)(1)<<CTRL_EN);
	  delay_us(100);
	  CTRL_PORT_CLR |= ((unsigned long)(1)<<CTRL_EN);
	  delay_us(100);
}

void init_lcd()
{
	  DATA_DIR |= (unsigned long)(DATA_PORT);		//initialize D0:D7 pins as output
      CTRL_DIR |= ((unsigned long)(1)<<CTRL_RS);	//initialize RS pins as output
      CTRL_DIR |= ((unsigned long)(1)<<CTRL_EN);	//initialize EN pins as output   
      CTRL_PORT_CLR |= ((unsigned long)(1)<<CTRL_EN);			//clear EN
	  CTRL_PORT_CLR |= ((unsigned long)(1)<<CTRL_RS);			//clear RS
	  delay_ms(100);
	  cmd_lcd(0x38);				       //Configure bus width as 8-bit, 2 line,5X7 dots
	  delay_ms(50);
	  cmd_lcd(0x0C);				       // DisplayOn,CursorON
	  delay_ms(1);
	  cmd_lcd(0x06);				       // EntryMode,Automatic Increment - No Display shift.
	  delay_ms(1);
	  cmd_lcd(0x01);				       //Clear Display and set address DDRAM with 0X00 
	  delay_ms(5);
}


void string_lcd(char *str)
{
while(*str)   
	data_lcd(*str++); 
}
