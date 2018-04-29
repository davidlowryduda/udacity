
## Reminders to Self

I work this in python3 and c++.

Note: I usually write a sample input.txt and output.txt for each programming
task. The easiest way to verify these is probably to do something like

    cat ../input.txt | python myfile.py | diff ../output.txt -
    cat ../input.txt | ./my_compiled_cpp.out | diff ../output.txt -

which will reveal if there are any differences between expected input and
output.

Note: I also usually have smaller tests associated to each challenge that I use
while writing, but these are commented or flagged out when done.

vim: foldcolumn=2 ts=2 sw=2 sts=2 cc= ft=markdown tw=80
