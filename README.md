## void CO(char* restrict cmd, char* restrict buf)
|Parameter | Usage |
|:------|:-----:|
|char* restrict cmd| The command to run|
|char* restrict buf| The buffer to save the output of the command to|

***WARNING: DOES NOT CHECK FOR BUFFER SIZE AND CAN OVERFLOW, CAUSING SEGFAULTS***

## int COn(char* restrict cmd, char* restrict buf, size_t bufSize)
|Parameter | Usage |
|:-|:-:|
|char* restrict cmd| The command to run|
|char* restrict buf| The buffer to save the output of the command to|
|size_t bufSize | The size of the given buffer|

## int sCOn(char* restrict cmd, char* restrict buf, size_t bufSize)
|Parameter | Usage |
|:-|:-:|
|char* restrict cmd| The command to run|
|char* restrict buf| The buffer to save the output of the command to|
|size_t bufSize | The size of the given buffer|

# Which One To Use?
generally, either sCOn or COn are the ones you should use. They both check for the size of the buffer to prevent errors. However, sCOn will end the buffer with a null byte whereas COn won't. CO will cause segfaults on any command that has larger output than the buffer size. 

# Testing
run `gcc example/Segfault.c -o example/Segfault` to compile test file. Then run  `example/Segfault` from the base directory

Test file shows consecuences of each method. Will almost certainly end with a segfault, but no memory leak.
