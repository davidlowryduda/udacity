
Note that the autograder requires one input file, so proper code reuse is left
as a dream. Frowny face.


## Notes

I learned something in this trivial exercise. In python, integers can have
arbitrary length. But if `a` and `b` are integers, then `a / b` will do float
division even if `b` actually divides `a`. Thus `a / b` may lose precision.
This makes sense, but I hadn't thought about it. Doing `a // b` to force integer
division keeps all the information (assuming that `b` divides `a` of course).
