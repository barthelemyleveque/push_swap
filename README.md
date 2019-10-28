# push_swap

** Project score : [110 / 100] **

The idea is simple, you have two stacks called Stack A and Stack B. 

Stack A is given a random list of unorganized numbers. You must take the random list of numbers in Stack A and sort them so that Stack A is organized from smallest to largest. 
There’s only a few moves you’re allowed to used to manipulate the stacks that we’re going to called “Actions”. 
The main goal of this project is to organize Stack A in as few actions as possible.

![Stacks](https://miro.medium.com/max/1054/1*rXKk8juFHQaLzI-uJyEVog.png)

## How to run it :

```
git clone https://github.com/barthelemyleveque/push_swap
cd push_swap
make
```

There is two executables :
* push_swap (the sorting program)
* checker (the program that checks that the given instructions are indeed sorting the list correctly)

## Usage :

```ARG=`ruby -e "puts (1..50).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker -vcat $ARG```

![push_swap](http://g.recordit.co/KhRnkDKhlX.gif)

## Code :

I implemented a custom quick-sort algorithm. Using two chained lists (one for stack A and the other for stack B), each link references the memory-address of a number in the list, which contain the value, the absolute position and it's quicksort interval.

```
typedef struct		s_number
{
	int				val;
	int				pos;
	int				inter;
}					t_number;

typedef struct		s_stack
{
	struct s_number	*nb;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

```

