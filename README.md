
# PHILOSOPHERS

<p align="center">
  <a href="">
    <img src="img/PHILOSOPHER.png" alt="philosopher">
  </a>
</p>

# Table of Contents
- [Table of Contents](#table-of-contents)
- [0. Description](#0-description)
- [1. Problem Description](#1-problem-description)
- [2. How to execute the program](#2-How-to-execute-the-program)
- [3. Running Makefile](#3-running-makefile)


# 0. Description

The Philosophers project is a classic synchronization problem often used in computer science and concurrent programming courses. The problem is designed to teach students about concurrency, deadlocks, and resource management.

# 1. Problem Description

• One or more philosophers sit at a round table.

• The philosopher alternatively **eat**, **think**, or **sleep**.

-> While they are eating, they are not thinking nor sleeping.

-> While thinking, they are not eating nor sleeping.

-> And, of course, while sleeping, they are not eating nor thinking.

• There are as many forks as philosophers on the table.

• Each philosopher should have two forks to start to eat, because serving and eating spaghetti with only one fork is  very incovenient.

• When a philosopher has finished eating, they put their forks back on the table and start sleeping. Once awake, they start thinking again. The simulation stops when a philosopher dies of starvation.

• Every philosopher needs to eat and should never starve.

• Philosopher do not speak to each other

• Philosopher do not known if another philosopher is about to die.


# 2. How to execute the program

```sh
# Sample of commands (this example the philo eats 4 times and stop running)
$> ./philo 4 410 200 200 4

# Sample of commands (this example the philo should theoretically run infinite)
$> ./philo 4 410 200 200

```


# 3. Running Makefile

```sh

# Will generate a executable
$> make all

# Execute valgrind. Will check memory leaks
$> make leak

# will run norminette
$> make norma

```
