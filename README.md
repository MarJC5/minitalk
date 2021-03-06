<h1 align="center">
    <img alt="42Lausanne" title="42Lausanne" src="https://github.com/MarJC5/42/blob/main/42_logo.svg" width="140"> </br>
    Project n°6 - minitalk
    <h4 align="center" style="width: 50%; margin: 2rem auto; font-weight: normal;">
    The purpose of this project is to code a small data exchange program using UNIX signals.
    </h4>
</h1>

## Goals

Create a communication program in the form of a client and server. The server must be launched first, and after being launched it must display its PID. The client must communicate the string passed as a parameter to the server. Once
the string has been received, the server must display it. Communication between your programs should ``ONLY`` be done using ``UNIX signals``.

The client will take as parameters:

- The server PID.
- The string that should be sent.

Only ``SIGUSR1`` and ``SIGUSR2`` can be used.

## Functions allowed

- [malloc()](https://man7.org/linux/man-pages/man3/malloc.3.html), [free()](https://man7.org/linux/man-pages/man1/free.1.html)
- [write()](https://man7.org/linux/man-pages/man2/write.2.html), [printf()](https://man7.org/linux/man-pages/man3/printf.3.html)
- [signal()](https://man7.org/linux/man-pages/man7/signal.7.html), [sigfillset()](https://man7.org/linux/man-pages/man3/sigfillset.3.html), [sigaddset()](https://man7.org/linux/man-pages/man3/sigfillset.3.html), [sigaction()](https://man7.org/linux/man-pages/man2/sigaction.2.html)
- [kill()](https://man7.org/linux/man-pages/man1/kill.1.html), [getpid()](https://man7.org/linux/man-pages/man2/getpid.2.html)
- [pause()](https://man7.org/linux/man-pages/man2/pause.2.html), [sleep()](https://man7.org/linux/man-pages/man3/sleep.3.html), [usleep()](https://man7.org/linux/man-pages/man3/usleep.3.html)
- [exit()](https://man7.org/linux/man-pages/man3/exit.3.html)

## UNIX signals

## SIGUSR1 & SIGUSR2

These signals are used for various other purposes. In general, they will not affect your program unless it explicitly uses them for something.

The ``SIGUSR1`` and ``SIGUSR2`` signals are set aside for us to use any way we want. They’re useful for simple interprocess communication, if we write a signal handler for them in the program that receives the signal.

There is an example showing the use of ``SIGUSR1`` and ``SIGUSR2`` in [Signaling Another Process](https://www.gnu.org/software/libc/manual/html_node/Signaling-Another-Process.html).

The default action is to terminate the process.

## Bitwise operation

This type of operator treats its operands as 32-bit binary data, rather than decimal, hexadecimal, or octal data.
These operators process this data according to their binary representation
but return standard numeric values in their original format.

| Operator | Denomination | Effect | Syntax | Result |
| ----------- | ----------- | ----------- | ----------- | ----------- |
|`&` |	ET bit-by-bit  |	Returns 1 if the two bits of the same weight are at 1 |	9 & 12 (1001 & 1100) |	8 (1000)|
|<code>&#124;</code> |	OU bit-by-bit  |	Returns 1 if either of the two equally significant bits is 1 (or both)  |	9 <code>&#124;</code> 12 (1001 <code>&#124;</code> 1100) |	13 (1101)|
|`^` |	OU bit-by-bit exclusif |	Returns 1 if one of the two bits of equal weight is 1 (but not both)  |	9 ^ 12 (1001 ^ 1100) |	5 (0101)|

### AND (&)

```nano
12 = 00001100 (In Binary)
25 = 00011001 (In Binary)

Bit Operation of 12 and 25
  00001100
& 00011001
  ________
  00001000  = 8 (In decimal)
```

### OR (|)

```nano
12 = 00001100 (In Binary)
25 = 00011001 (In Binary)

Bitwise OR Operation of 12 and 25
  00001100
| 00011001
  ________
  00011101  = 29 (In decimal)
```

### XOR

```nano
12 = 00001100 (In Binary)
25 = 00011001 (In Binary)

Bitwise XOR Operation of 12 and 25
  00001100
^ 00011001
  ________
  00010101  = 21 (In decimal)
```

### Right Shift Operator

Right shift operator shifts all bits towards right by certain number of specified bits. It is denoted by ``>>``.

```nano
212 = 11010100 (In binary)
212>>2 = 00110101 (In binary) [Right shift by two bits]
212>>7 = 00000001 (In binary)
212>>8 = 00000000 
212>>0 = 11010100 (No Shift)
```

### Left Shift Operator

Left shift operator shifts all bits towards left by a certain number of specified bits. The bit positions that have been vacated by the left shift operator are filled with 0. The symbol of the left shift operator is ``<<``.

```nano
212 = 11010100 (In binary)
212<<1 = 110101000 (In binary) [Left shift by one bit]
212<<0 = 11010100 (Shift by 0)
212<<4 = 110101000000 (In binary) =3392(In decimal)
```

## Bonus

- The server confirms every signal received by sending a signal to the client. (Not implemented)
- Support Unicode characters!
