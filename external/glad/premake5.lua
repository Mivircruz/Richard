project "glad"
   kind "StaticLib"
   language "C"
   staticruntime "on"

   targetdir(target_dir)
   objdir(obj_dir)

   files { 
      "include/**.h", 
      "src/**.c" 
   }

   externalincludedirs {
      "include"
   }

   systemversion "latest"

   filter "configurations:Debug"
      runtime "Debug"
      symbols "on"
   
   filter "configurations:Release"
      runtime "Release"
      symbols "on"
      optimize "on"