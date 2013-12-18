solution "Server"
    location "Serverbuild"
    language "C++"
    objdir "obj"

    configurations { "DebugDLL", "ReleaseDLL" }

    configuration "windows"
        defines { "WIN32", "_WIN32" }

    --configuration "bsd"
    --  defines { "LUA_USE_POSIX" }
    --  includedirs { "/usr/local/include", "/usr/local/include/mysql" }
    --  libdirs { "/usr/local/lib", "/usr/local/lib/mysql", "/usr/local/lib/event2" }

    --configuration "macosx"
    --    defines { "LUA_USE_MACOSX" }
    --    includedirs { "/opt/local/include", "/opt/local/include/mysql55/mysql" }
    --    libdirs { "/opt/local/lib", "/opt/local/lib/mysql55/mysql" }

    configuration "linux"
        --defines { "LUA_USE_LINUX" }
        --includedirs { "/usr/include/mysql", "/usr/local/include/mysql" }
        --libdirs { "/usr/local/lib/mysql" , "/usr/lib/x86_64-linux-gnu" }
		includedirs { "/usr/include/libtaomee" }
        libdirs { "/usr/lib/" }
		includedirs { "/usr/include/glib-2.0", "/usr/lib/x86_64-linux-gnu/glib-2.0/include" }
		libdirs {"/usr/lib/", "/usr/lib/x86_64-linux-gnu/"}

    configuration "vs*"
        flags "EnableSSE2"
        buildoptions { "-wd4996" }
        defines { "_CRT_SECURE_NO_WARNINGS" }

    configuration "not vs*"
        buildoptions {"-g", "-Wall", "-fexceptions", "-fno-strict-aliasing", "-fPIC", "-shared" }
    configuration {"not vs*", "windows"}
        buildoptions { "-static-libgcc", "-static-libstdc++" , "-fPIC"}

    configuration "Debug"
        flags "Symbols"
        defines "_DEBUG"
        targetdir "bin/debug"

    configuration { "Release", "not vs*" }
        flags "Symbols"

    configuration { "Release", "linux or freebsd" }
        buildoptions "-march=native"

    configuration "Release"
        flags { "OptimizeSpeed" }
        targetdir "bin/release"

    include "LoginServer"
	--include "AServer"
	if os.is("windows") then
	--include "hiredis"
	--include "event"
	end
