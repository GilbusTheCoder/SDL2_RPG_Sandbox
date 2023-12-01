workspace "SDL2_RPG_Sandbox"
    configurations {"Debug", "Release"}
    architecture "x64"

    output_dir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
    ---------------------------------
    ----     RPG SANDBOX CFG     ----
    ---------------------------------
    project "Sandbox"
        location "Sandbox"
        kind "ConsoleApp"
        language "C++"

        vendor_dir = "%{prj.name}/vendor"
        targetdir ("out-bin/" .. output_dir .. "/%{prj.name}")  -- Output Dir
        objdir ("int-bin/" .. output_dir .. "/%{prj.name}")     -- Intermediate Dir

        pchheader "pch.h"
        pchsource "%{prj.name}/src/pch.cpp"                             -- Required for visual studio, excluded by other compilers
        files { "%{prj.name}/src/**.h", "%{prj.name}/src/**.cpp" }      -- What do we want to include in the project make
        

        externalincludedirs {   vendor_dir .. "/SDL2/include",
                                vendor_dir .. "/SDL2_image/include",
                                vendor_dir .. "/SDL2_mixer/include",
                                vendor_dir .. "/SDL2_ttf/include",      }

        links {     "SDL2",
                    "SDL2main",
                    "SDL2_image",    
                    "SDL2_mixer",    
                    "SDL2_ttf",     }  
        
        libdirs {       vendor_dir .. "/SDL2/lib/x64",
                        vendor_dir .. "/SDL2_image/lib/x64",
                        vendor_dir .. "/SDL2_mixer/lib/x64",
                        vendor_dir .. "/SDL2_ttf/lib/x64",      }

        filter "system:windows"
            cppdialect "C++20"
            staticruntime "On"
            systemversion "latest"  -- If not set premake will generate a windows 8.1 SDK and that can fuck off

            defines {"GAME_PLAT_WINDOWS"}

            postbuildcommands{
                ("{COPYFILE} vendor/SDL2/lib/x64/SDL2.dll ../out-bin/" .. output_dir .. "/%{prj.name}"),
                ("{COPYFILE} vendor/SDL2_image/lib/x64/SDL2_image.dll ../out-bin/" .. output_dir .. "/%{prj.name}"),
                ("{COPYFILE} vendor/SDL2_mixer/lib/x64/SDL2_mixer.dll ../out-bin/" .. output_dir .. "/%{prj.name}"),
                ("{COPYFILE} vendor/SDL2_ttf/lib/x64/SDL2_ttf.dll ../out-bin/" .. output_dir .. "/%{prj.name}"), }
        filter "configurations:Debug"
            defines { "DEBUG" }
            symbols "On"

        filter "configurations:Release"
            defines { "NDEBUG" }
            optimize "Full"