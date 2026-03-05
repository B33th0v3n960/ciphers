## Ciphers

This is just personal hobby project to test and learn out encryption, decryption
and hacking. 

## Affine Cipher
Encrypted with using the following equation:

$$
    E(x) \equiv (ax + b) \pmod{m} 
$$

Decrypted with using the following equation:

$$
    D(y) \equiv v(y - b) \pmod{m} 
$$

where `v` is any modulo multiplicative inverse of `a(mod m)`

> Note: `m` is set as 256 to encrypt the message byte by byte

### Usage
Compile the code
```bash 
cc main.c -o cipher
```

Encryption
```
./cipher -f $FILENAME -a $A_VALUE -b $B_VALUE
```
> Note: `$A_VALUE` must be coprime to to m (i.e 256 = 2^8) ... just make it odd
> 
> Optionally output flag: `-o output.txt`

Decryption
```
./cipher -d -f $FILENAME -a $A_VALUE -b $B_VALUE
```
> Note: the `$A_VALUE` and `$B_VALUE` must be the same as during the encryption
> step 

## TODO
- [ ] Crack Affine Cipher
- [ ] Exponetial Cipher + Cracking
- [ ] RSA Cipher
