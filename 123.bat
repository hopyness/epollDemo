
@echo off
::Proto文件路径
set SOURCE_PATH=.\pbsrc
for /f "delims=" %%i in ('dir /b "%SOURCE_PATH%\*.proto"') do (
echo  %SOURCE_PATH%\%%i
protoc -I=./pbsrc --cpp_out=./pbinclude  %SOURCE_PATH%\%%i
)

echo end proto
 
pause