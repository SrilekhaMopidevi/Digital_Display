#include <8031.h>
#include "H_16_Eng.h"
#include "H_16_Tam.h"

#define MAX 120
#define CHAR 350
#define NOCHAR 12000
#define DELAY 500
#define ANI 5

far unsigned char at (0x0000) Buff1[12000]; 
far unsigned char Buff2[10000]; 
far unsigned char Buff3[10000];
far unsigned char at (0x8000) dport[100];
far unsigned char Zero[1];

unsigned int Offset=0,Check=0,Glob=0;
unsigned int Check1=0;
unsigned char row,Count=0,Ext1=0,Ext2=0;
unsigned int Get1=0, Get2=0;
bit DInt=1;

const unsigned char Mess1[] = {"KHADIKRAFT"};
const unsigned char Mess2[] = {"KHADIKRAFT WELCOMES YOU"}; //English
const unsigned char Mess3[] = {"fhjp fpuhg;l;"};
const unsigned char Mess4[] = {"fhjp fpuhg;l; cq;fis md;g[ld; tuntw;fpwJ"}; //Tamil

void Display0(void); // right to left
void Display1(void); // still
void Display2(void); // rolling top to bottom & bottom to top
void Delay(unsigned char);
void ECharLoad(unsigned char);
void TCharLoad(unsigned char);
void Blank0(void);
void Blank1();
void AddBlank(void);
void Start(void);
void ProcessData(void);
void Center(void);
unsigned char GetEffect(void);
void Load(void);
void InitilizeSerial(void);
unsigned char Getch(void);
interrupt void SerialInt(void);

void main(void)
{
    Blank0();
    InitilizeSerial();
    EI();
        if(Buff1[0] != '0')
                Start();
    for(;;)
    {
        DInt = 1;
                ProcessData();
    }
}

void Start(void)
{
        unsigned int i,j=0;
        
        //Mess1
        Buff1[j++] = '0';
        Buff1[j++] = '1';
        Buff1[j++] = '~';
        Buff1[j++] = 'e';
        i=0;
        while(Mess1[i] != 0)
                Buff1[j+i] = Mess1[i++];
        j += i;
        Buff1[j++] = '|';
        
        //Mess2
        Buff1[j++] = '0';
        Buff1[j++] = '0';
        Buff1[j++] = '~';
        Buff1[j++] = 'e';
        i=0;
        while(Mess2[i] != 0)
                Buff1[j+i] = Mess2[i++];
        j += i;
        Buff1[j++] = '|';
        
        //Mess3
        Buff1[j++] = '0';
        Buff1[j++] = '1';
        Buff1[j++] = '~';
        Buff1[j++] = 't';
        i=0;
        while(Mess3[i] != 0)
                Buff1[j+i] = Mess3[i++];
        j += i;
        Buff1[j++] = '|';
        
        //Mess4
        Buff1[j++] = '0';
        Buff1[j++] = '0';
        Buff1[j++] = '~';
        Buff1[j++] = 't';
        i=0;
        while(Mess4[i] != 0)
                Buff1[j+i] = Mess4[i++];
        j += i;
        Buff1[j++] = '|';
        
        //End
        Buff1[j++] = 0;
}

