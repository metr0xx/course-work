# CMakeList.txt : CMake project for students-database, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (students-database "students-database.cpp"  "Student.h"  "Subject.h"  "Date.h" "Session.h" "Table/Table.h" "Table/Table.cpp" "FileInteraction/FileInteraction.h" "FileInteraction/FileInteraction.cpp"  "ConsoleInteraction/ConsloleInteraction.h" "ConsoleInteraction/ConsoleInteraction.cpp" "Tools/Tools.h" "Tools/Tools.cpp")

# TODO: Add tests and install targets if needed.
