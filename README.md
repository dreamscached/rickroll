# RickrollCXX

A C++ program that as the title suggests, rickrolls the user. What did you
expect? That's all it does. Deal with it.

[Original project][1] created by TheSystemGuy1337, further on maintained and worked
on by dreamscached. RickrollCXX, in contrast to original Rickroll project, has:

* CMake builds
* Full support of three major platforms
  * Windows (natively) ✓
  * Linux (with xdg-open) ✓
  * MacOS (natively) ✓
* Original ([dQw4w9WgXcQ](https://youtu.be/dQw4w9WgXcQ)) and ad-less ([xvFZjo5PgG0](https://youtu.be/xvFZjo5PgG0))
  video URLs (`-DNOADS_URL` C++ flag)

## Building

RickrollCXX uses CMake for building. You'll need MinGW/Visual Studio 
compiler on Windows and GCC on Unix/Darwin.

### Preparing CMake project

```shell
git clone https://github.com/dreamscached/rickrollcxx
mkdir rickrollcxx/build && cd rickrollcxx/build
```

### Compiling

#### Default link ([dQw4w9WgXcQ](https://youtu.be/dQw4w9WgXcQ))

```shell
cmake -DCMAKE_BUILD_TYPE=Release .. && make
```

#### Link with no ads ([xvFZjo5PgG0](https://youtu.be/xvFZjo5PgG0))

```shell
cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_FLAGS="-DNOADS_URL" .. && make
```

[1]: https://github.com/TheSystemGuy1337/Rickroll
