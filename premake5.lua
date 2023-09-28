workspace "Richard"
   startproject "RichardEditor"
   architecture "x64"
   configurations 
   { 
      "Debug", 
      "Release" 
   }

project "RichardEditor"
   location "RichardEditor"
   kind "ConsoleApp"
   language "C++"

   files 
   { 
      "%{prj.name}/src/**.h",
      "%{prj.name}/src/**.c" 
   }

   -- Treat fatal warnings as errors
   flags { "FatalWarnings" }