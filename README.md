# PFE 3D Decimator

This project was made as an end-of-study project of Master in Computer Science at the _University of Bordeaux_, on behalf of the _Manao team_ of the _Inria_. It was originally developped in February and March 2022.

It contains a **mesh simplifier**, to reduce the number of faces of a mesh using different parameters, and is part of a [bigger project](https://github.com/Nimoka/PFE-3D-Viewer).

---

## Table of contents

- [PFE 3D Decimator](#pfe-3d-decimator)
	- [Table of contents](#table-of-contents)
	- [Dependencies](#dependencies)
	- [Usage](#usage)
		- [Install dependencies](#install-dependencies)
		- [Compilation](#compilation)
		- [Tests](#tests)
	- [Clang-format](#clang-format)

---

## Dependencies

This is a list of dependencies used in this project that you can install by yourself. Note that some of them are required, other can be compiled at the same time as the rest of the project.

- `cmake` _(required)_

## Usage

Usage: ./Decimator [OPTIONS]

Options:
  -h,--help                   Print this help message and exit
  -i,--input TEXT:FILE:PLY_EXTENSION REQUIRED
                              PLY file to load
  -o,--output TEXT:PLY_EXTENSION REQUIRED
                              PLY file to save
  -d FLOAT:FLOAT in [1 - 1e+06] REQUIRED
                              Decimation factor
  -s INT:POSITIVE             Random seed to use


### Install dependencies

- **On macOS:**
	- If needed, install `brew` _([steps](https://docs.brew.sh/Installation))_
	- Run the command:
		```
		brew install cmake
		```

### Compilation

- **On Linux/macOS:**
	- Run the command at the root of the directory:
		```
		./compile.sh
		```
 

### Tests

- **On Linux/macOS:**
	- Run the command at the root of the directory:
		```
		./test.sh
		```


### Clang-format

- **Launch the clang-format on .cpp, .hpp, .c, .h files**
  - set the path of .clang-format in vscode : go to Extension, install clang-format by xaver, at Manage-> extension Setting -> Clang-format:Style -> input the full path of .clang-format.
  - find . -regex '.*\.\(cpp\|hpp\|c\|h\)' -exec clang-format -style=file -i {} \ ; .  
