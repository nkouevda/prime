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
    prime [-s|--stat] [--] num ...
    prime [-s|--stat] [-r|--range] min max

## Examples

```
$ ./bin/prime 1 2 3 4 17 18 19
2
3
17
19
```

```
$ ./bin/prime -s 1 2 3 4 17 18 19
4 of 7 (0.571429%)
```

```
$ ./bin/prime -r 0 10
2
3
5
7
```

```
$ ./bin/prime -rs 0 1000000
78498 of 1000000 (0.078498%) in [0, 1000000)
```

## License

Licensed under the [MIT License](http://www.opensource.org/licenses/MIT).
