#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "shuffle.h"

#define PSIZE 20

int main()
{
	char *playlist[PSIZE] = {
			"Like a Rolling Stone", "Satisfaction", "Imagine",
			"What's Going On", "Respect", "Good Vibrations",
			"Johnny B. Goode", "Hey Jude", "What'd I Say",
			"Smells Like Teen Spirit", "My Generation",
			"Yesterday", "Blowin' in the Wind", "Purple Haze",
			"London Calling", "I Want to Hold Your Hand",
			"Maybellene", "Hound Dog", "Let It Be",
			"A Change Is Gonna Come"};
	int frequency[PSIZE];
	int shuffledPlayList[100];
	int x, idx, count;

	for (x = 0; x < PSIZE; x++)
		frequency[x] = 0;

	shuffle(PSIZE, 100, shuffledPlayList);

	/* run through the playlist randomly */
	puts("Playlist:");
	count = 0;
	while (count < 100)
	{
		idx = shuffledPlayList[count];
		printf("%3d: Now Playing '%s'\n",
					 count + 1,
					 playlist[idx]);
		frequency[idx]++;
		count++;
	}

	puts("Song frequency:");
	for (x = 0; x < PSIZE; x++)
		printf("%s: %d\n", playlist[x], frequency[x]);

	return (0);
}
