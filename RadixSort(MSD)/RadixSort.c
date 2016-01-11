#include"RadixSort.h"

void radixSortByMSD(queue* ans, queue* num, int n)
{
	int length = getLength(num);

	//��num�̥u���@�ӼƦr�ɴN�s�Jans
	if (length == 1)
	{
		element ele = getElement(num);
		enQueue(ans, ele);
	}
	else if (length&&n)
	{
		//radix is 10,decimal
		queue *bin[RADIX];//���Ӧs��U�ӹ�����ƪ��Ʀr

		int i;
		for (i = 0; i < RADIX; i++)
			bin[i] = createQueue();

		//�qnum���X�ƭȡA�N�Ʀr��J�ŦX�L����l(MSD)
		for (i = 0; i < length; i++)
		{
			element ele = getElement(num);

			int msd = (ele.val / n) % 10;//��msd

			deQueue(num);

			//add ele to bin
			enQueue(bin[msd], ele);

		}

		//�p�n�p��j�A��0 -> RADIX-1 
		for (i = RADIX - 1; i >= 0; i--)
			radixSortByMSD(ans, bin[i], n / 10);

		//destroy all bin
		for (i = 0; i < RADIX; i++)
			destroyQueue(bin[i]);

	}
}