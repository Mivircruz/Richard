-- WARNING! If this file is moved, its path needs to be updated in cli\cmd\project_settings.py (const PREMAKE_PATH)

workspace "richard"
   startproject "richardeditor"
   architecture "x64"
   configurations { 
      "Debug", 
      "Release" 
   }

-- WARNING! If this path is changed, the .exe path needs to be updated in cli\cmd\run.py
target_dir = "bin/solutions/target/%{cfg.buildcfg}/%{prj.name}"
obj_dir = "bin/solutions/obj/%{cfg.buildcfg}/%{prj.name}"

project "richardeditor"
   location "richardeditor"
   kind "ConsoleApp"
   language "C++"
   cppdialect "C++17"
   staticruntime "on"

   targetdir(target_dir)
   objdir(obj_dir)

   files { 
      "%{prj.name}/src/**.h",
      "%{prj.name}/src/**.c" 
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