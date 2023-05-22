#include "shuffle.h"
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define HISTORY_SIZE (15u)

void shuffle(const size_t paylistSize, const size_t playCount, int *shuffledList)
{
	int x, r, count;
	int playlistHistory[HISTORY_SIZE];

	memset(playlistHistory, -1, HISTORY_SIZE);
	memset(shuffledList, -1, playCount);

	/* initialize */
	srand((unsigned)time(NULL));

	/* run through the playlist randomly */
	count = 0;
	while (count < playCount)
	{
		bool songFoundInTheHistory = false;

		/* does r appear in recent[]? */
		r = rand() % paylistSize; /* random value */

		for (size_t i = 0; i < HISTORY_SIZE; i++)
		{
			// Song index found in the history
			if (r == playlistHistory[i])
			{
				songFoundInTheHistory = true;
				break;
			}
		}

		if (false == songFoundInTheHistory)
		{
			playlistHistory[count % HISTORY_SIZE] = r;
			shuffledList[count++] = r;
		}
	}
}
