# Lab6_Vector_Lab
this is CPE2600
`mini-mat` is vector calculator that operates via an interactive REPL. It supports storing up to a linked list of vectors containing 10 integer components and supporting file I/O operations to load and save.

You are able to do many equations such as:
Adding: A + B
Substracting: A - B
Multiplication: A * B
Scalar Multiplication: A * 2.5
Cross Product: A x B

You can save all the vectors you make by doind "save text.csv"
You are also able to load vectors you save by doing "load text.csv"
You are also able to clear them by doing "clear text.csv"

in order to run this program you type in "./lab7"

To build the program, use `gcc` to compile all source and object files together:

gcc -o lab7 lab5.c vectadd.c vectsub.c vector_product.c vect_operation.c vect_io.c find_or_creat_vector.c find_vect.c scalar.c vect_cross.c