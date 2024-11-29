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

## Compiling with make

Run the classic CMake + Makefile steps

``` bash
cd zephyr-app-scratch
mkdir -p build
cd build
cmake .. -DBOARD=<board name>
make

```

### Compiling with ninja and modifying banner

In order to build the app with Ninja instead of build, and configuring the initial boot banner using KConfig interface, the following steps can be done (for the example, the native_posix_64 board will be used):

``` bash
west build -b native_posix_64

mkdir build && cd build
cmake -GNinja -DBOARD=native_posix_64 ..
ninja
```
In order to change the banner message, it can be configured via KConfig. The menuconfig target can be built and run the following way:

```bash
west build -t menuconfig    ## build and run kconfig interface
ninja menuconfig            ## run kconfig interface
```
The CONFIG_BOOT_BANNER_STRING constant can be found on the following menu path: (Top) → General Kernel Options → Kernel Debugging and Metrics

After that, the app needs to be rebuilt. KConfig assures that not only the wanted variable is changed, but also its primitives.

The app can be run as this on the host machine (if not cross compiling):

```bash
cd build/zephhyr
./zephyr.elf

```
## License

Apache