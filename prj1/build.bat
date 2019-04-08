setlocal
if "%1"=="" (
	set config=vs
) else (
	set config=%1
)
set builddir=out\%config%
cd %~dp0
call configure.bat %config%
if %errorlevel% neq 0 exit /b %errorlevel%
call config-%config%.bat
cd %builddir%
set PATH=%cd%\bin;%PATH%
%build_command%
if %errorlevel% neq 0 exit /b %errorlevel%
