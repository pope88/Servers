project "ServerModel"
    --kind "ConsoleApp"
	kind "SharedLib"

    files { "**.cpp", "**.cc", "**.c", "**.h" }
    excludes { "Packet/PacketsLStoC.*", "Packet/PacketsCtoLS.*" }
   -- includedirs { "..", ".", "../ssu" }
    includedirs { "../ssu" }
    --links { "gd", "rt", "taomee++", "taomee", "ssl" }

    configuration "windows"
        if os.is("windows") then
        debugdir ".."
        end
        --includedirs { "../event/include", "../hiredis" }
        --links { "hiredis.kt", "event.kt", "ws2_32", "mswsock", "kernel32", "user32" }
    configuration { "vs* or codeblocks" }
        files "../Config.cpp"
        pchsource "../Config.cpp"
        pchheader "Config.h"
    configuration "not vs*"
        buildoptions { "-std=gnu++0x" }
		files "../Config.cpp"
        pchsource "../Config.cpp"
        pchheader "Config.h"
    configuration "not windows"
        --links { "hiredis", "curl", "event", "event_pthreads", "pthread" }
    configuration "linux"
        --links { "dl" }
		--links {  "librt", "libtaomee++", "libtaomee", "libssl" }
		--links {  "librt", "libssl" }
          --"libgd",跨平台的简单图形库:libgd_阿福的技术BLOG_百度空间
		  --Linux下使用librt中的定时器 - Gothic的专栏 - 博客频道 - CSDN.NET