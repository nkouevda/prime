<!-- Nikita Kouevda -->
<!-- 2014/10/15 -->

# prime

Command-line prime checking.

## Compilation

To compile:

    make

To clean up:

    make clean

## Usage
    
    prime [-h|--help] [-v|--verbose] [--] number ...

## Examples

    $ ./bin/prime {1..10}
    2
    3
    5
    7

    $ ./bin/prime -v 4321 1234567891
    4321 is not prime
    1234567891 is prime

## License

Licensed under the [MIT License](http://www.opensource.org/licenses/MIT).
