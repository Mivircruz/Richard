-- WARNING! If this file is moved, its path needs to be updated in cli/cmd/project_settings.py (const PREMAKE_PATH)

workspace "richard"
   startproject "client"
   architecture "x64"
   configurations { 
      "debug", 
      "release" 
   }

-- WARNING! If this path is changed, the .exe path needs to be updated in cli/cmd/run.bat
target_dir = "solutions/bin/%{cfg.buildcfg}/%{prj.name}"
obj_dir = "solutions/obj/%{cfg.buildcfg}/%{prj.name}"

-- External dependencies
externals = {}
externals["sdl2"] = "external/sdl2"
externals["spdlog"] = "external/spdlog"
externals["glad"] = "external/glad"
externals["stb"] = "external/stb"

-- Process Glad
-- It goes to the directory and looks for another premake5.lua file
include "external/glad"

project "engine"
   location "engine"
   kind "StaticLib"
   language "C++"
   cppdialect "C++17"
   staticruntime "on"

   targetdir(target_dir)
   objdir(obj_dir)

   files { 
      "%{prj.name}/src/**.h",
      "%{prj.name}/src/**.cpp" 
   }

   -- This allows you to import just the headers instead of referencing the full path
   -- For example, instead of importing the path external/sdl2/include/SDL.h we can directly import SDL.h
   externalincludedirs {
      "%{prj.name}/src",
      "%{externals.sdl2}/include",
      "%{externals.spdlog}/include",
      "%{externals.glad}/include",
      "%{externals.stb}"
   }

   -- Treat fatal warnings as errors
   flags { "FatalWarnings" }

   -- This ensures Glad won't include GLFW as we will use SDL2
   defines {"GLFW_INCLUDE_NONE"}

   systemversion "latest"

   filter "configurations:debug"
      defines {
         "RICHARD_CONFIG_DEBUG"
      }
      runtime "debug"
      symbols "on"
   
   filter "configurations:release"
      defines {
         "RICHARD_CONFIG_RELEASE"
      }
      runtime "release"
      symbols "on"
      optimize "on"

project "client"
   location "client"
   kind "ConsoleApp"
   language "C++"
   cppdialect "C++17"
   staticruntime "on"
   links "engine"

   targetdir(target_dir)
   objdir(obj_dir)

   files { 
      "%{prj.name}/src/**.h",
      "%{prj.name}/src/**.cpp" 
   }
   -- This allows you to use headers directly instead of referencing the engine folder
   -- For example, instead of engine/src/core/engine.h we can directly import core/engine.h
   externalincludedirs {
      "engine/src"
   }

   -- Treat fatal warnings as errors
   flags { "FatalWarnings" }

   systemversion "latest"

   libdirs {
      "%{externals.sdl2}/lib/x64"
   }

   links {
      "SDL2",
      "glad"
   }

   filter "configurations:debug"
      defines {
         "RICHARD_CONFIG_DEBUG"
      }
      runtime "debug"
      symbols "on"
   
   filter "configurations:release"
      defines {
         "RICHARD_CONFIG_RELEASE"
      }
      runtime "release"
      symbols "on"
      optimize "on"