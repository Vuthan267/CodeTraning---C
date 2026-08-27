//
// Created by toingubo on 8/27/26.
//

#include "activity.h"

int compareAc(const void *a, const void *b) {
	int finish_a = ((Activity *) a)->finish;
	int finish_b = ((Activity *) b)->finish;
	return (finish_a > finish_b) - (finish_a < finish_b);
}

int findMaxActivity(int start[], int finish[], int n) {
	Activity activities[n];
	for (int i = 0; i < n; i++) {
		activities[i].start = start[i];
		activities[i].finish = finish[i];
	}
	qsort(activities, n, sizeof(Activity), compareAc);

	int activity_count = 0;
	int last_finish = INT_MIN;
	for (int i = 0; i < n; i++) {
		Activity *current_activity = &activities[i];
		if (current_activity->start >= last_finish) {
			activity_count++;
			last_finish = current_activity->finish;
		}
	}

	return activity_count;
}
