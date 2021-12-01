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

## Bonus

- The server confirms every signal received by sending a signal to the client.
- Support Unicode characters!
