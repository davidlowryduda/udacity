
Interesting fact: (-1 % 5) in c++ is implementation defined. Notably it is not
4, as it usually appears to match the sign of the input. So it is necessary to
be a bit careful around moduli of potentially negative numbers.


vim: foldcolumn=2 ts=2 sw=2 sts=2 cc= ft=markdown tw=80
