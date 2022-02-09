#include "philo.h"

void	*run(void	*arg)
{
	t_philo	*philo;
	t_state	*state;

	philo = (t_philo *)arg;
	state = philo->state;
	if (philo->id % 2)
		usleep(20000);
	while (!(state->died))
	{
		msg(think, philo);
		take_fork(philo);
		eating(philo);
		put_fork(philo);
		sleeping(philo);
	}
	return (0);
}

void	take_fork(t_philo *philo)
{
	t_state	*state;

	state = philo->state;
	pthread_mutex_lock(&(state->forks[philo->l_fk]));
	msg(take_a_fork, philo);
	if (philo->state->nb == 1)
		usleep(1000000000);
	pthread_mutex_lock(&(state->forks[philo->r_fk]));
	msg(take_a_fork, philo);
}

void	eating(t_philo *philo)
{
	t_state	*state;

	state = philo->state;
	msg(eat, philo);
	philo->last_eat = gettime();
	usleep(1000 * state->time_eat);
	//precise_sleep(state->time_eat, state);
	(philo->total_eat)++;
}

void	put_fork(t_philo *philo)
{
	t_state	*state;

	state = philo->state;
	pthread_mutex_unlock(&(state->forks[philo->l_fk]));
	pthread_mutex_unlock(&(state->forks[philo->r_fk]));
}

void	sleeping(t_philo *philo)
{
	msg(sleeps, philo);
	usleep(1000 * philo->state->time_sleep);

	//precise_sleep(philo->state->time_sleep, philo->state);
}
