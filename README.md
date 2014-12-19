<!-- Nikita Kouevda -->
<!-- 2014/12/19 -->

# prime

Prime checker and finder.

## Compilation

To compile:

    make

To clean up:

    make clean

## Usage

```
prime - Prime checker and finder

usage: prime [-h|--help]
       prime [-s|--short] [--] <num>...
       prime [-s|--short] -r|--range [<start>] <stop>

prime [-h|--help]

    Show this help message and exit.

prime [-s|--short] [--] <num>...

    Print each prime number of the given <num>s. If --short is specified,
    instead of printing each prime number, output a summary in the following
    format, where P is the number of primes and T is the number of <num>s:

        P of T (P/T%)

prime [-s|--short] -r|--range [<start>] <stop>

    Print all primes between <start> (inclusive) and <stop> (exclusive). If not
    specified, <start> defaults to 0. If --short is specified, instead of
    printing each prime number, output a summary in the following format, where
    P is the number of primes and T is the number of numbers (<stop> - <start>):

        P of T (P/T%) in [<start>, <stop>)
```

## Examples

Check whether the given numbers are prime:

    $ ./bin/prime 1 2 3 4 17 18 19
    2
    3
    17
    19

Print a summary about the given numbers' primeness:

    $ ./bin/prime -s 1 2 3 4 17 18 19
    4 of 7 (57.142857%)

Find all primes in the range `[start, stop)`:

    $ ./bin/prime -r 2 7
    2
    3
    5

Print a summary about the given range (`start` defaults to `0`):

    $ ./bin/prime -rs 1000000
    78498 of 1000000 (7.849800%) in [0, 1000000)

## License

Licensed under the [MIT License](http://www.opensource.org/licenses/MIT).
