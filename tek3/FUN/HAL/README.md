# hal

**HA**skell **L**ISP

## Getting started

The HAL is a LISP interpretor written in Haskell for educational
purposes. It was made as an Epitech project for the 3rd year's
functionnal track.

```
$ cat example.lisp
(cond ((eq? 'foo (car '(foo bar))) 'here) ((eq? 1 2) 'there) (#t 'nope))
$ ./hal example.lisp
here
```

```
$ cat example.lisp
(define (fact x)
  (cond ((eq? x 1) 1)
    (#t (* x (fact (- x 1))))))
$ cat entry.lisp
(fact 10)
$ ./hal example.lisp entry.lisp
3628800
```

## Note for Epitech Student

We don't care if you look at this code to understand how it works, **_BUT_**,
we are not responsible for any -42 you could get coming here ;).

## Compilation

You need `make` and `stack` for the project to compile. Then execute the
following command in the root of the project :

```bash
make
```

## Other points

I haven't used `mtl` because I just needed basic error handling, which
I got to work using only a simple `Either`.
