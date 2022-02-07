#include "philo.h"

static int	isnum_str(char *str)
{
	int		i;

	i = -1;
	while (str[++i] != '\0')
		if (str[i] < '0' || str[i] > '9')
			return (0);
	return (1);
}

static bool	isvalid_input(int size, char **inputs)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (!isnum_str(inputs[i]))
			return (false);
		else
		{
			if (ft_atoi_check_overflow(inputs[i]) == 3000000000)
				return (false);
		}
		i++;
	}
	return (true);
}

static int	start_eating(t_state *state)
{
	int		i;

	i = 0;
	state->start = gettime();
	while (i < state->nb)
	{
		if (pthread_create(&(state->philos[i].thread), NULL,
				run, (void *)&(state->philos[i])))
			return (1);
		state->philos[i].last_eat = state->start;
		if (pthread_detach(state->philos[i].thread))
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_state	*state;

	state = (t_state *)malloc(sizeof(t_state));
	if (argc < 5 || argc > 6 || !isvalid_input(argc - 1, argv + 1))
	{
		write(2, "error\n", 6);
		return (1);
	}
	if (!init(state, argv, argc))
	{
		free(state);
		return (1);
	}
	if (start_eating(state))
		return (1);
	while (1)
	{
		if (!terminal_condition(state, argc))
			return (0);
	}
}
