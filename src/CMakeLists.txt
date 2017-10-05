# QTDIR must point to c:/Qt/5.7/mingw53_32/ or similar
message("qtdir is set to '$ENV{QTDIR}' (must be 'c:/Qt/5.7/mingw53_32/' or similar)")
set(CMAKE_PREFIX_PATH "$ENV{QTDIR}")

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

# Find the QtWidgets library
find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)

set(SOURCE_FILES
        main.cpp
        main.ui
        MainWindow.h
        MainWindow.cpp
        Processor.cpp
        Processor.h
        RegisterWidget.cpp
        RegisterWidget.h
        register.ui
        commands/Command.cpp
        commands/Command.h
        commands/CommandADD.cpp
        commands/CommandADD.h
        commands/CommandAND.cpp
        commands/CommandAND.h
        commands/CommandCMP.cpp
        commands/CommandCMP.h
        commands/CommandDIV.cpp
        commands/CommandDIV.h
        commands/CommandIN.cpp
        commands/CommandIN.h
        commands/CommandJGT.cpp
        commands/CommandJGT.h
        commands/CommandJLT.cpp
        commands/CommandJLT.h
        commands/CommandJMP.cpp
        commands/CommandJMP.h
        commands/CommandJZ.cpp
        commands/CommandJZ.h
        commands/CommandLOAD.cpp
        commands/CommandLOAD.h
        commands/CommandMOV.cpp
        commands/CommandMOV.h
        commands/CommandMUL.cpp
        commands/CommandMUL.h
        commands/CommandNOT.cpp
        commands/CommandNOT.h
        commands/CommandOR.cpp
        commands/CommandOR.h
        commands/CommandOUT.cpp
        commands/CommandOUT.h
        commands/CommandSET.cpp
        commands/CommandSET.h
        commands/CommandSTOP.cpp
        commands/CommandSTOP.h
        commands/CommandSTORE.cpp
        commands/CommandSTORE.h
        commands/CommandSUB.cpp
        commands/CommandSUB.h
        commands/CommandXOR.cpp
        commands/CommandXOR.h
        commands/DecodeException.h
        commands/DivByZeroException.h
        commands/StopException.h
        IOManager.cpp
        IOManager.h
        )

add_executable(schoty ${SOURCE_FILES})
target_link_libraries(schoty Qt5::Core Qt5::Widgets)
