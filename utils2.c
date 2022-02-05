#include "philo.h"

unsigned long long	time_diff(unsigned long long past, unsigned long long pres)
{
	return (pres - past);
}

void	precise_sleep(unsigned long long time, t_state *state)
{
	unsigned long long	i;

	i = gettime();
	while (!(state->died))
	{
		if (time_diff(i, gettime()) >= time)
			break ;
		usleep(50);
	}
}
