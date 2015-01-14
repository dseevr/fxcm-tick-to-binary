# fxcm-tick-to-binary

tick2binary is a little program which converts tick data from FXCM into a binary format for faster consumption and lower memory overhead.

There is an example of how to consume the binary file under examples/read\_binary\_file/

## Usage

```
./tick2binary input.csv output.bin
```

## Notes

Requires Clang, boost, and will only work on FreeBSD and Mac OSX due to libc++ usage.  It'd be easy to convert to libstdc++ if one were so inclined.

## License

BSD
