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

## Config file
To change the configuration of the game, you have to provide path to config
file via command line argument `-c, --config`. The default value for this
argument is `config.json` placed in app directory. For available options
look into `config.json` file in this repo.