
Project Setting

[Include directory]
..\..\_library\SDL2\include;..\..\_library\SDL2_image\include;$(IncludePath)

[Lib directory]
..\..\_library\SDL2\lib\x64;..\..\_library\SDL2_image\lib\x64;$(LibraryPath)

[Dependency]
SDL2.lib;SDL2main.lib;SDL2_image.lib;

[DLL]
copy SDL2.dll, SDL2_image.dll to [project\x64\Debug]

