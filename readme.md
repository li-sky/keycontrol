# Simple C51 Key Check Library

This library is intended for checking the key status in C51. Many situations are suitable for this key library, such as pooling the key
status in your service loop, and in interrupt service routine. This library uses a simple state machine to check the key status, and
it is (surely) easy to use.

You can change the default behaviour of this library by passing in function callbacks of your own. Note that the function need to be written
like this:

```c
void YourFunctionCallback(int *count, int* countStep, unsigned char timer, unsigned int *TimerConfigure) reentrant{
    // Your code here
}
```
