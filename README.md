<!-- Nikita Kouevda -->
<!-- 2014/12/13 -->

# prime

Command-line prime checking.

## Compilation

To compile:

    make

To clean up:

    make clean

## Usage

    prime [-h|--help]
    prime [-v|--verbose] [--] num ...
    prime [-v|--verbose] [-r|--range] min max

## Examples

```bash
$ ./bin/prime {1..10}
2
3
5
7
```

```bash
$ ./bin/prime -v 4321 1234567891
4321 is not prime
1234567891 is prime
```

```bash
$ ./bin/prime -r 0 100000000
5761455
```

```bash
$ ./bin/prime -v -r 250 750
primes in [250, 750): 79
```

## License

Licensed under the [MIT License](http://www.opensource.org/licenses/MIT).
