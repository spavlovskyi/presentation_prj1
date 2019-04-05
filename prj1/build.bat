setlocal
set builddir=out
cd %~dp0
call configure.bat
if %errorlevel% neq 0 exit /b %errorlevel%
cd %builddir%
msbuild.exe /m prj1.sln
if %errorlevel% neq 0 exit /b %errorlevel%
