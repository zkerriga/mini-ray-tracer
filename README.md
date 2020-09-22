# miniRT
:eyes::art: This project is the beginning of the study of <a href="https://en.wikipedia.org/wiki/Ray_tracing_(graphics)">Ray Tracing</a> technology!

### Objective of program:
The program gets a file that describes the scene, which can contain three-dimensional objects, light sources, and cameras.
If the program is running in `--save` mode, it should create a bmp-image of the scene that would be visible from the last camera. Otherwise, a window should open that shows the image visible from the cameras, which can be switched with arrows (right and left). The position of objects relative to each other, their lighting and shadows should be processed as closely as possible to real light.

### Prepare:
To download a project, use the command with an additional flag (used for connecting all libraries).
```
git clone https://github.com/zkerriga/miniRT --recursive
```
Next, you need to compile the project with the ` make ` command. The Makefile will report the successful build of the project.

### Usage:
The program starts as follows in the terminal:
```
./miniRT DESCRIPTION_PATH [FLAG]
```
Available flags:
- `-h`, `--help`  -  Shows the help
- `-s`, `--save`  -  Enables bmp-image saving mode.

### Examples:
```
./miniRT ./scene_tests/castle.rt
```
![castle.rt view-1](https://github.com/zkerriga/miniRT/blob/master/images/castle.jpg)
![castle.rt view-2](https://github.com/zkerriga/miniRT/blob/master/images/castle_view2.jpg)
![castle.rt view-3](https://github.com/zkerriga/miniRT/blob/master/images/castle_view3.jpg)
![castle.rt view-4](https://github.com/zkerriga/miniRT/blob/master/images/castle_view4.jpg)

### Issue:
The <a href="https://github.com/ttshivhula/minilibx.git">minilibx</a> library that is used in the project doesn't run on all systems. This build works well on ArchLinux with Xorg installed. If the library is not built, try replacing it with <a href="https://github.com/42Paris/minilibx-linux">this one</a>.