void ProcessData(void)
{
        unsigned char j;
        Glob=0;
        while((Buff1[Glob] != 0) && (DInt))
        {
                switch(GetEffect())
                {
                        case 0: //Right To Left
                        {
                                Top0:
                                Offset=0;
                                AddBlank();
                                Offset = MAX;
                                Check1 = (10000-(2*MAX)-40);
                                Load();
                                AddBlank();
                                Check=0;
                                while(Check < Offset)
                                {
                                        Display0();
                                        Check++;
                                } 
                                if(Check1 == 1)
                                        goto Top0;
                                break;
                        }
                        case 1: //Still
                        {
                                Top1:
                                Offset=0;
                                AddBlank();
                                Offset = MAX;
                                Check1 = (2*MAX);
                                Load();
                                AddBlank();
                                Center();
                                for(j=0;j<=DELAY;j++)
                                        Display1();
                                if(Check1 == 1)
                                        goto Top1;
                                break;
                        }
                        case 2: //RollDown
                        { 
                                Top2:
                                Offset=0;
                                AddBlank();
                                Offset = MAX;
                                Check1 = (2*MAX);
                                Load();
                                AddBlank();
                                Center();
                                Ext1=0x00;Ext2=0x00;
                                for(j=0;j<=ANI;j++)
                                        Display2();
                                Ext1 = 0x01;
                                for(j=0;j<=ANI;j++)
                                        Display2();
                                Ext1 = 0x03;
                                for(j=0;j<=ANI;j++)
                                        Display2();
                                Ext1 = 0x07;
                                for(j=0;j<=ANI;j++)
                                        Display2();
                                Ext1 = 0x0F;
                                for(j=0;j<=ANI;j++)
                                        Display2();
                                Ext1 = 0x1F;
                                for(j=0;j<=ANI;j++)
                                        Display2();
                                Ext1 = 0x3F;
                                for(j=0;j<=ANI;j++)
                                        Display2();
                                Ext1 = 0x7F;
                                for(j=0;j<=ANI;j++)
                                        Display2();
                                Ext1 = 0xFF;
                                for(j=0;j<=ANI;j++)
                                        Display2();
                                Ext2 = 0x01;
                                for(j=0;j<=ANI;j++)
                                        Display2();
                                Ext2 = 0x03;
                                for(j=0;j<=ANI;j++)
                                        Display2();
                                Ext2 = 0x07;
                                for(j=0;j<=ANI;j++)
                                        Display2();
                                Ext2 = 0x0F;
                                for(j=0;j<=ANI;j++)
                                        Display2();
                                Ext2 = 0x1F;
                                for(j=0;j<=ANI;j++)
                                        Display2();
                                Ext2 = 0x3F;
                                for(j=0;j<=ANI;j++)
                                        Display2();
                                Ext2 = 0x7F;
                                for(j=0;j<=ANI;j++)
                                        Display2();
                                Ext2 = 0xFF;
                                for(j=0;j<=ANI;j++)
                                        Display2();
                                for(j=0;j<=DELAY;j++)
                                        Display2();
                                if(Check1 == 1)
                                        goto Top2;
                                break;
                        }
                        case 3: //RollTop
                        {
                                Top3:
                                Offset=0;
                                AddBlank();
                                Offset=MAX;
                                Check1=(2*MAX);
                                Load();
                                AddBlank();
                                Center();
                                Ext1=0x00;Ext2=0x00;
                                for(j=0;j<=ANI;j++)
                                        Display2();
                                Ext2 = 0x80;
                                for(j=0;j<=ANI;j++)
                                        Display2();
                                Ext2 = 0xC0;
                                for(j=0;j<=ANI;j++)
                                        Display2();
                                Ext2 = 0xE0;
                                for(j=0;j<=ANI;j++)
                                        Display2();
                                Ext2 = 0xF0;
                                for(j=0;j<=ANI;j++)
                                        Display2();
                                Ext2 = 0xF8;
                                for(j=0;j<=ANI;j++)
                                        Display2();
                                Ext2 = 0xFC;
                                for(j=0;j<=ANI;j++)
                                        Display2();
                                Ext2 = 0xFE;
                                for(j=0;j<=ANI;j++)
                                        Display2();
                                Ext2 = 0xFF;
                                for(j=0;j<=ANI;j++)
                                        Display2();
                                Ext1 = 0x80;
                                for(j=0;j<=ANI;j++)
                                        Display2();
                                Ext1 = 0xC0;
                                for(j=0;j<=ANI;j++)
                                        Display2();
                                Ext1 = 0xE0;
                                for(j=0;j<=ANI;j++)
                                        Display2();
                                Ext1 = 0xF0;
                                for(j=0;j<=ANI;j++)
                                        Display2();
                                Ext1 = 0xF8;
                                for(j=0;j<=ANI;j++)
                                        Display2();
                                Ext1 = 0xFC;
                                for(j=0;j<=ANI;j++)
                                        Display2();
                                Ext1 = 0xFE;
                                for(j=0;j<=ANI;j++)
                                        Display2();
                                Ext1 = 0xFF;
                                for(j=0;j<=ANI;j++)
                                        Display2();
                                for(j=0;j<=DELAY;j++)
                                        Display2();
                                if(Check1 == 1)
                                        goto Top3;
                                break;
                        }
                }
                Glob++;
        }
}

