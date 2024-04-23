# FKernel 

FKernel is a [Hybrid Kernel](https://en.wikipedia.org/wiki/N%C3%BAcleo_h%C3%ADbrido) envisioned by [KitsuneSemCalda](https://github.com/KitsuneSemCalda) aiming to be similar to [Unix/BSD](https://en.wikipedia.org/wiki/Berkeley_Software_Distribution) and [Plan9](https://en.wikipedia.org/wiki/Plan_9_from_Bell_Labs), specifically designed for [x64](https://en.wikipedia.org/wiki/X86-64).

The focus of FKernel is to be built with some [Memory Safety](https://en.wikipedia.org/wiki/Memory_safety) utilizing and leveraging [Smart Pointers](https://en.wikipedia.org/wiki/Smart_pointer) and smart compilers like [Rust](https://en.wikipedia.org/wiki/Rust_(programming_language)).

## About

FKernel is a project to be written in C++, Rust, and Nasm. It aims to be easily customizable using an [SDK](https://en.wikipedia.org/wiki/Software_development_kit) based on Object-Oriented programming, facilitating secure development of [Drivers](https://en.wikipedia.org/wiki/Driver_(software)) and [Modules](https://en.wikipedia.org/wiki/Loadable_kernel_module).


## Prerequisites

- [QEMU](https://www.qemu.org/)
- [NASM](https://www.nasm.us/)
- [CLANG/LLVM](https://llvm.org/)
- [XMAKE](https://xmake.io/)
- [LLDB](https://lldb.llvm.org/)
- [GRUB](https://www.gnu.org/software/grub/)


## Building

```bash
$ xmake
```
and 
```bash
$ xmake run
```




## Contribution

Contributions are welcome! But this is an opinionated project, so please make sure your changes align with the project's goals and vision. Here are some ways you can contribute:

- **Bug**: In case you find a new bug, please create an issue on our GitHub with steps to reproduce the bug or provide tests to verify its resolution.

- **Feature**: If you have a new feature idea, please create an issue and discuss it with the team before starting to code.

- **Documentation**: Help us improve the documentation by fixing typos, adding examples, adding new languages, or clarifying explanations.

- **Code**: If you want to contribute code, please make sure it follows the project's coding style and conventions. You can start by fixing a bug or implementing a new feature that has been discussed and approved by the team.

## License

The FKernel is built with the BSD 3-Clause License. See the [License](http://github.com/FoxBSD/FKernel/blob/main/LICENSE).
