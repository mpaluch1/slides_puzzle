# Slides puzzle

## Setup (Linux only)
```shell
$ git clone https://github.com/mpaluch1/slides_puzzle
$ cd slides_puzzle/
$ git submodule update --init --recursive

# build spdlog as static library
$ cd spdlog/
$ mkdir build && cd build/
$ cmake .. && make -j
```