unsigned char GetEffect(void)
{
        if((Buff1[Glob++] == '0') && (Buff1[Glob++] == '0')) //Right To Left
                return(0); 
        Glob-=2;     
  
        if((Buff1[Glob++] == '0') && (Buff1[Glob++] == '1')) //Still
                return(1);
        Glob-=2;      
  
        if((Buff1[Glob++] == '0') && (Buff1[Glob++] == '2')) //Roll Down
                return(2); 
        Glob-=2;   
  
        if((Buff1[Glob++] == '0') && (Buff1[Glob++] == '3')) //Roll Top
                return(3);
        Glob-=2;  
}

void Load(void)
{
    unsigned char Lang=0,i,n,ch;
    while((Buff1[Glob] != '|') && (DInt))
    {
        if(Buff1[Glob] == '~')
        {
            Glob++;
            if(Buff1[Glob] == 'e')
                                Lang=0;
            else if(Buff1[Glob] == 't')
                                Lang=1;
                }
        else
                {
            if(Lang == 0)
                ECharLoad(Buff1[Glob]);
                    else if(Lang == 1)
            {
                TCharLoad(Buff1[Glob]);
                Glob++;
                ch = Buff1[Glob];
                if(ch == ';')
                                {
                    ch -= ' ';
                    n = H_16_Tam[ch][0];
                    Offset -= (Count/2)+1;
                    for(i=0;i<n;i++)
                    {
                        Buff2[(Offset+i)] |= H_16_Tam[ch][i+1];
                        Buff3[(Offset+i)] |= H_16_Tam[ch][i+1+n];
                    }
                    Offset += ((Count/2)+1);
                }
                else if(ch == ':')
                                {
                    ch -= ' ';
                    n = H_16_Tam[ch][0];
                    Offset -= Count+1;
                    for(i=0;i<n;i++)
                    {
                        Buff2[(Offset+i)] |= H_16_Tam[ch][i+1];
                        Buff3[(Offset+i)] |= H_16_Tam[ch][i+1+n];
                    }
                    Offset += Count+1;
                }                
                                else if(ch == '}')
                                {
                    ch -= ' ';
                    n = H_16_Tam[ch][0];
                    Offset -= 2;
                    for(i=0;i<n;i++)
                    {
                        Buff2[(Offset+i)] = H_16_Tam[ch][i+1];
                        Buff3[(Offset+i)] = H_16_Tam[ch][i+1+n];
                    }
                    Offset += n;
                }
                else if((ch == 'p') || (ch == 'P'))
                {
                    ch -= ' ';
                    n = H_16_Tam[ch][0];
                    for(i=0;i<9;i++)
                    {
                        Buff2[(Offset+i)] = 0x00;
                        Buff3[(Offset+i)] = 0x00;
                    }
                    Offset -= 6;
                    for(i=0;i<(n-1);i++)
                    {
                        Buff2[(Offset+i)] |= H_16_Tam[ch][i+1];
                        Buff3[(Offset+i)] |= H_16_Tam[ch][i+1+n];
                                        }
                    Buff2[(Offset+i)] = 0x00;
                    Buff3[(Offset+i)] = 0x00;
                    Offset += n;
                }
                else if(ch == '[')
                {
                    ch -= ' ';
                    n = H_16_Tam[ch][0];
                    for(i=0;i<n;i++)
                    {
                        Buff2[(Offset+i-3)] |= H_16_Tam[ch][i+1];
                        Buff3[(Offset+i-3)] |= H_16_Tam[ch][i+1+n];
                    }
                                }
                else if(ch == '{')
                {
                   ch -= ' ';
                    n = H_16_Tam[ch][0];
                    for(i=0;i<9;i++)
                    {
                        Buff2[(Offset+i)] = 0x00;
                        Buff3[(Offset+i)] = 0x00;
                    }
                    Offset -= 15;
                    for(i=0;i<(n-1);i++)
                    {
                        Buff2[(Offset+i)] |= H_16_Tam[ch][i+1];
                        Buff3[(Offset+i)] |= H_16_Tam[ch][i+1+n];
                                        }
                    Buff2[(Offset+i)] = 0x00;
                    Buff3[(Offset+i)] = 0x00;
                    Offset += n;
                                }
                else
                                        Glob--;
            }
            if(Offset > Check1)
            {
                Check1 = 1;
                Offset -= Count;
                                AddBlank();
                break;
            }
        }
        Glob++;
    }
}

