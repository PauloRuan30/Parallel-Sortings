add_rules("mode.debug", "mode.release")

target("Cpp_Parallel")
    set_kind("binary")
    add_files("src/*.cpp", "src/lib/*.cpp") -- .cpp files for compilation
    add_includedirs("src/include") -- header files directory for referencing
