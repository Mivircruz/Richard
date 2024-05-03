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

   filter "configurations:debug"
      runtime "debug"
      symbols "on"
   
   filter "configurations:release"
      runtime "release"
      staticruntime "off"
      symbols "on"
      optimize "on"