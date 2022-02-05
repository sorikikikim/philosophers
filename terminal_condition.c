#include "philo.h"

int	died_free(t_state *state)
{
	int	i;

	i = 0;
	while (i < state->nb)
	{
		pthread_mutex_destroy(&(state->forks[i]));
		i++;
	}
	pthread_mutex_destroy(&(state->lock));
	pthread_mutex_destroy(&(state->write));
	free(state);
	return (0);
}

bool	terminal_condition(t_state *state, int argc)
{
	int		i;
	int		eat_finished;
	t_philo	*philo;

	eat_finished = 1;
	i = 0;
	while (i < state->nb)
	{
		philo = &(state->philos[i]);
		if (argc == 6 && (philo->total_eat < state->must_eat))
			eat_finished = 0;
		if ((unsigned long long)state->time_die
			< gettime() - philo->last_eat)
		{
			msg(died, philo);
			state->died = 1;
			return (died_free(state));
		}
		i++;
	}
	if (argc == 6 && eat_finished == 1)
		return (died_free(state));
	return (1);
}
