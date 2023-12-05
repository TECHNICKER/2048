# CMakeList.txt : CMake project for 248, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (248 "248.cpp" "248.h" "Leaderboard.h" "Leaderboard.cpp" "Draw.h" "Draw.cpp" "Gamelogic.h" "Gamelogic.cpp" "Save.h" "Save.cpp" "Style.h" "Style.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 248 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
