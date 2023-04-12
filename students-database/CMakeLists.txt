# CMakeList.txt : CMake project for students-database, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (students-database "students-database.cpp"  "Models/Student.h"  "Models/Subject.h"  "Models/Date.h" "Models/Session.h" "Table/Table.h" "Table/Table.cpp" "FileInteraction/FileInteraction.h" "FileInteraction/FileInteraction.cpp"  "ConsoleInteraction/ConsloleInteraction.h" "ConsoleInteraction/ConsoleInteraction.cpp" "Tools/Tools.h" "Tools/Tools.cpp" "Handlers/Handlers.h" "Handlers/Handlers.cpp" "Models/Student.cpp" Tools/List.cpp CryptManager/CryptManager.cpp)

# TODO: Add tests and install targets if needed.
