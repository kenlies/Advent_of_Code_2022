#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _monkey
{
	int	*items;

}	monkey;

monkey *initialize_monkey(monkey *monkey_, int *items_)
{
	monkey_->items = items_;
	return monkey_;
}

void	append_monkey(monkey *monkey_to_append, int num)
{
	int i = 0;
	while (monkey_to_append->items[i] != 0)
		i++;
	monkey_to_append->items[i] = num;
}

int	main(void)
{	
	monkey *monkey0 = (monkey*)malloc(sizeof(monkey));
    monkey *monkey1 = (monkey*)malloc(sizeof(monkey));
    monkey *monkey2 = (monkey*)malloc(sizeof(monkey));
    monkey *monkey3 = (monkey*)malloc(sizeof(monkey));
	monkey *monkey4 = (monkey*)malloc(sizeof(monkey));
	monkey *monkey5 = (monkey*)malloc(sizeof(monkey));
	monkey *monkey6 = (monkey*)malloc(sizeof(monkey));
	monkey *monkey7 = (monkey*)malloc(sizeof(monkey));

	int *items0 = (int *)malloc(sizeof(int) * 1000);
	memset(items0, 0, 1000);
	items0[0] = 59;
	items0[1] = 74;
	items0[2] = 65;
	items0[3] = 86;
	monkey0 = initialize_monkey(monkey0, items0);

	int *items1 = (int *)malloc(sizeof(int) * 1000);
	memset(items1, 0, 1000);
	items1[0] = 62;
	items1[1] = 84;
	items1[2] = 72;
	items1[3] = 91;
	items1[4] = 68;
	items1[5] = 78;
	items1[6] = 51;
	monkey1 = initialize_monkey(monkey1, items1);

	int *items2 = (int *)malloc(sizeof(int) * 1000);
	memset(items2, 0, 1000);
	items2[0] = 78; 
	items2[1] = 84;
	items2[2] = 96;
	monkey2 = initialize_monkey(monkey2, items2);

	int *items3 = (int *)malloc(sizeof(int) * 1000);
	memset(items3, 0, 1000);
	items3[0] = 97;
	items3[1] = 86;
	monkey3 = initialize_monkey(monkey3, items3);

	int *items4 = (int *)malloc(sizeof(int) * 1000);
	memset(items4, 0, 1000);
	items4[0] = 50;
	monkey4 = initialize_monkey(monkey4, items4);

	int *items5 = (int *)malloc(sizeof(int) * 1000);
	memset(items5, 0, 1000);
	items5[0] = 73;
	items5[1] = 65;
	items5[2] = 69;
	items5[3] = 65;
	items5[4] = 51;
	monkey5 = initialize_monkey(monkey5, items5);

	int *items6 = (int *)malloc(sizeof(int) * 1000);
	memset(items6, 0, 1000);
	items6[0] = 69;
	items6[1] = 82;
	items6[2] = 97;
	items6[3] = 93;
	items6[4] = 82;										//hardcoding adventures c:
	items6[5] = 84;
	items6[6] = 58;
	items6[7] = 63;
	monkey6 = initialize_monkey(monkey6, items6);

	int *items7 = (int *)malloc(sizeof(int) * 1000);
	memset(items7, 0, 1000);
	items7[0] = 81;
	items7[1] = 78;
	items7[2] = 82;
	items7[3] = 76;
	items7[4] = 79;
	items7[5] = 80;
	monkey7 = initialize_monkey(monkey7, items7);

	int r = 0;

	int m0_ins = 0;
	int m1_ins = 0;
	int m2_ins = 0;
	int m3_ins = 0;
	int m4_ins = 0;
	int m5_ins = 0;
	int m6_ins = 0;
	int m7_ins = 0;

	while (r < 20)
	{
		int i = 0;
		while(monkey0->items[i] != 0)
		{	
			monkey0->items[i] = monkey0->items[i] * 19;
			monkey0->items[i] = monkey0->items[i] / 3;
			if (monkey0->items[i] % 7)
				append_monkey(monkey2, monkey0->items[i]);
			else
				append_monkey(monkey6, monkey0->items[i]);
			i++;
			m0_ins++;
		}
		while (i != 0)
		{
			monkey0->items++;
			i--;
		}
		while(monkey1->items[i] != 0)
		{	
			monkey1->items[i] = monkey1->items[i] + 1;
			monkey1->items[i] = monkey1->items[i] / 3;
			if (monkey1->items[i] % 2)
				append_monkey(monkey0, monkey1->items[i]); 
			else
				append_monkey(monkey2, monkey1->items[i]);
			i++;
			m1_ins++;
		}
		while (i != 0)
		{
			monkey1->items++;
			i--;
		}
		while(monkey2->items[i] != 0)
		{	
			monkey2->items[i] = monkey2->items[i] + 8;
			monkey2->items[i] = monkey2->items[i] / 3;
			if (monkey2->items[i] % 19)
				append_monkey(monkey5, monkey2->items[i]); 
			else
				append_monkey(monkey6, monkey2->items[i]);
			i++;
			m2_ins++;
		}
		while (i != 0)
		{
			monkey2->items++;
			i--;
		}
		while(monkey3->items[i] != 0)
		{	
			monkey3->items[i] = monkey3->items[i] * monkey3->items[i];
			monkey3->items[i] = monkey3->items[i] / 3;
			if (monkey3->items[i] % 3)
				append_monkey(monkey0, monkey3->items[i]); 
			else
				append_monkey(monkey1, monkey3->items[i]);
			i++;
			m3_ins++;
		}
		while (i != 0)
		{
			monkey3->items++;
			i--;
		}
		while(monkey4->items[i] != 0)
		{	
			monkey4->items[i] = monkey4->items[i] + 6;
			monkey4->items[i] = monkey4->items[i] / 3;
			if (monkey4->items[i] % 13)
				append_monkey(monkey1, monkey4->items[i]); 
			else
				append_monkey(monkey3, monkey4->items[i]);
			i++;
			m4_ins++;
		}
		while (i != 0)
		{
			monkey4->items++;
			i--;
		}
		while(monkey5->items[i] != 0)
		{	
			monkey5->items[i] = monkey5->items[i] * 17;
			monkey5->items[i] = monkey5->items[i] / 3;
			if (monkey5->items[i] % 11)
				append_monkey(monkey7, monkey5->items[i]); 
			else
				append_monkey(monkey4, monkey5->items[i]);
			i++;
			m5_ins++;
		}
		while (i != 0)
		{
			monkey5->items++;
			i--;
		}
		while(monkey6->items[i] != 0)
		{	
			monkey6->items[i] = monkey6->items[i] + 5;
			monkey6->items[i] = monkey6->items[i] / 3;
			if (monkey6->items[i] % 5)
				append_monkey(monkey7, monkey6->items[i]); 
			else
				append_monkey(monkey5, monkey6->items[i]);
			i++;
			m6_ins++;
		}
		while (i != 0)
		{
			monkey6->items++;
			i--;
		}
		while(monkey7->items[i] != 0)
		{	
			monkey7->items[i] = monkey7->items[i] + 3;
			monkey7->items[i] = monkey7->items[i] / 3;
			if (monkey7->items[i] % 17)
				append_monkey(monkey4, monkey7->items[i]); 
			else
				append_monkey(monkey3, monkey7->items[i]);
			i++;
			m7_ins++;
		}
		while (i != 0)
		{
			monkey7->items++;
			i--;
		}
		r++;
	}

	int arr[8] = {m0_ins, m1_ins, m2_ins, m3_ins, m4_ins, m5_ins, m6_ins, m7_ins};
	int tmp;

	for(int i=0; i<8; i++)
    {
        for(int j=i+1; j<8; j++)
        {
            if(arr[j] > arr[i])
            {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }

	printf("monkey business: %d\n", arr[0] * arr[1]);

	return 0;
}