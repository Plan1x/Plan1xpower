# Plan1xpower
Hi! It`s great to see you here.
Welcome to my library.
There are only 2 methods here, but i hope they will help you.
I managed to speed up function digitalWrite 11 times!
And pinMode became 2.5 times faster!

How to download the library:
1) Open "plan1xpower.h.zip" file.
2) Press View raw (clicking this button will launch the instalation of the zip file).
3) Unzip the file.
4) Open folder "libraries"
5) Add the unziped file to the "libraries" folder.

How to work with the library:
1) First of all you have to create an object of type Boost
For example:
Boost object;//This part of the code should be outside the functions(loop and setup) as written in the example.
And don`t forget to include the library :D
2) Methods:
Here are the syntaxes of new methods:
digitalWrite is now object.write(uint8_t pin, uint8_t mode);
pinMode is now object.pin_init(uint8_t pin, uint8_t mode);//Unfortunately I havent added INPUT_PULLUP mode yet
3) Now the library is ready for the work(look at the example)
P.S. If you find any bugs or shortcomings in my library, I would be grateful if you let me know about them.
My instagram: @v_a_n_4_e_k
