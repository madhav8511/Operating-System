/*

soft limit: The soft limit is the actual limit enforced by the kernel for the corresponding resource.
hard limit: The hard limit acts as a ceiling for the soft limit.

*/

#include <stdio.h>
#include <sys/resource.h>

int main()
{
	struct rlimit s;

	if(getrlimit(RLIMIT_AS, &s) == 0)
	{
		printf("Size of virtual memory\n");
		printf("Soft - %lu\n", s.rlim_cur);
		printf("Hard - %lu\n", s.rlim_max);
	}
	printf("\n");
	if (getrlimit(RLIMIT_CORE, &s) == 0)
	{
		printf("Size of core file\n");
		printf("Soft - %lu\n", s.rlim_cur);
		printf("Hard - %lu\n", s.rlim_max);
	}
	printf("\n");
	if (getrlimit(RLIMIT_CPU, &s) == 0)
	{
		printf("Limit on CPU time\n");
		printf("Soft - %lu\n", s.rlim_cur);
		printf("Hard - %lu\n", s.rlim_max);
	}
	printf("\n");
	if (getrlimit(RLIMIT_DATA, &s) == 0)
	{
		printf("Size of Data segment of process\n");
		printf("Soft - %lu\n", s.rlim_cur);
		printf("Hard - %lu\n", s.rlim_max);
	}
	printf("\n");
	if (getrlimit(RLIMIT_FSIZE, &s) == 0)
	{
		printf("Size of files that the process can create\n");
		printf("Soft - %lu\n", s.rlim_cur);
		printf("Hard - %lu\n", s.rlim_max);
	}
	printf("\n");
	if (getrlimit(RLIMIT_LOCKS, &s) == 0)
	{
		printf("Limit on the number of locks\n");
		printf("Soft - %lu\n", s.rlim_cur);
		printf("Hard - %lu\n", s.rlim_max);
	}
	printf("\n");
	if (getrlimit(RLIMIT_MEMLOCK, &s) == 0)
	{
		printf("Max no of bytes in memory that may be locked\n");
		printf("Soft - %lu\n", s.rlim_cur);
		printf("Hard - %lu\n", s.rlim_max);
	}
	printf("\n");
	if (getrlimit(RLIMIT_NICE, &s) == 0)
	{
		printf("Max nice value\n");
		printf("Soft - %lu\n", s.rlim_cur);
		printf("Hard - %lu\n", s.rlim_max);
	}
	printf("\n");
	if (getrlimit(RLIMIT_NOFILE, &s) == 0)
	{
		printf("Maximum no. file descriptors\n");
		printf("Soft - %lu\n", s.rlim_cur);
		printf("Hard - %lu\n", s.rlim_max);
	}
	printf("\n");
	if (getrlimit(RLIMIT_NPROC, &s) == 0)
	{
		printf("Number of extant processes for the real user id of the process\n");
		printf("Soft - %lu\n", s.rlim_cur);
		printf("Hard - %lu\n", s.rlim_max);
	}
	printf("\n");
	if (getrlimit(RLIMIT_RTPRIO, &s) == 0)
	{
		printf("Max real time priority\n");
		printf("Soft - %lu\n", s.rlim_cur);
		printf("Hard - %lu\n", s.rlim_max);
	}
	printf("\n");
	if (getrlimit(RLIMIT_RTTIME, &s) == 0)
	{
		printf("Max CPU time for a real time process\n");
		printf("Soft - %lu\n", s.rlim_cur);
		printf("Hard - %lu\n", s.rlim_max);
	}
	printf("\n");
	if (getrlimit(RLIMIT_SIGPENDING, &s) == 0)
	{
		printf("Max no of queued signals for the real user ID of the calling process\n");
		printf("Soft - %lu\n", s.rlim_cur);
		printf("Hard - %lu\n", s.rlim_max);
	}
	printf("\n");
	if (getrlimit(RLIMIT_STACK, &s) == 0)
	{
		printf("Max size of the process stack\n");
		printf("Soft - %lu\n", s.rlim_cur);
		printf("Hard - %lu\n", s.rlim_max);
	}

	return(0);
}