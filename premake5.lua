-- WARNING! If this file is moved, its path needs to be updated in cli/cmd/project_settings.py (const PREMAKE_PATH)

workspace "Richard"
   startproject "RichardEditor"
   architecture "x64"
   configurations { 
      "Debug", 
      "Release" 
   }

-- WARNING! If this path is changed, the .exe path needs to be updated in cli/cmd/run.bat
target_dir = "solutions/bin/%{cfg.buildcfg}/%{prj.name}"
obj_dir = "solutions/obj/%{cfg.buildcfg}/%{prj.name}"

-- External dependencies
externals = {}
externals["sdl2"] = "external/sdl2"
externals["spdlog"] = "external/spdlog"

project "RichardEngine"
   location "RichardEngine"
   kind "StaticLib"
   language "C++"
   cppdialect "C++17"
   staticruntime "on"

   targetdir(target_dir)
   objdir(obj_dir)

   files { 
      "%{prj.name}/include/**.h", -- This folder will contain all header files that will be exposed to other apps
      "%{prj.name}/src/**.h",
      "%{prj.name}/src/**.cpp" 
   }

   -- This allows you to import just the headers instead of referencing the full path
   -- For example, instead of importing the path external/sdl2/include/SDL.h we can directly import SDL.h
   externalincludedirs {
      "%{prj.name}/src", -- This is added to import headers in include/richard.h
      "%{externals.sdl2}/include",
      "%{externals.spdlog}/include"
   }

   -- Treat fatal warnings as errors
   flags { "FatalWarnings" }

   systemversion "latest"

   filter "configurations:Debug"
      defines {
         "RICHARD_CONFIG_DEBUG"
      }
      runtime "Debug"
      symbols "on"
   
   filter "configurations:Release"
      defines {
         "RICHARD_CONFIG_RELEASE"
      }
      runtime "Release"
      symbols "on"
      optimize "on"

project "RichardEditor"
   location "RichardEditor"
   kind "ConsoleApp"
   language "C++"
   cppdialect "C++17"
   staticruntime "on"
   links "RichardEngine"

   targetdir(target_dir)
   objdir(obj_dir)

   files { 
      "%{prj.name}/src/**.h",
      "%{prj.name}/src/**.cpp" 
   }
   -- This allows you to use headers directly instead of referencing the RichardEngine folder
   -- For example, instead of RichardEngine/include/Richard/engine.h we can directly import Richard/engine.h
   externalincludedirs {
      "RichardEngine/include",
      "RichardEngine/src"
   }

   -- Treat fatal warnings as errors
   flags { "FatalWarnings" }

   systemversion "latest"

   libdirs {
      "%{externals.sdl2}/lib/x64"
   }

   links {
      "SDL2"
   }

   filter "configurations:Debug"
      defines {
         "RICHARD_CONFIG_DEBUG"
      }
      runtime "Debug"
      symbols "on"
   
   filter "configurations:Release"
      defines {
         "RICHARD_CONFIG_RELEASE"
      }
      runtime "Release"
      symbols "on"
      optimize "on"