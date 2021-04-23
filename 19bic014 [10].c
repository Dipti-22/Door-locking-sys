// coded by DIPTI SHARMA 
#include<reg51.h> // header file of c51 family
sbit r1=P1^0;    // rows
sbit r2=P1^1;
sbit r3=P1^2;
sbit r4=P1^3;
sbit c1=P1^4;    // colunms
sbit c2=P1^5;
sbit c3=P1^6;
// 4*3 keypad connection i.e 4 rows and 3 colunms    
sbit rs=P3^0;
sbit rw=P3^1;
sbit en=P3^2;
// these all are LCD control lines
sbit motp=P3^3;
sbit motn=P3^4;
// motor connections
void lcdcmd(unsigned char);
void lcddat(unsigned char);
void lcddis(unsigned char * , unsigned char);
void delay();
void check();
unsigned char pwd[10],x;
void main()
{
	lcdcmd(0x38);
	lcdcmd(0x01);
	lcdcmd(0x10);
	lcdcmd(0x0c);
	lcdcmd(0x80);
	lcddis("PASSWORD  PROTECTED",19);
	lcdcmd(0xc0);
	lcddis("SYSTEM",7);
	lcdcmd(0x01);
		lcddis("ENTER PASSWORD",14);
		lcdcmd(0xc0);
	while(1)
	{
		
		r1=0; // scanning row 0
		if(c1==0)
		{
			pwd[x]='0';		
			delay();
			lcddat('*'); // for hidding the password 
			x=x+1;
		}
		if(c2==0)
		{
			pwd[x]='2';
			delay;
			lcddat('*'); // for hidding the password
			x=x+1;
		}
		if(c3==0)
		{
			pwd[x]='3';
			delay();
			lcddat('*'); // this star is for hidding the password 
			x=x+1;
		}
		r2=0;r1=1; //scanning of row 2
		if(c1==0)
		{
			pwd[x]='4';
			delay();
			lcddat('*');
			x=x+1;
		}
		if(c2==0)
		{
			pwd[x]='5';
			delay();
			lcddat('*');
			x=x+1;
		}
		if(c3==0)
		{
			 pwd[x]='6';
			delay();
			lcddat('*');
			x=x+1;
		}
		r3=0;r2=1; // scanning of row 3
		if(c1==0)
		{
			pwd[x]='7';
			delay();
			lcddat('*');
			x=x+1;
		}
		if(c2==0)
		{
			pwd[x]='8';
			delay();
			lcddat('*');
			x=x+1;
		}
		if(c3==0)
		{
			pwd[x]='9';
			delay();
			lcddat('*');
			x=x+1;
		}
		r4=0;r3=1; // scaning of row 4
	  if(c1==0)
		{
			pwd[x]='*';
			delay();
			lcddat('*');
			x=x+1;
		}
		if(c2==0)
		{
			pwd[x]='0';
			delay();
			lcddat('*');
			x=x+1;
		}
		if(c3==0)
		{
			check();
			delay();
			delay();
		}
		r4=1;
	}
	
}
void check()
{
	if(pwd[0]=='9'&&pwd[1]=='8'&&pwd[2]=='2'&&pwd[3]=='9'&&pwd[4]=='2'&&pwd[5]=='3'&&pwd[6]=='3'&&pwd[7]=='9'&&pwd[8]=='3'&&pwd[9]=='9')
	{
		motp=1;
		motn=0;
		lcdcmd(0x01);
		lcddis("PASSWORD MATCHED",16);
		delay();
	}
	else
	{
		lcdcmd(0x01);
		lcddis("PASSWORD WRONG",14);
	}

}
void lcdcmd(unsigned char val)
{
	P2=val;
	rs=0; // control signal
	rw=1;
	en=1;
	delay();
	en=0;
}
void lcddat(unsigned char dat)
{
	P2=dat;
	rs=1;
	rw=0;
	en=0;
	delay();
	en=1;
}
void lcddis(unsigned char *s, unsigned char r)
{
	unsigned char w;
	for(w=0;w<r;w++)
	{
		lcddat(s[w]);
		delay();
	}
}
void delay()
{
	unsigned int i,j;
	for(i=0;i<4000;i++)
	{
	for(j=0;j<100;j++);
	}
}



