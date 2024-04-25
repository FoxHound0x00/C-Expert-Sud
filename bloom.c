#include <stdio.h>
#include <stdbool.h>

// Complete implementation of bloom filter
// Hash function generates a hash ( 0 - 63)
// Change that idx to True
// During querying step you generate a hash and check if the particular idx is True
// If True then there is a possibility that the number exists

int hash(int x)
{
	if (x < 64 && x > -1)
	{
		return x;
	}
	else if (x > 0)
	{
		return x % 64;
	}
	else
	{
		return 404;
	}
}

int main()
{
	int x;
	int db[64];
	printf("How many numbers to add to the db?\n");
	scanf("%d", &x);
	for (int i = 0; i < x; i++)
	{
		int y;
		printf("Enter number %d : \n", i + 1);
		scanf("%d", &y);
		printf("%d\n", hash(y));
		if (hash(y) != 404)
		{
			db[hash(y)] = 1;
		}
	}

	bool search_ = true;
	while (search_)
	{
		int searchNum;
		printf("Enter a number to search for: ");
		scanf("%d", &searchNum);
		printf("\n");

		int numHash = hash(searchNum);
		if (db[numHash] == 1)
		{
			printf("%d is in the db\n", searchNum);
		}
		else
		{
			printf("%d is not in the db\n", searchNum);
		}

		char answer;
		printf("Would you like to search for another number? (y/n)\n");
		scanf(" %c", &answer);
		if (answer == 'y')
		{
			continue;
		}
		else if (answer == 'n')
		{
			search_ = false;
		}
	}
}
