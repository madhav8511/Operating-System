#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sched.h>

int main(){
	// Can also use SCHED_FIFO.
	printf("Max priority for real-time round-robin: %d\n", sched_get_priority_max(SCHED_RR));
	printf("Min priority for real-time round-robin: %d\n", sched_get_priority_min(SCHED_RR));
	return 0;
}