void Center(void)
{
    unsigned int i;
    i = (Offset - MAX);
    if(i <= MAX)
    {
                Check = (MAX - ((MAX-i)/2));
    }
    else
        Check = MAX;
}

interrupt void SerialInt(void)
{
    unsigned int i=0;
    unsigned char Ch;
    DI();
    SET_VECTOR(SINT,SerialInt);
    Ch = Getch();
    if(Ch == '~')
    {
        EI();
        Ch=Getch();
        while((Ch != '^') && (i < (NOCHAR-1)))
        {
            Buff1[i++] = Ch;
            EI();
            Ch=Getch();
                        if(Ch == 1)
                                break;
        }
        Buff1[i]=0;
                DInt=0;
                if((Ch == 1) || (Buff1[0] != '0') || (i == (NOCHAR-1)))
                {
                        DI();
                        Start();
                        EI();
                }
    }
    EI();
}

unsigned char Getch(void)
{
        Get1=0;
        Get2=0;
        while((!RI) && (Get2 < 2))
        {
                Get1++;
                if(Get1 >= 60000)
                {
                        Get1 = 0;
                        Get2++;
                }
        }
        RI = 0;
        if(Get2 >= 2)
                return 1;       
        else
                return SBUF;
}

void ECharLoad(unsigned char n)
{
    unsigned char i,j=1;
    if((n >= ' ') && (n <= '}'))
    {
        n -= ' ';
        Count = H_16_Eng[n][0];
        for(i=0;i<Count;i++)
        {
            Buff2[Offset+i] = H_16_Eng[n][j];
            Buff3[Offset+i] = H_16_Eng[n][j+1];
            j+=2;
        }
        Offset += Count;
        for(i=0;i<2;i++)
        {
            Buff2[Offset+i] = 0;
            Buff3[Offset+i] = 0;
        }
        Offset += 2;
    }
}

void TCharLoad(unsigned char n)
{
        unsigned char i;
        if((n >= ' ') && (n <= '}'))
        {
                n -= ' ';
                Count = H_16_Tam[n][0];
                for(i=0;i < Count;i++)
                {
                        Buff2[Offset+i] = H_16_Tam[n][i+1];
                        Buff3[Offset+i] = H_16_Tam[n][i+1+Count];
                }
                Offset += Count;
                for(i=0;i<1;i++)
                {
                        Buff2[Offset+i] = 0;
                        Buff3[Offset+i] = 0;
                }
                Offset += 1;
        }
} 

void AddBlank(void)
{
    unsigned int i=0;
    for(i=0;i<MAX;i++)
    { 
        Buff2[Offset+i] = 0x00;
        Buff3[Offset+i] = 0x00;
        }
}

void Display0(void)
{
        unsigned char i;
        for(row=0;((row<=9) && (DInt));row++)    
        {
                for(i=0;i<2;i++)
                {
                        //Borad 1 - 8000
                        dport[0] = row;
                        dport[1] = Buff2[row+Check];
                        dport[2] = Buff3[row+Check];
                        dport[3] = Buff2[9+row+Check];
                        dport[4] = Buff3[9+row+Check];

                        //Borad 2 - 8010
                        dport[16] = row;
                        dport[17] = Buff2[18+row+Check];
                        dport[18] = Buff3[18+row+Check];
                        dport[19] = Buff2[27+row+Check];
                        dport[20] = Buff3[27+row+Check];

                        //Borad 3 - 8020
                        dport[32] = row;
                        dport[33] = Buff2[36+row+Check];
                        dport[34] = Buff3[36+row+Check];
                        dport[35] = Buff2[45+row+Check];
                        dport[36] = Buff3[45+row+Check];

                        //Borad 4 - 8030
                        dport[48] = row;
                        dport[49] = Buff2[54+row+Check];
                        dport[50] = Buff3[54+row+Check];
                        dport[51] = Buff2[63+row+Check];
                        dport[52] = Buff3[63+row+Check];

                        //Borad 5 - 8040
                        dport[64] = row;
                        dport[65] = Buff2[72+row+Check];
                        dport[66] = Buff3[72+row+Check];
                        dport[67] = Buff2[81+row+Check];
                        dport[68] = Buff3[81+row+Check];

                        //Borad 6 - 8050
                        dport[80] = row;
                        dport[81] = Buff2[90+row+Check];
                        dport[82] = Buff3[90+row+Check];
                        dport[83] = Buff2[99+row+Check];
                        dport[84] = Buff3[99+row+Check];
                }
                Blank0();
        }
}

