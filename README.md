<!-- Nikita Kouevda -->
<!-- 2014/12/15 -->

# prime

Prime checker and finder.

## Compilation

To compile:

    make

To clean up:

    make clean

## Usage

    usage: prime [-h|--help]
           prime [-s|--stat] [--] num ...
           prime [-s|--stat] [-r|--range] [start] stop

## Examples

Check whether the given numbers are prime:

    $ ./bin/prime 1 2 3 4 17 18 19
    2
    3
    17
    19

Only print stats about the given numbers' primeness:

    $ ./bin/prime -s 1 2 3 4 17 18 19
    4 of 7 (0.571429%)

Find all primes in the range `[start, stop)`:

    $ ./bin/prime -r 0 10
    2
    3
    5
    7

Only print stats about the given range (`start` defaults to `0`):

    $ ./bin/prime -rs 1000000
    78498 of 1000000 (0.078498%) in [0, 1000000)

## License

Licensed under the [MIT License](http://www.opensource.org/licenses/MIT).
