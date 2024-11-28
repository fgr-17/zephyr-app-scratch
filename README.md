# Zephyr App - Created from scratch

*  Author: rouxfederico@gmail.com

## Introduction

This project is an example of a [T2 Topology project](https://docs.zephyrproject.org/latest/develop/west/workspaces.html)

Basic files needed for a Zephyr Project basic app:

``` bash

zephyr-app-scratch/
├─ CMakeLists.txt
├─ west.yml
├─ src/
│  ├─ main.c

```

## Environment 

This project needs the Zephyr SDK and West tool pre-installed. One of the easiest way is using the [Zephyr Project docker image](https://github.com/zephyrproject-rtos/docker-image)

## Creation Steps

After creating the files according to a T2 Topology, is necessary to initialize this dir as the Zephyr active project. To do this, execute inside the workspace:

``` bash
cd workspace
west init -l zephyr-app-scratch
cd zephyr-app-scratch
west zephyr-export .

```

## Compiling

Run the classic CMake + Makefile steps

``` bash
cd zephyr-app-scratch
mkdir -p build
cd build
cmake .. -DBOARD=<board name>
make

```

## License

Apache