void Display1(void)
{
        for(row=0;((row<=9) && (DInt));row++)
        {
        //Borad 1 - 8000
        dport[0] = row;
        dport[1] = Buff2[row+Check];
        dport[2] = Buff3[row+Check];
        dport[3] = Buff2[10+row+Check];
        dport[4] = Buff3[10+row+Check];

        //Borad 2 - 8010
        dport[16] = row;
        dport[17] = Buff2[20+row+Check];
        dport[18] = Buff3[20+row+Check];
        dport[19] = Buff2[30+row+Check];
        dport[20] = Buff3[30+row+Check];

        //Borad 3 - 8020
        dport[32] = row;
        dport[33] = Buff2[40+row+Check];
        dport[34] = Buff3[40+row+Check];
        dport[35] = Buff2[50+row+Check];
        dport[36] = Buff3[50+row+Check];

        //Borad 4 - 8030
        dport[48] = row;
        dport[49] = Buff2[60+row+Check];
        dport[50] = Buff3[60+row+Check];
        dport[51] = Buff2[70+row+Check];
        dport[52] = Buff3[70+row+Check];

        //Borad 5 - 8040
        dport[64] = row;
        dport[65] = Buff2[80+row+Check];
        dport[66] = Buff3[80+row+Check];
        dport[67] = Buff2[90+row+Check];
        dport[68] = Buff3[90+row+Check];

        //Borad 6 - 8050
        dport[80] = row;
        dport[81] = Buff2[100+row+Check];
        dport[82] = Buff3[100+row+Check];
        dport[83] = Buff2[110+row+Check];
        dport[84] = Buff3[110+row+Check];

                Blank0();
        }
}

void Display2(void)
{
    for(row=0;((row<=9) && (DInt));row++)
    {
        //Borad 1 - 8000
        dport[0] = row;
        dport[1] = Buff2[row+Check] & Ext1;
        dport[2] = Buff3[row+Check] & Ext2;
        dport[3] = Buff2[10+row+Check] & Ext1;
        dport[4] = Buff3[10+row+Check] & Ext2;

        //Borad 2 - 8010
        dport[16] = row;
        dport[17] = Buff2[20+row+Check] & Ext1;
        dport[18] = Buff3[20+row+Check] & Ext2;
        dport[19] = Buff2[30+row+Check] & Ext1;
        dport[20] = Buff3[30+row+Check] & Ext2;

        //Borad 3 - 8020
        dport[32] = row;
        dport[33] = Buff2[40+row+Check] & Ext1;
        dport[34] = Buff3[40+row+Check] & Ext2;
        dport[35] = Buff2[50+row+Check] & Ext1;
        dport[36] = Buff3[50+row+Check] & Ext2;

        //Borad 4 - 8030
        dport[48] = row;
        dport[49] = Buff2[60+row+Check] & Ext1;
        dport[50] = Buff3[60+row+Check] & Ext2;
        dport[51] = Buff2[70+row+Check] & Ext1;
        dport[52] = Buff3[70+row+Check] & Ext2;

        //Borad 5 - 8040
        dport[64] = row;
        dport[65] = Buff2[80+row+Check] & Ext1;
        dport[66] = Buff3[80+row+Check] & Ext2;
        dport[67] = Buff2[90+row+Check] & Ext1;
        dport[68] = Buff3[90+row+Check] & Ext2;

        //Borad 6 - 8050
        dport[80] = row;
        dport[81] = Buff2[100+row+Check] & Ext1;
        dport[82] = Buff3[100+row+Check] & Ext2;
        dport[83] = Buff2[110+row+Check] & Ext1;
        dport[84] = Buff3[110+row+Check] & Ext2;

                Blank1();
    }
}

