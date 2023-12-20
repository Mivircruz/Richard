-- WARNING! If this file is moved, its path needs to be updated in cli\cmd\project_settings.py (const PREMAKE_PATH)

workspace "richard"
   startproject "richardeditor"
   architecture "x64"
   configurations { 
      "debug", 
      "release" 
   }

-- WARNING! If this path is changed, the .exe path needs to be updated in cli\cmd\run.bat
target_dir = "bin/solutions/%{cfg.buildcfg}/%{prj.name}"
obj_dir = "obj/%{cfg.buildcfg}/%{prj.name}"

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
      "%{prj.name}/src/**.cpp" 
   }

   -- Treat fatal warnings as errors
   flags { "FatalWarnings" }

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