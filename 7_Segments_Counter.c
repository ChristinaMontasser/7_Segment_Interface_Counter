#include "define.h"
#include "type.h"
#include "DIO_interface.h"
#include "DIO_Registers.h"
#include "SegmentBit.h"

int main()
{
	//Application1 --> 7-Segments Interface Counter 
	u8 arr[10]={zero, one, two, three, four, five, six, seven, eight, nine};
	//Set Port direction
	DIO_vdSetPortDirection(PortA, PORT_OUTPUT);
	DIO_vdSetPortDirection(PortC, PORT_OUTPUT);
	while(1)
	{
	    //Set PORT value
		DIO_vdSetPortValue(PortC , PORT_INPUT);
		for(u8 u=0; u<=9; u++)
		{
			for(u8 i=0; i<=9; i++)
			{
				//Set PORT value units
				DIO_vdSetPortValue(PortA ,arr[i]);
				if(u!=0 && i==0)
				{
					//Set PORT value tens
					DIO_vdSetPortValue(PortC ,arr[u]);
					//Delay
					for (s32 d = 1; d <= 70000; d++){}
				}
				else
				{
					//Delay
					for (s32 d = 1; d <= 70000; d++){}
				}

			}

		}
	}
	




return 0;
}
