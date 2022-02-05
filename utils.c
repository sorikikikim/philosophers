#include "philo.h"

void	msg(int act, t_philo *philo)
{
	pthread_mutex_lock(&philo->state->write);
	if (!philo->state->died)
	{
		if (act == take_a_fork)
			printf("%llums %d %s\n", gettime()
				- philo->state->start, philo->id + 1, "has taken a fork");
		else if (act == eat)
			printf("%llums %d %s\n", gettime()
				- philo->state->start, philo->id + 1, "is eating");
		else if (act == sleeps)
			printf("%llums %d %s\n", gettime()
				- philo->state->start, philo->id + 1, "is sleeping");
		else if (act == think)
			printf("%llums %d %s\n", gettime()
				- philo->state->start, philo->id + 1, "is thinking");
		else if (act == died)
			printf("%llums %d %s\n", gettime()
				- philo->state->start, philo->id + 1, "died");
	}
	pthread_mutex_unlock(&philo->state->write);
}

int	ft_atoi(const char *str)
{
	unsigned int	ret;
	int				sign;

	ret = 0;
	sign = 1;
	while ((9 <= *str && *str <= 13) || *str == ' ')
		++str;
	if (*str == '+' || *str == '-')
	{
		if (*(str++) == '-')
			sign *= -1;
	}
	while ('0' <= *str && *str <= '9')
	{
		ret *= 10;
		ret += *str - '0';
		str++;
	}
	return ((int)(ret * sign));
}

unsigned long long	gettime(void)
{
	struct timeval		time;
	unsigned long long	ms;

	gettimeofday(&time, NULL);
	ms = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (ms);
}

long long	ft_atoi_check_overflow(const char *str)
{
	unsigned long long	ret;
	int					sign;

	ret = 0;
	sign = 1;
	while ((9 <= *str && *str <= 13) || *str == ' ')
		++str;
	if (*str == '+' || *str == '-')
	{
		if (*(str++) == '-')
			sign *= -1;
	}
	while ('0' <= *str && *str <= '9')
	{
		ret *= 10;
		ret += *str - '0';
		str++;
		if ((sign == -1 && ret > (unsigned long long)2147483648)
			|| (sign == 1 && ret > (unsigned long long)2147483647))
			return (3000000000);
	}
	return ((long long)(ret * sign));
}
