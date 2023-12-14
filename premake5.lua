-- WARNING! If this file is moved, its path needs to be updated in cli\cmd\gensln.py (const PREMAKE_PATH)

workspace "Richard"
   startproject "RichardEditor"
   architecture "x64"
   configurations 
   { 
      "Debug", 
      "Release" 
   }

-- WARNING! If this path is changed, the .exe path needs to be updated in cli\cmd\run.py
target_dir = "bin/solutions/target/%{cfg.buildcfg}/%{prj.name}"
obj_dir = "bin/solutions/obj/%{cfg.buildcfg}/%{prj.name}"

project "RichardEditor"
   location "RichardEditor"
   kind "ConsoleApp"
   language "C++"

   targetdir(target_dir)
   objdir(obj_dir)

   files 
   { 
      "%{prj.name}/src/**.h",
      "%{prj.name}/src/**.c" 
   }

   -- Treat fatal warnings as errors
   flags { "FatalWarnings" }