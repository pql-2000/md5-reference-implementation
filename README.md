# MD5 reference implementation

Fully featured reference implementation of the MD5 hashing algorithm.

From Wikipedia - 
```
The MD5 message-digest algorithm is a widely used hash function producing a 128-bit hash value. Although MD5 was initially designed to be used as a cryptographic hash function, it has been found to suffer from extensive vulnerabilities. It can still be used as a checksum to verify data integrity, but only against unintentional corruption.
```

## Compilation

To compile, use
```
g++ *.c -o md5
```

or the equivalent syntax of your favorite compiler.

## Synopsis

```
./md5 [assert]
```

Supply "assert" as first argument to run 100 tests to verify code integrity.


Anything else will read from stdin until EOF, and echo the hashed plaintext back.
