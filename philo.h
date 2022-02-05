#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>

# define THOUSAND 1000

enum e_behavior
{
	take_a_fork,
	eat,
	sleeps,
	think,
	died
};

typedef struct s_philo
{
	int					id;
	int					l_fk;
	int					r_fk;
	unsigned long long	last_eat;
	int					total_eat;
	pthread_t			thread;
	struct s_state		*state;
}				t_philo;

typedef struct s_state
{
	int					nb;
	int					time_die;
	int					time_eat;
	int					time_sleep;
	int					must_eat;
	unsigned long long	start;
	int					died;
	t_philo				philos[300];
	pthread_mutex_t		forks[300];
	pthread_mutex_t		lock;
	pthread_mutex_t		write;
}	t_state;

int					init(t_state *state, char **argv, int argc);
void				init_philo(t_philo *philo, t_state *state);
void				*run(void	*arg);
void				test(t_philo *philo);
void				take_fork(t_philo *philo);
void				put_fork(t_philo *philo);
void				eating(t_philo *philo);
void				sleeping(t_philo *philo);
void				msg(int act, t_philo *philo);
int					ft_atoi(const char *str);
unsigned long long	gettime(void);
long long			ft_atoi_check_overflow(const char *str);
bool				terminal_condition(t_state *state, int argc);
unsigned long long	time_diff(unsigned long long past, unsigned long long pres);
void				precise_sleep(unsigned long long time, t_state *state);
int					died_free(t_state *state);
#endif