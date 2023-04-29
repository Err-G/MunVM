
# MunVM

MunVM is a lightweight virtual machine written in C, designed for learning about CPU
instructions and Forth. Inspired by minimalistic VMs such as `uxn` and `nga`, MunVM
has a memory area, two stacks (data and return), and a set of instructions that can
be executed. The VM initializes its memory and stacks before executing the
instructions in memory.

MunVM is a great starting point for those who want to learn about virtual machines
and CPU instruction sets. The code is simple and easy to understand, making it a
great platform to experiment with and extend.

## Getting Started

To get started with the virtual machine, you can simply clone the repository and run
the `build.sh` and run `vm`.

```bash
git clone https://github.com/err-g/MunVM
cd MunVM
make
# Run the vm
./vm
```

## How to use

MunVM is designed to be easy to use and modify. However, at the moment, it cannot
read files and has no I/O capabilities. In the future, an assembler will be included
in the same standalone executable used to run the VM.

## Roadmap

### Core Functionality
* Implement all 30/31 standard instructions, covering arithmetic operations, flow
control, stack manipulation, memory access, and I/O.
### Tooling 
* Develop an assembler for the VM, making it easier to create programs that run on
the VM. This will be a simple assembler, with plans for a more advanced language
later on.
### Devices
* Add support for external devices, such as a display, mouse, and keyboard. This will
allow users to create more interactive programs and applications.
### Compatibility
* Port some of the programs written for Uxn to run on this VM. This will help
showcase the capabilities of the VM and provide a starting point for developers to
build on.

## License

This project is licensed under the MIT License - see the `LICENSE.md` file for
details.
