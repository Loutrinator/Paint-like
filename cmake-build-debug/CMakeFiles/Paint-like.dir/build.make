# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\Antoine\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\202.7660.37\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\Antoine\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\202.7660.37\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\0-Workspace\CLion\Paint-like

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\0-Workspace\CLion\Paint-like\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\Paint-like.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\Paint-like.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\Paint-like.dir\flags.make

CMakeFiles\Paint-like.dir\vendor\glad\src\glad.c.obj: CMakeFiles\Paint-like.dir\flags.make
CMakeFiles\Paint-like.dir\vendor\glad\src\glad.c.obj: ..\vendor\glad\src\glad.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\0-Workspace\CLion\Paint-like\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Paint-like.dir/vendor/glad/src/glad.c.obj"
	"D:\Programmes\Microsoft Visual Studio\2017\Enterprise\VC\Tools\MSVC\14.15.26726\bin\Hostx64\x64\cl.exe" @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\Paint-like.dir\vendor\glad\src\glad.c.obj /FdCMakeFiles\Paint-like.dir\ /FS -c D:\0-Workspace\CLion\Paint-like\vendor\glad\src\glad.c
<<

CMakeFiles\Paint-like.dir\vendor\glad\src\glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Paint-like.dir/vendor/glad/src/glad.c.i"
	"D:\Programmes\Microsoft Visual Studio\2017\Enterprise\VC\Tools\MSVC\14.15.26726\bin\Hostx64\x64\cl.exe" > CMakeFiles\Paint-like.dir\vendor\glad\src\glad.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\0-Workspace\CLion\Paint-like\vendor\glad\src\glad.c
<<

CMakeFiles\Paint-like.dir\vendor\glad\src\glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Paint-like.dir/vendor/glad/src/glad.c.s"
	"D:\Programmes\Microsoft Visual Studio\2017\Enterprise\VC\Tools\MSVC\14.15.26726\bin\Hostx64\x64\cl.exe" @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\Paint-like.dir\vendor\glad\src\glad.c.s /c D:\0-Workspace\CLion\Paint-like\vendor\glad\src\glad.c
<<

CMakeFiles\Paint-like.dir\src\main.cpp.obj: CMakeFiles\Paint-like.dir\flags.make
CMakeFiles\Paint-like.dir\src\main.cpp.obj: ..\src\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\0-Workspace\CLion\Paint-like\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Paint-like.dir/src/main.cpp.obj"
	"D:\Programmes\Microsoft Visual Studio\2017\Enterprise\VC\Tools\MSVC\14.15.26726\bin\Hostx64\x64\cl.exe" @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Paint-like.dir\src\main.cpp.obj /FdCMakeFiles\Paint-like.dir\ /FS -c D:\0-Workspace\CLion\Paint-like\src\main.cpp
<<

CMakeFiles\Paint-like.dir\src\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Paint-like.dir/src/main.cpp.i"
	"D:\Programmes\Microsoft Visual Studio\2017\Enterprise\VC\Tools\MSVC\14.15.26726\bin\Hostx64\x64\cl.exe" > CMakeFiles\Paint-like.dir\src\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\0-Workspace\CLion\Paint-like\src\main.cpp
<<

CMakeFiles\Paint-like.dir\src\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Paint-like.dir/src/main.cpp.s"
	"D:\Programmes\Microsoft Visual Studio\2017\Enterprise\VC\Tools\MSVC\14.15.26726\bin\Hostx64\x64\cl.exe" @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Paint-like.dir\src\main.cpp.s /c D:\0-Workspace\CLion\Paint-like\src\main.cpp
<<

# Object files for target Paint-like
Paint__like_OBJECTS = \
"CMakeFiles\Paint-like.dir\vendor\glad\src\glad.c.obj" \
"CMakeFiles\Paint-like.dir\src\main.cpp.obj"

# External object files for target Paint-like
Paint__like_EXTERNAL_OBJECTS =

Paint-like.exe: CMakeFiles\Paint-like.dir\vendor\glad\src\glad.c.obj
Paint-like.exe: CMakeFiles\Paint-like.dir\src\main.cpp.obj
Paint-like.exe: CMakeFiles\Paint-like.dir\build.make
Paint-like.exe: CMakeFiles\Paint-like.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\0-Workspace\CLion\Paint-like\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Paint-like.exe"
	C:\Users\Antoine\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\202.7660.37\bin\cmake\win\bin\cmake.exe -E vs_link_exe --intdir=CMakeFiles\Paint-like.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x64\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x64\mt.exe --manifests  -- "D:\Programmes\Microsoft Visual Studio\2017\Enterprise\VC\Tools\MSVC\14.15.26726\bin\Hostx64\x64\link.exe" /nologo @CMakeFiles\Paint-like.dir\objects1.rsp @<<
 /out:Paint-like.exe /implib:Paint-like.lib /pdb:D:\0-Workspace\CLion\Paint-like\cmake-build-debug\Paint-like.pdb /version:0.0  /machine:x64 /debug /INCREMENTAL /subsystem:console   -LIBPATH:D:\0-Workspace\CLion\Paint-like\vendor\glfw-3.3.2\lib  glfw3.lib kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\Paint-like.dir\build: Paint-like.exe

.PHONY : CMakeFiles\Paint-like.dir\build

CMakeFiles\Paint-like.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Paint-like.dir\cmake_clean.cmake
.PHONY : CMakeFiles\Paint-like.dir\clean

CMakeFiles\Paint-like.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" D:\0-Workspace\CLion\Paint-like D:\0-Workspace\CLion\Paint-like D:\0-Workspace\CLion\Paint-like\cmake-build-debug D:\0-Workspace\CLion\Paint-like\cmake-build-debug D:\0-Workspace\CLion\Paint-like\cmake-build-debug\CMakeFiles\Paint-like.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\Paint-like.dir\depend

