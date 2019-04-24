## void CO(char* restrict cmd, char* restrict buf)
|Parameter | Usage |
|:------|:-----:|
|char* restrict cmd| The command to run|
|char* restrict buf| The buffer to save the output of the command to|
### Reason for use
Prints output of command to given string.

***WARNING: DOES NOT CHECK FOR BUFFER SIZE AND CAN OVERFLOW, CAUSING SEGFAULTS***

## int COn(char* restrict cmd, char* restrict buf, size_t bufSize)
|Parameter | Usage |
|:-|:-:|
|char* restrict cmd| The command to run|
|char* restrict buf| The buffer to save the output of the command to|
|size_t bufSize | The size of the given buffer|
### Reason for use
Prints output of command to given string, cutting it off if the command's output is larger than given buffer. Does not end string in null byte.


## int sCOn(char* restrict cmd, char* restrict buf, size_t bufSize)
|Parameter | Usage |
|:-|:-:|
|char* restrict cmd| The command to run|
|char* restrict buf| The buffer to save the output of the command to|
|size_t bufSize | The size of the given buffer|
### Reason for use
Prints output of command to given string, cutting it off if the command's output is larger than the given buffer. Ends the string in a null byte. Thus, maximum string size is buffer size - 1.

## int COn_f(char* restrict cmd, char* restrict buf, size_t bufSize)
|Parameter | Usage |
|:-|:-:|
|char* restrict cmd| The command to run|
|char* restrict buf| The buffer to save the output of the command to|
|size_t bufSize | The size of the given buffer|
### Reason for use
Prints output of command to given string, exiting and returning an error if the command's output is larger than the given buffer.

# Which One To Use?
generally, either sCOn or COn are the ones you should use. They both check for the size of the buffer to prevent errors. However, sCOn will end the buffer with a null byte whereas COn won't. CO will cause segfaults on any command that has larger output than the buffer size. 

# Testing
run `gcc test.c -o test` to compile test file.

Test file shows consecuences of each method. Will almost certainly end with a segfault, but no memory leak.