void Blank0(void)
{
        unsigned char Temp1=0;
        unsigned int Temp2=0;

    //Borad 1 - 8000
        Zero[0] = 0;
    dport[1] = Zero[0+Temp1+Temp2];
    dport[2] = Zero[0+Temp1+Temp2];
    dport[3] = Zero[0+Temp1+Temp2];
    dport[4] = Zero[0+Temp1+Temp2];
        
    //Borad 2 - 8010
        Zero[0] = 0;
    dport[17] = Zero[0+Temp1+Temp2];
    dport[18] = Zero[0+Temp1+Temp2];
    dport[19] = Zero[0+Temp1+Temp2];
    dport[20] = Zero[0+Temp1+Temp2];
  
    //Borad 3 - 8020
        Zero[0] = 0;
    dport[33] = Zero[0+Temp1+Temp2];
    dport[34] = Zero[0+Temp1+Temp2];
    dport[35] = Zero[0+Temp1+Temp2];
    dport[36] = Zero[0+Temp1+Temp2];

    //Borad 4 - 8030
        Zero[0] = 0;
    dport[49] = Zero[0+Temp1+Temp2];
    dport[50] = Zero[0+Temp1+Temp2];
    dport[51] = Zero[0+Temp1+Temp2];
    dport[52] = Zero[0+Temp1+Temp2];

    //Borad 5 - 8040
        Zero[0] = 0;
    dport[65] = Zero[0+Temp1+Temp2];
    dport[66] = Zero[0+Temp1+Temp2];
    dport[67] = Zero[0+Temp1+Temp2];
    dport[68] = Zero[0+Temp1+Temp2];

    //Borad 6 - 8050
        Zero[0] = 0;
    dport[81] = Zero[0+Temp1+Temp2];
    dport[82] = Zero[0+Temp1+Temp2];
    dport[83] = Zero[0+Temp1+Temp2];
    dport[84] = Zero[0+Temp1+Temp2];
}

void Blank1(void)
{
        unsigned char Temp1=0;
        unsigned int Temp2=0;

    //Borad 1 - 8000
        Zero[0] = 0;
    dport[1] = Zero[0+Temp1+Temp2] & Temp1;
    dport[2] = Zero[0+Temp1+Temp2] & Temp1;
    dport[3] = Zero[0+Temp1+Temp2] & Temp1;
    dport[4] = Zero[0+Temp1+Temp2] & Temp1;
        
    //Borad 2 - 8010
        Zero[0] = 0;
    dport[17] = Zero[0+Temp1+Temp2] & Temp1;
    dport[18] = Zero[0+Temp1+Temp2] & Temp1;
    dport[19] = Zero[0+Temp1+Temp2] & Temp1;
    dport[20] = Zero[0+Temp1+Temp2] & Temp1;
  
    //Borad 3 - 8020
        Zero[0] = 0;
    dport[33] = Zero[0+Temp1+Temp2] & Temp1;
    dport[34] = Zero[0+Temp1+Temp2] & Temp1;
    dport[35] = Zero[0+Temp1+Temp2] & Temp1;
    dport[36] = Zero[0+Temp1+Temp2] & Temp1;

    //Borad 4 - 8030
        Zero[0] = 0;
    dport[49] = Zero[0+Temp1+Temp2] & Temp1;
    dport[50] = Zero[0+Temp1+Temp2] & Temp1;
    dport[51] = Zero[0+Temp1+Temp2] & Temp1;
    dport[52] = Zero[0+Temp1+Temp2] & Temp1;

    //Borad 5 - 8040
        Zero[0] = 0;
    dport[65] = Zero[0+Temp1+Temp2] & Temp1;
    dport[66] = Zero[0+Temp1+Temp2] & Temp1;
    dport[67] = Zero[0+Temp1+Temp2] & Temp1;
    dport[68] = Zero[0+Temp1+Temp2] & Temp1;

    //Borad 6 - 8050
        Zero[0] = 0;
    dport[81] = Zero[0+Temp1+Temp2] & Temp1;
    dport[82] = Zero[0+Temp1+Temp2] & Temp1;
    dport[83] = Zero[0+Temp1+Temp2] & Temp1;
    dport[84] = Zero[0+Temp1+Temp2] & Temp1;
}

void Delay(unsigned char n)
{
    unsigned char i;
    for(i=0;((i<=n) && (DInt));i++);
}

void InitilizeSerial(void)
{
    PCON &= 0x7f; /* internal clock divided by 2 */ 
    TMOD &= 0x00; /* Clear timer 1 bits    */
    TMOD |= 0x22; /* timer 1 auto-reload mode */
    TL1 = -3; /* 9600 baud at 11.0592MHz */
    TH1 = -3;
    TR1 = 1;  /* Turn timer1 on */
    SM1 = 1;  /* 8bit uart variable baud */
    REN = 1;  /* reception enable */
    TI  = 0;
    RI = 0;
    IE |= 0x90;
}


