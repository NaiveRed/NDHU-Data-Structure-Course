#include"RadixSort.h"

void radixSortByMSD(queue* ans, queue* num, int n)
{
	int length = getLength(num);

	//讽num柑Τ计碞ans
	if (length == 1)
	{
		element ele = getElement(num);
		enQueue(ans, ele);
	}
	else if (length&&n)
	{
		//radix is 10,decimal
		queue *bin[RADIX];//ㄓ癸莱计计

		int i;
		for (i = 0; i < RADIX; i++)
			bin[i] = createQueue();

		//眖num计盢计才表(MSD)
		for (i = 0; i < length; i++)
		{
			element ele = getElement(num);

			int msd = (ele.val / n) % 10;//msd

			deQueue(num);

			//add ele to bin
			enQueue(bin[msd], ele);

		}

		//璶э0 -> RADIX-1 
		for (i = RADIX - 1; i >= 0; i--)
			radixSortByMSD(ans, bin[i], n / 10);

		//destroy all bin
		for (i = 0; i < RADIX; i++)
			destroyQueue(bin[i]);

	}
}