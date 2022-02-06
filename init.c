#include "philo.h"

void	init_philo(t_philo *philo, t_state *state)
{
	int	i;

	i = 0;
	while (i < state->nb)
	{
		philo[i].id = i;
		philo[i].l_fk = i;
		philo[i].r_fk = (i + 1) % state->nb;
		philo[i].last_eat = 0;
		philo[i].total_eat = 0;
		philo[i].state = state;
		i++;
	}
}

int	init(t_state *state, char **argv, int argc)
{
	state->nb = ft_atoi(argv[1]);
	if (state->nb > 300 || state->nb <= 0)
		return (0);
	state->time_die = ft_atoi(argv[2]);
	state->time_eat = ft_atoi(argv[3]);
	state->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		state->must_eat = ft_atoi(argv[5]);
	state->died = 0;
	if (pthread_mutex_init(&state->write, NULL))
		return (0);
	init_philo(state->philos, state);
	return (1);
}
